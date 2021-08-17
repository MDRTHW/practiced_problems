#include <bits/stdc++.h>

using namespace std;

void countsort(int a[], int n,int k)
{
    map<int,int> count;
    map<int,int>::iterator itr;
    map<int,int>::iterator itr2;
    int b[n];

    ///updating all elements to zero
    for(int i=0;i<=k;i++)
        count.insert(pair<int,int>(i,0));

    ///making a count array of frequency
    for(int i=0;i<n;i++)
        {
            int temp=0;
            itr=count.find(a[i]);
            count.insert(pair<int,int>(a[i],(itr->second)++));
            temp=itr->second;

        }

    /*for (itr = count.begin(); itr != count.end(); ++itr) {
        cout << '\t' << itr->first
             << '\t' << itr->second << '\n';
    }*/

    ///updating to actual position
    for(int i=1;i<=k;i++)
        {
            int p;
            itr=count.find(i);
            itr2=count.find(i-1);
            p=itr2->second;
            itr->second=itr->second + p;
            count.insert(pair<int,int>(i,itr->second));
        }

    /*for (itr = count.begin(); itr != count.end(); ++itr) {
        cout << '\t' << itr->first
             << '\t' << itr->second << '\n';
    }*/

    ///building the sorted array
    for(int i=n-1;i>=0;i--)
        {
            itr=count.find(a[i]);
            b[--itr->second]=a[i];
        }

    ///updating the main array with this sorted array
    for(int i=0;i<n;i++)
        a[i]=b[i];

    ///printing the sorted array
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";

    cout<<endl;

}

int main()
{
    int a[]={2,1,1,0,2,5,4,0,2,8,7,7,9,2,0,1,9};
    int n= sizeof(a)/sizeof(a[0]);
    int k = *max_element(a,a+n);
    countsort(a,n,k);

    return 0;
}
