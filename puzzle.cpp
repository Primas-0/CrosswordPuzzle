// UMBC - CMSC 341 - Spring 2024 - Proj0
#include "puzzle.h"
Puzzle::Puzzle(int rows, int cols){

}

Puzzle::~Puzzle(){

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