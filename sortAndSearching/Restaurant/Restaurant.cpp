#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2E+5;

int main(){
    ios::sync_with_stdio(0);
    int n, a, b;

    cin>>n;

    vector<pair<int,int>> intervalo;
    for(int i = 0; i<n; i++) {
        cin>>a>>b; 
        intervalo.push_back({a, 1});
        intervalo.push_back({b,-1});
    }

    sort(intervalo.begin(), intervalo.end());

    int ans = 0;
    int ans_mesmo = 0;

    for(int i = 0; i<=2*n; i++){
       ans += intervalo[i].second;
       ans_mesmo = max(ans, ans_mesmo);
    }

    cout<<ans_mesmo<<'\n';

    return 0;
}