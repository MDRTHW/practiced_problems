#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;


int main() {
  int arr[10000];
  int n ,x;
  cin>>n;
  for(int i=0;i<n;i++)
  {cin>>x;
      arr[i]=x;}

  auto start = high_resolution_clock::now();
   for (int i = 0; i < n - 1; ++i) {
    for (int j = 0; j < n - i - 1; ++j) {


      if (arr[j] > arr[j + 1]) {
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);

  cout << "Sorted Array in Ascending Order:\n";
  for (int i = 0; i < n; ++i)
    cout << "  " << arr[i];

cout << endl<<"Time taken by algorithm: "
         << duration.count() << " microseconds" << endl;
}
