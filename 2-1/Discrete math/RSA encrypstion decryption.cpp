#include <bits/stdc++.h>

using namespace std;
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

 bool isprime(int n)
 {
     if (n <= 1)
        return false;
    for (int i = 2; i < n; i++)
        if (n % i == 0)
            return false;
    return true;
 }
int main()
{
    int p,q,n,pn,e,d,x,y;
    srand(time(0));

    for(;;)
    {
        p=rand()%999;
        q=rand()%999;
        if((isprime(p)&&isprime(q))&&p!=q)
            break;
    }
    n=p*q;
    pn=n-(p+q-1);

    for(int i=2;;i++)
    {
        e=i;
        if(gcdExtended(e,pn,&x,&y)==1)
        break;
    }


    d=yy-((pn/e)*xx);

    cout<<"Two prime numbers are = "<<p<<" , "<<q<<endl;
    cout<<"A valid RSA encryption key is (n,e) = ( "<<n<<" , "<<e<<" )"<<endl;
    cout<<"A valid RSA decryption key is (n,d) = ( "<<n<<" , "<<d<<" )"<<endl;
    return 0;
}
