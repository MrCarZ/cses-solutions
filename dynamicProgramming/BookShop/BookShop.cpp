#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1E+3 + 5;
const int MAXSUM = 1E+5 + 5;
const int INF = 1E+9 + 7;

int price[MAXN], pages[MAXN], dp[MAXN][MAXSUM];
int n, x;

void solve2(){
    dp[n][0] = 0;
    for(int i = 1; i<=x; i++){
        dp[n][i] = -INF;
    }
    for(int st = n-1; st >= 0; st--){
        for(int sum = 0; sum <= x; sum++){
            int ans = 0;
            if(sum - price[st] >= 0){
                ans = max(dp[st+1][sum-price[st]]+pages[st], ans);
            }
            ans = max(dp[st+1][sum], ans);
            dp[st][sum] = ans;
        }
    }
}


int main(){
    ios::sync_with_stdio(0);
    cin>>n>>x;
    for(int i = 0; i<n; i++) cin>>price[i];
    for(int i = 0; i<n; i++) cin>>pages[i];    
    solve2(); 
    
    int ans = 0;

    for(int i = 1; i<=x; i++){
        ans= max(dp[0][i], ans);
    }

    cout<<ans<<'\n';
    return 0;
}