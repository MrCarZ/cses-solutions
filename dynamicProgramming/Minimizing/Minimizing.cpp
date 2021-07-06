#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1E+6;
const int INF = 1E+9 + 7;

vector<int> dp(MAXN+1, -1);
vector<int> vec(1E+2 +1, 0);

int solve(int sum, int n){
    if(sum == 0) return 0;
    if (dp[sum] != -1) return dp[sum];

    int ans = INF;

    for(int i = 0; i<n; i++){
        int pos = sum - vec[i];
        if(pos >= 0){
            ans = min(solve(sum - vec[i], n) + 1, ans);
        }
    }

    dp[sum] = ans;

    return dp[sum];
}


int main(){
    ios::sync_with_stdio(0);
    int n, c;

    cin>>n>>c;
    
    for(int i = 0; i<n; i++) cin>>vec[i];
    
    dp[0] = 0;
    
    int ans = solve(c,n);

    if(ans != INF){
        cout<<ans<<'\n';
    }
    else{
        cout<<-1<<'\n';
    }

    return 0;
}
