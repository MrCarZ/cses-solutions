#include <bits/stdc++.h>

using namespace std;
 
const int MAXN = 2e+5;
pair<int,int> t[4*MAXN];

void build(vector<int>& a, int v, int tl, int tr){
    if( tl == tr){
        t[v].first = a[tl];
        t[v].second = tl+1;
    }
    else{
        int tm = (tr+tl)/2;
        build(a, 2*v, tl, tm);
        build(a, 2*v+1, tm+1, tr);
        t[v].first = max(t[2*v].first,t[2*v+1].first);
    }
}

void update(int v, int tl, int tr, int pos, int value){
    if(tl == tr){
        t[v].first -= value;
    }
    else{
        int tm = (tl+tr)/2;
        if(tm >= pos) update(2*v, tl, tm, pos, value);
        else update(2*v+1, tm+1, tr, pos, value);
        t[v].first = max(t[2*v].first, t[2*v+1].first);
    }
}

int query(int v, int tl, int tr, int value){
    if(t[1].first >= value){
        if(tl == tr) return t[v].second;
        int tm = (tl+tr)/2;
        if(t[2*v].first < value) query(2*v+1, tm+1, tr, value);
        else query(2*v, tl, tm, value);
    }
    else{
        return 0;
    }
}

int main(){
    int n, m, r, aux;
    int y = 0;
    cin>>n>>m;

    vector<int> vec(n);
    vector<int> ans(m);

    for(int i = 0; i<n; i++){
        cin>>vec[i];
    }

    build(vec, 1, 0, n-1);

    for(int i = 0; i<m; i++){
        cin>>r;
        aux = query(1, 0, n-1, r);
        ans[i] = aux;
        if(aux){
            update(1, 0, n-1, aux-1, r);
        }
    }

    for(int i=0; i<m; i++){
        if(y){
            cout<<" ";
        }
        cout<<ans[i];
        y = 1;
    }
    cout<<endl;

    return 0;
}