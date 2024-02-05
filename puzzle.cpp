// UMBC - CMSC 341 - Spring 2024 - Proj0
#include "puzzle.h"
Puzzle::Puzzle(int rows, int cols){
    if (rows >= 10 && cols >= 10) {
        //if the requirements are met, initialize member variables with passed-in values
        m_numRows = rows;
        m_numCols = cols;

        //allocate memory for 2D array
        m_puzzle = new char*[m_numRows]; //array of pointers
        for (int i = 0; i < m_numRows; i++) {
            //each pointer points to a separate array of chars
            m_puzzle[i] = new char[m_numCols];
        }
    } else {
        //if the requirements are not met, create an empty object
        m_numRows = 0;
        m_numCols = 0;
        m_puzzle = nullptr;
    }
}

Puzzle::~Puzzle(){
    //deallocate 2D array (should be done in inside-out order)
    for (int i = 0; i < m_numRows; i++) {
        //deallocate each array of chars
        delete[] m_puzzle[i];
    }
    //deallocate the array of pointers
    delete[] m_puzzle;
}

void Puzzle::clear(){
    //deallocate all memory
    for (int i = 0; i < m_numRows; i++) {
        delete[] m_puzzle[i];
    }
    delete[] m_puzzle;

    //clear the current object to an empty object
    m_numRows = 0;
    m_numCols = 0;
    m_puzzle = nullptr;
}

bool Puzzle::reCreate(int rows, int cols, int seed){

}

void Puzzle::fill(int seed){
    int randCharIndex = 0; //where random number will be stored

    //create instance of Random class and set seed
    Random randObject(MIN, MAX, UNIFORMINT);
    randObject.setSeed(seed);

    //fill 2D array with random characters
    for (int i = 0; i < m_numRows; i++) {
        for (int j = 0; j < m_numCols; j++) {
            randCharIndex = randObject.getRandNum();
            m_puzzle[i][j] = ALPHA[randCharIndex];
        }
    }
}

Puzzle::Puzzle(const Puzzle& rhs){

}

const Puzzle& Puzzle::operator=(const Puzzle& rhs){

}

bool Puzzle::appendRight(const Puzzle& rhs){

}

bool Puzzle::appendBottom(const Puzzle& bottom){

}

void Puzzle::dump(){
    int i=0;
    int j=0;
    cout << "   ";
    for (int k=0;k<m_numCols;k++){
        if ((k+1) < 10) cout << "0";
        cout << (k+1) << " ";
    }
    cout << endl;
    while(i<m_numRows){
        if ((i+1) < 10) cout << "0";
        cout << (i+1) << " ";
        while(j<m_numCols){
            if (m_puzzle[i][j] == '#')
                cout << "\033[1;31m\u2731\033[0m" << "  ";   // this prints HEAVY ASTERISK as separators
            else
                cout << m_puzzle[i][j] << "  ";
            j++;
        }
        cout << endl;
        j=0;
        i++;
    }
    cout << endl;
}