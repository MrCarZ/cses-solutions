#include <bits/stdc++.h>

using namespace std;
using ll = long long int;

const int MAXN = 2E+5;

int main(){
    ios::sync_with_stdio(0);
    int n;

    cin>>n;

    vector<int> vec(MAXN, 0);
    ll med = 0;
    for(int i = 0; i<n; i++){
        cin>>vec[i];
    }
    sort(vec.begin(), vec.begin()+n);
    
    int mid = (n-1 >> 1);    
    
    if(n%2 == 0){
        med = vec[mid+1] + vec[mid-1] >> 1; 
    }
    else{
        med = vec[mid];
    }

    ll ans = 0;
    for(int i = 0; i<n; i++){
        ans += abs(vec[i]-med);
    }

    cout<<ans<<'\n';

    return 0;
}