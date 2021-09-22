#include <bits/stdc++.h>

using namespace std;

const int MAXN = 5E+3 + 5;
const int INF = 1E+9 + 5;
string n, m;

int dp[MAXN][MAXN], v[MAXN][MAXN];

int solve(int i, int j){
    if(i == n.size() && j == m.size()){
        return 0;
    }
    if(i == n.size() && m.size() > j){
        return m.size() - j;
    }
    if(j == m.size() && n.size() > i){
        return n.size() - i;
    }
    if(v[i][j] == 1){
        return dp[i][j];
    }

    v[i][j] = 1;
    int ans = INF;

    
    ans = min(solve(i+1, j+1)+1 , ans); // replace current different letters by one
    ans = min(solve(i, j+1)+1 , ans);   // ignore current letter in second array in order to delete it
    ans = min(solve(i+1, j)+1 , ans);   // ignore current letter in first array in order to delete it
    


    if(n[i] == m[j]){
        ans = min(solve(i+1, j+1), ans);
    }

    return dp[i][j] = ans;
}


int main(){
    ios::sync_with_stdio(0);
    cin>>n>>m;
    
    if(n.size() > m.size()){
        swap(n, m);
    }

    cout<<solve(0, 0)<<'\n';
    
    return 0;
}