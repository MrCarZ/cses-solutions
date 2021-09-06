#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1E+3 + 5;
const int MOD = 1E+9 + 7;

int n;
int vec[MAXN][MAXN], dp[MAXN][MAXN], v[MAXN][MAXN];

int solve(int down, int right){
    if(down == 1 && right == 1){
        return !vec[down][right];
    }
    if(v[down][right] == 1){
        return dp[down][right];
    }

    v[down][right] = 1;
    int ans = 0;

    if(down-1 >= 1 && !vec[down-1][right]){
        ans += solve(down-1, right);
        ans %= MOD;
    }
    if(right-1 >= 1 && !vec[down][right-1]){
        ans += solve(down, right-1);
        ans %= MOD;
    }

    return dp[down][right] = ans % MOD;
}


int main(){
    ios::sync_with_stdio(0);
    cin>>n;

    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=n; j++){
            char aux;
            cin>>aux;
            vec[i][j] = (aux == '*');
        }
    }
    if(vec[n][n]){
        cout<<0<<'\n';
    }
    else{
        cout<<solve(n,n)<<'\n';
    }
    return 0;
}