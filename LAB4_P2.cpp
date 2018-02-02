#include<iostream>
using namespace std;

class node{
	public:
	float data; 
	node* next;
};
class stackll{
	public:
	node* bottom, *top; 
	stackll(){
		bottom = NULL;
		top = NULL;
	}
	void push(float data);
	void pop();
	void show();
	void mkqu(node* bottom);
	void dlt();
};
class queue{
	stackll stack1, stack2;
	public:
	void push();
	void pop();
	void show();
};
int main(){
	queue one;
	cout<<"This is to implement queue using two stack"<<endl;
	one.push();
	one.show();
	one.pop();
	one.show();
	return 0; 
}
 
void stackll::push(float data){
	node* temp =new node;
	temp ->data = data;
	temp->next=NULL;
	if (bottom ==NULL){
		bottom =temp ;
		top =temp;
	}	
	else {
		temp->next=bottom;
		bottom =temp;
	}
}
void stackll::pop(){
	if (bottom==NULL){
		cout<<"This stack is empty you can't pop any more"<<endl;
	}
	else if(bottom==top){
		node* temp =bottom;
		delete temp;
		bottom =NULL;
		top= NULL;
	}
	else {
		node* temp=bottom;
		bottom=bottom->next;
		delete temp;
	}
}
void stackll::show(){
	node* temp =bottom;
	if(bottom==NULL){
	cout<<"there is nothing to show"<<endl;
	}
	else {
		while(temp!=top){
		cout<<temp->data<<"->";
		temp=temp->next;	
		}
		cout<<temp->data<<endl;
	}
}
void stackll::mkqu(node* bottom){ 
		node* temp =bottom;
		if(bottom!=NULL){
			while(temp->next!=NULL){
				push(temp->data);
				temp=temp->next;
			}
			push(temp->data);
		}
}	
void stackll::dlt(){
	while(bottom!=NULL){
		pop();
	}	
}


void queue::push(){
	cout<<"Number of data"<<endl;
	int num,data;
	cin>>num;
	for(int i=0; i<num; i++){
		cout<<"Data"<<i+1<<":";
		cin>>data;
		stack1.push(data);
	}
	stack2.dlt();
	stack2.mkqu(stack1.bottom);
}	
void queue::pop(){
	cout<<"Number of data you want to delete:"<<endl;
	int num;
	cin>>num;
	for(int i=0; i<num; i++){
		stack2.pop();
	}
	stack1.dlt();
	stack1.mkqu(stack2.bottom);
}	
void queue::show(){
	stack1.show();
}
