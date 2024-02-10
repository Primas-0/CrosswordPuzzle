#include "puzzle.h"

class Tester{//this is your tester class, you add your test functions in this class
public:

};

int main() {
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

    return 0;
}