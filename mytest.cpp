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

    bool testFillError(int seed);
    bool testFillNormal(int seed);

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


    //fill tests
    cout << "\nTesting Fill (error case) - does not modify the current object:" << endl;
    if (tester.testFillError(3 + time(0))) {
        cout << "\tFill passed!" << endl;
    } else {
        cout << "\tFill failed!" << endl;
    }
    cout << "Testing Fill (normal case) - properly populates array with letters and separators:" << endl;
    if (tester.testFillNormal(4 + time(0))) {
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
    puzzle2.fill(5 + time(0));
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
    puzzle4.fill(6 + time(0));
    cout << "Testing Assignment Operator (normal case) - creates deep copy:" << endl;
    if (tester.testAssignmentOperatorNormal(puzzle4)) {
        cout << "\tAssignment Operator passed!" << endl;
    } else {
        cout << "\tAssignment Operator failed!" << endl;
    }


    //appendRight tests
    Puzzle puzzle5(11, 11);
    puzzle5.fill(7 + time(0));
    cout << "\nTesting appendRight (error case, rows do not match) - does not modify the current object:" << endl;
    if (tester.testAppendRightError(puzzle5)) {
        cout << "\tappendRight passed!" << endl;
    } else {
        cout << "\tappendRight failed!" << endl;
    }
    Puzzle puzzle6(17, 13);
    puzzle6.fill(8 + time(0));
    cout << "Testing appendRight (normal case) - adds new columns to current object with correct data:" << endl;
    if (tester.testAppendRightNormal(puzzle6)) {
        cout << "\tappendRight passed!" << endl;
    } else {
        cout << "\tappendRight failed!" << endl;
    }
    Puzzle puzzle7(14, 10);
    puzzle7.fill(9 + time(0));
    cout << "Testing appendRight (edge case, normal to empty) - overwrites empty object with normal:" << endl;
    if (tester.testAppendRightNormalToEmpty(puzzle7)) {
        cout << "\tappendRight passed!" << endl;
    } else {
        cout << "\tappendRight failed!" << endl;
    }
    Puzzle puzzle8(-4, 5);
    cout << "Testing appendRight (edge case, empty to normal) - does not modify the current object:" << endl;
    if (tester.testAppendRightEmptyToNormal(puzzle8)) {
        cout << "\tappendRight passed!" << endl;
    } else {
        cout << "\tappendRight failed!" << endl;
    }
    Puzzle puzzle9(12, 18);
    puzzle9.fill(10 + time(0));
    cout << "Testing appendRight (edge case, to self) - doubles column number and duplicates data:" << endl;
    if (tester.testAppendRightToSelf(puzzle9)) {
        cout << "\tappendRight passed!" << endl;
    } else {
        cout << "\tappendRight failed!" << endl;
    }


    //appendBottom tests
    Puzzle puzzle10(11, 11);
    puzzle10.fill(11 + time(0));
    cout << "\nTesting appendBottom (error case, columns do not match) - does not modify the current object:" << endl;
    if (tester.testAppendBottomError(puzzle10)) {
        cout << "\tappendBottom passed!" << endl;
    } else {
        cout << "\tappendBottom failed!" << endl;
    }
    Puzzle puzzle11(17, 19);
    puzzle11.fill(12 + time(0));
    cout << "Testing appendBottom (normal case) - adds new columns to current object with correct data:" << endl;
    if (tester.testAppendBottomNormal(puzzle11)) {
        cout << "\tappendBottom passed!" << endl;
    } else {
        cout << "\tappendBottom failed!" << endl;
    }
    Puzzle puzzle12(14, 10);
    puzzle12.fill(13 + time(0));
    cout << "Testing appendBottom (edge case, normal to empty) - overwrites empty object with normal:" << endl;
    if (tester.testAppendBottomNormalToEmpty(puzzle12)) {
        cout << "\tappendBottom passed!" << endl;
    } else {
        cout << "\tappendBottom failed!" << endl;
    }
    Puzzle puzzle13(-4, 5);
    cout << "Testing appendBottom (edge case, empty to normal) - does not modify the current object:" << endl;
    if (tester.testAppendBottomEmptyToNormal(puzzle13)) {
        cout << "\tappendBottom passed!" << endl;
    } else {
        cout << "\tappendBottom failed!" << endl;
    }
    Puzzle puzzle14(12, 18);
    puzzle14.fill(14 + time(0));
    cout << "Testing appendBottom (edge case, to self) - doubles row number and duplicates data:" << endl;
    if (tester.testAppendBottomToSelf(puzzle14)) {
        cout << "\tappendBottom passed!" << endl;
    } else {
        cout << "\tappendBottom failed!" << endl;
    }
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


bool Tester::testFillError(int seed) {
    //create an empty object
    Puzzle puzzle(0,9);

    puzzle.fill(seed);

    if (puzzle.m_puzzle == nullptr && puzzle.m_numRows == 0 && puzzle.m_numCols == 0) {
        //test passes if object is still empty
        return true;
    }
    return false;
}

bool Tester::testFillNormal(int seed) {
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
    return true;
}


bool Tester::testAssignmentOperatorEdge(const Puzzle &original) {
    //make normal object
    Puzzle copy;

    //assign empty object (original) to normal object (copy)
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
    return true;
}


bool Tester::testAppendRightError(const Puzzle &puzzleRight) {
    //left puzzle has a different number of rows
    Puzzle puzzleFinal(15, 16);
    puzzleFinal.fill(15 + time(0));

    //save current dimensions to check against later
    int initialRows = puzzleFinal.m_numRows;
    int initialCols = puzzleFinal.m_numCols;

    //save the current data of puzzleFinal in puzzleInitial
    Puzzle puzzleInitial(puzzleFinal);

    puzzleFinal.appendRight(puzzleRight);

    for (int i = 0; i < puzzleFinal.m_numRows; i++) {
        for (int j = 0; j < puzzleFinal.m_numCols; j++) {
            if (puzzleFinal.m_numRows != initialRows || puzzleFinal.m_numCols != initialCols ||
                puzzleFinal.m_puzzle[i][j] != puzzleInitial.m_puzzle[i][j]) {
                //test fails if any changes have been made to the dimensions or data of the initial puzzle
                return false;
            }
        }
    }
    return true;
}

bool Tester::testAppendRightNormal(const Puzzle &puzzleRight) {
    Puzzle puzzleFinal(17, 10);
    puzzleFinal.fill(16 + time(0));

    //save dimensions of left and right sides to check against later
    int leftRows = puzzleFinal.m_numRows;
    int leftCols = puzzleFinal.m_numCols;
    int rightRows = puzzleRight.m_numRows;
    int rightCols = puzzleRight.m_numCols;

    //save the current data of left side (which will become the final puzzle)
    Puzzle puzzleLeft(puzzleFinal);

    puzzleFinal.appendRight(puzzleRight);

    if (puzzleFinal.m_numRows != leftRows || puzzleFinal.m_numRows != rightRows ||
        puzzleFinal.m_numCols != leftCols + rightCols) {
        //test fails if final row number is different from either puzzle ...
        //... or if final column number is not the sum of the left and right side columns
        return false;
    }

    for (int i = 0; i < puzzleLeft.m_numRows; i++) {
        for (int j = 0; j < puzzleLeft.m_numCols; j++) {
            if (puzzleFinal.m_puzzle[i][j] != puzzleLeft.m_puzzle[i][j]) {
                //test fails if left side of final puzzle does not match the left puzzle
                return false;
            }
        }
    }

    for (int i = 0; i < puzzleRight.m_numRows; i++) {
        for (int j = 0; j < puzzleRight.m_numCols; j++) {
            if (puzzleFinal.m_puzzle[i][leftCols + j] != puzzleRight.m_puzzle[i][j]) {
                //test fails if right side of final puzzle does not match the right puzzle
                return false;
            }
        }
    }

    return true;
}

bool Tester::testAppendRightNormalToEmpty(const Puzzle &puzzleRight) {
    //make empty object
    Puzzle puzzleFinal(-2, 0);

    puzzleFinal.appendRight(puzzleRight);

    if (puzzleFinal.m_numRows != puzzleRight.m_numRows || puzzleFinal.m_numCols != puzzleRight.m_numCols) {
        //test fails if the final puzzle's dimensions do not match the right puzzle's dimensions
        return false;
    }

    for (int i = 0; i < puzzleRight.m_numRows; i++) {
        for (int j = 0; j < puzzleRight.m_numCols; j++) {
            if (puzzleFinal.m_puzzle[i][j] != puzzleRight.m_puzzle[i][j]) {
                //test fails if final puzzle data does not match the right puzzle data
                return false;
            }
        }
    }

    return true;
}

bool Tester::testAppendRightEmptyToNormal(const Puzzle &puzzleRight) {
    Puzzle puzzleFinal;
    puzzleFinal.fill(17 + time(0));

    //save current dimensions to check against later
    int initialRows = puzzleFinal.m_numRows;
    int initialCols = puzzleFinal.m_numCols;

    //save the current data of puzzleFinal in puzzleInitial
    Puzzle puzzleInitial(puzzleFinal);

    puzzleFinal.appendRight(puzzleRight);

    for (int i = 0; i < puzzleFinal.m_numRows; i++) {
        for (int j = 0; j < puzzleFinal.m_numCols; j++) {
            if (puzzleFinal.m_numRows != initialRows || puzzleFinal.m_numCols != initialCols ||
                puzzleFinal.m_puzzle[i][j] != puzzleInitial.m_puzzle[i][j]) {
                //test fails if any changes have been made to the dimensions or data of the initial puzzle
                return false;
            }
        }
    }
    return true;
}

bool Tester::testAppendRightToSelf(const Puzzle &puzzleRight) {
    //make copy of object passed in
    Puzzle puzzleFinal(puzzleRight);

    //save dimensions to check against later
    int rows = puzzleFinal.m_numRows;
    int cols = puzzleFinal.m_numCols;

    //save the current data of left side (which will become the final puzzle)
    Puzzle puzzleLeft(puzzleFinal);

    puzzleFinal.appendRight(puzzleRight);

    if (puzzleFinal.m_numRows != rows || puzzleFinal.m_numCols != cols * 2) {
        //test fails if final row number is different or if final column number is not double
        return false;
    }

    for (int i = 0; i < puzzleLeft.m_numRows; i++) {
        for (int j = 0; j < puzzleLeft.m_numCols; j++) {
            if (puzzleFinal.m_puzzle[i][j] != puzzleLeft.m_puzzle[i][j]) {
                //test fails if left side of final puzzle does not match the left puzzle
                return false;
            }
        }
    }

    for (int i = 0; i < puzzleRight.m_numRows; i++) {
        for (int j = 0; j < puzzleRight.m_numCols; j++) {
            if (puzzleFinal.m_puzzle[i][cols + j] != puzzleRight.m_puzzle[i][j]) {
                //test fails if right side of final puzzle does not match the right puzzle
                return false;
            }
        }
    }

    return true;
}


bool Tester::testAppendBottomError(const Puzzle &puzzleBottom) {
    //left puzzle has a different number of columns
    Puzzle puzzleFinal(17, 20);
    puzzleFinal.fill(18 + time(0));

    //save current dimensions to check against later
    int initialRows = puzzleFinal.m_numRows;
    int initialCols = puzzleFinal.m_numCols;

    //save the current data of puzzleFinal in puzzleInitial
    Puzzle puzzleInitial(puzzleFinal);

    puzzleFinal.appendBottom(puzzleBottom);

    for (int i = 0; i < puzzleFinal.m_numRows; i++) {
        for (int j = 0; j < puzzleFinal.m_numCols; j++) {
            if (puzzleFinal.m_numRows != initialRows || puzzleFinal.m_numCols != initialCols ||
                puzzleFinal.m_puzzle[i][j] != puzzleInitial.m_puzzle[i][j]) {
                //test fails if any changes have been made to the dimensions or data of the initial puzzle
                return false;
            }
        }
    }
    return true;
}

bool Tester::testAppendBottomNormal(const Puzzle &puzzleBottom) {
    Puzzle puzzleFinal(15, 19);
    puzzleFinal.fill(19 + time(0));

    //save dimensions of top and bottom sides to check against later
    int topRows = puzzleFinal.m_numRows;
    int topCols = puzzleFinal.m_numCols;
    int bottomRows = puzzleBottom.m_numRows;
    int bottomCols = puzzleBottom.m_numCols;

    //save the current data of top side (which will become the final puzzle)
    Puzzle puzzleTop(puzzleFinal);

    puzzleFinal.appendBottom(puzzleBottom);

    if (puzzleFinal.m_numCols != topCols || puzzleFinal.m_numCols != bottomCols ||
        puzzleFinal.m_numRows != topRows + bottomRows) {
        //test fails if final column number is different from either puzzle ...
        //... or if final row number is not the sum of the top and bottom side rows
        return false;
    }

    for (int i = 0; i < puzzleTop.m_numRows; i++) {
        for (int j = 0; j < puzzleTop.m_numCols; j++) {
            if (puzzleFinal.m_puzzle[i][j] != puzzleTop.m_puzzle[i][j]) {
                //test fails if top side of final puzzle does not match the top puzzle
                return false;
            }
        }
    }

    for (int i = 0; i < puzzleBottom.m_numRows; i++) {
        for (int j = 0; j < puzzleBottom.m_numCols; j++) {
            if (puzzleFinal.m_puzzle[topRows + i][j] != puzzleBottom.m_puzzle[i][j]) {
                //test fails if bottom side of final puzzle does not match the bottom puzzle
                return false;
            }
        }
    }

    return true;
}

bool Tester::testAppendBottomNormalToEmpty(const Puzzle &puzzleBottom) {
    //make empty object
    Puzzle puzzleFinal(-6, -5);

    puzzleFinal.appendBottom(puzzleBottom);

    if (puzzleFinal.m_numRows != puzzleBottom.m_numRows || puzzleFinal.m_numCols != puzzleBottom.m_numCols) {
        //test fails if the final puzzle's dimensions do not match the right puzzle's dimensions
        return false;
    }

    for (int i = 0; i < puzzleBottom.m_numRows; i++) {
        for (int j = 0; j < puzzleBottom.m_numCols; j++) {
            if (puzzleFinal.m_puzzle[i][j] != puzzleBottom.m_puzzle[i][j]) {
                //test fails if final puzzle data does not match the right puzzle data
                return false;
            }
        }
    }

    return true;
}

bool Tester::testAppendBottomEmptyToNormal(const Puzzle &puzzleBottom) {
    Puzzle puzzleFinal;
    puzzleFinal.fill(20 + time(0));

    //save current dimensions to check against later
    int initialRows = puzzleFinal.m_numRows;
    int initialCols = puzzleFinal.m_numCols;

    //save the current data of puzzleFinal in puzzleInitial
    Puzzle puzzleInitial(puzzleFinal);

    puzzleFinal.appendBottom(puzzleBottom);

    for (int i = 0; i < puzzleFinal.m_numRows; i++) {
        for (int j = 0; j < puzzleFinal.m_numCols; j++) {
            if (puzzleFinal.m_numRows != initialRows || puzzleFinal.m_numCols != initialCols ||
                puzzleFinal.m_puzzle[i][j] != puzzleInitial.m_puzzle[i][j]) {
                //test fails if any changes have been made to the dimensions or data of the initial puzzle
                return false;
            }
        }
    }
    return true;
}

bool Tester::testAppendBottomToSelf(const Puzzle &puzzleBottom) {
    //make copy of object passed in
    Puzzle puzzleFinal(puzzleBottom);

    //save dimensions to check against later
    int rows = puzzleFinal.m_numRows;
    int cols = puzzleFinal.m_numCols;

    //save the current data of top side (which will become the final puzzle)
    Puzzle puzzleTop(puzzleFinal);

    puzzleFinal.appendBottom(puzzleBottom);

    if (puzzleFinal.m_numCols != cols || puzzleFinal.m_numRows != rows * 2) {
        //test fails if final column number is different or if final row number is not double
        return false;
    }

    for (int i = 0; i < puzzleTop.m_numRows; i++) {
        for (int j = 0; j < puzzleTop.m_numCols; j++) {
            if (puzzleFinal.m_puzzle[i][j] != puzzleTop.m_puzzle[i][j]) {
                //test fails if top side of final puzzle does not match the top puzzle
                return false;
            }
        }
    }

    for (int i = 0; i < puzzleBottom.m_numRows; i++) {
        for (int j = 0; j < puzzleBottom.m_numCols; j++) {
            if (puzzleFinal.m_puzzle[rows + i][j] != puzzleBottom.m_puzzle[i][j]) {
                //test fails if bottom side of final puzzle does not match the bottom puzzle
                return false;
            }
        }
    }

    return true;
}