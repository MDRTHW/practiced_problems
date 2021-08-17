#include <bits/stdc++.h>

using namespace std;

int q=1;
void knapsack_greedy(int m,int w[],int b[],int n);
int knapSack_DP(int W, int w[], int b[], int n);
int max(int a, int b);

int max(int a, int b)
{ return (a > b) ? a : b; }

int knapSack_DP(int m, int w[], int b[], int n)
{

	if (n == 0 || m == 0)
		return 0;


	if (w[n - 1] > m)
		return knapSack_DP(m, w, b, n - 1);
	else
		return max(
			b[n - 1]
				+ knapSack_DP(m - w[n - 1],
						w, b, n - 1),
			knapSack_DP(m, w, b, n - 1));
}

void knapsack_greedy(int m,int w[],int b[],int n)
{

    int y=m;
    float arr[n][2];
    for(int i=0;i<n;i++)
    {
        arr[i][0]=i;
        arr[i][1]=((1.0*b[i])/w[i]);
    }

    for (int i = 0; i < n; ++i)
        {
            for (int j = i + 1; j < n; ++j)
            {
                if (arr[i][1] < arr[j][1])
                {
                    swap(arr[i][1],arr[j][1]);
                    swap(arr[i][0],arr[j][0]);
                }
            }
        }

        int index[n];
        for(int i=0;i<n;i++)
        {
            index[i]=arr[i][0];

        }
        int i=0;
        float result=0;

       while(m!=0)
       {
        if(m>=w[index[i]])
        {

            result = result+(b[index[i]]);
            m=m-w[index[i]];



        }
        else
        {

            result = result+(m*arr[i][1]);



            m=0;
        }
        i++;
       }



   cout<<q++<<"     ";
   cout<<"          "<<y<<"             "<<result<<" ---> using greedy method"<<endl;


}

int main()
{
    int n=5;
    int w[5]={1,2,5,6,7};
    int b[5]={1,6,18,22,28};
    int m=11;
    cout<<"Solution "<<"    "<<"Total weight"<<"    "<<"Total benefit"<<endl;
    knapsack_greedy(m,w,b,n);
    cout<<"2\t\t"<<m<<"\t\t"<<knapSack_DP(m,w,b, n)<<"\t---> using DP"<<endl;


    return 0;
}
