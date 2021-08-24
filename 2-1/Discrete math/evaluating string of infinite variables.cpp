#include <bits/stdc++.h>

using namespace std;
bool evaluation(int p,int q,int r);
void conversion(string s);
char postfix[100];
int pre(char x);
bool bi_cond(int a,int b);





class phew
{
public:
int stackk[100];
int top=-1;
void push(bool x);
bool pop();
bool  peep();

};



bool bi_cond(int a,int b)
{

    return((!a|b)&(!b|a));
}


void conversion(string s)
{
    char infix[100],ch;
   phew s1;
   int j=0,i=0;

    ///adding ( and )
    infix[j]='(';
    j=j+1;



    while(s[i]!='\0')
    {
        infix[j]=s[i];
        i++;
        j++;
    }
    infix[j]=')';
    infix[j+1]='\0';
    cout<<infix<<endl;

    ///adding finished


    i=0;
    j=0;
    while(infix[i]!='\0')
    {
        if(infix[i]=='(')
        {
            s1.push(infix[i]);
        }
       else  if(infix[i]>='a'&&infix[i]<='z')
       {
           postfix[j]=infix[i];
           j++;
       }
       else if(infix[i]=='&'||infix[i]=='|'||infix[i]=='~'||infix[i]=='!'||infix[i]=='^')
       {
           while(s1.peep()=='&'||s1.peep()=='|'||s1.peep()=='~'||s1.peep()=='!'||s1.peep()=='^')
           {
               if(pre(s1.peep())>=pre(infix[i]))
              {
                  postfix[j]=s1.pop();
                    j++;

              }
               else
                break;
           }
           s1.push(infix[i]);

       }
       else if(infix[i]==')')
       {
           while((ch=s1.pop())!='(')
           {
               postfix[j]=ch;

               j++;
           }
       }
        i++;
    }

    postfix[j]='\0';
    cout<<postfix<<endl;
}






int pre(char x)
{
    switch(x)
    {
    case '!':
        return 4;
    case '&':
    case '|':
        return 3;
    case '~':
        return 2;
    case '^':
        return 1;
    }
}

void phew::push(bool x)
{
    stackk[++top]=x;

}

bool phew::pop()
{
    return stackk[top--];
}

bool  phew::peep()
{
    return stackk[top];
}





bool evaluation(map<char,bool> val)
{
    int i=0,a,b,c;
    bool temp;
    phew s2;


    while(postfix[i]!='\0')
    {

        if(postfix[i]>='a'&&postfix[i]<='z')
        {

            temp=val[postfix[i]];

            s2.push(temp);
        }
        else if(postfix[i]=='&'||postfix[i]=='|'||postfix[i]=='~'||postfix[i]=='!'||postfix[i]=='^')
        {
            if(postfix[i]=='!')
            {
                a=s2.pop();
                c=!a;
                s2.push(c);

            }
            else
                {a=s2.pop();
            b=s2.pop();
            switch(postfix[i])
            {
            case '&':
                c=a&b;
                s2.push(c);
                break;
            case '|':
                c=a|b;
                s2.push(c);
                break;
            case '~':
                c=(!a)|b;
                s2.push(c);
                break;
            case '^':
                c=bi_cond(a,b);
                s2.push(c);
                break;
            }}
        }

        i++;
    }
    return s2.pop();



}





int main()
{
   string d;
   int z;
 cout<<"Give the string(not=! ,and=& ,or=|, implication=~, bi-conditional=^): ";
   cin>>d;
   conversion(d);

    string s;
    char variable[20],operatorr[20];
    int j=0,k=0,flag,carry=0,p;

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
        for( p=j-1;p>=0;p--)
        {
            if(carry==1)
            {
                if(val[variable[p]]==1)
                    val[variable[p]]=0;
                else
                {
                    val[variable[p]]=1;
                    carry=0;
                    ///carry 0 means value is 1
                }
            }


        }
        cout<<val[variable[p]];
            z=evaluation(val);
        cout<<"     "<<z<<endl;


    }


    return 0;
}
