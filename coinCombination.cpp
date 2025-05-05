#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;

int main(){

    int n , x;
    cin >> n >> x;

    vector<int> coins(n);
    for(int i = 0 ; i < n ; i++){
        cin >> coins[i];
    }

    vector<int> dp(x+1,0);

    dp[0] = 1; // Base Case as we can make 0 

    for(int i = 1; i <= x ; i++){
        for(int j = 0 ; j < n ; j++){
            int remCoins = i - coins[j];
            if(remCoins >= 0 && dp[remCoins]){
                (dp[i] += dp[remCoins]) %= mod;
            }
        }
    }

    cout << dp[x] << endl;

}   
