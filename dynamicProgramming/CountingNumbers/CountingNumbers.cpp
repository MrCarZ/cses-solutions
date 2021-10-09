#include<bits/stdc++.h>

using namespace std;

using ll = long long int;

const int MAXDIGIT = 18 + 2;

vector<ll> A(MAXDIGIT), B(MAXDIGIT), C(MAXDIGIT);

ll dp[19][11][3][3][3], v[19][11][3][3][3];
string a, b, current;

ll solve(int n, int previous, int upper, int zeros, int diffs){
    if(n == current.size()){
        return diffs != 0;
    }
    if(v[n][previous][upper][zeros][diffs] == 1){
        return dp[n][previous][upper][zeros][diffs]; 
    }

    v[n][previous][upper][zeros][diffs] = 1;
    ll ans = 0;
    
    for(int i = (upper ? (int)(current[n] - '0') : 9); i >= 0; i--){
        ans += solve(n+1, i, upper&(i == (current[n] - '0')), zeros&(i == 0), diffs|(previous == i && !zeros));
    }
    
    return dp[n][previous][upper][zeros][diffs] = ans;
}

ll init(string digit){
    current = digit;
    memset(v, 0, sizeof(v));
    
    return solve(0, 0, 1, 1, 0);
}


int main(){

    cin>>a>>b;
 
    ll pot10 = 1;
    ll valA = 0;
    ll valB = 0;

    for(int i = a.size()-1; i >= 0; i--){
        valA += pot10*(a[i] - '0');
        pot10 *= 10LL;
    }

    pot10 = 1;
    for(int i = b.size()-1; i>=0; i--){
        valB += pot10*(b[i] - '0');
        pot10 *= 10LL;
    }

    ll ans = init(b) - init(a);
    
    ll condition = 0;

    for(int i = 0; i<a.size()-1; i++){
        condition |= (a[i] == a[i+1]); 
    }

    cout<<(valB-valA+1)-ans-condition<<'\n';

    return 0;
}