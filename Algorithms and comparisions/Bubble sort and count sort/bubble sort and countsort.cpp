#include <bits/stdc++.h>
#include <chrono>
using namespace std::chrono;
using namespace std;

void create_files();
void bubbleSort(int arr[], int n);
void countsort(int a[], int n,int k);

void countsort(int a[], int n,int k)
{
    int count1[k+1];
    int b[n];

    ///updating all elements to zero
    for(int i=0;i<k;i++)
        count1[i]=0;

    ///making a count array of frequency
    for(int i=0;i<n;i++)
        count1[a[i]]++;
;
    ///updating to actual position
    for(int i=1;i<=k;i++)
        count1[i]=count1[i]+count1[i-1];

    ///building the sorted array
    for(int i=n-1;i>=0;i--)
        b[--count1[a[i]]]=a[i];

    ///updating the main array with this sorted array
    for(int i=0;i<n;i++)
        a[i]=b[i];


}

void bubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n-1; i++)
    for (j = 0; j < n-i-1; j++)
        if (arr[j] > arr[j+1])
            swap(arr[j], arr[j+1]);
}

void create_files()
{

    fstream file1;
    file1.open("input.txt",ios::out);
    srand(time(0));
    for(int i=0;i<100000;i++)
    {
        file1<<rand()%10000;
        file1<<" ";
    }
    file1.close();
}

int main()
{
    ///creating random numbers
    create_files();

    ///initializing array
    int a[100000],p=0,buf;

    ///taking input from file(input.txt)
    fstream file1;
    file1.open("input.txt");
    while(!file1.eof())
    {
        file1>>buf;
        a[p++]=buf;
    }
    file1.close();
    int n= sizeof(a)/sizeof(a[0]);
    int k = *max_element(a,a+n);
    ///Using bubble sort
    auto start = high_resolution_clock::now();
    bubbleSort(a,n);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout<<"Time taken by bubble sort algorithm = "<<0.001*(duration.count())<<" miliSeconds"<<endl;

    ///Using counting sort

    auto start1 = high_resolution_clock::now();
    countsort(a,n,k);
    auto stop1 = high_resolution_clock::now();
    auto duration1 = duration_cast<microseconds>(stop1 - start1);
    cout<<"Time taken by counting sort algorithm = "<<0.001*(duration1.count())<<" miliSeconds"<<endl;

    return 0;
}
