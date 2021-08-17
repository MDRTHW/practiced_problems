#include<bits/stdc++.h>
#define pb              push_back


using namespace std;


void solve(){

    int v,e;
    cout<<"Enter vertice and edges number: ";
    cin>>v>>e;
    vector<vector<int>> g(v);
    cout<<"Enter value such that x is connected to y:"<<endl;
    for(int i=0;i<e;i++){
        int x,y;
        cin>>x>>y;
        g[x].pb(y);
        g[y].pb(x);
    }
    int cs[v];
    bool available[v];
    cs[0]=0;
    for(int i=1;i<v;i++)
        cs[i] = -1;
    for(int i=0;i<v;i++)
        available[i] = 0;

    int cn = 0;
    for(int i=1;i<v;i++){
        for(auto x:g[i]){
            if(cs[x]!=-1){
                available[cs[x]] = 1;
            }
        }

        int cr;
        for(cr=0;cr<v;cr++){
            if(available[cr] == false){
                break;
            }
        }

        cs[i] = cr;
        cn = max(cn,cr+1);

        for(auto x:g[i]){
            if(cs[x]!=-1){
                available[cs[x]] = false;
            }
        }
    }
    cout<<"Chromatic number: "<<cn<<endl;
    cout<<"Solution: ";
    for(int i=0;i<v;i++)
        cout<<cs[i]<<"   ";
    cout<<endl;

}

int main() {

    solve();
    return 0;

}




