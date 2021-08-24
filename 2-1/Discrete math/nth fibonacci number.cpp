#include <bits/stdc++.h>

using namespace std;

int fibo(int num);


int main()
{
    int num;
   int fibonacci;


    cout<<"Enter any number to find nth fiboacci term: ";
    cin>>num;

    fibonacci = fibo(num);

    cout<<num<<"th fibonacci term is "<<fibonacci<<endl;;

    return 0;
}

int fibo(int num)
{
    if(num == 0)
        return 0;
    else if(num == 1)
        return 1;
    else
        return fibo(num-1) + fibo(num-2);
}
