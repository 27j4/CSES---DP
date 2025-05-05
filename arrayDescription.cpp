#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;

int main(){

    int n , m;
    cin >> n >> m;

    vector<int> vec(n);
    for(int i = 0 ;i < n ; i++){
        cin >> vec[i];

    }

    vector<int> curr(m+1,0) , prev(m+1,0);

    // Base Case

    if(vec[0]){
        prev[vec[0]] = 1;
    }
    else{
        prev.assign(m+1,1);
    }


    for(int i = 1; i < n ; i++){
        if(vec[i]){
            if(vec[i]-1 >= 1){
                (curr[vec[i]] += prev[vec[i]-1]) %= mod;
            }
            if(vec[i]+1 <= m){
                (curr[vec[i]] += prev[vec[i]+1]) %= mod;
            }
            (curr[vec[i]] += prev[vec[i]]) %= mod;
        }
        else{
            for(int j = 1; j <= m ; j++){
                if(j-1 >= 1){
                    (curr[j] += prev[j-1]) %= mod;
                }
                if(j+1 <= m){
                    (curr[j] += prev[j+1]) %= mod;
                }
                (curr[j] += prev[j]) %= mod;
            }
        }


        prev = curr;
        curr.assign(m+1,0);

    }

    int ans = 0;

    for(int i = 1 ; i <= m ; i++){
        ans = (ans + prev[i])%mod;
    }

    cout << ans << endl;

}
