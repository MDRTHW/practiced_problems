#include <bits/stdc++.h>

using namespace std;
int scr=-1,sc=2;
string st;

int fibr(int n)
{
    scr++;
    if (n <= 1)
            {   scr++;
                return n;}
    return fibr(n-1) + fibr(n-2);
}

void fib(int n)
{
    int n3,n1=0,n2=1;
    for(int i=2;i<n;++i)
    {
        n3=n1+n2;
        n1=n2;
        n2=n3;
        sc+=3;
    }
}

int main()
{
    ifstream f;
    f.open("fibonacci.txt");
    f>>st;
    int x;
    x= stod(st);
    fibr(x);
    fib(x);
    cout<<"Using recursion : "<<scr<<" steps."<<endl;
    cout<<"Without recursion : "<<sc<<" steps."<<endl;

    return 0;
}
