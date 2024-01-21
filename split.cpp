/*
CSCI 104: Homework 1 Problem 1

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even 
numbers and the other contains the odd numbers. Students 
will receive no credit for non-recursive solutions. 
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/

#include "split.h"

/* Add a prototype for a helper function here if you need */
Node* append(Node*& headptr, Node*& tailNode);

void split(Node*& in, Node*& odds, Node*& evens)
{
  /* Add code here */
  if (in == nullptr) {
    return;
  }

  Node* nextNode = in->next;
  in->next = nullptr;

  if(in->value % 2 == 0) {
    if(evens == nullptr) {
      evens = in;
    }
    else {
      append(evens, in);
    }
  }
  else {
    if(odds == nullptr) {
      odds = in;
    }
    else {
      append(odds, in);
    }
  }
  in = nextNode;
  split(in, odds, evens);
}

/* If you needed a helper function, write it here */

Node* append(Node*& headptr, Node*& tailNode) {
  if(headptr->next == nullptr) {
    headptr->next = tailNode;
    return tailNode;
  }
  else {
    return append(headptr->next, tailNode);
  }
}