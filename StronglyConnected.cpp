/// Kosaraju Algorithm
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N '\n'
#define pb push_back
vector<int>G[1000];
vector<bool>vis(10000,false);
stack<int>st;
vector<int>ans[1000];

void Reverse(ll n)
{
    for(ll i=0;i<n;i++){
        for(auto j:G[i]){
            G[j].pb(j);
        }
    }
}
void dfs(ll source)
{
    vis[source] = 1;
    for(ll j=0;j<G[source].size();j++){
        if(!vis[j]){
            ll next = G[source][j];
            dfs(next);
        }
    }
    st.push(source);
}

void dfs2(ll source,ll p)
{
    ans[p].pb(source);
    vis[source] = 0;
    for(ll i=0;i<G[source].size();i++){
        ll next = G[source][i];
        if(vis[next]){
            dfs2(next,p);
        }
    }
}
ll solve()
{
    ll node,edge,p=0;
    cin>>node>>edge;
    while(edge--){
        ll x,y;
        cin>>x>>y;
        G[x].pb(y);
    }
    for(ll i=0;i<node;i++){
        if(!vis[i]){
            dfs(i);
        }
    }
    Reverse(node);

    while(!st.empty()){
        /// use same visited array as unchanged
        /// true = false
        /// false = true
        if(vis[st.top()]){
            dfs2(st.top(),p++);

        }
        st.pop();
    }
    return p;
}
int main()
{
    ll p = solve();
    for(ll i=0;i<p;i++){
        cout<<i+1<<" Strongly Connected Component : " ;
        for(auto a:ans[i]){
            cout<<a<<" ";
        }
        cout<<N;
    }
    return 0;
}
/*
8
10
1 2
2 0
0 1
3 4
4 5
5 6
2 3
6 4
6 7
4 7
*/
