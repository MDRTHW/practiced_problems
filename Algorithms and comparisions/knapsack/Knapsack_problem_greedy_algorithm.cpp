#include <bits/stdc++.h>

using namespace std;
int w[100];
int item[100];
int b[100];
int m=0;
int q=1;
void knapsack(int n)
{

    int y=m;
    float arr[n][2];
    for(int i=0;i<n;i++)
    {
        arr[i][0]=i;
        arr[i][1]=((1.0*b[i])/w[i]);
    }

    for (int i = 0; i < n; ++i)
        {
            for (int j = i + 1; j < n; ++j)
            {
                if (arr[i][1] < arr[j][1])
                {
                    swap(arr[i][1],arr[j][1]);
                    swap(arr[i][0],arr[j][0]);
                }
            }
        }

        int index[n];
        for(int i=0;i<n;i++)
        {
            index[i]=arr[i][0];

        }
        int i=0;
        float result=0;

       while(m!=0)
       {
        if(m>=w[index[i]])
        {

            result = result+(b[index[i]]);
            m=m-w[index[i]];



        }
        else
        {

            result = result+(m*arr[i][1]);



            m=0;
        }
        i++;
       }



   cout<<q++<<"     ";
   cout<<"          "<<y<<"             "<<result<<endl;


}

int main()
{ifstream file;

  file.open("greedy.txt");

  int iq=0,t,it=0,we=0,be=0;
  int temp;
  string te;
  file>>t;
  cout<<"Solution "<<"    "<<"Total weight"<<"    "<<"Total benefit"<<endl;
  while(t!=0)
  {
    iq=0;
      while(1){
      file>>temp;
      if(temp==99999)
      {


           knapsack(we);
          for(int p=0;p<it;p++)
          {
              item[p]=0;
              w[p]=0;
              b[p]=0;
          }
          it=0;
          we=0;
          be=0;


      break;}
      if(iq==0)
        m=temp;
      else
      {
        item[it++]=temp;
        file>>temp;
        w[we++]=temp;
        file>>temp;
        b[be++]=temp;

      }
      iq++;}
      t=t-1;

  }




    return 0;
}
