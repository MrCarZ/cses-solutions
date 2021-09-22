#include <bits/stdc++.h>

using namespace std;

const int MAXSIDE = 5E+2 + 5;
const int INF = 1E+9 + 7;

int dp[MAXSIDE][MAXSIDE], v[MAXSIDE][MAXSIDE];
int h, w;

int solve(int a, int b){
    if(a == b){
        return 0;
    }
    if(v[a][b] == 1){
        return dp[a][b];
    }

    v[a][b] = 1;
    int ans = INF;

    if(a > b){
        ans = min(solve(a-b, b)+1, ans);
    }
    else{
        ans = min(solve(a, b-a)+1, ans);
    }
    
    return dp[a][b] = ans;
}


int main(){
    ios::sync_with_stdio(0);
    cin>>h>>w;

    cout<<solve(h, w)<<'\n';
    return 0;
}