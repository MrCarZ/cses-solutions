#include <bits/stdc++.h>

using namespace std;
using ll = long long int;

const int MAXN = 5E+3 + 5;

ll n, vec[MAXN], dp[MAXN][MAXN], v[MAXN][MAXN]; 


ll solve(int l, int r){
    if(r-l+1 == 1){
        return vec[r];
    }
    if(v[l][r] == 1){
        return dp[l][r];
    }
    v[l][r] = 1;

    ll ans = max(vec[r] - solve(l, r-1), vec[l] - solve(l+1, r));   

    return dp[l][r] = ans;
}


int main(){
    ios::sync_with_stdio(0);
    cin>>n;
    ll val = 0;

    for(int i = 0; i<n; i++){
        cin>>vec[i];
        val += vec[i];
    }

    cout<<((solve(0, n-1) + val) >> 1)<<'\n';
    return 0;
}