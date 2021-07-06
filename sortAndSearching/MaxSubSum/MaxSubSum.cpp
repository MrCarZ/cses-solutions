#include <bits/stdc++.h>
#define ll long long int
using namespace std;

const ll MAXN = 2E+5;
const ll INF = 1E+15;

ll sol(vector<ll>& arr, int l, int r){
    if(l > r) return -INF;

    if(r == l) return arr[l];

    int mid = l+r >> 1;

    ll ans = -INF;
    ans = max(ans,sol(arr, l, mid));
    ans = max(ans, sol(arr, mid+1, r));

    ll msum = arr[mid];
    ll lsum = 0; 
    ll bestl = 0;
    ll rsum = 0; 
    ll bestr = 0;

    for(int i = mid+1; i<=r; i++){
        lsum += arr[i];
        bestl = max(bestl, lsum);
    }
    for(int i = mid-1; i>=l; i--){
        rsum += arr[i];
        bestr = max(bestr, rsum);
    }

    ans = max(ans, msum + bestr + bestl);
    return ans;
}


int main(){
    ios::sync_with_stdio(0);
    int n;
    cin>>n;
    vector<ll> vec(MAXN+1, 0);

    for(int i = 1; i<=n; i++){
        cin>>vec[i];
    }

    ll ans = sol(vec, 1, n); 

    cout<<ans<<'\n';
    return 0;
}