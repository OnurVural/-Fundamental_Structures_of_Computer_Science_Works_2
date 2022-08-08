/**
* Title : Balanced Search Trees , Hashing and Graphs
* Author : N.Onur Vural
* ID: 21902330
* Section : 2
* Assignment : 4
* Description : declaration of Stack class
*/
#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <string>
using namespace std;
typedef int StackItemType;

class Stack
{
    public:
        // constructor
        Stack();

        // destructor
        ~Stack();

        // @return: true if stack is empty, false otherwise
        bool isEmpty() const;

        /*
        Insert the item to the top of stack
        @param itemToAdd: desired item to be inserted
        @return: true if inserted succesfully, false otherwise
        */
        bool push(StackItemType itemToAdd);

        /*
        Remove the item from the top of stack
        @return: true if removed succesfully, false otherwise
        */
        bool pop();

        /*
        Remove the item from the top of stack and return it
        @param top: item that is currently removed
        @return: true if removed succesfully, false otherwise
        */
        bool pop(StackItemType& top);

        /*
        Retrieve the item from the top of stack
        @param top: item that is returned
        @return: true if returned succesfully, false otherwise
        */
        bool peek(StackItemType& top) const;

        /*
        Retrieve the item from the top of stack
        @return: item itself
        */
        StackItemType peek() const;

    protected:

    private:
        struct SearchStackNode {
            StackItemType item;        // the respective data
            SearchStackNode *next;        // pointing to the next node of stack
        };

        SearchStackNode *topOnStack;     // pointer to first node in the stack
};

#endif // STACK_H
