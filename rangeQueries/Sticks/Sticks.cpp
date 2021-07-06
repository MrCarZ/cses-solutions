#include <bits/stdc++.h>

using namespace std;
using ll = long long int;

const int MAXN = 2E+5;

int main(){
    ios::sync_with_stdio(0);
    int n;

    cin>>n;

    vector<int> vec(MAXN, 0);
    ll med;
    for(int i = 0; i<n; i++){
        cin>>vec[i];
        med += vec[i];
    }

    med /= n;
    ll ans = 0;
    for(int i = 0; i<n; i++){
        ans += abs(vec[i]-med);
    }

    cout<<ans<<'\n';

    return 0;
}