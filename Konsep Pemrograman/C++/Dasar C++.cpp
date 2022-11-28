#include <iostream>
#include <set>

#define Phi 3.14

using namespace std;

double total;

inline int Pow(int a, int b);
inline int Sum(int a, int b, int c);
inline int Mul(int a, int b, int c);
inline double Ball(const double r = 1);
inline void TotalVol(double &x = total, double n1 = 1, double n2 = 1, double d = 1);

int main()
{
    while(1){
        double r1, r2;
        double v1, v2;
        double &x = v1, &y = v2;
        double total;
        
        cout << "Enter First Ball Radius : "; cin >> r1;
        v1 = Ball(r1);
        cout << "The ball radius is " << x << endl;
        cout << "=============================" << endl;
        cout << "Enter Second Ball Radius : "; cin >> r2;
        v2 = Ball(r2);
        cout << "The ball radius is " << y << endl;
        cout << "=============================" << endl;
        cout << "The default ball radius is " << Ball() << endl;
        cout << "=============================" << endl;
        TotalVol(total, x, y, Ball());
        cout << "total ball radius is " << total << endl;
        cout << "=============================" << endl <<"=============================" << endl;
        TotalVol();
        cout << "Total Vol Default " << ::total << endl;
        cout << "=============================" << endl <<"=============================" << endl;
        
        char c;
        cout << "Continue? y/n "; cin >> c;
        if(c == 'Y' || c == 'y'){
            printf("\e[1;1H\e[2J");
        }else{
            return 0;
        }
    }
}

inline int Pow(int a, int b){ if(b <= 1) { return a; }else{ return a * Pow(a, b - 1); } }
inline int Sum(int a, int b, int c){ return a + b + c; }
inline int Mul(int a, int b, int c){ return a * b * c; }
inline double Ball(const double r){ return (4 * Phi * Pow(r, 3)) / 3; }
inline void TotalVol(double &x, double n1, double n2, double d){ x = n1 + n2 + d; }

