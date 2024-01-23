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

void ULListStr::push_back(const std::string& val) {
  if(empty()) {
    head_ = new Item();
    tail_ = head_;
    tail_->val[tail_->first] = val;
  }
  // checks if there is room in the Item
  else if(tail_->last < ARRSIZE) {
    tail_->val[tail_->last] = val;
  }
  // if Item is full make a new Item
  else {
    Item* nextItem = new Item();
    tail_->next = nextItem;
    nextItem->prev = tail_;
    tail_ = nextItem;
    tail_->val[tail_->first] = val;

  }
  tail_->last++;
  size_++;
}


void ULListStr::pop_back() {
  if(empty()) {
    return;
  }
  tail_->last--;
  size_--;
  if(tail_->first == tail_->last) {
    Item* temp = tail_;
    tail_ = tail_->prev;
    if(tail_ == NULL) {
      head_ = NULL;
    }
    else{
      tail_->next = NULL;
    }
    delete temp;
  }
}


void ULListStr::push_front(const std::string& val) {
  if(empty()) {
    // make a new Item and place the value
    head_ = new Item();
    tail_ = head_;
    head_->val[head_->last] = val;
    head_->last++;
  }
  else if(head_->first > 0) {
    head_->val[--head_->first] = val;
  }
  else {
    Item* prevItem = new Item();
    prevItem->first = ARRSIZE-1;
    prevItem->val[prevItem->first] = val;
    prevItem->last = ARRSIZE;

    head_->prev = prevItem;
    prevItem->next = head_;
    head_ = prevItem;
  }
  size_++;
}


void ULListStr::pop_front() {
  if(empty()) {
    return;
  }
  head_->first++;
  size_--;

  if(head_->first == head_->last) {
    Item* temp = head_;
    head_ = head_->next;

    if(head_ == NULL) {
      tail_ = NULL;
    }
    else{
      head_->prev = NULL;
    }
    delete temp;
  }
}

std::string const & ULListStr::back() const {
  return tail_->val[tail_->last-1];
}

std::string const & ULListStr::front() const {
  return head_->val[head_->first];
}

std::string* ULListStr::getValAtLoc(size_t loc) const {
  // index out of range
  if(loc >= size_) {
    return NULL;
  }

  Item* curr = head_;
  // traverses Items to reach the location
  while (loc >= (curr->last - curr->first) && curr != nullptr) {
    loc -= (curr->last - curr->first);
    curr = curr->next;    
  }
  return &curr->val[curr->first + loc];
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
