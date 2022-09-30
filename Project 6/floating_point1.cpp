#include <iostream>
using namespace std;

float a, b, c, h;
float oneHalf = 0.5, two = 2;
float len, wid;
float tArea, tPerimeter, rArea, rPerimeter;

int main()
{
    cout << "Enter the values of a,b,c, and h for the triangle: ";
    cin >> a >> b >> c >> h;

    cout << "Enter the length and the width of the rectangle: ";
    cin >> len >> wid;
    
    _asm {
        //Triangle
        //area = 1/2 c * h
        fld oneHalf;    //st[0] = 0.5
        fld c;              //st[0] = c st[1] = 0.5
        fld h;              //st[0] = h st[1] = c st[2] = 0.5
        fmul;              //st[0] = ch st[1] = 0.5
        fmul;              //st[0] = 0.5ch
        fstp tArea;     //tArea = 0.5ch
        //perimeter = a + b + c
        fld c;             	 //st[0] = c
        fld b;             	 //st[0] = b st[1] = c
        fld a;             	 //st[0] = a st[1] = b st[2] = c
        fadd;             	 //st[0] = a+b st[1] = c
        fadd;             	 //st[0] = a+b+c
        fstp tPerimeter;    //tPerimeter = a+b+c

        //Rectangle
        //area = len * wid
        fld wid;           //st[0] = wid
        fld len;            //st[0] = len st[1] = wid
        fmul;               //st[0] = len * wid
        fstp rArea;      //rArea = len * wid
        //perimeter = 2(len + wid)
        fld two;           	//st[0] = 2
        fld wid;           	//st[0] = wid st[1] = 2
        fld len;            	//st[0] = len st[1] = wid st[2] = 2
        fadd;              	//st[0] = len + wid st[1] = 2
        fmul;              	//st[0] = 2(len + wid)
        fstp rPerimeter;   //rPerimeter = 2(len + wid)
    }

    cout << "\tTriangle\n\t\t" << "Area..................." << fixed << setprecision(2) << tArea;
    cout << "\n\t\tPerimeter.............." << tPerimeter << endl;
    cout << "\tRectangle\n\t\t" << "Area..................." << rArea << "\n\t\tPerimeter.............." << rPerimeter << endl;

    return 0;
}
