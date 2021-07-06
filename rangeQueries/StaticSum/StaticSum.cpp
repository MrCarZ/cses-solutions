#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e+5;

long long int t[4*MAXN];

void build(vector<int>& a, int v, int tl, int tr){
    if(tl == tr) t[v] = a[tl];
    else{
        int tm = (tr+tl)/2;
        build(a, 2*v, tl, tm);
        build(a, 2*v+1, tm+1, tr);
        t[v] = t[2*v]+t[2*v+1];
    }
}

long long int query(int v, int tl, int tr, int l, int r){
    if(l > r || tl > tr){
        return 0;
    }
    if(tl == l && tr == r){
        return t[v];
    }
    int tm = (tl+tr)/2;
    return query(2*v, tl, tm, l, min(r,tm)) + query(2*v+1, tm+1, tr, max(tm+1, l), r);
}

void update(int v, int tl, int tr, int pos, int value){
    if(tl == tr){
        t[v] = value;
    }
    else{
        int tm = (tr+tl)/2;
        if(tm >= pos){
            update(2*v, tl, tm, pos, value);
        }
        else{
            update(2*v+1, tm+1, tr, pos, value);
        }
        t[v] = t[2*v] + t[2*v+1];
    }
}


int main(){
    ios::sync_with_stdio(0);
    int n,op, k, u, q, l, r;
    cin>>n>>q;

    vector<int> vec(n);

    for(int i = 0; i<n; i++){
        cin>>vec[i];
    }

    build(vec, 1, 0, n-1);

    for(int i = 0; i<q; i++){
        cin>>op;
        if(op == 1){
            cin>>k>>u;
            k--;
            update(1, 0, n-1, k, u);
        }
        if(op == 2){
            cin>>l>>r;
            l--; r--;
            cout<<query(1, 0, n-1, l, r)<<endl;
        }
    }
}