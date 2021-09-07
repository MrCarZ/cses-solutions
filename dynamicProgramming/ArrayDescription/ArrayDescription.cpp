#include<bits/stdc++.h>
 
using namespace std;
 
const int MAXN = 1E+5 + 5;
const int MAXM = 1E+2 + 5;
const int MOD = 1E+9 + 7;
 
int n, m;
int vec[MAXN], dp[MAXM][MAXN], v[MAXM][MAXN];
 
int solve(int prev, int st){
    if(st == n){
        return 1;
    }
    if(v[prev][st] == 1){
        return dp[prev][st];
    }
 
    v[prev][st] = 1;
 
    int ans = 0; 
    if(vec[st] == 0){
        if(st == 0){
            for(int i = 1; i<=m; i++){
                ans += solve(i, st+1);
                ans %= MOD;
            }
        }
        else{
            for(int i = max(prev-1, 1); i<=min(prev+1, m); i++){
                ans += solve(i, st+1);
                ans %= MOD;
            }
        }
    }
    else{
        if(abs(prev-vec[st]) <= 1 || (st == 0)){
            ans += solve(vec[st], st+1);
            ans %= MOD;
        }
    }
 
    return dp[prev][st] = ans;
}
 
 
 
int main(){
    ios::sync_with_stdio(0);
    cin>>n>>m;
 
    for(int i = 0; i<n; i++) cin>>vec[i];
 
    cout<<solve(0, 0)<<'\n';
 
}