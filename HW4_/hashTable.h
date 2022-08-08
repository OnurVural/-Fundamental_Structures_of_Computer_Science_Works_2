/**
* Title : Balanced Search Trees , Hashing and Graphs
* Author : N.Onur Vural
* ID: 21902330
* Section : 2
* Assignment : 4
* Description : declaration of hashTable class with separate chaining
*/
#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <string>
using namespace std;

class hashTable
{
    public:
        // constructor
        hashTable();

        // destructor
        ~hashTable();

        /*
        Converts given word key to int lineNum
        @param key: key word
        @param tableSize: hash table size
        @return: hash value
        */
        int hash (const string &key, int tablesize);

        /*
        Adds a new vertex to table
        @param newWord: word to be inserted
        @param newLineNum: lineNum correspondance of item
        */
        void addVertice(string newWord, int newLineNum);

        /*
        Checks whether a word is in the table or not
        @param searchWord: word to be checked
        @return: true if exists, false otherwise
        */
        bool wordExists(string searchWord);

        /*
        Finds the line number of given word
        @param searchWord: word to be checked
        @return: the corresponding lineNum
        */
        int retrieveLineNum(string searchWord);

        /*
        Deletes the head item from given index
        @param index: deletion bucket
        */
        void deleteFromHead(int index);

        /*
        Clears the whole bucket
        @param index: deletion bucket
        */
        void deleteBucket(int index);

    protected:

    private:
        // table size is up to choice whether it is more efificent to have a dense or scarce configuration
        static const int tableSize = 100;

        struct HashNode{
            string word;
            int lineNum; // line number in adj matrix
            HashNode *next; // in order to have "separate chaining function"
        };

        HashNode* theTable[tableSize]; // to keep the linked list items composed of HashNode's
};
#endif // HASHTABLE_H
