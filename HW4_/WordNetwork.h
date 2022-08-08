/**
* Title : Balanced Search Trees , Hashing and Graphs
* Author : N.Onur Vural
* ID: 21902330
* Section : 2
* Assignment : 4
* Description : declaration of WordNetwork class
*/
#ifndef WORDNETWORK_H
#define WORDNETWORK_H
#include <iostream>

#include "Stack.h"
#include "Queue.h"
#include "hashTable.h"
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

class WordNetwork
{
    public:
        // constructor that reads edge and vertex files and constructs: hash table & adjacnecy matrix accordingly
        WordNetwork ( const string vertexFile , const string edgeFile );

        // destructor
        ~WordNetwork ();

        /*
        Lists all the adjacent components for a given word
        @param word: key word
        */
        void listNeighbors ( const string word );

        /*
        Lists all the components from a desired distance for a given word
        @param word: key word
        @param distance: the distance to traverse
        */
        void listNeighbors ( const string word , const int distance );

        /*
        Lists the connected components inside the whole graph
        */
        void listConnectedComponents ();

        /*
        Finds shortest path from a source to destination word and prints the path
        @param word1: starting index / source
        @param word2: end index / destination
        */
        void findShortestPath ( const string word1 , const string word2 );


    protected:

    private:
        /*
        Makes depth first traversel in the graph
        @param visited: defines the condition of a particular vertex being visited or not
        @param startingVertex: starting index / source
        */
        void DFT ( bool*& visited, int startingVertex );

        /*
        Makes upgraded breadth first traversel in the graph
        @param visited: defines the condition of a particular vertex being visited or not
        @param predec: defines the predecessors
        @param distance: defines given distances for an unweighted, undirected graph
        @param word1Num: starting index / source
        @param word2Num: end index / destination
        @return: true if there is exists a path from source to destination, false otherwise
        */
        bool BFT ( bool*& visited, int*&  predec, int*& distance, int word1Num, int word2Num );

        int matrixSize;
        // USES A HASH TABLE FOR AN OVERALL EFFICIENT LOOKUP PROCESS
        hashTable ht;

        // USES ADJACENCY MATRIX TO STORE THE WORDS
        bool **adjMatrix;
        string *vertices;

};

#endif // WORDNETWORK_H
