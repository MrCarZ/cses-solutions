#include <bits/stdc++.h>

using namespace std;


struct leaf{
    long long int sum;
    long long int pref;
    long long int suf;
    long long int ans;
};

const int MAXN = 2e+5;

leaf t[4*MAXN];

leaf newleaf(int value){
    leaf a;
    a.sum = a.ans = a.pref = a.suf = value;
    return a;
}

// NAO FAZ SENTIDO:

// l.prefix + r.suf
// l.prefix + r.sum suf + sum
// 


leaf combine(leaf l, leaf r){
    leaf c;
    c.sum = r.sum + l.sum;
    c.pref = max(l.sum + r.pref, l.pref);
    return c;
}


void build(vector<int>& a, int v, int tl, int tr){
    if(tl == tr){
        t[v] = newleaf(a[tl]); 
    }
    else{
        int tm = (tl+tr)/2;
        build(a, 2*v, tl, tm);
        build(a, 2*v+1, tm+1, tr);
        t[v] = combine(t[2*v], t[2*v+1]);
    }
}

void update(int v, int tl, int tr, int pos, int value){
    if(tl == tr){
        t[v] = newleaf(value);
    }
    else{
        int tm = (tl+tr)/2;
        if(tm >= pos) update(2*v, tl, tm, pos, value);
        else update(2*v+1, tm+1, tr, pos, value);
        t[v] = combine(t[2*v], t[2*v+1]);
    }
}


leaf query(int v, int tl, int tr, int l, int r){
    if(l > r){
        leaf a;
        a.sum = a.ans = a.pref = a.suf = 0;
        return a;
    }
    if(tl == l && tr == r){
        return t[v];
    }
    int tm = (tl+tr)/2;
    leaf p1 = query(2*v, tl, tm, l, min(r, tm));
    leaf p2 = query(2*v+1, tm+1, tr, max(l, tm+1), r);
    if (p1.pref == 0) return p2;
    if (p2.pref == 0) return p1;
    return combine(p1 , p2);
}


int main(){
    ios::sync_with_stdio(0);
    int n, q;
    int l, r, op;

    cin>>n>>q;

    vector<int> vec(n);

    for(int i=0; i<n; i++) cin>>vec[i];

    build(vec, 1, 0, n-1);
    for(int i = 0; i<q;i++){
        cin>>op;
        if(op == 1){
            cin>>l>>r;
            l--;
            update(1, 0, n-1, l,r);
        }
        if(op == 2){
            cin>>l>>r;
            l--;r--;
            cout<<max(query(1, 0, n-1, l, r).pref, (long long int) 0)<<endl;
        }
    }
    return 0;
}