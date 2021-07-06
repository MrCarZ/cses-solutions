#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e+5;


int main(){
    ios::sync_with_stdio(0);
    int n;
    cin>>n;

    vector<pair<int,int>> vec(MAXN, {0,0});
    for(int i = 0; i< n; i++){
        cin>>vec[i].second>>vec[i].first;
    }

    sort(vec.begin(), vec.begin()+n);

    int ans = 1;
    int aux = vec[0].first;
    for(int i = 1; i<n; i++){
        if(aux <= vec[i].second){
            ans++;
            aux = vec[i].first;
        }
    }
    cout<<ans<<'\n';
    return 0;
}