#include <bits/stdc++.h>
#define $ ios::sync_with_stdio(0);

using namespace std;
using ll = long long int;

const int MAXN = 1E+2 + 5;
const int MAXX = 1E+6 + 5;
const int MOD = 1E+9 + 7;
const int INF = 1E+9 + 7;

// Checar Overflow
// Checar acesso em posição inválida
// Checar casos de borda
// Checar TLE

int vec[MAXN];
int dp[MAXX];
int v[MAXX];

int n, x;

int solve(int sum){
    if(sum==0){
        return 1;
    }
    if(v[sum]){
        return dp[sum];
    }

    dp[sum] = 0;
    v[sum] = 1; 

    for(int i = 0; i<n; i++){
        if(sum - vec[i] >= 0){
            dp[sum] += solve(sum - vec[i]);
            dp[sum] %= MOD;
        }
    }

    return dp[sum];
}

void solve2(int x){
    dp[0] = 1;

    for(int i = 1; i<=x; i++) dp[i] = 0;

    for(int sum = 1; sum<=x; sum++){
        for(int i = 0; i<n; i++){
            if(sum - vec[i] >= 0){
                dp[sum] += dp[sum - vec[i]];
                dp[sum] %= MOD;
            }
        }   
    }
}



int main(){
    $
    cin>>n>>x;

    for(int i = 0; i<n; i++){
        cin>>vec[i];
    }

    solve2(x);

    cout<<dp[x]<<"\n";
    
    return 0;
}