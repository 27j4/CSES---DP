#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define vi vector<ll>
#define loop(i, a, b) for (ll i = a; i < b; i++)
 
const ll mod = 1e9 + 7;
 
vector<vector<ll>> dp;
const ll maxn = 1e6;
 
ll helper(ll i , ll prev){
    
    if(i == maxn){
        return (prev == 0);
    }
    
    if(dp[i][prev] != -1){
        return dp[i][prev];
    }
    
    ll ans = 0;
    
    if(prev == 0){
        
        (ans += helper(i+1,3)) %= mod;
        (ans += helper(i+1,4)) %= mod;
        (ans += 2*helper(i+1,0)) %= mod;
        (ans += helper(i+1,1)) %= mod;
        (ans += helper(i+1,2)) %= mod;
    }
    else if(prev == 1){
        
        (ans += helper(i+1,0)) %= mod;
        (ans += helper(i+1,1)) %= mod;
        (ans += helper(i+1,2)) %= mod;
        (ans += helper(i+1,4)) %= mod;
    
        
    }
    else if(prev == 2){
        
        (ans += helper(i+1,0)) %= mod;
        (ans += helper(i+1,1)) %= mod;
        (ans += helper(i+1,2)) %= mod;
        (ans += helper(i+1,4)) %= mod;
        
    }
    else if(prev == 3){
        
        (ans += helper(i+1,3)) %= mod;
        (ans += helper(i+1,0)) %= mod;
        
    }
    else{
        
        (ans += helper(i+1,0)) %= mod;
        (ans += helper(i+1,1)) %= mod;
        (ans += helper(i+1,2)) %= mod;
        (ans += helper(i+1,4)) %= mod;
        
    }
    
    return dp[i][prev] = ans;
    
}
 
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll t;
    cin >> t;
    
    
    
    dp.assign(maxn+1,vector<ll>(5,-1));
    ll ans = helper(0,0);
    
 
    while(t--){
        
        ll n;
        cin >> n;
        
        cout << dp[maxn-n][0] << endl; 
        
    }
    
 
 
}
