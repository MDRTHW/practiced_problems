#include <bits/stdc++.h>
using namespace std;

int max(int a, int b);
int longest_common_subs( string x, string y, int m, int n );
int longest_common_subs( string x, string y, int m, int n )
{
	if (m == 0 || n == 0)
		return 0;
	if (x[m-1] == y[n-1])
		return 1 + longest_common_subs(x, y, m-1, n-1);
	else
		return max(longest_common_subs(x, y, m, n-1), longest_common_subs(x, y, m-1, n));
}


int max(int a, int b)
{
	return (a > b)? a : b;
}

int main()
{
	string a,b;
	cout<<"Enter strings: ";
	cin>>a>>b;
	int m = a.size();
	int n = b.size();

	cout<<"Length of Longest common subsequence is = "<< longest_common_subs( a, b, m, n ) ;

	return 0;
}

