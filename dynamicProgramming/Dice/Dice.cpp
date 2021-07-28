#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e+6 + 5;
const int MOD = 1e+9 + 7;

int dp[MAXN];
int v[MAXN];

int solve(int n){
    if(n == 0){
        return 1;
    }
    if(v[n]){
        return dp[n];
    }

    dp[n] = 0;
    v[n] = 1;

    for(int i = 1; i<=6; i++){
        if(n - i >= 0){
            dp[n] += solve(n-i);
            dp[n] %= MOD;
        }
    }

    return dp[n];
}

void solve2(int n){
    dp[0] = 1;

    for(int i = 1; i<=n; i++){
        dp[i] = 0;
    }

    for(int sum = 1; sum<=n; sum++){
        for(int i = 1; i<=6; i++){
            if(sum - i >= 0){
                dp[sum] += dp[sum-i];
                dp[sum] %= MOD;
            }
        }
    }
}


int main(){
    ios::sync_with_stdio(0);
    int n;
    cin>>n;

    solve2(n);
    
    cout<<dp[n]<<'\n';
    return 0;
}