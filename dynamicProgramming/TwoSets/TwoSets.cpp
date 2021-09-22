#include<bits/stdc++.h>

using namespace std;
using ll = long long int;

const int MAXSUM = 130000;
const int MAXN = 5E+2 + 5;
const ll MOD = 1E+9 + 7;

ll n;
ll full_sum;
ll mid_point;
ll dp[2][MAXSUM];

void solve(){
    dp[(n+1)&1][mid_point] = 1;

    for(int i = 0; i<=full_sum; i++){
        if(i != mid_point) dp[(n+1)&1][i] = 0;
    }

    for(int st = n; st>=0; st--){
        for(int sum = 0; sum <= full_sum; sum++){
            dp[st&1][sum] = 0;
            if(sum+st <= full_sum) {
                dp[st&1][sum] += dp[(st+1)&1][sum+st];
                dp[st&1][sum] %= MOD;
            }
            if(sum-st >= 0){
                dp[st&1][sum] += dp[(st+1)&1][sum-st];
                dp[st&1][sum] %= MOD;
            }
        }
    }

}

int extended(int a, int b, int& x, int& y){
    if(b == 0){
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = extended(b, a%b, x1, y1); 
    x = y1;
    y = x1 - y1*(a/b);
    return d;
}


int main(){
    ios::sync_with_stdio(0);
    cin>>n;
    
    full_sum = ((n+(ll)1)*n) >> (ll)1; 
    mid_point = ((n+(ll)1)*n) >> (ll)2; 

    solve();

    int x, y;
    
    int g = extended(2, MOD, x, y);
    
    if(g == 1){
        x = (x % MOD+MOD) % MOD;
        cout<<((dp[1][mid_point]*x) % MOD)<<'\n';
    }

    return 0;
}
