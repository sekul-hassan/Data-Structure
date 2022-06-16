#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll gcd(ll a,ll b)
{
    if(b==0 or a==b)
        return a;
    else if(a==0)
        return b;
    else if(a>b)
        return gcd(a-b,b);
    else
        return gcd(a,b-a);

}
void solve()
{
    ll n,x,c = 0;
    cin>>n>>x;
    ll gc = gcd(n,x);
    cout<<gc<<endl;
}
int main()
{
        int t = 1;
        while(t){
            solve();
        }
        return 0;
}
