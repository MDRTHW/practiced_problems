#include <bits/stdc++.h>
using namespace std;
int s=0,t=0;
int xx,yy;
int gcdExtended(int a, int b, int *x, int *y)
{

	if (a == 0)
	{
		*x = 0;
		*y = 1;
		return b;
	}

    int x1, y1;
	int gcd = gcdExtended(b%a, a, &x1, &y1);


	*x = y1 - (b/a) * x1;
	*y = x1;
    xx=x1;
    yy=y1;

	return gcd;
}


int main()
{
	int x, y, a, b;
	cout<<"Give two positive integers : ";
	cin>>a>>b;

	if(a>0&&b>0){
	gcdExtended(a, b, &x, &y);
	s=yy-((b/a)*xx);
	t=xx;
	cout<<"s = "<<s<<" t = "<<t<<endl;}

	else
        cout<<"Invalid input"<<endl;
	return 0;
}


