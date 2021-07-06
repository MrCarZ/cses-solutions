#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

const ll MAXN = 1E+6;
const ll MOD = 1E+9 + 7;

ll dice[] = {1, 2, 3, 4, 5, 6};

vector<ll> ans(MAXN+1, 0);

ll count_ways(int n){
    
    ans[0] = 1;
    for(int i = 1; i<=n; i++){
        for(int j = 0; j<6;j++){
            if(i >= dice[j]){
                ans[i] += ans[i - dice[j]] % MOD;
            }
        }
    }
    return ans[n];
}

int main(){
    ll n;

    cin>>n;

    ll ans = count_ways(n);

    cout<<ans % MOD<<'\n';
    return 0;
}