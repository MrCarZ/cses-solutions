#include <bits/stdc++.h>

using namespace std;
const int MAXN = 2E+5;
const int INF = 1E+9;

int main(){
    int n;

    cin>>n;

    vector<int> vec(MAXN, 0);
    vector<int> pos(MAXN, 0);
    
    for(int i = 0; i< n; i++)
    {
        cin>>vec[i];
        pos[vec[i]] = i;
    }
    int ans = 1;

    for(int i = 1; i<=n; i++){
        if(pos[i] < pos[i-1]) ans++;    
    }

    cout<<ans<<'\n';

    return 0;
}