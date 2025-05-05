#include <bits/stdc++.h>
#define MOD 1000000007
#define ll long long
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define all(x) (x).begin(), (x).end()
#define loop(i, a, b) for (ll i = a; i < b; i++)
#define rloop(i, b, a) for (ll i = b; i >= a; i--)
ll dp[1000001];
using namespace std;
void print(vi vec)
{
    int a = 0, b = vec.size();
    loop(i, a, b)
    {
        cout << vec[i] << ' ';
    }
    cout << endl;
}
void find()
{
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = dp[1] + dp[0];
    dp[3] = dp[2] + dp[1] + dp[0];
    dp[4] = dp[3] + dp[2] + dp[1] + dp[0];
    dp[5] = dp[4] + dp[3] + dp[2] + dp[1] + dp[0];
    loop(i, 6, 1000001)
    {
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3] + dp[i - 4] + dp[i - 5] + dp[i - 6];
        dp[i] %= MOD;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    find();
    int n;
    cin >> n;
    cout << dp[n];
}
