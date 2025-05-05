#include<bits/stdc++.h>
using namespace std;
 
vector<vector<int>> dp;
const int mod = 1e9+7;
int n , m;
 
 
vector<vector<int>> is;
 
int helper(int i , int currmask){
 
    if(i == m){
        return currmask == 0;
    }
    
    if(dp[i][currmask] != -1) return dp[i][currmask];
    
    int ans = 0;
 
    for(auto it : is[currmask]){
        ans = (ans + 0ll + helper(i+1,it))%mod;
    }
 
    return dp[i][currmask] = ans;
}
 
int main(){
    
    cin >> n >> m;
    
    dp.assign(m,vector<int>((1<<n),-1)); // dp assign
 
    is.assign((1<<n),vector<int>(0));
 
 
    for(int currmask = 0 ; currmask < (1<<n) ; currmask++){
        for(int mask = 0; mask < (1<<n) ; mask++){
            int curr = 0;
            bool flag = true;
            int nextmask = 0;
            
            for(int j = 0 ; j < n ; j++){
                if(currmask&(1<<j)){
                    if(mask&(1<<j)){
                        flag = false;
                        break;
                    }
                    if(curr&1){
                        flag = false;
                        break;
                    }
                }
                else{
                    if(mask&(1<<j)){
                        nextmask |= (1<<j);
                        if(curr&1){
                            flag = false;
                            break;
                        }
                    }
                    else{
                        curr++;
                    }
                }
            }
            if(curr&1)  flag = false;  
 
            if(flag){
                is[currmask].push_back(nextmask);
            }
        }
    }
 
 
    
    int ans = 0;
    
    for(int i = 0 ; i < (1<<n) ; i++){
 
        int curr = 0;
        bool flag = true;
 
        int mask = 0;
 
        for(int j = 0 ; j < n ; j++){
            if(!(i&(1<<j))){
                curr++;
            }
            else{
 
                mask |= (1<<j);
 
                if(curr&1){
                    flag = false;
                }
                else{
                    curr = 0;
                }
 
            }
        }
        
        if(curr&1) flag = false;
        
        if(flag){
            ans = (ans + 0LL + helper(1,mask))%mod;
        }
    }
    
    cout << ans << endl;
    
}
