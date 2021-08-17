#include <bits/stdc++.h>


using namespace std;
int stackk[100]={0},top=0;
int valid[100]={0};
int solnum=1;
int valid_sum();
void Printstack();
bool isSafe(int num,int lim,int length);
void nQueen(int num, int total);

void nQueen(int num, int total)
{
    int length =1; ///stack length
    int initial =1; ///first value to check with n=1
    int p;
    top=top+1;
    stackk[top] = num;
    valid[num] = 1;
    while(length != 0)
    {
        if(valid_sum() == total)
        {
            cout<<endl<<"Solution #"<<solnum<<":"<<endl;
            Printstack();
            cout<<endl<<endl;
            p = stackk[top];
            stackk[top]=0;
            top=top-1;
            valid[p]=0;
            length = length-1;

            while(stackk[top] == total)
            {
                p = stackk[top];
                stackk[top]=0;
                top=top-1;
                valid[p]=0;
                length = length-1;
            }
             p = stackk[top];
            stackk[top]=0;
            top=top-1;
            valid[p]=0;
            length = length-1;
            initial =p+1;
        }
        int k;
        k = isSafe(initial,total,length);

        if(k == false)
        {
            if(initial == total)
            {
                while(stackk[top]==total && length !=1)
                {
                    p = stackk[top];
                    stackk[top]=0;
                    top=top-1;
                    valid[p]=0;
                    length = length-1;
                }
                p = stackk[top];
                stackk[top]=0;
                top=top-1;
                valid[p]=0;
                length = length-1;
                initial = p+1;
                continue;
            }
            else
                {initial = initial+1;
                continue;}
        }
        else
        {
            initial = 1;
            length = length+1;
        }

    }
}

bool isSafe(int num,int lim,int length)
{
    if(valid[num] == 1)
    {
        return false;
    }
    else
    {
        if(1 <= num && num<= lim)
        {
            for(int m=1,t=top;m<length+1;m++,t--)
            {
                if(abs(stackk[t] - num) == m) ///abs() used as diagonal of both side would be same in magnitude
                {
                    return false;
                }


            }
        }
    }

    valid[num] = 1;
    top=top+1;
    stackk[top] = num;
    return true;
}
void Printstack()
{

    for(int i=1;i<=top;i++)
        {
            for(int j=1;j<=top;j++)
            {
                    if(stackk[i]==j)
                        cout<<"Q\t";
                    else
                        cout<<"*\t";
            }
            cout<<endl;


        }
        solnum++;

}
int valid_sum()
{
    int s=0;
    for (int i=1;i<=100;i++)
        s=s+valid[i];
    return s;
}
int main()
{
    int n;
    fstream file1;
    file1.open("queen.txt");
    while(!file1.eof())
    {
        file1>>n;

    }
    file1.close();
    for(int i=1;i<n+1;i++)
        nQueen(i,n);

    return 0;
}
