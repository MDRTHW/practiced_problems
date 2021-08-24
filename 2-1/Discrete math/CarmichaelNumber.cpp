#include <iostream>
using namespace std;

 bool isprime(int n)
 {
     if (n <= 1)
        return false;
    for (int i = 2; i < n; i++)
        if (n % i == 0)
            return false;
    return true;
 }

int gcd(int a, int b)
{
	if (a < b)
		return gcd(b, a);
	if (a % b == 0)
		return b;
	return gcd(b, a % b);
}


int power(int x, int y, int mod)
{
	if (y == 0)
		return 1;
	int temp = power(x, y / 2, mod) % mod;
	temp = (temp * temp) % mod;
	if (y % 2 == 1)
		temp = (temp * x) % mod;
	return temp;
}


bool isCarmichaelNumber(int n)
{
	for (int b = 2; b < n; b++) {
		if (gcd(b, n) == 1)

			if (power(b, n - 1, n) != 1)
				return false;
	}
	return true;
}

int main()
{
    int n;
    cout<<"Give a number : ";
    cin>>n;

    if(isprime(n))
        cout<<"Invalid input , given number is not a composite number."<<endl;
    else
	{
	    if(isCarmichaelNumber(n))
            cout<<"It's a Carmichael number"<<endl;
        else
            cout<<"It's not a Carmichael number"<<endl;
	}
	return 0;
}
