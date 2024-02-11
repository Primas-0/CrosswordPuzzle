#include "puzzle.h"

class Tester {
public:
    bool testConstructorError(int rows, int cols);
    bool testConstructorEdgeAndNormal(int rows, int cols);

    bool testClear();

    bool testReCreateError(int rows, int cols, int seed);
    bool testReCreateEdgeAndNormal(int rows, int cols, int seed);

    bool testFill(int seed);

    bool testCopyConstructorError(const Puzzle& puzzleToCopy);
    bool testCopyConstructorEdge(const Puzzle& puzzleToCopy);
    bool testCopyConstructorNormal(const Puzzle& puzzleToCopy);

    bool testOverloadedAssignmentError(const Puzzle& puzzleToCopy);
    bool testOverloadedAssignmentEdge(const Puzzle& puzzleToCopy);
    bool testOverloadedAssignmentNormal(const Puzzle& puzzleToCopy);
    bool testOverloadedAssignmentToSelf(const Puzzle& puzzleToCopy);

    bool testAppendRightError(const Puzzle& puzzleToAppend);
    bool testAppendRightNormal(const Puzzle& puzzleToAppend);
    bool testAppendRightNormalToEmpty(const Puzzle& puzzleToAppend);
    bool testAppendRightEmptyToNormal(const Puzzle& puzzleToAppend);
    bool testAppendRightToSelf(const Puzzle& puzzleToAppend);

    bool testAppendBottomError(const Puzzle& puzzleToAppend);
    bool testAppendBottomNormal(const Puzzle& puzzleToAppend);
    bool testAppendBottomNormalToEmpty(const Puzzle& puzzleToAppend);
    bool testAppendBottomEmptyToNormal(const Puzzle& puzzleToAppend);
    bool testAppendBottomToSelf(const Puzzle& puzzleToAppend);
};

int main() {
    Tester tester;

    //constructor tests
    cout << "Testing Constructor (error case) - creates an empty object:" << endl;
    if (tester.testConstructorError(-5, 5)) {
        cout << "\tConstructor passed!" << endl;
    } else {
        cout << "\tConstructor failed!" << endl;
    }
    cout << "Testing Constructor (edge case) - creates memory, initializes all member variables to the proper values:" << endl;
    if (tester.testConstructorEdgeAndNormal(10, 10)) {
        cout << "\tConstructor passed!" << endl;
    } else {
        cout << "\tConstructor failed!" << endl;
    }
    cout << "Testing Constructor (normal case) - creates memory, initializes all member variables to the proper values:" << endl;
    if (tester.testConstructorEdgeAndNormal(12, 12)) {
        cout << "\tConstructor passed!" << endl;
    } else {
        cout << "\tConstructor failed!" << endl;
    }

    //clear test
    cout << "\nTesting Clear - empties the current object:" << endl;
    if (tester.testClear()) {
        cout << "\tClear passed!" << endl;
    } else {
        cout << "\tClear failed!" << endl;
    }

    //reCreate tests
    cout << "\nTesting reCreate (error case) - does not modify the current object:" << endl;
    if (tester.testReCreateError(8, 8, time(0))) {
        cout << "\treCreate passed!" << endl;
    } else {
        cout << "\treCreate failed!" << endl;
    }
    cout << "Testing reCreate (edge case) - creates memory, initializes all member variables to the proper values:" << endl;
    if (tester.testReCreateEdgeAndNormal(10, 10, time(0))) {
        cout << "\treCreate passed!" << endl;
    } else {
        cout << "\treCreate failed!" << endl;
    }
    cout << "Testing reCreate (normal case) - creates memory, initializes all member variables to the proper values:" << endl;
    if (tester.testReCreateEdgeAndNormal(12, 14, time(0))) {
        cout << "\treCreate passed!" << endl;
    } else {
        cout << "\treCreate failed!" << endl;
    }

    //fill test
    cout << "\nTesting Fill - properly populates array with letters and separators:" << endl;
    if (tester.testFill(time(0))) {
        cout << "\tFill passed!" << endl;
    } else {
        cout << "\tFill failed!" << endl;
    }

    //copy constructor tests


    //assignment operator tests


    //appendRight tests


    //appendBottom tests

}

bool Tester::testConstructorError(int rows, int cols) {
    //call constructor with invalid parameters
    Puzzle puzzle(rows, cols);

    if (puzzle.m_puzzle == nullptr && puzzle.m_numRows == 0 && puzzle.m_numCols == 0) {
        //test passes if an empty object has been created
        return true;
    }
    return false;
}

bool Tester::testConstructorEdgeAndNormal(int rows, int cols) {
    //call constructor with valid parameters
    Puzzle puzzle(rows, cols);

    if (puzzle.m_puzzle != nullptr && puzzle.m_numRows == rows && puzzle.m_numCols == cols) {
        //test passes if puzzle has been created and dimensions match passed-in values
        return true;
    }
    return false;
}


bool Tester::testClear() {
    //create an initial puzzle with default constructor (10x10)
    Puzzle puzzle;

    puzzle.clear();

    if (puzzle.m_puzzle == nullptr && puzzle.m_numRows == 0 && puzzle.m_numCols == 0) {
        //test passes if object has been emptied
        return true;
    }
    return false;
}


bool Tester::testReCreateError(int rows, int cols, int seed) {
    //create an initial puzzle with default constructor (10x10)
    Puzzle puzzle;

    //store initial dimensions to check against later
    int initialRows = puzzle.m_numRows;
    int initialCols = puzzle.m_numCols;

    //call reCreate with invalid parameters
    bool reCreateSuccess = puzzle.reCreate(rows, cols, seed);

    if (!reCreateSuccess && puzzle.m_puzzle != nullptr && puzzle.m_numRows == initialRows && puzzle.m_numCols == initialCols) {
        //test passes if function returns false and puzzle has not been changed
        return true;
    }
    return false;
}

bool Tester::testReCreateEdgeAndNormal(int rows, int cols, int seed) {
    //create an initial puzzle with default constructor (10x10)
    Puzzle puzzle;

    //call reCreate with valid parameters
    bool reCreateSuccess = puzzle.reCreate(rows, cols, seed);

    if (reCreateSuccess && puzzle.m_puzzle != nullptr && puzzle.m_numRows == rows && puzzle.m_numCols == cols) {
        //test passes if function returns true, puzzle is not empty, and dimensions match passed-in values
        return true;
    }
    return false;
}


bool Tester::testFill(int seed) {
    Puzzle puzzle;

    puzzle.fill(seed);

    //separator counts
    int rowSeparatorCount = 0;
    int colSeparatorCountArray[puzzle.m_numCols];

    //zero out count array
    for (int i = 0; i < puzzle.m_numCols; i++) {
        colSeparatorCountArray[i] = 0;
    }

    //iterate through puzzle to check whether it has been filled
    for (int i = 0; i < puzzle.m_numRows; i++) {
        rowSeparatorCount = 0;
        for (int j = 0; j < puzzle.m_numCols; j++) {
            if (puzzle.m_puzzle[i][j] == '#') {
                rowSeparatorCount++;
                colSeparatorCountArray[j]++;
            }

            if ((!isalpha(puzzle.m_puzzle[i][j]) && puzzle.m_puzzle[i][j] != '#')
                || rowSeparatorCount > 3 || colSeparatorCountArray[j] > 3) {
                //test fails if any cell is empty or holds an invalid value, or if either separator count exceeds limit
                return false;
            }
        }
    }
    //test passes if all cells correctly contain either a letter or separator, and separator counts are within range
    return true;
}

//TODO: copy constructor test functions
bool Tester::testCopyConstructorError(const Puzzle &puzzleToCopy) {
    Puzzle copy(puzzleToCopy);

    return true;
}


//TODO: assignment operator test functions


//TODO: appendRight test functions


//TODO: appendBottom test functions