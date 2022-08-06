#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N '\n'
ll mx = 10000;

void bfs()
{
    ll n;
    ll edge;
    cin>>n>>edge;
    bool vis[n] = {0};
    int d[n] = {mx};
    int p[n] = {-1};
    vector<ll>G[n];
    list<ll>path;
    while(edge--){
        ll x,y;
        cin>>x>>y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    ll s = 0;
    vis[s] = 1;
    d[s] = 0;
    p[s] = -1;
    queue<ll>q;
    q.push(s);
    while(!q.empty()){
        ll v = q.front();
        q.pop();
        for(int u:G[v]){
            if(!vis[u]){
                vis[u] = 1;
                q.push(u);
                d[u] = d[v]+1;
                p[u] = v;
            }
        }
    }
    /// shortest path source to destination
    ll dest = 5;
    while(dest!=-1){
        path.push_front(dest);
        dest = p[dest];
    }
    for(int i=0;i<n;i++){
        cout<<"Sortest distance from source 0 to : "<<i<<" is "<<d[i]<<N;
    }
    for(int pt:path){
        cout<<pt<<" ";
    }
    cout<<N;

}
int main()
{
    bfs();
    return 0;
}

/*
6
6
0 1
0 2
0 3
2 4
2 5
3 5
*/
/*
7
9
0 1
0 6
0 4
4 5
6 5
1 2
2 5
1 2
1 3
*/
