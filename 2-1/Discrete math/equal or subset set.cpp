#include <bits/stdc++.h>

using namespace std;
void task1();
void task2();
void task3();
///task4();

 set<int> st;
 set<int>st2;
 set<int>::iterator it;
 set<int>::iterator it2;

 bool impliab(int i)
 {

     if((*it)==(*it2))

     {
         it++;
         it2++;
         return 1;}
 }

  bool impliba(int i)
 {

     if((*it)==(*it2))
        {
         it++;
         it2++;
         return 1;}
 }

void task1()
{
    int s[100],n,j=1,s2[100],k=1;
    cout<<"Give the set element number: ";

    cin>>n;

    for(int i=0;i<n;i++)
    {
        cin>>s[i];
    }

    s2[0]=s[0];
    int f=0;
    while(j!=n-1)
    {
        f=0;
        for(int i=0;i<=k;i++)
            if(s2[i]==s[j])
                {
                    f=1;
                    break;
                }
        if(f==1)
        {
            j++;
            continue;
        }
        else
        {s2[k]=s[j];
        k++;
        j++;}

    }
    cout<<"The set={";
    for(int i=0;i<k;i++)
    cout<<s2[i]<<",";
    cout<<"}"<<endl;
}

void task2()
{

 int n,p,n2;

 cout<<"Give the set 1 element number:";
 cin>>n;

 for(int i=0;i<n;i++)
    {cin>>p;
     st.insert(p);
    }

for(it=st.begin();it!=st.end();++it)
    cout<<*it<<"  ";

    cout<<endl;

    cout<<"Give the set 2 element number:";
 cin>>n;

 for(int i=0;i<n;i++)
    {cin>>p;
     st2.insert(p);
    }

for(it=st2.begin();it!=st2.end();++it)
    cout<<*it<<"  ";

    cout<<endl;


  ///find equality
    int f=0;
for(int i=0;i<n;i++)
{
    if((impliab(i))&(impliba(i))==0)
    {
        f=1;
        break;
    }
}

if(f==0)
    cout<<"The sets are equal and subset of each other."<<endl;
else
    cout<<"The sets are not equal."<<endl;

///find subset
int k=0;
it=st.begin();
it2=st2.begin();
while(it!=st.end()||it2!=st2.end())
{
    if(*it==*it2)
        k++;
    ++it;
    ++it2;
}


if(k==n||k==n2)
{
    if(n>n2)
        cout<<"Set2 is a subset of set1"<<endl;
    else
        cout<<"Set1 is a subset of set2 "<<endl;
}
else
    cout<<"There is no subset"<<endl;














}

void task3()
{

}

int main()
{
    int n;
    cout<<"Choose one: "<<endl<<"1.Task 1"<<endl<<"2. Task 2"<<endl<<"3. Task 3"<<endl<<"4. Exit"<<endl;
    cin>>n;
    if(n==1)
        task1();
    else if(n==2)
        task2();
    else if(n==3)
        task3();
    else
        cout<<"Terminated"<<endl;
    return 0;
}
