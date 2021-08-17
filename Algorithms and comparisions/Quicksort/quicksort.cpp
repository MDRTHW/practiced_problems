#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cstdlib>
#include <time.h>
#include <windows.h>
#include <chrono>
#include <unistd.h>
using namespace std;

void quickSort(int arr[], int low, int high);
int partition (int arr[], int low, int high);


int partition (int arr[], int low, int high)
{
	int pivot = arr[high];
	int i = (low - 1);

	for (int j = low; j <= high- 1; j++)
	{

		if (arr[j] <= pivot)
		{
			i++;
			swap(arr[i], arr[j]);

		}
	}
	swap(arr[i + 1], arr[high]);

	return (i + 1);
}


void quickSort(int arr[], int low, int high)
{
	if (low < high)
	{

		int pivot = partition(arr, low, high);

		quickSort(arr, low, pivot - 1);
		quickSort(arr, pivot + 1, high);
	}
}

int main()
{
   int arr1[8000];
    int i=0;
    int c,n=0;
    ifstream file;


    for(int k=1;k<=3;k++){
    cout<<"For "<<k+3<<"000 inputs : "<<endl<<endl;
    string ss;
    if(k==1)
        {ss= "quick1.txt";
        n=4000;}
    if(k==2)
        {ss= "quick2.txt";
        n=5000;}
    if(k==3)
        {ss= "quick3.txt";
        n=6000;}


    fstream file1;
   file1.open(ss,ios::out);
    srand(time(0));
    for(int p=0;p<n;p++)
    {
        file1<<rand()%n;
        file1<<" ";
    }
    file1.close();

    file.open(ss);
    while(!file.eof())
    {file>>c;
    arr1[i]=c;
    i++;
    c=0;}

     auto s1 = chrono::steady_clock::now();
     quickSort(arr1,0,i-1);
     auto e1 = chrono::steady_clock::now();
     cout<<"Time taken by quicksort algorithm = "<< 0.001*(chrono::duration_cast<chrono::microseconds>(e1 - s1).count())<<" miliseconds"<<endl;

    cout<<endl;
    file1.open(ss);
    for(int p=0;p<n;p++)
    {
        file1<<arr1[p];
        file1<<" ";
    }}
    return 0;
}
