#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e+2 + 5;
const int MAXSUM = 1e+5 + 5;

int n, vec[MAXN], dp[MAXN][MAXSUM], v[MAXN][MAXSUM];

int solve(int st, int sum){
    if(st == n){
        return sum == 0;
    }
    if(v[st][sum] == 1){
        return dp[st][sum];
    }

    v[st][sum] = 1;

    int ans = 0;

    ans |= solve(st+1, sum);
    
    if(sum - vec[st] >= 0) ans |= solve(st+1, sum-vec[st]);

    return dp[st][sum] = ans;
}



int main(){
    ios::sync_with_stdio(0);
    cin>>n;

    int full_sum = 0;

    for(int i = 0; i <n; i++){
        cin>>vec[i];
        full_sum += vec[i];
    }

    vector<int> ans;

    for(int i = 1; i<= full_sum; i++){
        int aux = solve(0, i);
        if(aux == 1){
            ans.push_back(i);
        }
    }
    
    cout<<ans.size()<<'\n';
    
    bool yes = 0;
    for(int i = 0; i<ans.size(); i++){
        if(yes) cout<<' ';
        cout<<ans[i];
        yes = 1;
    }
    cout<<'\n';

    return 0;
}