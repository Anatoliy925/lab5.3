#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;
double j(double x);

int main(){
    double k, kp, kk, z;
    int n;
    
    cout << "kp = "; cin >> kp;
    cout << "kk = "; cin >> kk;
    cout << "n = "; cin >> n;
    
    cout << fixed;
    cout << "-------------------------" << endl;
    cout << "|" << setw(5) << "k" << "     |" << setw(7) << "z" << "     |" << endl;
    cout << "-------------------------" << endl;
    
    double dk = (kk - kp)/n;
    
    k = kp;
    while(k <= kk)
    {
        z = j(1+k+j(k))+pow(j(1+k*k), 2);
        cout << "|"
        << setw(5)  << setprecision(3) << k << "    |"
        << setw(7) << setprecision(5) << z << "   |" << endl;
        k += dk;
    }
    return 0;
}
double j(double x)
{
    if (abs(x)>=1)
       return (cos(x)+exp(-(abs(x))))/(cos(x)*cos(x)+1);
    else
    {
        double S = 0;
        int i = 0;
        double a = x;
        S = a;
        do{
            i++;
            double R = x*x/(4*i*i+2*i);
            a *= R;
            S += a;
        }while(i<5);
            return S;
    }
}
