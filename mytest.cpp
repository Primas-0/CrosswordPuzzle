#include "puzzle.h"

class Tester {
public:
    bool testConstructorError(int rows, int cols);
    bool testConstructorEdge(int rows, int cols);
    bool testConstructorNormal(int rows, int cols);

    bool testClear();

    bool testReCreateError(int rows, int cols, int seed);
    bool testReCreateEdge(int rows, int cols, int seed);
    bool testReCreateNormal(int rows, int cols, int seed);

    bool testFill(int seed);

    bool testCopyConstructorEdge(const Puzzle& original);
    bool testCopyConstructorNormal(const Puzzle& original);

    bool testAssignmentOperatorEdge(const Puzzle& original);
    bool testAssignmentOperatorNormal(const Puzzle& original);

    bool testAppendRightError(const Puzzle& puzzleRight);
    bool testAppendRightNormal(const Puzzle& puzzleRight);
    bool testAppendRightNormalToEmpty(const Puzzle& puzzleRight);
    bool testAppendRightEmptyToNormal(const Puzzle& puzzleRight);
    bool testAppendRightToSelf(const Puzzle& puzzleRight);

    bool testAppendBottomError(const Puzzle& puzzleBottom);
    bool testAppendBottomNormal(const Puzzle& puzzleBottom);
    bool testAppendBottomNormalToEmpty(const Puzzle& puzzleBottom);
    bool testAppendBottomEmptyToNormal(const Puzzle& puzzleBottom);
    bool testAppendBottomToSelf(const Puzzle& puzzleBottom);
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
    if (tester.testConstructorEdge(10, 10)) {
        cout << "\tConstructor passed!" << endl;
    } else {
        cout << "\tConstructor failed!" << endl;
    }
    cout << "Testing Constructor (normal case) - creates memory, initializes all member variables to the proper values:" << endl;
    if (tester.testConstructorNormal(12, 12)) {
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
    if (tester.testReCreateEdge(10, 10, 1 + time(0))) {
        cout << "\treCreate passed!" << endl;
    } else {
        cout << "\treCreate failed!" << endl;
    }
    cout << "Testing reCreate (normal case) - creates memory, initializes all member variables to the proper values:" << endl;
    if (tester.testReCreateNormal(12, 14, 2 + time(0))) {
        cout << "\treCreate passed!" << endl;
    } else {
        cout << "\treCreate failed!" << endl;
    }

    //fill test
    cout << "\nTesting Fill - properly populates array with letters and separators:" << endl;
    if (tester.testFill(3 + time(0))) {
        cout << "\tFill passed!" << endl;
    } else {
        cout << "\tFill failed!" << endl;
    }

    //copy constructor tests
    Puzzle puzzle1(0, 2);
    cout << "\nTesting Copy Constructor (edge case) - creates empty copy:" << endl;
    if (tester.testCopyConstructorEdge(puzzle1)) {
        cout << "\tCopy Constructor passed!" << endl;
    } else {
        cout << "\tCopy Constructor failed!" << endl;
    }
    Puzzle puzzle2(13, 15);
    puzzle2.fill(4 + time(0));
    cout << "Testing Copy Constructor (normal case) - creates deep copy:" << endl;
    if (tester.testCopyConstructorNormal(puzzle2)) {
        cout << "\tCopy Constructor passed!" << endl;
    } else {
        cout << "\tCopy Constructor failed!" << endl;
    }

    //assignment operator tests
    Puzzle puzzle3(-2, 0);
    cout << "\nTesting Assignment Operator (edge case) - copies empty object to normal object (empty copy):" << endl;
    if (tester.testAssignmentOperatorEdge(puzzle3)) {
        cout << "\tAssignment Operator passed!" << endl;
    } else {
        cout << "\tAssignment Operator failed!" << endl;
    }
    Puzzle puzzle4(16, 18);
    puzzle4.fill(5 + time(0));
    cout << "Testing Assignment Operator (normal case) - creates deep copy:" << endl;
    if (tester.testAssignmentOperatorNormal(puzzle4)) {
        cout << "\tAssignment Operator passed!" << endl;
    } else {
        cout << "\tAssignment Operator failed!" << endl;
    }

    //appendRight tests
    Puzzle puzzle5(11, 11);
    puzzle5.fill(6 + time(0));
    cout << "\nTesting appendRight (error case) - does not modify the current object:" << endl;
    if (tester.testAppendRightError(puzzle5)) {
        cout << "\tappendRight passed!" << endl;
    } else {
        cout << "\tappendRight failed!" << endl;
    }

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

bool Tester::testConstructorEdge(int rows, int cols) {
    //call constructor with valid parameters
    Puzzle puzzle(rows, cols);

    if (puzzle.m_puzzle != nullptr && puzzle.m_numRows == rows && puzzle.m_numCols == cols) {
        //test passes if puzzle has been created and dimensions match passed-in values
        return true;
    }
    return false;
}

bool Tester::testConstructorNormal(int rows, int cols) {
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

bool Tester::testReCreateEdge(int rows, int cols, int seed) {
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

bool Tester::testReCreateNormal(int rows, int cols, int seed) {
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


bool Tester::testCopyConstructorEdge(const Puzzle &original) {
    //original is an empty object
    Puzzle copy(original);

    if (copy.m_puzzle != original.m_puzzle && copy.m_numRows == 0 && copy.m_numCols == 0) {
        //test passes if the objects point to different memory locations and copy is empty
        return true;
    }
    return false;
}

bool Tester::testCopyConstructorNormal(const Puzzle &original) {
    Puzzle copy(original);

    for (int i = 0; i < copy.m_numRows; i++) {
        for (int j = 0; j < copy.m_numCols; j++) {
            if (copy.m_puzzle == original.m_puzzle ||
                copy.m_numRows != original.m_numRows || copy.m_numCols != original.m_numCols ||
                copy.m_puzzle[i] == original.m_puzzle[i] || copy.m_puzzle[i][j] != original.m_puzzle[i][j]) {
                //test fails if the objects point to the same memory location, the dimensions do not match, ...
                //... any of the row pointers are the same, or if any of the array data is different
                return false;
            }
        }
    }
    //test passes otherwise
    return true;
}


bool Tester::testAssignmentOperatorEdge(const Puzzle &original) {
    //make normal object
    Puzzle copy;

    //assign empty (original) to normal (copy)
    copy = original;

    if (copy.m_puzzle != original.m_puzzle && copy.m_numRows == 0 && copy.m_numCols == 0) {
        //test passes if the objects point to different memory locations and copy is empty
        return true;
    }
    return false;
}

bool Tester::testAssignmentOperatorNormal(const Puzzle &original) {
    Puzzle copy;

    copy = original;

    for (int i = 0; i < copy.m_numRows; i++) {
        for (int j = 0; j < copy.m_numCols; j++) {
            if (copy.m_puzzle == original.m_puzzle ||
                copy.m_numRows != original.m_numRows || copy.m_numCols != original.m_numCols ||
                copy.m_puzzle[i] == original.m_puzzle[i] || copy.m_puzzle[i][j] != original.m_puzzle[i][j]) {
                //test fails if the objects point to the same memory location, the dimensions do not match, ...
                //... any of the row pointers are the same, or if any of the array data is different
                return false;
            }
        }
    }
    //test passes otherwise
    return true;
}

//TODO: appendRight test functions
bool Tester::testAppendRightError(const Puzzle &puzzleRight) {
    //left puzzle has a different number of rows
    Puzzle puzzleFinal(15, 16);
    puzzleFinal.fill(11 + time(0));

    //save current dimensions to check against later
    int initialRows = puzzleFinal.m_numRows;
    int initialCols = puzzleFinal.m_numCols;

    //save the current data of puzzleFinal in puzzleInitial
    Puzzle puzzleInitial;
    puzzleInitial = puzzleFinal;

    puzzleFinal.appendRight(puzzleRight);

    for (int i = 0; i < puzzleFinal.m_numRows; i++) {
        for (int j = 0; j < puzzleRight.m_numCols; j++) {
            if (puzzleFinal.m_numRows != initialRows || puzzleFinal.m_numCols != initialCols ||
                puzzleFinal.m_puzzle[i][j] != puzzleInitial.m_puzzle[i][j]) {
                return false;
            }
        }
    }
    return true;
}

bool Tester::testAppendRightNormal(const Puzzle &puzzleRight) {
    Puzzle puzzleFinal;
    puzzleFinal.fill(12 + time(0));

    //save the data of each puzzle

    puzzleFinal.appendRight(puzzleRight);

    return false;
}

bool Tester::testAppendRightNormalToEmpty(const Puzzle &puzzleRight) {
    //make empty object
    Puzzle puzzleFinal(-2, 0);

    //save the data of each puzzle

    puzzleFinal.appendRight(puzzleRight);

    return false;
}

bool Tester::testAppendRightEmptyToNormal(const Puzzle &puzzleRight) {
    Puzzle puzzleFinal;
    puzzleFinal.fill(13 + time(0));

    //save the data of each puzzle

    puzzleFinal.appendRight(puzzleRight);

    return false;
}

bool Tester::testAppendRightToSelf(const Puzzle &puzzleRight) {
    //make object with dimensions identical to the one passed-in
    Puzzle puzzleFinal(puzzleRight.m_numRows, puzzleRight.m_numCols);

    //fill object with same data
    puzzleFinal = puzzleRight;

    puzzleFinal.appendRight(puzzleRight);

    return false;
}

//TODO: appendBottom test functions

