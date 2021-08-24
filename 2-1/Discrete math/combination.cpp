#include<bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    char variable[20],operatorr[20];
    int j=0,k=0,flag,carry=0;

    map<char, bool> val;
    for(int i=0;i<20;i++)
    {
        variable[i]='\0';
        operatorr[i]='\0';
        val[i]=0;
    }
    cout<<"Give the string: ";
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]>='a'&&s[i]<='z')
            {
                flag=0;
                for(int l=0;l<=j;l++)
                    if(variable[l]==s[i])
                        flag=1;
                if(flag==1)
                    continue;
                else
                variable[j++]=s[i];
            }
        else
            operatorr[k++]=s[i];
    }

    cout<<variable<<endl<<operatorr<<endl<<endl<<endl;

    for(int i=0;i<pow(2,j);i++)
    {
        carry=1;
        for(int p=j-1;p>=0;p--)
        {
            if(carry==1)
            {
                if(val[variable[p]]==1)
                    val[variable[p]]=0;
                else
                {
                    val[variable[p]]=1;
                    carry=0;
                }
            }
            cout<<val[variable[p]];
        }
        cout<<endl;


    }
    return 0;
}
