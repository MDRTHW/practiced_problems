#include <bits/stdc++.h>

using namespace std;
int a[]={126,328,636,341,416,131,328};
int k=9;
void Print_array(int n);
void Radix_sort();
void Count_sort(int n, int pos);


void Print_array(int n)
{
    for(int i=0;i<n;i++)
        cout<<a[i]<<"   ";
    cout<<endl;
}

void Radix_sort()
{

    int n = sizeof(a)/sizeof(a[0]);
    int max= *max_element(a,a+n);
    for(int pos=1; max/pos >0; pos*=10)
    {
        Count_sort(n,pos);
    }
    Print_array(n);
}

void Count_sort(int n, int pos)
{

    int count[k+1]={0};
    int b[n];

    for(int i=0;i<n;i++)
        ++count[(a[i]/pos)%10];
    for(int i=1;i<=k;i++)
        count[i] = count[i]+count[i-1];
    for(int i=n-1;i>=0;i--)
        b[--count[(a[i]/pos)%10]] = a[i];
    for(int i=0;i<n;i++)
        a[i]=b[i];
}

int main()
{
    Radix_sort();
    return 0;
}
