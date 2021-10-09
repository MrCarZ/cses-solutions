#include<bits/stdc++.h>

using namespace std;
using ll = long long int;

const int MAXN = 20;
const int MAXSIZE = (1 << MAXN) + 2;
const int INF = 1E+9 + 7;

int vec[MAXN], n, w;
int v[MAXSIZE];
pair<int,int> dp[MAXSIZE];

pair<int,int> solve(int mask){
    if(mask == 0){
        return {1, w};
    }
    if(v[mask] == 1){
        return dp[mask];
    }

    v[mask] = 1;

    pair<int,int> ans = {INF,w};
    
    for(int i = 0; i<n; i++){
        if(((1<<i)&mask) > 0){
            pair<int,int> sol = solve(mask^(1<<i));
            if(sol.second - vec[i] >= 0){
                if(ans.first > sol.first){
                    ans.first = sol.first;
                    ans.second = sol.second - vec[i];
                }
                if(ans.first == sol.first){
                    ans.second = max(ans.second, sol.second-vec[i]);
                } 
            }
            else{
                if(ans.first > 1+sol.first){
                    ans.first = 1+sol.first;
                    ans.second = w-vec[i];
                }
                if(ans.first == 1+sol.first){
                    ans.second = max(ans.second, w-vec[i]);
                }
            } 
        }
    }

    return dp[mask] = ans;
}

int main(){
    ios::sync_with_stdio(0);
    cin>>n>>w;

    for(int i = 0; i<n; i++){
        cin>>vec[i];
    }

    cout<<solve(((1<<n)-1)).first<<'\n';

    return 0;
}