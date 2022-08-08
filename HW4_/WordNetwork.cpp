/**
* Title : Balanced Search Trees , Hashing and Graphs
* Author : N.Onur Vural
* ID: 21902330
* Section : 2
* Assignment : 4
* Description : implementation of WordNetwork class
*/
#include "WordNetwork.h"



WordNetwork::WordNetwork ( const string vertexFile , const string edgeFile ){
    //1) FIRST DETECT THE MATRIX SIZE AND WORD LENGTH => FOR DEFENSE PURPOSES
    //-------------------------------------------------------------------------------------
    int wordLength;
    matrixSize = 0;
    string iterate;
    ifstream countFile;
    countFile.open(vertexFile.c_str());

    while(countFile >> iterate){
            wordLength = iterate.length(); // find the length of word
            matrixSize++;
    }
    countFile.close();
    //-------------------------------------------------------------------------------------


    //CONSTRUCTOR
    int lineNum = 0;
    ifstream inputFile;
    inputFile.open(vertexFile.c_str());
    string currentWord;

    // construct the adjacency matrix for given size
    adjMatrix = new bool*[matrixSize];
    for(int i = 0; i < matrixSize; ++i) {
        adjMatrix[i] = new bool[matrixSize];
    }

    for ( int i = 0; i < matrixSize; i++){
        for ( int j = 0; j < matrixSize; j++)
            adjMatrix[i][j] = false;
    }

    vertices = new string[matrixSize];


    // begin reading the vertex file
    while(inputFile >> currentWord){
            //wordLength = currentWord.length();
            //cout << "====================" << wordLength << "=====================" << endl;
            currentWord = currentWord.substr(0,wordLength);
            vertices[lineNum] = currentWord;
            // ADD THE VERTICE TO HASH TABLE
            ht.addVertice(currentWord, lineNum);
            lineNum++;
    }
    inputFile.close();
    //-----------------------------------------------------------------------------------------
    ifstream inputFile2;

    inputFile2.open(edgeFile.c_str());
    string line, first, second;
    int firstLineNum, secondLineNum;

    while(getline(inputFile2, line)){
//        stringstream ss(line);
//        getline(ss, first, ',');
//        getline(ss, second);

        first = line.substr(0, wordLength);
        second = line.substr(wordLength + 1, wordLength);

        // USE THE HASH TABLE FOR LOOKUP TO CALCULATE THE INDEX MUCH EFFICIENTLY!
        firstLineNum = ht.retrieveLineNum(first);
        secondLineNum = ht.retrieveLineNum(second);

        // CONSTRUCT AN EDGE BETWEEN GIVEN VERTICES
        adjMatrix[firstLineNum][secondLineNum] = true;
        //since it is undirected, it needs to have at its symmetric component too
        adjMatrix[secondLineNum][firstLineNum] = true;
    }
    inputFile2.close();
}

WordNetwork::~WordNetwork(){
    // clean adj matrix
    for(int i = 0; i < matrixSize; ++i) {
        delete [] adjMatrix[i];
    }
    delete [] adjMatrix;

    //clean vertex array
    delete[] vertices;
}

void WordNetwork::listNeighbors( const string word ){
    if (ht.wordExists(word)){
        cout << "Neighbors of " << word << ": " << endl;
        // FIND THE CORRECT PLACE FROM HASH TABLE
        int place = ht.retrieveLineNum(word);
        // CHECK THE NEIGHBOURS WITHIN
        for ( int i = 0; i < matrixSize; i++){
            if (adjMatrix[place][i] == true)
                cout << vertices[i] << endl;
        }
    }
    else
        cout << "The given word does not exist in the word database..." << endl;
}



void WordNetwork::listNeighbors ( const string word , const int distance ){
    if (ht.wordExists(word)){
            cout << "Neighbors of " << word << " at word distance " << distance<< ": " << endl;
            if ( distance == 0){
                cout << word << endl;
                return;
            }

            // DEFINE THE QUEUE NECESSARY FOR THE TRAVERSAL
            Queue Q;

            int wordNum = ht.retrieveLineNum(word);
            bool* visited = new bool[matrixSize];
            int *d = new int[matrixSize];

            for ( int i = 0; i < matrixSize; i++){
                visited[i] = false;
                d[i] = 0;
            }

            // MARK STARTING INDEX AS TRUE AND ADD TO THE QUEUE
            visited[wordNum] = true;
            d[wordNum] = 0;
            Q.enqueue(wordNum); // ADD TO THE QUEUE

            while (!Q.isEmpty() ){
                //GET THE FIRST-IN
                int currentVertex;
                Q.getFront(currentVertex);
                Q.dequeue(); // REMOVE FROM THE QUEUE

                for ( int i = 0; i < matrixSize; i++){
                // FOUND AN UNVISITED VERTEX
                    if (adjMatrix[currentVertex][i] && !visited[i]){
                        visited[i] = true;
                        Q.enqueue(i); // AD NEIGHBOR TO THE QUEUE
                        d[i] = d[currentVertex] + 1;

                        if (d[i] == distance)
                            cout << vertices[i] << endl; // FOUND THE PATH!
                    }
                }
            }
            delete [] visited;
            delete [] d;
    }
    else
        cout << "The given word does not exist in the word database..." << endl;
}


void WordNetwork::listConnectedComponents (){
    int num = 1;
    //1) DEFINE A MATRIX TO KEEP THE VISITED VERTICES IN MIND
    bool *visited = new bool[matrixSize];
    for ( int i = 0; i < matrixSize; i++)
        visited[i] = false;
    //2) FIND FIRST UNVISITED VERTICE AND START
    for ( int i = 0; i < matrixSize; i++){
        // first unvisited is found
        if (!visited[i]){
        cout << "Connected component " << num << endl;
        DFT(visited, i);
        num++;
        }
    }
    delete [] visited;
}

void WordNetwork::findShortestPath ( const string word1 , const string word2 ){
    if (!ht.wordExists(word1) || !ht.wordExists(word2) ){
        cout << "ATTENTION! You entered invalid word(s)..." << endl;
        return;
    }

    if (word1 == word2){
        cout << "Shortest path from "<< word1 << " to " << word2 << ":" << endl;
        cout << vertices[ht.retrieveLineNum(word1)] << endl;
        return;
    }

    //cout << "Shortest path from nodes to graph:" << endl;
    //CONSTRUCT AN ARRAY TO AVOID VISITING THE SAME ITEMS AGAIN
    bool *visited = new bool[matrixSize];
    //CONSTRUCT AN ARRAY TO KEEP THE DISTANCE VALUES WITHIN
    int *distance = new int[matrixSize];
    //CONSTRUCT AN ARRAY TO KEEP THE PREDECESSOR INDEXES WITHIN
    int *predec = new int[matrixSize];

    for ( int i = 0; i < matrixSize; i++){
        distance[i] = -1; // WE ASSUME ALL ARE DISJOINT AT FIRST
        predec[i] = -1;  // NO PREDECESSORS FOR ANY ITEM
        visited[i] = false; // ALL ITEMS ARE UNVISITED
    }

    // USE HASH TABLE FOR AN EFFICIENT LOOKUP
    // CALL THE TRAVERSEL TO OBTAIN PROPER VALUES FOR PREDEC SINCE IT MEANS THE PATH ITSELF
    if (!BFT(visited, predec, distance, ht.retrieveLineNum(word1), ht.retrieveLineNum(word2))){
        cout << "There is no path from " << word1 << " to " << word2 << " in the graph" << endl;
    }
    else{
        // USE A STACK SINCE IT REVERSES THE PRINT ORDER - THUS PRODUCES PROPER RESULTS
        Stack printer;
        int backwardsIndex = ht.retrieveLineNum(word2);
        printer.push(backwardsIndex);

        // UNTIL WE FIND NO PREDECESSOR WE CONTINUE...
        while (predec[backwardsIndex] != -1) {
            printer.push(predec[backwardsIndex]);
            backwardsIndex = predec[backwardsIndex]; // OLD PREDECESSOR BECOMES NEW INDEX TO CHECK
        }

        // PRINT THE WHOLE PATH (THE SHORTEST PATH)
        cout << "Shortest path from "<< word1 << " to " << word2 << ":" << endl;
        while(!printer.isEmpty()){
            int item = printer.peek();
            printer.pop();
            cout << vertices[item] << endl;
        }
        cout << endl;
    }
    // DEALLOC TO AVOID FROM MEMORY LEAKS...
    delete [] visited;
    delete [] distance;
    delete [] predec;

}

void WordNetwork::DFT(bool*& visited, int startingVertex){
    Stack S;
    // PUT STARTING INDEX TO STACK AND SELECT AS VISITED
    visited[startingVertex] = true;
    S.push(startingVertex);

    cout << vertices[startingVertex] << endl;

    while(!S.isEmpty()){
        int currentVertex, i;
        // GET CURRENT VERTEX TO CHECK
        S.peek(currentVertex);
        for ( i = 0; i < matrixSize; i++){
            // COME ACROSS A NEIGHBOUR UNVISITED YET
            if (adjMatrix[currentVertex][i] && !visited[i]){
                S.push(i);
                visited[i] = true;
                cout << vertices[i] << endl;
                break;
            }
        }
        // THERE IS NO NEIGHBOR LEFT THAT IS UNVISITED
        if ( i == matrixSize ){
            S.pop(); // POP CURRENT FROM THE STACK
        }
    }
}


bool WordNetwork::BFT( bool*& visited, int*&  predec, int*& distance, int word1Num, int word2Num ){
    // DEFINE THE QUEUE NECESSARY FOR THE TRAVERSAL
    Queue Q;

    // MARK STARTING INDEX AS TRUE AND ADD TO THE QUEUE
    visited[word1Num] = true;
    distance[word1Num] = 0; // IMPORTANT STEP SINCE DISTANCE OF THE ITEM WITH ITSELF IS ZERO
    Q.enqueue(word1Num); // ADD TO THE QUEUE

    while (!Q.isEmpty()){
        //GET THE FIRST-IN
        int currentVertex;
        Q.getFront(currentVertex);
        Q.dequeue(); // REMOVE FROM THE QUEUE

        for ( int i = 0; i < matrixSize; i++){
            // FOUND AN UNVISITED VERTEX
            if (adjMatrix[currentVertex][i] && !visited[i]){
                visited[i] = true;
                distance[i] = distance[currentVertex] + 1; // CALCULATE THE DISTANCE OF NEIGHBOR FROM THE CURRENT
                predec[i] = currentVertex; // CURRENT BECOMES THE PREDECESSOR OF THE GIVEN NEIGHBOR
                Q.enqueue(i); // AD NEIGHBOR TO THE QUEUE

                if (i == word2Num)
                    return true; // FOUND THE PATH!

                }
            }
    }
    return false; // COULD NOT FIND A PATH BETWEEN TWO VERTICES
}

