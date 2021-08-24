#include <iostream>

using namespace std;

int main()
{

  long long  int f1=0,f2=1,display=0,n;
   double a[100];

   cin>>n;
   display=f1+f2;
   cout<<f1<<"   "<<f2;
   a[0]=f1;
   a[1]=f2;
   a[2]=display;
   for(int i=3;i<n;i++)
   {
       f1=f2;
       f2=display;
       display=f1+f2;
       a[i]=display;
       cout<<"   "<<display;

   }
   cout<<endl<<endl<<"The approach to golden ratio:"<<endl<<endl;

   for(int i=2;i<n-1;i++)
   {
       cout<<i+2<<" & "<<i+1<<" : "<<(double)(a[i+1]/a[i])<<endl;
   }
    return 0;
}
