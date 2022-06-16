#include<bits/stdc++.h>
#define ll long long
using namespace std;
void test()
{
    ll n,i,c =0,total = 0;
    vector<ll>v;
    /// first ll prime factor
    /// second ll prime power
    vector<pair<ll,ll>>p;
    /// if p.size == 0 {this is prime number}
    cin>>n;
    for(i=2;i*i<=n;i++){
        c = 0;
        while(n%i==0){
            n/=i;
            c++;
        }
        if(c){
            v.push_back(c);
            total+=c;
            p.push_back({i,c});
        }
    }
    if(n!=1){
        p.push_back({n,1});
    }
    for(auto a:p){
        cout<<a.first<<" "<<a.second<<endl;
    }
   /// cout<<p.size();
    cout<<endl;
}
int main()
{
    int t = 1;
    while(t){
        test();
    }
    return 0;
}
