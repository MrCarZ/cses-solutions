#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2E+5;

vector<int> pos(MAXN+1, 0);

int solve(int l, int r){
    if(l >= r) return 0;

    int ans = 0;
    int mid = l+r >> 1;
    
    ans += solve(l, mid);
    ans += solve(mid+1, r);

    if(pos[mid] > pos[mid+1]){
        ans++;
    }

    return ans;
}


int main(){
    ios::sync_with_stdio(0);
    int n;

    cin>>n;

    vector<int> vec(MAXN+1, 0);

    for(int i = 0; i<n; i++){
        cin>>vec[i];
        vec[i]--;
        pos[vec[i]] = i;
    }

    cout<<solve(0, n-1) + 1<<'\n';
    
    return 0;
}