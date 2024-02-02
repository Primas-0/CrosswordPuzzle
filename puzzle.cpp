// UMBC - CMSC 341 - Spring 2024 - Proj0
#include "puzzle.h"
Puzzle::Puzzle(int rows, int cols){
    if (rows >= 10 && cols >= 10) {
        //if the requirements are met, initializes member variables
        m_numRows = rows;
        m_numCols = cols;

        //allocates memory for 2D array
        m_puzzle = new char*[m_numRows];
        for (int i = 0; i < m_numRows; i++) {
            m_puzzle[i] = new char[m_numCols];
        }
    } else {
        //if the requirements are not met, creates an empty object
        m_numRows = 0;
        m_numCols = 0;
        m_puzzle = nullptr;
    }
}

Puzzle::~Puzzle(){
    //deallocates 2D array (must be in reverse order of allocation)
    for (int i = 0; i < m_numRows; i++) {
        delete[] m_puzzle[i];
    }
    delete[] m_puzzle;
}

void Puzzle::clear(){

}

bool Puzzle::reCreate(int rows, int cols, int seed){

}

void Puzzle::fill(int seed){

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