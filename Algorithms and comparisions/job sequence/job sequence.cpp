#include<bits/stdc++.h>
using namespace std;
int d[100],j[100],p[100];
int n=0;

void print()
{
    for(int i=1;i<=n;i++)
    {
        cout<<p[i]<< " \t" <<d[i]<<endl;
    }
}
int JS()
{
    int k=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(p[j]<p[j+1])
            {
                swap(p[j],p[j+1]);
                swap(d[j],d[j+1]);
            }
        }
    }
    cout<<"After Sorting: "<<endl;
    print();

    d[0]=0;
    j[0]=0;///dummy job.

    j[1]=1;///first job has max profit.
    k=1;///how many jobs are taken.

    for(int i=2;i<=n;i++)
    {
        int r=k;
        while(d[j[r]]>d[i]&&d[j[r]]!=r)
        {
            r--;
        }
        if((d[j[r]]<=d[i])&&(d[i]>r))
        {
            for(int q=k;q>=(r+1);q--)
            {
                j[q+1]=j[q];
            }
            j[r+1]=i;
            k++;
        }
    }

    return k;

}
int main()
{
    ifstream f;
    f.open("JobSequence.txt");
    int temp1,temp2;
    f>>n;

    for(int i=1;i<=n;i++)
    {
        f>>temp1>>temp2;
        p[i]=temp1;
        d[i]=temp2;

    }

    print();
    int k=JS();

    cout<<"Job Sequence: "<<endl;

    for(int i=1;i<=k;i++)
    {
        cout<<"Job: "<<j[i]<<" Profit: "<<p[j[i]]<<endl;
    }


}
