
/*  stack_3358.h
  CS 3358 Fall 2015
  
  a very simple linked list Stack ADT
*/

#ifndef STACK_3358_H
#define STACK_3358_H
#include <cstdlib>  // Provides size_t
#include <cassert>
#include <iostream>
using namespace std;

template<class ItemType>
class Stack_3358 {

public:

    // typedef int value_type;
    typedef size_t size_type;

    // Default constructor. Creates an empty stack.
    Stack_3358();

    //Copy constructor
    Stack_3358(const Stack_3358 & src);
    
    //Preconditions: None.
    //Postconditions: Destroys the list, cleaning up all resources associated with the object.
    ~Stack_3358();

    /****************************  
    makeEmpty

    Method: Removes all the items from the stack. 
    Preconditions: Stack has been initialized 
    Postconditions: All the items have been removed
    *****************************/          
    void makeEmpty();

    /****************************  
    isEmpty

    Method: Checks to see if there are any items on the stack. 
    Preconditions: Stack has been initialized
    Postconditions: Returns true if there are no items on the stack, else false.
    *****************************/          
    bool isEmpty() const;

    /****************************  
    isFull

    Method: Determines if you have any more room to add items to the stack
    Preconditions: Stack has been initialized
    Postconditions: Returns true if there is no more room to add items, else false
    *****************************/          
    bool isFull() const;

    /****************************  
    push

    Method: Adds newItem to the top of the stack. 
    Preconditions: Stack has been initialized and is not full.
    Postconditions: newItem is at the top of the stack.
    *****************************/     
    void push(const ItemType & pushValue);

    /****************************  
    pop

    Method: Removes topItem from stack and returns it.
    Preconditions: Stack has been initialized and is not empty.
    Postconditions: Top element has been removed from stack and item is a copy of the removed element. 
    *****************************/      
    ItemType pop();


private:
    struct Node {
        ItemType value;
        Node *next;
    };  

    Node *top;
}; 

/*******************************
/ Function implementations
********************************/

template <class ItemType>
Stack_3358<ItemType>::Stack_3358() : top(NULL) { }

template <class ItemType>
Stack_3358<ItemType>::Stack_3358(const Stack_3358& src)
{
   Node* newStack = new Node;
   newStack = src.top;
   
   if (src.top == NULL)
   {
	 top = NULL;
   }
   else
   {
	 Node* temp;
	 Node* prev = NULL;
	   
	 for (Node* p = src.top; p != NULL; p = p->next)
     {
	   temp = new Node;
	   temp->value = p->value;
	   temp->next = NULL;
	  
	  if (prev == NULL)
  		  prev = temp;
	  else
	  {
		prev->next = temp;
    	prev = temp;
	  }
	  
	  if (p == src.top)
		  top = temp;
	 }
   }
}   

template <class ItemType>
Stack_3358<ItemType>::~Stack_3358()
{
    Node *ptr = top;
    
    while (top != NULL)
    {
        top = top->next;
        delete ptr;
        ptr = top;
    }
}

template <class ItemType>
void Stack_3358<ItemType>::makeEmpty()
{
  while ( top != NULL )
  {
	ItemType trash = pop();
  }
}

template <class ItemType>
bool Stack_3358<ItemType>::isEmpty() const 
{
	return (top == NULL);
}

template <class ItemType>
bool Stack_3358<ItemType>::isFull() const
{
	return false;
}

template <class ItemType>
void Stack_3358<ItemType>::push(const ItemType & pushedItem)
{
	Node *newTop;
	newTop = new Node();
	 
	if ( isEmpty() )
	{
	  newTop->value = pushedItem;
	  newTop->next = NULL;
	  top = newTop;
    }
    else
    {
	  newTop->value = pushedItem;
	  newTop->next = top;
	  top = newTop;		
    }	 
 }

template <class ItemType>       
ItemType Stack_3358<ItemType>::pop()
{ 
   ItemType poppedItem;
   if ( isEmpty() )
   {
      cout << "Error: Unable to pop an empty stack. \n";
      exit(1);
   }
   else
   {
      poppedItem = top->value;
      Node* oldTop = new Node;
      oldTop = top;
      top = top->next;
      delete oldTop;
      return poppedItem;
   }
}    
//...
#endif


