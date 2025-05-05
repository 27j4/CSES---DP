#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
typedef long long ll;
typedef unsigned long long ull;
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<":"; _print(x); cerr << endl;
#else
#define debug(x)
#endif
void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
/*---------------------------------------------------------------------------------------------------------------------------*/
const ll mod = 1e9+7;
ll binpow(ll a , ll b){
    ll ans = 1;
    while(b){
        if(b&1){
            ans = (ans*a)%mod;
            b--;
        }
        else{
            a = (a*a)%mod;
            b = b/2;
        }
    }
    return ans;
}
ll dp[62626][501];
ll helper(ll i , vector<ll> &vec , ll sum){
    if(sum == 0){
        return 1;
    }
    if(i > vec.size()){
        return 0;
    }
    if(dp[sum][i] != -1){
        return dp[sum][i];
    }
    // Take case
    ll ans = 0;
    if(vec[i]<=sum){
        ans = (ans%mod + helper(i+1,vec,sum-vec[i])%mod)%mod;
    }
    ans = (ans+helper(i+1,vec,sum))%mod;
    return dp[sum][i] = ans;
}
int main()
{
#ifndef ONLINE_JUDGE
    // freopen("input.in", "r", stdin);
    // freopen("output.out", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    memset(dp,-1,sizeof(dp));
    ll sum = (n*(n+1))/2;
    if(sum&1){
        cout << 0 << endl;
        return 0;
    }  
    vector<ll> vec(n);
    iota(all(vec),1);
    cout << (helper(0,vec,sum/2)*binpow(2ll,mod-2))%mod;
}
