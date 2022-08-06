#include<bits/stdc++.h>
#define ll long long
#define N '\n'
using namespace std;
ll const n = 10000;
vector<ll>G[n];
bool vis[n] = {0};
/// Topological Sort Path
list<ll>TP;

void dfs(ll source)
{
    vis[source] = 1;
    for(ll i=0;i<G[source].size();i++){
        ll next = G[source][i];
        if(vis[next]==0){
            dfs(next);
        }
    }
    TP.push_front(source);
}
int main()
{
    ll node,edge,i;
    cin>>node>>edge;
    while(edge--){
        int x,y;
        cin>>x>>y;
        G[x].push_back(y);
    }
    for(i=0;i<node;i++){
        if(vis[i]==0){
            dfs(i);
        }
    }
    for(auto i:TP){
        cout<<i<<" ";
    }
    cout<<N;
    return 0;
}

/*
6
6
0 1
0 3
1 2
1 5
2 5
1 4

*/
