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
void push(int x);
int pop();
int  peep();

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
       else  if(infix[i]=='p'||infix[i]=='q'||infix[i]=='r')
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

void phew::push(int x)
{
    stackk[++top]=x;

}

int phew::pop()
{
    return stackk[top--];
}

int  phew::peep()
{
    return stackk[top];
}





bool evaluation(int p,int q,int r)
{
    int i=0,a,b,c;
    phew s2;
    ///object of the class

    while(postfix[i]!='\0')
    {

        if(postfix[i]=='p'||postfix[i]=='q'||postfix[i]=='r')
        {
            if(postfix[i]=='p')
                s2.push(p);
            if(postfix[i]=='q')
                s2.push(q);
            if(postfix[i]=='r')
                s2.push(r);
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
   string s;
   int i,j,k,z;
 cout<<"Give the string(not=! ,and=& ,or=|, implication=~, bi-conditional=^): ";
   cin>>s;
   conversion(s);
    cout<<"P"<<"    "<<"Q"<<"    "<<"R"<<"    "<<s<<endl;
   for(i=0;i<=1;i++)
    for(j=0;j<=1;j++)
        for(k=0;k<=1;k++)
            {
                 z=evaluation(i,j,k);
                 cout<<i<<"    "<<j<<"    "<<k<<"    "<<z<<endl;


            }

    return 0;
}
