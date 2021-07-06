#include <bits/stdc++.h>
 
using namespace std;
 
const int MAXN = 2e+5;
 
long long int t[4*MAXN];
long long int lazy[4*MAXN];

void push(int v){
    if(lazy[v]){
        t[2*v] += t[v];
        t[2*v+1] += t[v];
        lazy[2*v] = lazy[2*v+1] = t[v];
        lazy[v] = 0;
        t[v] = 0;
    }
}
 
void build(vector<int>& a, int v, int tl, int tr){
    if(tl == tr) t[v] = a[tl];
    else{
        int tm = (tr+tl)/2;
        build(a, 2*v, tl, tm);
        build(a, 2*v+1, tm+1, tr);
        t[v] = 0;
    }
}
 
void update(int v, int tl, int tr, int l, int r, int k){
    if(l > r) return ;
    if(tl == l && tr == r){
        t[v] += k;
        lazy[v] = k;
    }
    else{
        push(v);
        int tm = (tl+tr)/2;
        update(2*v, tl, tm, l, min(r, tm), k);
        update(2*v+1, tm+1, tr, max(l, tm+1), r, k);
    }
}
 
long long int query(int v, int tl, int tr, int pos){
    if(tl == tr){return t[v];}
    else{
        push(v);
        int tm = (tl+tr)/2;
        if(tm >= pos){
            return query(2*v, tl, tm, pos);
        }
        else{
            return query(2*v+1, tm+1, tr, pos);
        }
    }
}
 
 
int main(){
    ios::sync_with_stdio(0);
    int n, q, op, l, r, k;
 
    cin>>n>>q;
 
    vector<int> vec(n);
 
    for(int i = 0; i<n; i++){
        cin>>vec[i];
    }
 
    build(vec, 1, 0, n-1);
 
    for(int i = 0; i<q; i++){
        cin>>op;
        if(op ==1){
            cin>>l>>r>>k;
            l--;r--;
            update(1, 0, n-1, l, r, k);
        }
        if(op == 2){
            cin>>k;
            k--;
            cout<<query(1, 0, n-1, k)<<endl;
        }
    }
    return 0;
}   