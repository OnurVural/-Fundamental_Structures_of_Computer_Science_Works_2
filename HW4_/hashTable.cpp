/**
* Title : Balanced Search Trees , Hashing and Graphs
* Author : N.Onur Vural
* ID: 21902330
* Section : 2
* Assignment : 4
* Description : implementation of hashTable class with separate chaining
*/
#include "hashTable.h"

hashTable::hashTable()
{
    //ctor
    for (int i = 0; i < tableSize; i++){
        theTable[i] = new HashNode;
        theTable[i]->lineNum = -1; //invalid index
        theTable[i]->word = "EMPTY";
        theTable[i]->next = NULL;
    }
}
hashTable::~hashTable(){
     for (int i = 0; i < tableSize; i++){
            deleteBucket(i);
     }
}
int hashTable::hash(const string &key, int tablesize){
    int hashVal = 0;

    for ( int i = 0; i < key.length(); i++)
        hashVal = 37 * hashVal + key[i];

    hashVal %=tablesize;
    if ( hashVal < 0) // if overflow happens
        hashVal += tablesize;

    return hashVal;
}

void hashTable::addVertice(string newWord, int newLineNum){
    int place = hash(newWord, tableSize);

    if (theTable[place]->word == "EMPTY" ){ //MEANS=> (HEAD == NULL)
        theTable[place]->lineNum = newLineNum;
        theTable[place]->word = newWord;
    }
    else{
            // create a new HashNode with given properties
            HashNode* newPtr = new HashNode;
            newPtr->lineNum = newLineNum;
            newPtr->word = newWord;
            newPtr->next = NULL;

            HashNode* temp = theTable[place];
            while (temp->next != NULL){
                temp = temp->next;
            }
            temp->next = newPtr;
    }
}

bool hashTable::wordExists(string searchWord){
// find correct index to search for
    int place = hash(searchWord, tableSize);
    HashNode* cur = theTable[place];

    while (cur != NULL){
        if (cur->word == searchWord){
            return true;
        }
        cur = cur->next;
    }
    return false;
}

int hashTable::retrieveLineNum(string searchWord){
    // find correct index to search for
    int place = hash(searchWord, tableSize);

    HashNode* cur = theTable[place];

    while (cur != NULL){
        if (cur->word == searchWord ){
            return cur->lineNum;
        }
        cur = cur->next;
    }

}

void hashTable::deleteFromHead(int index){
    // EMPTY NODE TO CLEAR
    if(theTable[index]->word == "EMPTY"){
            HashNode* delPtr = theTable[index];
            delete delPtr;
            theTable[index] = NULL;
            //delete theTable[index];
    }
    // NODE TO SET TO EMPTY
    else if (theTable[index]->next == NULL){
        theTable[index]->word = "EMPTY";
        theTable[index]->lineNum = -1;
    }
    // NODE THAT HAS A NEXT ELEMENT
    else if(theTable[index]->next != NULL){
            HashNode* delPtr = theTable[index];
            theTable[index] = theTable[index]->next;
            delete delPtr;
    }

}

void hashTable::deleteBucket(int index){
    while(theTable[index] != NULL ){
        deleteFromHead(index);
    }
}

