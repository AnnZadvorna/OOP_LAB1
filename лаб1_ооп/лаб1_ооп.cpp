// лаб1_ооп.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
using namespace std;
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <ATLComTime.h>
#define M_PI 3.14159265358979323846


int a = 10;
int m = 2003;
int c = 5;
int d = 11;
int p = 2803;
int lenth = 1000;
int mu = 161;
double pi = M_PI;
int x0 = 0;
int x1 = 1;

int z0 = time(0);

int all[10] = {};
int all1[15] = {};


void esc1() {
    
    for (int i = 0; i < 10; i++)
    {
        cout << "[0," + to_string(i) + "; 0," + to_string(i + 1) + "]:     " << float(all[i]) / 1000 << endl;
    }
    fill(&all[0], &all[10], 0);
}


void esc10() {

    for (int i = 0; i < 15; i++)
    {
        string grid1 = to_string(i / 2.5 - 3);
        string grid2 = to_string(i / 2.5 - 2.6);

        cout << "[" + grid1.substr(0, grid1.length() - 4) + "; " + grid2.substr(0, grid2.length() - 4) + "]:     " << float(all1[i]) / 1000 << endl;
    }
    fill(&all1[0], &all1[15], 0);
}


void esc100() {

    for (int i = 0; i < 10; i++)
    {
        cout << "[" + to_string(i) + "0; " + to_string(i + 1) + "0]:     " << float(all[i]) / 1000 << endl;
    }
    fill(&all[0], &all[10], 0);
}


void LinCongr(int &x0,double &u) {
    x0 = (x0 * a + c) % m;
    u = double(x0) / m;
}


void method1() {
    double u=0;
    cout << "enter number between 0 and 2002: ";
    cin >> x0;
    for (int i = 0; i < lenth; i++) {
        LinCongr(x0, u);
        int index = 10 * u;
        all[int(index)]++;
    }
    esc1();
}


void method2() {
    float u;
    cout << "enter number between 0 and 2002: " << endl;
    cin >> x0;
    for (int i = 0; i < 1000; i++) {
         x0 = (d*x0*x0+x0 * a + c) % m;
         u = double(x0) / m;
         int index = 10 * u;
         all[int(index)]++;
    }
    esc1();
}


void method3() {
    double u = 0;
    cout << "enter number between 0 and 2002: " << endl;
    cin >> x0;
    for (int i = 0; i < 1000; i++) {
        x0 = (x0 + x1) % m;        
        x1 = x0;
        u = double(x0) / m;
        int index = 10 * u;
        all[int(index)]++;
    }   
    esc1();
}


int modinv(int x0, int p)
{
    for (int x1 = 0; x1 < p; x1++)
    {
        if ((x0 * x1) % p==1) {
            return x1;
        }
    }
    return 0;
}


void method4() {
    double u = 0;
    cout << "enter number between 0 and 2802: " << endl;
    cin >> x0;
    for (int i = 0; i < 1000; i++) {
        x0 = modinv(x0, m);
        LinCongr(x1, u);
        all[int(10 * u)]++;
    }
    esc1();
}


void method5() {
    cout << "enter number between 0 and 2002: " << endl;
    cin >> x0;
    double u = 0;
    int y =x0-1;
    for (int i = 0; i < 1000; i++) {
        LinCongr(x0, u);
        y = (d * y *y +a*y+ c) % m;
        float z = (x0+y)%m;
        float u = z / m;
        all[int(10*u)]++;
    }
    esc1();
}


void method6() {
    double u = 0;
    cout << "enter number between 0 and 2002: " << endl;

    cin >> x0;
    for (int i = 0; i < 1000; i++) {
        float sum=0;
        for (int j = 0; j < 12; j++)
        {
            LinCongr(x0, u);
            sum = sum + u;
        }
        float u_res = sum - 6;
        int index = int(5 * (u_res + 3) / 2);
        all1[index]++;
    }
    esc10();
}


void method7() {
    float  v1, v2, s, x2, x1;
    cout << "enter number between 0 and 2002: " << endl;
    cin >> x0;
    cout << "enter number between 0 and 2002: " << endl;
    cin >> z0;
    double u = 0;
    for (int i = 0; i < 1000; i++) {
        
        do {
            LinCongr(x0,u);
            v1 = 2 * ( float(u)) - 1;
            LinCongr(z0,u);
            v2 = 2 * (float(u)) - 1;
            s = v1 * v1 + v2 * v2;
        } 
        while (s >= 1);
        x1 = v1 * sqrt((-2 * log(s)) / s);
        x2 = v2 * sqrt((-2 * log(s)) / s);

        int index = int(5 * (x1 + 3) / 2);
        all1[int(index)]++;

    }
    esc10();
}


void method8() {
    double x, v=0;
    double u=0;
    cout << "enter number between 1 and 2002: " << endl;
    cin >> x0;
    cout << "enter number between 0 and 2002: " << endl;
    cin >> z0;
    for (int i = 0; i < 1000; i++) {
        do {
            LinCongr(x0,u);
            LinCongr(z0,v);
            x = sqrt(8 / exp(1)) * (v - 0.5) / u;

        } while (x * x >= -4 * log(u));

        int index = int(5 * (x + 3) / 2);
        all1[index]++;

    }
    esc10();
}


void method9() {
    double x, u=0;
    cout << "enter number between 0 and 2002: " << endl;
    cin >> x0;
    for (int i = 0; i < 1000; i++) {
        do {
            LinCongr(x0,u);
            x = -mu * log(u);
        } while (x >= 100);
        int index = int(x/ 10);
        all[index]++;
    }
    esc100();
}

void method10() {
    double x, y;
    double u=0;
    double v = 0;
    double perev;
    cout << "enter number between 0 and 2002: " << endl;
    cin >> x0;
    cout << "enter number between 0 and 2002: " << endl;
    cin >> z0;
    for (int i = 0; i < 1000; i++) {
        do {
            LinCongr(z0,v);
            LinCongr(x0,u);
            y = tan(pi*u);
            x = sqrt(2*a-1)*y+a-1;
            perev = (1 + y * y) * exp((a - 1) * log(x / (a - 1)) - sqrt(2 * a - 1) * y);
        } while ((x < 0)&&(v > perev));
        
        int index = int(x / 10);
        all[index]++;
    }
    esc100();
}
void enter(int method) {

    switch (method) {
    case 1:
        method1();
        break;
    case 2:
        method2();
        break;
    case 3:
        method3();
        break;
    case 4:
        method4();
        break;
    case 5:
        method5();
        break;
    case 6:
        method6();
        break;
    case 7:
        method7();
        break;
    case 8:
        method8();
        break;
    case 9:
        method9();
        break;
    case 10:
        method10();
        break;
    default: std::cout << "There is no such method" << std::endl;
    }
}

int main()
{
    cout << "Methods:\n\t1 - Linear congruent method."
        "\n\t2 - Quadratic congruent method.\n\t3 - Fibonacci numbers.\n\t4 - Inverse congruent sequence"
        "\n\t5 - Method of association.\n\t6 - The rule of \"3 sigma\".\n\t7 - The method of polar coordinates."
        "\n\t8 - Method of correlations. \n\t9 - The logarithm method for generating an indicative distribution."
        "\n\t10 - Ahrens' method for generating a gamma distribution of order a > 1."
        "\nEnter number of method which you want to try:" << endl;
    int vvod = 0;
    cin >> vvod;
    enter(vvod);
}


