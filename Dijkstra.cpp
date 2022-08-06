/// Is a greedy algorithm
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N '\n'
#define pb push_back
const int MX = 1e5 + 5;
const int INF = 1e9 + 10;
vector<pair<int,int>>g[MX];
vector<bool>vis(MX,0);
vector<ll>dis(MX,INF);
vector<ll>parent(MX);

void Dijkstra(ll source)
{
    /// first weight second node
    set<pair<ll,ll>>st;
    st.insert({0,source});
    dis[source] = 0;
    parent[source] = -1;

    while(st.size()!=0){
        auto node = *st.begin();
        ll v = node.second;
        ll d = node.first;
        st.erase(st.begin());
        if(vis[v]) continue;
        vis[v] = 1;
        for(auto child:g[v]){
            ll v_child = child.first;
            ll wt = child.second;
            if(dis[v]+wt<dis[v_child]){
                dis[v_child] = dis[v]+wt;
                st.insert({dis[v_child],v_child});
                parent[v_child] = v;
            }
        }
    }

}

void solve()
{
     ll node,edge;
     cin>>node>>edge;
     for(ll i=0;i<edge;i++){
        ll x,y,wt;
        cin>>x>>y>>wt;
        g[x].pb({y,wt});
        g[y].pb({x,wt});
     }
     Dijkstra(0);
}
int main()
{
    solve();
//    ll i=4;
//    while(1){
//        cout<<i<<N;
//        i = parent[i];
//        if(i==-1)
//            break;
//    }
    cout<<dis[1]<<N;
    for(ll i=0;i<6;i++){
        cout<<parent[i]<<" ";
    }
    cout<<N;
    return 0;
}
/*
6
9
0 1 14
0 3 9
0 5 7
1 2 8
1 3 2
3 5 10
3 4 11
2 6 2
4 5 15


*/
