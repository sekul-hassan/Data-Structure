
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mx = 1000000;
const int ok = 20;

void solve(int id)
{
    int n,m,i,k,j;
    vector<pair<int ,int>>p;
    cin>>n>>m;
    k = log2(n);
    int dp[k+3][n+3];
    int arr[n+1];
    for(i=0;i<n;i++){
        cin>>arr[i];
        dp[0][i]=arr[i];
    }

    for(i=1;i<=k;i++){
        for(j=0;j<n;j++){
            dp[i][j]=min(dp[i-1][j],dp[i-1][j+(1<<(i-1))]);
          //  cout<<dp[i][j]<<" ";
        }
        //cout<<endl;
    }
    for(i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        p.push_back({x,y});
    }
    cout<<"Case "<<id<<":"<<endl;
    for(i=0;i<m;i++){
        int a,b;
        a = p[i].first -1;
        b = p[i].second -1;
        k = log2(b-a+1);
        cout<<(min(dp[k][a], dp[k][b-(1<<k)+1]))<<endl;;
   }
}
int main()
{
    int t,id=0;
    cin>>t;
    while(t--){
        solve(++id);
    }
}
