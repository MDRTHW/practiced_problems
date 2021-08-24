#include <bits/stdc++.h>

using namespace std;

int main(void) {
  int arr[1002];

  for(int i=0;i<1200;i++)
    arr[i]=i+1;

  int x = 1200 ;
  int n = 1200;
  int location = -1;
  int mid=-1,low=0,high=n;

  int sc=0;

  while (low <= high) {
     mid = low + (high - low) / 2;
     sc=sc+2;

    if (arr[mid] == x)
      {location= mid;
      sc=sc+2;}

    if (arr[mid] < x)
      {low = mid + 1;
      sc=sc+3;}

    else
      {high = mid - 1;
      sc=sc+3;}

  }


  if (location == -1)
    printf("Not found");
  else
    printf("Element is found at index %d", location);


    cout<<endl<<"The algorithm took= "<<sc<<" statements."<<endl;

    return 0;
}
