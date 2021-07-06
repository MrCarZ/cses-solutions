#include <bits/stdc++.h>
#define $ ios::sync_with_stdio(0);

using namespace std;
using ll = long long int;

const int MAXN = 1E+6 + 12;
const int MOD = 1E+9 + 7;
const int INF = 1E+9 + 7;

// Checar Overflow
// Checar acesso em posição inválida
// Checar casos de borda
// Checar TLE

ll dp[MAXN];
ll v[MAXN];
int vec[105];
int n;

ll solve(int sum){
    if(sum == 0) return 1;
    if(v[sum]) return dp[sum] % MOD;

    dp[sum] = 0;
    

    for(int i = 0; i<n; i++){
        int pos = sum - vec[i];
        if(pos >= 0) {
            dp[sum] = (dp[sum] + (solve(pos))) % MOD;        
            v[sum] = 1;
        }
    }

    return dp[sum] % MOD;
}

int main(){$
    int c;
    cin>>n>>c;

    for(int i = 0; i<n; i++){ 
        cin>>vec[i];
    }

    v[0] = 1;

    ll ans = solve(c);

    cout<<ans % MOD<<'\n';

    return 0;
}