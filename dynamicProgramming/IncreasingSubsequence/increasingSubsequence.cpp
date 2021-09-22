#include<bits/stdc++.h>

using namespace std;

const int MAXN = 2E+5 + 5;
const int MAXX = 1E+9 + 7;

int n, vec[MAXN],vec2[MAXN],dp[MAXN];

vector<int> fenwick(MAXN, 0);

void add(int pos, int val){
    for(int i = pos; i<=n; i+=i&(-i)){
        fenwick[i] = max(val, fenwick[i]);
    }
}

int get(int pos){
    int ans = -MAXX;
    for(int i = pos; i>0; i-=i&(-i)){
        ans = max(ans, fenwick[i]);
    }

    return ans;
}

int main(){
    ios::sync_with_stdio(0);

    cin>>n;

    map<int,int> comp;
   

    for(int i = 1; i<=n; i++){
        cin>>vec[i];
        vec2[i] = vec[i];
    }
    
    sort(vec2, vec2+n+1);
    int counter = 1;
    for(int i = 1; i<=n; i++){
        if(comp[vec2[i]] == 0){
            comp[vec2[i]] = counter++;
        }
    }
    
    for(int i = 1; i<=n; i++) {vec[i] = comp[vec[i]];}

    int ans = -MAXX;

    for(int i = 1; i<=n; i++){
        dp[i] = 1;
        dp[i] = max(get(vec[i]-1)+1, dp[i]); 
        add(vec[i], dp[i]);
        ans = max(ans, dp[i]);   
    }

    cout<<ans<<'\n';
    return 0;
}