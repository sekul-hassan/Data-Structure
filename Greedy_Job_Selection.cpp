#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N '\n'
vector<pair<ll,ll>>m;
vector<ll>st,ed;
void make_pair(ll n)
{
    ll i;
    for(i=0;i<n;i++){
        m.push_back({ed[i],st[i]});
    }
}
void solve()
{
    ll n,i,j,work = 0;

    int s,e;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>s;
        st.push_back(s);
    }
    for(i=0;i<n;i++){
        cin>>e;
        ed.push_back(e);
    }
    make_pair(n);
    sort(m.begin(),m.end());
    for(i=0,j=0;i<n-1;i++){
        ll a,b;
        a = m[j].first;
        b = m[i+1].second;
        if(a>=b){
            work++;
            j=i;
        }
        else{
            continue;
        }
    }
    cout<<work<<endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=4;
    cin>>t;
    while(t--){
        m.clear();
        st.clear();
        ed.clear();
        solve();
    }
    return 0;
}
