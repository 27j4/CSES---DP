#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
typedef long long ll;
typedef unsigned long long ull;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    ll n, x;
    cin >> n >> x;
    vector<ll> vec(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> vec[i];
    }
 
    vector<pair<ll, ll>> dp((1 << n));
 
    dp[0] = {1, 0};
 
    for (ll i = 1; i < (1 << n); i++)
    {
 
        dp[i] = {21, 0};
 
        for (ll j = 0; j < n; j++)
        {
            if (i & (1 << j))
            {
 
                ll minimumRides = dp[i ^ (1 << j)].first;
                ll lastweight = dp[i ^ (1 << j)].second;
 
                if (vec[j] + lastweight > x)
                {
                    minimumRides++;
                    lastweight = vec[j];
                }
                else
                {
                    lastweight += vec[j];
                }
 
                if (minimumRides < dp[i].first)
                {
                    dp[i].first = minimumRides;
                    dp[i].second = lastweight;
                }
                else if (dp[i].second > lastweight && minimumRides == dp[i].first)
                {
                    dp[i].second = lastweight;
                }
            }
        }
    }
 
    cout << dp[(1 << n) - 1].first << endl;
}
