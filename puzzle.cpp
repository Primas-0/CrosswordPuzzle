// UMBC - CMSC 341 - Spring 2024 - Proj0
#include "puzzle.h"
Puzzle::Puzzle(int rows, int cols){
    if (rows >= 10 && cols >= 10) {
        //if requirements are met, initialize member variables with passed-in values
        m_numRows = rows;
        m_numCols = cols;

        //allocate memory for 2D array
        m_puzzle = new char*[m_numRows]; //m_puzzle is a pointer to an array of pointers
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
        deallocPuzzle(); //deallocate current object

        //re-construct current object with passed-in values
        m_numRows = rows;
        m_numCols = cols;
        m_puzzle = new char*[m_numRows];
        for (int i = 0; i < m_numRows; i++) {
            m_puzzle[i] = new char[m_numCols];
        }

        //fill array with random data
        fill(seed);

        return true;
    }
    //if requirements are not met, make no changes to current object and return false
    return false;
}

void Puzzle::fill(int seed){
    //where random values will be stored
    int randCharIndex = 0;
    bool randDecision = false;

    //we will be iterating through each column multiple times due to the structure of the for loops, so we need arrays to keep track of them
    int randFrequencyColArray[m_numCols]; //keeps track of how many separators there should be in each column
    int colSeparatorCountArray[m_numCols]; //keeps track of the current number of separators in each column

    //initialize arrays to zero to avoid garbage values
    for (int i = 0; i < m_numCols; i++) {
        randFrequencyColArray[i] = 0;
        colSeparatorCountArray[i] = 0;
    }

    //we will only be iterating through each row once
    //so the row separator count does not need to be in an array (can simply be reset to zero each time)
    int rowSeparatorCount = 0;

    //create instances of Random class and set seeds
    Random randObjectForChar(MIN, MAX, UNIFORMINT);
    randObjectForChar.setSeed(seed);

    Random randObjectForColFrequency(0, 3, UNIFORMINT);
    randObjectForColFrequency.setSeed(seed);

    Random randObjectToDecide(0, 1, UNIFORMINT);
    randObjectToDecide.setSeed(seed);

    //populates array with a random intended number of separators for each column
    for (int i = 0; i < m_numCols; i++) {
        randFrequencyColArray[i] = randObjectForColFrequency.getRandNum();
    }

    //fill puzzle
    for (int i = 0; i < m_numRows; i++) {
        rowSeparatorCount = 0; //reset count of separators in a row for each new row
        for (int j = 0; j < m_numCols; j++) {
            //randomly choose between inserting a letter or separator
            randDecision = (randObjectToDecide.getRandNum() == 1);

            if (randDecision && (colSeparatorCountArray[j] < randFrequencyColArray[j]) && rowSeparatorCount <= 3) {
                //if decision is true and separator counts are below threshold, insert separator into cell
                m_puzzle[i][j] = '#';

                //increment separator counts
                rowSeparatorCount++;
                colSeparatorCountArray[j]++;
            } else {
                //otherwise, insert a random letter into cell
                randCharIndex = randObjectForChar.getRandNum();
                m_puzzle[i][j] = ALPHA[randCharIndex];
            }
        }
    }
}

Puzzle::Puzzle(const Puzzle& rhs){
    //construct current object with same dimensions as rhs
    m_numRows = rhs.m_numRows;
    m_numCols = rhs.m_numCols;
    m_puzzle = new char*[m_numRows];
    for (int i = 0; i < m_numRows; i++) {
        m_puzzle[i] = new char[m_numCols];
    }

    //make current object a deep copy of rhs
    for (int i = 0; i < m_numRows; i++) {
        for (int j = 0; j < m_numCols; j++) {
            m_puzzle[i][j] = rhs.m_puzzle[i][j];
        }
    }
}

const Puzzle& Puzzle::operator=(const Puzzle& rhs){
    if (this != &rhs) {
        //if not self-assignment, change current object
        deallocPuzzle(); //deallocate current object

        //re-construct current object with same dimensions as rhs
        m_numRows = rhs.m_numRows;
        m_numCols = rhs.m_numCols;
        m_puzzle = new char*[m_numRows];
        for (int i = 0; i < m_numRows; i++) {
            m_puzzle[i] = new char[m_numCols];
        }

        //make current object a deep copy of rhs
        for (int i = 0; i < m_numRows; i++) {
            for (int j = 0; j < m_numCols; j++) {
                m_puzzle[i][j] = rhs.m_puzzle[i][j];
            }
        }
    }
    //return current object
    return *this;
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
                newPuzzle[i][j] = m_puzzle[i][j];
            }
        }

        //loop though passed-in puzzle and copy over data to right side of new puzzle
        for (int i = 0; i < rhs.m_numRows; i++) {
            for (int j = 0; j < rhs.m_numCols; j++) {
                newPuzzle[i][m_numCols + j] = rhs.m_puzzle[i][j];
            }
        }

        //deallocate original puzzle
        deallocPuzzle();

        //re-initialize current object with new information
        m_puzzle = newPuzzle;
        m_numCols = newCols;

        return true;
    }
    //if requirements for append not met, do nothing and return false
    return false;
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
                newPuzzle[i][j] = m_puzzle[i][j];
            }
        }

        //loop though passed-in puzzle and copy over data to bottom part of new puzzle
        for (int i = 0; i < bottom.m_numRows; i++) {
            for (int j = 0; j < bottom.m_numCols; j++) {
                newPuzzle[m_numRows + i][j] = bottom.m_puzzle[i][j];
            }
        }

        //deallocate original puzzle
        deallocPuzzle();

        //re-initialize current object with new information
        m_puzzle = newPuzzle;
        m_numRows = newRows;

        return true;
    }
    //if requirements for append not met, do nothing and return false
    return false;
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