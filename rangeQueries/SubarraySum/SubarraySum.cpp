#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e+5;
const int INF = 1e+9;

struct Vertex{
    long long int pref;
    long long int suf;
    long long int sum;
    long long int ans;

    Vertex(){};
    Vertex(int _value): pref(_value), suf(_value), sum(_value), ans(_value) {};
};

Vertex t[4*MAXN];

Vertex combine( Vertex l, Vertex r){
    Vertex c;
    c.sum = l.sum + r.sum;
    c.pref = max({l.sum+r.pref, l.pref});
    c.suf = max(l.suf + r.sum, r.suf); 
    c.ans= max({c.sum, c.pref, c.suf, l.suf+r.pref, l.ans, r.ans});
    return c;
}

void build(vector<int>& a, int v, int tl, int tr){
    if(tl == tr){
        t[v] = Vertex(a[tl]);
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
        t[v] = Vertex(value);
    }
    else{
        int tm = (tl+tr)/2;
        if(pos <= tm) update(2*v, tl, tm, pos, value);
        else update(2*v+1, tm+1, tr, pos, value);
        t[v] = combine(t[2*v], t[2*v+1]);
    }   
}

int main(){
    ios::sync_with_stdio(0);
    int n, q, k, x;

    cin>>n>>q;

    vector<int> vec(n);

    for(int i = 0; i<n; i++){
        cin>>vec[i];
    }

    build(vec, 1, 0, n-1);

    for(int i = 0; i<q; i++){
        cin>>k>>x;
        k--;
        update(1, 0, n-1, k, x);
        
        if(t[1].ans >= 0) cout<<t[1].ans<<'\n';
        else cout<<0<<'\n';
    }
    return 0;
}