// UMBC - CMSC 341 - Spring 2024 - Proj0
#include "puzzle.h"

class Tester{//this is your tester class, you add your test functions in this class
public:
    bool testCopyConstructorNormal(const Puzzle& puzzle);
};

int main() {
    Tester tester;
    {
        //test deep copy, object with many members
        Puzzle p1(10,12);
        cout << "Testing Copy Constructor (normal case): same values, same size, different pointers (deep copy):" << endl;
        if (tester.testCopyConstructorNormal(p1)) cout << "\tCopy constructor passed!" << endl;
        else cout << "\tCopy constructor failed!" << endl;
    }

    {
        Puzzle p1(12,10);
        p1.fill(10+time(0));
        cout << "\ndump of p1 after creation:\n\n"; p1.dump();

        Puzzle p2(12,14);
        p2.fill(5+time(0));
        cout << "\ndump of p2 after creation:\n\n"; p2.dump();
        p1.appendRight(p2);
        cout << "\ndump of p1 after append:\n\n"; p1.dump();
        cout << "\ndump of p2 after append:\n\n"; p2.dump();

        cout << endl;
    }
    return 0;
}

bool Tester::testCopyConstructorNormal(const Puzzle& puzzle){
    Puzzle copy(puzzle);
    if (puzzle.m_numCols == copy.m_numCols &&
        puzzle.m_numRows == copy.m_numRows &&
        puzzle.m_puzzle != copy.m_puzzle){
        for (int i=0;i<puzzle.m_numRows;i++){
            for (int j=0;j<puzzle.m_numCols;j++)
            {
                if ((puzzle.m_puzzle[i][j] != copy.m_puzzle[i][j]) ||   //check the value
                    (puzzle.m_puzzle[i] == copy.m_puzzle[i])){            //check the ith pointer
                    return false;
                }
            }
        }
        return true;// everything is correct
    }
    else return false;//everthing else
}