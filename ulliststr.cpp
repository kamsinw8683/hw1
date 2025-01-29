#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE
/**
 * push_back(val):
 *   1. If the list is empty, allocate a new Item, set head_ and tail_ to it,
 *      and place val in val[0], adjusting first=0, last=1.
 *   2. Else if tail_ has space (tail_->last < ARRSIZE), simply place val in
 *      tail_->val[ tail_->last ] and tail_->last++.
 *   3. Else (no space in tail_), allocate a new Item and link it at the end.
 *      Put val in new tail_'s val[0], first=0, last=1.
 *   4. size_++ in each case.
 */
void ULListStr::push_back(const std::string& val){
  if(empty()) {
    Item* newItem = new Item();
    newItem->first = 0;
    newItem->last = 1; 
    newItem->val[0] = val;
    head_ = newItem;
    tail_ = newItem;
    }
  else if(tail_->last < ARRSIZE){
    tail_->val[tail_->last] = val;
    tail_->last++;
  }
  else{
    Item* newItem = new Item();
    newItem->first = 0;
    newItem->last = 1;
    newItem->val[0] = val;
    tail_->next = newItem;
    newItem->prev = tail_;
    tail_ = newItem;
  }
  size_++;
  }

void ULListStr::pop_back(){
  if(empty()) {
    return; 
  }
  tail_->last--;
  size_--;
  if(tail_->first == tail_->last) {
    Item* temp = tail_;
    if(tail_->prev) {
      tail_ = tail_->prev;
      tail_->next = nullptr;
    }
    else {
      head_ = nullptr;
      tail_ = nullptr;
    }
    delete temp;
  }
}
void ULListStr::push_front(const std::string& val)
{
  if(empty()) {
    Item* newItem = new Item();
    newItem->first = 0;
    newItem->last = 1;
    newItem->val[0] = val;
    head_ = newItem;
    tail_ = newItem;
  }
  else {
    if(head_->first > 0) {
      head_->first--;
      head_->val[ head_->first ] = val;
    }
    else {
      Item* newItem = new Item();
      newItem->first = ARRSIZE - 1;
      newItem->last = ARRSIZE;
      newItem->val[newItem->first] = val;
      newItem->next = head_;
      head_->prev = newItem;
      head_ = newItem;
    }
  }
  size_++;
}
void ULListStr::pop_front()
{
  if(empty()) {
    return; 
  }
  head_->first++;
  size_--;
  if(head_->first == head_->last) {
    Item* temp = head_;
    if(head_->next) {
      head_ = head_->next;
      head_->prev = nullptr;
    }
    else {
      head_ = nullptr;
      tail_ = nullptr;
    }
    delete temp;
  }
}
std::string const & ULListStr::back() const
{
  return tail_->val[ tail_->last - 1 ];
}


std::string const & ULListStr::front() const
{
  return head_->val[ head_->first ];
}

std::string* ULListStr::getValAtLoc(size_t loc) const
{
    if (loc >= size_) {
        return nullptr;
    }

    Item* current = head_;
    size_t currentIndex = 0;

    while (current != nullptr) {
        size_t nodeElements = current->last - current->first;

        if (currentIndex + nodeElements > loc) {
            size_t indexInNode = loc - currentIndex + current->first;
            return &(current->val[indexInNode]);
        }

        currentIndex += nodeElements;
        current = current->next;
    }

    return nullptr;
}


void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}
