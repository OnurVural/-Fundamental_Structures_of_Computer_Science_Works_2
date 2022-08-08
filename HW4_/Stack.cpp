/**
* Title : Balanced Search Trees , Hashing and Graphs
* Author : N.Onur Vural
* ID: 21902330
* Section : 2
* Assignment : 4
* Description : implementation of Stack class
*/
#include "Stack.h"



Stack::Stack()
{
    topOnStack = NULL;
}



Stack::~Stack(){
    while (!isEmpty())
      pop();
}

bool Stack::isEmpty() const {
    if (topOnStack)
        return false;
    else
        return true;
}

bool Stack::push(StackItemType itemToAdd){
    SearchStackNode* newNode = new SearchStackNode;
    newNode->item = itemToAdd;
    newNode->next = topOnStack;
    topOnStack = newNode;
    return true;
}

bool Stack::pop(){
    if (!isEmpty()){
      SearchStackNode *tempNode = topOnStack;
      topOnStack = topOnStack->next;
      tempNode->next = NULL; //optional
      delete tempNode;
      return true;
    }
   else
    return false; //to indicate we could not delete
}
bool Stack::pop(StackItemType& top){
    if (!isEmpty()){
        top = topOnStack->item;
        pop();
        return true;
    }
    else
        return false;

}


 bool Stack::peek(StackItemType& top) const{
    if (!isEmpty()){
        top = topOnStack->item;
        return true;
    }
   // stack is not empty; retrieve top
   else
    return false;
 }

 StackItemType Stack::peek() const{
 if (!isEmpty()){
        return topOnStack->item;
}

 }
