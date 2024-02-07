// UMBC - CMSC 341 - Spring 2024 - Proj0
#include "puzzle.h"
Puzzle::Puzzle(int rows, int cols){
    if (rows >= 10 && cols >= 10) {
        //if requirements are met, initialize member variables with passed-in values
        m_numRows = rows;
        m_numCols = cols;

        //allocate memory for 2D array
        m_puzzle = new char*[m_numRows]; //array of pointers
        for (int i = 0; i < m_numRows; i++) {
            //each pointer points to a separate array of chars
            m_puzzle[i] = new char[m_numCols];
        }
    } else {
        //if requirements are not met, create an empty object
        m_numRows = 0;
        m_numCols = 0;
        m_puzzle = nullptr;
    }
}

Puzzle::~Puzzle(){
    //deallocate 2D array (should be done inside-out)
    for (int i = 0; i < m_numRows; i++) {
        //deallocate each array of chars
        delete[] m_puzzle[i];
    }
    delete[] m_puzzle; //deallocate the array of pointers
}

void Puzzle::clear(){
    //deallocate all memory
    deallocPuzzle();

    //clear the current object to an empty object
    m_numRows = 0;
    m_numCols = 0;
    m_puzzle = nullptr;
}

bool Puzzle::reCreate(int rows, int cols, int seed){
    if (rows >= 10 && cols >= 10) {
        //if requirements are met
        deallocPuzzle(); //destroy current object

        //construct new object with passed-in values
        m_numRows = rows;
        m_numCols = cols;
        m_puzzle = new char*[m_numRows];
        for (int i = 0; i < m_numRows; i++) {
            m_puzzle[i] = new char[m_numCols];
        }

        //fill array with random data
        fill(seed);

        return true;
    } else {
        //if requirements are not met, make no changes to current object and return false
        return false;
    }
}

void Puzzle::fill(int seed){
    int randCharIndex = 0; //where random number will be stored

    //create instance of Random class and set seed
    Random randObject(MIN, MAX, UNIFORMINT);
    randObject.setSeed(seed);

    //fill puzzle with random characters
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
    if (m_numRows == rhs.m_numRows || m_puzzle == nullptr || rhs.m_puzzle == nullptr) {
        int newCols = m_numCols + rhs.m_numCols; //store updated column number

        //allocate new puzzle with updated rows and columns
        char** newPuzzle = new char*[m_numRows];
        for (int i = 0; i < m_numRows; i++) {
            newPuzzle[i] = new char[newCols];
        }

        //loop through original puzzle and copy over data to left side of new puzzle
        for (int i = 0; i < m_numRows; i++) {
            for (int j = 0; j < m_numCols; j++) {
                m_puzzle[i][j] = newPuzzle[i][j];
            }
        }

        //loop though passed-in puzzle and copy over data to right side of new puzzle
        for (int i = 0; i < rhs.m_numRows; i++) {
            for (int j = 0; j < rhs.m_numCols; j++) {
                rhs.m_puzzle[i][j] = newPuzzle[i][m_numCols + j];
            }
        }

        //deallocate original puzzle
        deallocPuzzle();

        //re-initialize current object with new values
        m_puzzle = newPuzzle;
        m_numCols = newCols;

        return true;
    } else {
        //if requirements for append not met, do nothing and return false
        return false;
    }
}

bool Puzzle::appendBottom(const Puzzle& bottom){
    if (m_numCols == bottom.m_numCols || m_puzzle == nullptr || bottom.m_puzzle == nullptr) {
        int newRows = m_numRows + bottom.m_numRows; //store updated row number

        //allocate new puzzle with updated rows and columns
        char** newPuzzle = new char*[newRows];
        for (int i = 0; i < m_numRows; i++) {
            newPuzzle[i] = new char[m_numCols];
        }

        //loop through original puzzle and copy over data to top part of new puzzle
        for (int i = 0; i < m_numRows; i++) {
            for (int j = 0; j < m_numCols; j++) {
                m_puzzle[i][j] = newPuzzle[i][j];
            }
        }

        //loop though passed-in puzzle and copy over data to bottom part of new puzzle
        for (int i = 0; i < bottom.m_numRows; i++) {
            for (int j = 0; j < bottom.m_numCols; j++) {
                bottom.m_puzzle[i][j] = newPuzzle[m_numRows + i][j];
            }
        }

        //deallocate original puzzle
        deallocPuzzle();

        //re-initialize current object with new values
        m_puzzle = newPuzzle;
        m_numRows = newRows;

        return true;
    } else {
        //if requirements for append not met, do nothing and return false
        return false;
    }
}

void Puzzle::deallocPuzzle() {
    //identical to destructor
    for (int i = 0; i < m_numRows; i++) {
        delete[] m_puzzle[i];
    }
    delete[] m_puzzle;
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