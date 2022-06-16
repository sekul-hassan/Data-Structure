#include<bits/stdc++.h>
using namespace std;
#define ll long long
void test()
{
    ll n,i,j;

    cin>>n;
    vector<ll>p;
    ll v[n+1];
    for(i=1;i<=n;i++){
        v[i] = i;
    }
    for(i=2;i<=n;i++){
        if(v[i]==i){
            p.push_back(i);
            for(j=i;j<=n;j+=i){
                v[j]=v[j]/i;
            }
        }
    }
    for(i=0;i<p.size();i++){
        cout<<p[i]<<" ";
    }
    cout<<'\n';
}
int main()
{
    int t = 1;
    while(t){
        test();
    }
    return 0;
}
