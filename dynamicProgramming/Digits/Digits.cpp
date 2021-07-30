#include <bits/stdc++.h>

using namespace std;

const int INF = 1E+9 + 7;
const int MAXN = 1e+6 + 5;

int dp[MAXN];
int v[MAXN];

int solve(int sum){
    if(sum == 0){
        return 1;
    }
    
    if(v[sum] == 1){
        return dp[sum];
    }

    v[sum] = 1;
    
    int ans = INF;
    int remain = sum;
    int num;

    for(int i = 0; i<7; i++){
        num = remain%10;
        remain -= num;
        remain /= 10;
        if(num > 0 && sum - num >= 0){
            ans = min(solve(sum-num)+1, ans);
        }
    }


    return dp[sum] = ans;
}


void solve2(int n){
    dp[0] = 1;

    for(int sum = 0; sum <= n; sum++){
        int ans = INF;
        int remain = sum;
        int num;

        for(int i = 0; i<7; i++){
            num = remain%10;
            remain -= num;
            remain /= 10;
            if(num > 0 && sum - num >= 0){
                ans = min(dp[sum-num]+1, ans);
                dp[sum] = ans; 
            }
        }
    } 
}


int main(){
    ios::sync_with_stdio(0);
    int n;

    cin>>n;
    
    solve2(n);

    cout<<dp[n]-1<<"\n";
    
    return 0;
}