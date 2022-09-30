#include <iostream>
#include <iomanip>
using namespace std;

float negOne = -1, Four = 4, two = 2, x1, x2, a, b, c;


int main() {

    cout << "To see the two real roots of aX^2+ bX + c=0, enter the a,b, and c values: ";
    cin >> a >> b >> c;

    _asm {

        // X1
        fld b;          // b
        fld negOne;     // -1, b
        fmul;           // b * -1 = -b
        fld b;          // b, -b
        fld b;          // b, b, -b
        fmul;           // (b*b = b^2), -b
        fld c;          // c, b^2, -b
        fld a;          // a, c, b^2, -b
        fmul;           // ac, b^2, -b
        fld Four;       // 4, ac, b^2, -b
        fmul;           // 4ac, b^2, -b
        fsub;           // b^2-4ac, -b
        fsqrt;          // sqrt(b^2-4ac), -b
        fadd;           // -b + sqrt(b^2-4ac)
        fld two;        // 2, -b + sqrt(b^2-4ac)
        fld a;          // a, 2, -b + sqrt(b^2-4ac)
        fmul;           // 2a, -b + sqrt(b^2-4ac)
        fdiv;           // -b + sqrt(b^2-4ac) / 2a
        fstp x1;        // x1 = -b + sqrt(b^2-4ac) / 2a

        // X2
        fld b;          // b
        fld negOne;     // -1, b
        fmul;           // -b
        fld b;          // b, -b
        fld b;          // b, b, -b
        fmul;           // b^2, -b
        fld c;          // c, b^2, -b
        fld a;          // a, c, b^2, -b
        fmul;           // ac, b^2, -b
        fld Four;       // 4, ac, b^2, -b
        fmul;           // 4ac, b^2, -b
        fsub;           // b^2-4ac, -b
        fsqrt;          // sqrt(b^2-4ac), -b
        fsub;           // -b - sqrt(b^2-4ac)
        fld two;        // 2, -b - sqrt(b^2-4ac)
        fld a;          // a, 2, -b - sqrt(b^2-4ac)
        fmul;           // 2a, -b - sqrt(b^2-4ac)
        fdiv;           // -b - sqrt(b^2-4ac) / 2a
        fstp x2;        // x2 = -b - sqrt(b^2-4ac) / 2a
    }

    cout << setprecision(3) << "\tX1=" << x1 << "\tX2=" << x2 << endl;

    return 0;
}
