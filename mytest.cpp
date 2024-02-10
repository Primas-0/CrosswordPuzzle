#include "puzzle.h"

class Tester {
public:
    bool testConstructorError(int rows, int cols);
    bool testConstructorEdgeAndNormal(int rows, int cols);

    //test destructor

    //test clear

    bool testReCreateError(int rows, int cols, int seed);
    bool testReCreateEdgeAndNormal(int rows, int cols, int seed);

    //test fill

    //test copy constructor

    //test overloaded assignment operator

    bool testAppendRightError(const Puzzle& puzzle);
    bool testAppendRightNormal(const Puzzle& puzzle);
    bool testAppendRightNormalToEmpty(const Puzzle& puzzle);
    bool testAppendRightEmptyToNormal(const Puzzle& puzzle);
    bool testAppendRightToItself(const Puzzle& puzzle);

    bool testAppendBottomError(const Puzzle& puzzle);
    bool testAppendBottomNormal(const Puzzle& puzzle);
    bool testAppendBottomNormalToEmpty(const Puzzle& puzzle);
    bool testAppendBottomEmptyToNormal(const Puzzle& puzzle);
    bool testAppendBottomToItself(const Puzzle& puzzle);

    //test dealloc (private function)
};

int main() {
    Tester tester;

    //
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

    //
    cout << "\nTesting reCreate (error case) - does not modify the object:" << endl;
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
}

bool Tester::testConstructorError(int rows, int cols) {
    //call constructor with invalid parameters
    Puzzle puzzle(rows, cols);

    //make sure an empty object has been created
    if (puzzle.m_puzzle == nullptr && puzzle.m_numRows == 0 && puzzle.m_numCols == 0) {
        return true;
    }
    return false;
}

bool Tester::testConstructorEdgeAndNormal(int rows, int cols) {
    //call constructor with valid parameters
    Puzzle puzzle(rows, cols);

    //make sure puzzle has been created and dimensions match passed-in values
    if (puzzle.m_puzzle != nullptr && puzzle.m_numRows == rows && puzzle.m_numCols == cols) {
        return true;
    }
    return false;
}

bool Tester::testReCreateError(int rows, int cols, int seed) {
    //create an initial puzzle with default constructor
    Puzzle puzzle;

    //call reCreate with invalid parameters
    bool reCreateSuccess = puzzle.reCreate(rows, cols, seed);

    //make sure function returns false and puzzle has not been changed
    //TODO: something is wrong here
    if (!reCreateSuccess && puzzle.m_puzzle == nullptr) {
        return true;
    }
    return false;
}

bool Tester::testReCreateEdgeAndNormal(int rows, int cols, int seed) {
    //create an initial puzzle with default constructor
    Puzzle puzzle;

    //call reCreate with valid parameters
    bool reCreateSuccess = puzzle.reCreate(rows, cols, seed);

    //make sure function returns true, puzzle is not empty anymore, and dimensions match passed-in values
    if (reCreateSuccess && puzzle.m_puzzle != nullptr && puzzle.m_numRows == rows && puzzle.m_numCols == cols) {
        return true;
    }
    return false;
}