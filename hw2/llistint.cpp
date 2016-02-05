#include "llistint.h"
#include <cstdlib>
#include <stdexcept>

LListInt::LListInt()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

LListInt::~LListInt()
{
  clear();
}

bool LListInt::empty() const
{
  return size_ == 0;
}

int LListInt::size() const
{
  return size_;
}

/**
 * Complete the following function
 */
void LListInt::insert(int loc, const int& val)
{
	if(loc < 0 || loc > size_){//in case of invalid location
    	return;
	}
	else
	{
	   if (loc ==0)//special case
	   {
	      if (size_ == 0)//if the list is empty
	      {
	         Item *temp = new Item;
		      temp -> val = val;
		      temp -> next = NULL;//no next element
		      head_ = temp;
		      tail_ = temp;
		      size_++;
	      }
	      else//if it is the beginning of the list
	      {
	         Item *temp = new Item;
		      temp -> val = val;
		      temp -> next = head_;
		      head_ -> prev = temp;//old head's prev should be the new element
		      size_++;
		      head_ = temp;//assign the new head
		   }
	   }
	   else if (loc == size_)//at the end of the list
	   {
	      Item *temp = new Item;
		   temp -> val = val;
		   temp -> next = NULL;//no next element
		   temp -> prev = tail_;
		   tail_-> next = temp;
		   size_++;
		   tail_ = temp;//set the new tail
	   }
	   else//normal case
	   {
		   Item *place = getNodeAt(loc);
		   Item *temp = new Item;
		   temp -> val = val;
		   temp -> next = place;
		   temp -> prev = place -> prev;
		   place -> prev -> next = temp;
		   place -> prev = temp;
		   size_++;
		}
	}
}

/**
 * Complete the following function
 */
void LListInt::remove(int loc)
{
	if(loc < 0 || loc >= size_){//in case of invalid input location
    	return;
	}
	else
	{
	   if (loc == 0 )//special cases
	   {
	      if (size_ == 1)//last element in the list
	      {
	      	delete head_;//delete the space
	        head_ = NULL;
	        tail_ = NULL;
	        size_ = 0;
	      }
	      else//head of the list
	      {
				  head_->next->prev = NULL;
				  delete head_;//delete the space
				  head_ = head_ -> next;
				  size_--;
	      }
	   }
	   else if (loc == size_-1)//end of the list
	   {
		    tail_->prev->next = NULL;
		    delete tail_;//delete the space
		    tail_ = tail_ -> prev;
		    size_--;
	   }
	   else//normal case
	   {
		   Item* temp = getNodeAt(loc);
		   temp -> next -> prev = temp -> prev;
		   temp -> prev -> next = temp -> next;
		   delete temp;//delete the space
		   size_--;
		}
	}
}

void LListInt::set(int loc, const int& val)
{
  Item *temp = getNodeAt(loc);
  temp->val = val;
}

int& LListInt::get(int loc)
{
  if(loc < 0 || loc >= size_){
    throw std::invalid_argument("bad location");
  }
  Item *temp = getNodeAt(loc);
  return temp->val;
}

int const & LListInt::get(int loc) const
{
  if(loc < 0 || loc >= size_){
    throw std::invalid_argument("bad location");
  }
  Item *temp = getNodeAt(loc);
  return temp->val;
}

void LListInt::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}


/**
 * Complete the following function
 */
LListInt::Item* LListInt::getNodeAt(int loc) const
{
	if(loc < 0 || loc >= size_){
    	throw std::invalid_argument("bad location");//invalid location
  	}	
  	Item *temp = head_;//get the starting point
	for (int i=0; i<loc; i++)
	{
		temp = temp -> next;//find the node that we want
	}
	return temp;//return it
}
