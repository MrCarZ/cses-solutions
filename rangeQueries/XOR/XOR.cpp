#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e+5;

int t[4*MAXN];

void build(vector<int>& a, int v, int tl, int tr){
    if(tl == tr) t[v] = a[tl];
    else{
        int tm = (tl+tr)/2;
        build(a, 2*v, tl, tm);
        build(a, 2*v+1, tm+1, tr);
        t[v] = t[2*v] ^ t[2*v+1];
    }
}

int query(int v, int tl, int tr, int l, int r){
    if(l > r || tl > tr) return 0;
    if(tl == l && tr == r) return t[v];
    int tm = (tl + tr)/2;
    return query(2*v, tl, tm, l, min(r, tm)) ^ query(2*v+1, tm+1, tr, max(l, tm+1), r);
}


int main(){
    int n, q, r, l;

    scanf("%d %d", &n, &q);

    vector<int> vec(MAXN);

    for(int i = 0; i<n; i++){
        int aux;
        scanf("%d", &aux);
        vec[i] = aux;
    }

    build(vec, 1, 0, n-1);

    for(int i = 0; i<q; i++){
        scanf("%d %d", &l, &r);
        l--; r--;
        int ans = query(1, 0, n-1, l, r);
        printf("%d\n", ans);
    }

    return 0;
}