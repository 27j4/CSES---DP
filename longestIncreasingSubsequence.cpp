#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
typedef long long ll;
typedef unsigned long long ull;
const ll maxN = 2e5+1;
ll dp[maxN];
ll getBestAnswer(map<ll,ll> &mp , ll val){
    auto it = mp.lower_bound(val);
    if(it == mp.begin()){
        return 0;
    }
    it--;
    return it->ss;
}
void insert(map<ll,ll> &mp , ll val , ll ans){
    if(mp[val] >= ans){
        return;
    }
    mp[val] = ans;
    auto it = mp.find(val);
    it++;
    while(it != mp.end() && it->ss <= ans){
        auto temp = it;
        it++;
        mp.erase(temp);
    }
}
ll solve(ll arr[] , ll n){


    // Solution 1 :  it uses a map data structure 

    // dp[0] = 1;
    // map<ll,ll> mp;
    // mp[arr[0]] = 1;
    // for(ll i = 1; i < n ;i++){
    //     dp[i] = 1 + getBestAnswer(mp,arr[i]);
    //     insert(mp,arr[i],dp[i]);
    // }
    // return *max_element(dp,dp+n);



    // Solution 2 : it uses a vector data stucture ans the "ans" store the LIS

    vector<int> ans;

    for(int i = 0 ; i < n ; i++){
        auto it = lower_bound(ans.begin(),ans.end(),arr[i]);
        if(it == ans.end()){
            ans.push_back(arr[i]);
        }
        else{
            ans[it-ans.begin()] = arr[i];
        }
    }

    return ans.size();



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
    ll arr[n];
    for(ll i = 0; i < n ;i++){
        cin >> arr[i];
    }
    cout << solve(arr,n);
}
