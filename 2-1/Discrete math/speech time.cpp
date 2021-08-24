#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,du[100],p,tt;

    cout<<"Give total number of participants= ";
    cin>>n;
    cout<<"Give speech time of each participants= ";
    for(int i=0;i<n;i++)
        cin>>du[i];
    cout<<"Give total time of speech (in minutes)= ";
    cin>>tt;

    sort(du, du + n, greater<int>());




    int count=0;
    for(int i=0;i<n;i++)
    {

        tt=tt-du[i];

        if(tt<=0)
            break;
        count++;

    }
    cout<<"Total maximum number of participants to scheduled= "<<count<<endl;

    return 0;
}
