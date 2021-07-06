#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e+5;

struct Vertex{
    int l;
    int r;
    long long int value;
    Vertex(): l(-1), r(-1), value(0){};
};

vector<Vertex> t;

vector<int> roots;

void build(vector<int>& a, int v, int tl, int tr){
    if(tl == tr){
        t[v].value = a[tl];
    }
    else{
        int tm = (tl+tr)/2;
        if(t[v].l == -1){
            t.push_back(Vertex()); 
            t[v].l = t.size()-1;
        }
        if(t[v].r == -1){
            t.push_back(Vertex()); 
            t[v].r = t.size()-1;
        }

        int nex_left = t[v].l;
        int nex_right = t[v].r;  

        build(a, nex_left, tl, tm);
        build(a, nex_right, tm+1, tr);

        t[v].value = t[nex_left].value + t[nex_right].value;

    }
}


void update(int v, int tl, int tr, int pos, int value){
    if(tl == tr){
        t[v].value = value;
    }
    else{
        int tm = (tl+tr)/2;    
        if(pos <= tm){
            t.push_back(t[t[v].l]);
            int last = t.size() -1;
            t[v].l = last;
            update(t[v].l, tl, tm, pos, value);
        }
        else{
            t.push_back(t[t[v].r]);
            int last = t.size()-1;
            t[v].r = last;
            update(t[v].r, tm+1, tr, pos, value);
        }

        t[v].value = t[t[v].l].value + t[t[v].r].value;
    }
}

void copy(int k) {
    t.push_back(t[roots[k]]);
    roots.push_back(t.size()-1);
}

long long int query(int v, int tl, int tr, int l, int r){
    if( l > r) return 0;
    else if (tl == l && tr == r) return t[v].value;
    else{
        int tm = (tr+tl)/2;
        int nex_left = t[v].l;
        int nex_right = t[v].r;  
        return query(nex_left, tl, tm, l, min(tm,r)) + query(nex_right, tm+1, tr, max(tm+1, l), r); 
    }
}

int main(){
    ios::sync_with_stdio(0);
    int n, q;
    int op, k, a, x;

    cin>>n>>q;

    vector<int> vec(n);

    for(int i = 0; i<n; i++) {
        cin>>vec[i];
    }

    t.push_back(Vertex());
    t.push_back(Vertex());

    roots.push_back(1);

    build(vec, 1, 0, n-1);

    for(int i = 0 ; i < q; i++){
        cin>>op;
        if(op == 1){
            cin>>k>>a>>x;
            k--; a--;
            update(roots[k], 0, n-1, a, x);
        }
        if(op == 2){
            cin>>k>>a>>x;
            k--; a--; x--;
            cout<<query(roots[k], 0, n-1, a, x)<<'\n';
        }
        if(op == 3){
            cin>>k;
            k--;
            copy(k);
        }
    }
    return 0;
}