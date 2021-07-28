#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1E+2 + 5;
const int MAXX = 1E+6 + 5;
const int INF = 1E+9;

int n, x;
int vec[MAXN];
int dp[MAXX];
int v[MAXX];

int solve(int sum){
    if(sum == 0){
        return 1;
    }
    if(v[sum]){
        return dp[sum];
    }

    dp[sum] = INF;
    v[sum] = 1;

    for(int i = 0; i<n; i++){
        if(sum - vec[i] >= 0){
            dp[sum] = min(solve(sum - vec[i])+1, dp[sum]);
        }
    }

    return dp[sum];
}

void solve2(int x){
    dp[0] = 1;

    for(int i = 1; i<=x; i++){
        dp[i] = 0;
    }

    for(int sum = 1; sum<=x; sum++){
        dp[sum] = INF;
        for(int i = 0; i<n; i++){
            if(sum - vec[i] >= 0){
                dp[sum] = min(dp[sum - vec[i]]+1, dp[sum]);
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin>>n>>x;

    for(int i = 0; i<n; i++){
        cin>>vec[i];
    }

    solve2(x);

    if(dp[x] == INF){
        cout<<-1<<'\n';
    }
    else{
        cout<<dp[x]-1<<'\n';
    }

    return 0;
}

