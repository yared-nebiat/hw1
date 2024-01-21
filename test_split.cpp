/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/
#include <iostream>
#include "split.h"


int main(int argc, char* argv[])
{
  Node* head = new Node(3, nullptr);
  Node* curr = head;

  for(int i=4;i<14;i++) {
    curr->next = new Node(i, nullptr);
    curr = curr->next;
  }
  
  Node* oddVals = nullptr;
  Node* evenVals = nullptr;

  split(head, oddVals, evenVals);

  Node* temp;

  while(oddVals != nullptr) {
    std::cout << oddVals->value << " ";
    temp = oddVals;
    oddVals = oddVals->next;
    delete temp;
  }

  std::cout << std::endl;

  while(evenVals != nullptr) {
    std::cout << evenVals->value << " ";
    temp = evenVals;
    evenVals = evenVals->next;
    delete temp;
  }
}

