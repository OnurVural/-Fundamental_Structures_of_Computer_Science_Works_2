/**
* Title : Balanced Search Trees , Hashing and Graphs
* Author : N.Onur Vural
* ID: 21902330
* Section : 2
* Assignment : 4
* Description : description of your code
*/
#include <iostream>

#include "hashTable.h"
#include "Stack.h"
#include "Queue.h"
#include "WordNetwork.h"
using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    WordNetwork ww("words_vertices.txt", "words_edges.txt");
    ww.listNeighbors("jiber");
    cout << "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX" << endl;
    cout << "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX" << endl;
    ww.listNeighbors("jiber", 1);
    ww.listNeighbors("aided", 3);
    ww.listNeighbors("aided", 4);
    ww.listNeighbors("nodes", 9);
    ww.listNeighbors("order", 12);
    cout << "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX" << endl;
    cout << "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX" << endl;
    cout << "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX" << endl;
    ww.listConnectedComponents();
    ww.findShortestPath ( "nodes" , "graph" );
    ww.findShortestPath ( "nodes" , "mummy" );
    ww.findShortestPath ( "aided" , "ender" );
    ww.findShortestPath ( "order" , "mafia" );
    return 0;
}
