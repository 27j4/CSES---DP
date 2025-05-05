#include <bits/stdc++.h>
using namespace std;
 
const unsigned long long maxi = LLONG_MAX*2ULL;
 
int n;
vector<int> a, b;
vector<vector<vector<vector<vector<unsigned long long>>>>> dp;
 
unsigned long long helper(int i, int b1, int b2, int prev, int is) {
    if (i == n) return 1;
 
    if (dp[b1][b2][prev][i][is] != maxi) {
        return dp[b1][b2][prev][i][is];
    }
 
    unsigned long long ans = 0;
 
    for (int j = 0; j <= 9; j++) {
        if (((j > b[i]) && (!b2)) || (j < a[i] && (!b1))) {
            continue;
        }
        if (j == prev) {
            if (is == 0)
                ans += helper(i + 1, (b1 | (j > a[i])), (b2 | (j < b[i])), j, is | (j != 0));
        } else {
            ans += helper(i + 1, (b1 | (j > a[i])), (b2 | (j < b[i])), j, is | (j != 0));
        }
    }
 
    return dp[b1][b2][prev][i][is] = ans;
}
 
int main() {
    long long num1, num2;
    cin >> num1 >> num2;
 
    if (num1 == 0 && num2 == 0) {
        a.push_back(0);
        b.push_back(0);
    }
 
    while (num1) {
        a.push_back(num1 % 10);
        num1 /= 10;
    }
 
    while (num2) {
        b.push_back(num2 % 10);
        num2 /= 10;
    }
 
    while (a.size() < b.size()) {
        a.push_back(0);
    }
 
    n = a.size();
 
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
 
    // Initialize dp as vector
    dp.assign(
        2,
        vector<vector<vector<vector<unsigned long long>>>>(
            2,
            vector<vector<vector<unsigned long long>>>(
                10,
                vector<vector<unsigned long long>>(
                    n,
                    vector<unsigned long long>(2, maxi)
                )
            )
        )
    );
 
 
    unsigned long long ans = 0;
 
    for (int i = a[0]; i <= b[0]; i++) {
        bool b1 = false, b2 = false;
        if (i > a[0]) b1 = true;
        if (i < b[0]) b2 = true;
        ans += helper(1, b1, b2, i, (i != 0));
    }
 
    cout << ans << endl;
}
