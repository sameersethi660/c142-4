/*
This program implements Singly Linked List using C++ which includes the following functions: 
insert(int data)  
insertAt(int pos, int data)  
delete()
deleteAt(int pos)
countItems()
display()
*/

#include <iostream>
using namespace std;

class Node
{  
   public:
   int num;
   Node* next;
   Node()
   {
	   num=0;
	   next=NULL;
   }
};
class SLL
{
    private:
   Node* head;
   Node* tail;
   int size;
   public:
   SLL()
   {
	   size=0;
	   head=NULL;
	   tail=NULL;
   }
   void insert(int n);
   void insertAt(int data, int position);
   void deleten();
   void deleteAt(int pos);
   int countItems();
   void display();
};


   
   //Adds a new element to the end of the linked list.
   void SLL::insert(int n)
   {
      
      Node *tmp=new Node;
      tmp->num=n;
      tmp->next=NULL;
      if(head==NULL)                           // Steps to perform when the list is empty.
      {
         head=tmp;
         
      }
      else
      {
         tail->next=tmp;
        
      }
      tail=tmp;
      size++;
   }
	
	
	
   /*
   It includes the position at which the insertion happens. Positioning starts with 1.  
   Example: insertAt(1, 3)inserts 3 at the first position. 
	    It should print a statement “Linked List does not have that many elements” if the position does not exist in the linked list.
   */  
   void SLL::insertAt(int data, int position)
   { 
     if(position>size)
     {
      cout<<"\n \nLinked List does not have that many elements";     
     }     
     else if(position==0)
     {
      Node *n=new Node;
      n->num=data;  
      n->next=head;
      head=n;
      size++;
     }
     else if(position==size)
     {
      Node *tmp=new Node;
      tmp->num=data;
      tmp->next=NULL;
      if(head==NULL)                           // Steps to perform when the list is empty.
      {
         head=tmp;
       }
      else
      {
         tail->next=tmp;
        
      }
      tail=tmp;
      size++;
	     
     }
     else
     {
	  Node* n=new Node;
	     n->num=data;
	 Node* traverse=head;
         int count=0;
         while(count<position-1)
         {
          traverse=traverse->next;
          count++;
         }
      n->next=traverse->next;
      traverse->next=n;
      size++;
     }
   }
	
	
//Deletes the element at the end of the list 
   void SLL::deleten()
   {
                Node* traverse = head;
		//goes to the 2nd last element
	        int count=0;
		while(count<size-2)
		{
			traverse = traverse->next;
			count++;
		}
		
		tail = traverse;
		traverse->next = NULL;
		size--;

   }
	
	
	
   //Deletes the element(or node) at the position pos)
   void SLL::deleteAt(int pos)
   {
      if(pos>=size)
      {
	      cout<<"\n \nList doesn't have that many elements";
	      return;
      }
      int count=0;
      Node* temp, *temp1;
      temp = head  ;
      
      if(head==NULL)                              // Steps to perform when the list is empty.
      {
        cout<<"\n \nLinked List Empty !!!";
	      return;
      }
      else if(pos == 0)
      {
        head = head->next;
        delete temp;
      size--;
      }
      else
      {
      while(count!= pos-1)
      {
         temp = temp->next;
         count++;   
      }
      temp1 = temp->next;
      temp->next = temp1->next;
      temp1->next=NULL;
      delete temp1;
      size--;
      }
   }
	   
	   

   //Returns the number of items in the linked list. 
   int SLL::countItems()
   {
      //using size variable
	  int s=size;
	   return s; 
   }
   
   
	
	
//Displays all the elements in the linked list. Format should be followed as “1 -> 2 -> 3 -> 4 -> NULL” for a linked list holding integers in the order 1,2,3,4. 
   void SLL::display()
   {
    if(head==NULL)
      cout << "\n \nNULL \n \nThe List is empty";             // Steps to perform when the list is empty.
    else
    {
      Node *temp = head;
      cout<<"\n \n";
      while(temp != NULL)
      {
       cout << temp->num;
       cout<<"  -->  ";
       temp = temp->next;
      }
      cout<<"NULL \n";
     }
    }




//Main function to implement all the data structures and functions together
int main()
{
    int ch,x;
    char cha;
    int pos;
    SLL S;
    cout<<"\n \nPROGRAM TO USE THE CONCEPT OF LINKED LIST";
	
    //running a loop that asks continously to the user until "n" is received as an input
    do 
    {
       cout<<"\n1. Insert a node at the end \n2. Insert a node at a position specified \n3. Delete a node at the end ";
       cout<<"\n4. Delete a node at a position specifed \n5. Count the number of items \n6. Display ";
       cout<<"\nPlease enter your choice: ";
       cin>>ch;
       switch(ch)
       {
       case 1:
       {
              cout<<"\nEnter the data: ";
              cin>>x;
              S.insert(x);
              break;
        }
       case 2:
         {     cout<<"\nEnter the data to be inserted";
              cin>>x;
              cout<<"\nEnter the position to insert the node";
              cin>>pos;
              S.insertAt(x,pos);
              break;
          }
      case 3:
       {
		 S.deleten();	  
		 break;
       }
       case 4:
           {   cout<<"\nEnter the position of node to be deleted ";
              cin>>pos;
              S.deleteAt(pos);
              break;
	   }
       case 5:
          {
		  int num=0;
		  num=S.countItems();
		  cout<<"\n \nThe number of items in the Linked List is: "<<num;
		  break;
	  }		       
       case 6:
             {
                 S.display();
                 break;
              }
       default:
             { cout<<"\nWrong choice !!!!";
             break;}
    }
    cout<<"Do you want to continue? (y/n)  ";
    cin>>cha;
    }
    while(cha=='y' || cha=='Y');
    return 0;
}

