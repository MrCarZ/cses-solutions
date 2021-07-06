#include <bits/stdc++.h>
#define ll long long int
using namespace std;

const int MAXN = 2e+5;

int main(){
    ios::sync_with_stdio(0);
    int n, x;

    cin>>n>>x;

    vector<int> vec(MAXN,0);
    
    for(int i = 0; i<n; i++) cin>>vec[i];

    sort(vec.begin(), vec.begin()+n);

    int p1 = 0;
    int p2 = n-1;

    int ans = 0;

    ll aux1;

    while(p1 <= p2){
        aux1 = vec[p2] + vec[p1]; 
        if(aux1 <= x){
            p1++;
        }
        ans++;
        p2--;
    }

    cout<<ans<<'\n';

    return 0;
}