#include<bits/stdc++.h>
using namespace std;

int main(){

    int n , x;
    cin >> n >> x;

    vector<int> coins(n);
    for(int i = 0 ; i < n ; i++){
        cin >> coins[i];
    }

    vector<int> coinsReq(x+1,INT_MAX);

    coinsReq[0] = 0; // Base Case as we can make 0 by using 0 coins

    for(int i = 1; i <= x ; i++){
        for(int j = 0 ; j < n ; j++){
            // I am using this coin
            int remCoins = i - coins[j];
            if(remCoins >= 0 && coinsReq[remCoins] != INT_MAX){
                coinsReq[i] = min(coinsReq[i],coinsReq[remCoins]+1);
            }
        }
    }

    if(coinsReq[x] == INT_MAX){
        coinsReq[x] = -1;
    }

    cout << coinsReq[x] << endl;

}   
