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

void mergeSort(int arr[],int l,int r);
void merge(int arr[], int l, int m, int r);

void merge(int arr[], int l, int m, int r)
{
	int n1 = m - l + 1;
	int n2 = r - m;

    int Left[n1], Right[n2];
	for (int i = 0; i < n1; i++)
		Left[i] = arr[l + i];

	for (int j = 0; j < n2; j++)
		Right[j] = arr[m + 1 + j];

	int i = 0;
	int j = 0;
	int k = l;
	while (i < n1 && j < n2) {
		if (Left[i] <= Right[j]) {
			arr[k] = Left[i];

			i++;}
		else {
			arr[k] = Right[j];

			j++;}
		k++;}
	while (i < n1) {
		arr[k] = Left[i];
		i++;
		k++;
		}
    while (j < n2) {
		arr[k] = Right[j];
		j++;
		k++;
		}
}


void mergeSort(int arr[],int l,int r){
	if(l>=r){
		return;
	}
	int m =l+ (r-l)/2;

	mergeSort(arr,l,m);
	mergeSort(arr,m+1,r);
	merge(arr,l,m,r);
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
        {ss= "merge1.txt";
        n=4000;}
    if(k==2)
        {ss= "merge2.txt";
        n=5000;}
    if(k==3)
        {ss= "merge3.txt";
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

     auto s11 = chrono::steady_clock::now();
     mergeSort(arr1,0,i-1);
     auto e11 = chrono::steady_clock::now();
     cout<<"Time taken by mergesort algorithm = "<< 0.001*(chrono::duration_cast<chrono::microseconds>(e11 - s11).count())<<" miliSeconds"<<endl;

    cout<<endl;
    file1.open(ss);
    for(int p=0;p<n;p++)
    {
        file1<<arr1[p];
        file1<<" ";
    }}




    return 0;
}
