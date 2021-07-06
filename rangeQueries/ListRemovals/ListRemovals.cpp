#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e+5;

pair<int,int> t[4*MAXN];

void build(vector<int>& a, int v, int tl, int tr){
    if(tl == tr) {
        t[v].first = a[tl];
        t[v].second = 1;
    }
    else{
        int tm = (tr+tl)/2;
        build(a, 2*v, tl, tm);
        build(a, 2*v+1, tm+1, tr);
        t[v].second = t[2*v].second + t[2*v+1].second;
    }
}

void update(int v, int tl, int tr, int pos){
    if(tl == tr) t[v].second = 0;  
    else{
        int tm = (tr+tl)/2;
        if(pos <= t[2*v].second) update(2*v, tl, tm, pos);
        else update(2*v+1, tm+1, tr, pos-(t[2*v].second));
        t[v].second = t[2*v].second + t[2*v+1].second;;
    }
}

int query(int v, int tl, int tr, int pos){
    if(tl == tr) return t[v].first;
    int tm = (tr+tl)/2;
    if(pos <= t[2*v].second) return query(2*v, tl, tm, pos); 
    else return query(2*v+1, tm+1, tr, pos-(t[2*v].second));
}

int main(){
    ios::sync_with_stdio(0);

    int n,k, y=0;
    cin>>n;
    vector<int> vec(MAXN), ans(MAXN);

    for(int i = 0; i<n; i++){
        cin>>vec[i];
    }

    build(vec, 1, 0, n-1);

    for(int i = 0; i<n; i++){
        cin>>k;
        ans[i] = query(1, 0, n-1, k);
        update(1, 0, n-1, k);
    }

    for(int  i = 0; i<n; i++){
        if(y) cout<<" ";
        cout<<ans[i];
        y=1;
    }
    cout<<endl;

    return 0;
}