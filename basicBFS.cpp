#include<bits/stdc++.h
using namespace std;
const int mx = 1000;
vector<int>gp[mx];
vector<bool>v[mx];
void bfs(int i,int j)
{
    v[i][j] = 1;
    list<int>q;
    q.push_back(gp[i][j]);
    while(!q.empty()){

    }
}
void graph(int n)
{
    int u,v,i;
    for(i=0;i<n;i++){
        cin>>u>>v;
        graph[u].push_back(v);
    }
    bfs(0,0);
}
int main()
{
    int n = 4;
    graph(n);
    return 0;
}
