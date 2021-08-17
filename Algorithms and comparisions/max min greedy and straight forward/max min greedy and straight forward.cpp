#include <bits/stdc++.h>

using namespace std;
void straightmaxmin();
void divide_and_conquer(int arr[], int low, int high, int& min, int& max);
string buffer;
int inputdata[1000];
int n=0,mid;

void straightmaxmin()
{
    int maxx=inputdata[0];
    int minn=inputdata[0];

    for(int i=1;i<n;i++)
    {
        if(inputdata[i]>maxx)
            maxx = inputdata[i];
        if(inputdata[i]<minn)
            minn = inputdata[i];
    }
    cout<<"Using Straight forward method : Max = "<<maxx<<"    Min = "<<minn<<endl;
}



void divide_and_conquer(int arr[], int low, int high, int& min, int& max)
{


    if (low == high)
    {
        if (max < arr[low])
            max = arr[low];

        if (min > arr[high])
            min = arr[high];

        return;
    }



    if (high - low == 1)
    {
        if (arr[low] < arr[high])
        {
            if (min > arr[low])
                min = arr[low];

            if (max < arr[high])
                max = arr[high];
        }
        else
        {
            if (min > arr[high])
                min = arr[high];

            if (max < arr[low])
                max = arr[low];
        }
        return;
    }
    int mid = (low + high) / 2;


    divide_and_conquer(arr, low, mid, min, max);


    divide_and_conquer(arr, mid + 1, high, min, max);
}
int main()
{
    ifstream f1;
    f1.open("datasets.txt");


    while(!f1.eof())
    {
        f1>>buffer;
        inputdata[n++]=stod(buffer);
        buffer.clear();
    }

    straightmaxmin();
    int max = INT_MIN, min = INT_MAX;
    divide_and_conquer(inputdata, 0, n-1 , min, max);
    cout<<"Using Divide and conquer : Max = "<<max<<"    Min = "<<min<<endl;
    return 0;
}
