#include <bits/stdc++.h>

using namespace std;

const int INF = 1e+9 +5;
const int MAXN = 2e+5;

struct Vertex{
    int sum = 0;
    int diff = 0;
    int possum = 0;
    int posdiff = 0;
    Vertex(){};
    Vertex(int _a, int _pos): sum(_a + _pos), diff(_a-_pos), possum(_pos), posdiff(_pos){};
};

Vertex combine( Vertex a, Vertex b){
    Vertex c;

    c.sum = min(a.sum, b.sum);
    if(c.sum == a.sum) c.possum = a.possum;
    else c.possum = b.possum;

    c.diff = min(a.diff, b.diff);
    if(c.diff == a.diff) c.posdiff = a.posdiff;
    else c.posdiff = b.posdiff;

    return c;    
}

Vertex t[4*MAXN];

void build(vector<int>& a, int v, int tl, int tr){
    if(tl == tr){
        t[v] = Vertex(a[tl], tl);
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
        t[v] = Vertex(value, tl);
    }
    else{
        int tm = (tl+tr)/2;
        if(pos <= tm){
            update(2*v, tl, tm, pos, value);
        }
        else{
            update(2*v+1,tm+1, tr, pos, value);
        }
        t[v] = combine(t[2*v], t[2*v+1]);
    }
}

Vertex query_1(int v, int tl, int tr, int pos){
    if(t[v].possum >= pos){
        return t[v];
    }
    else if(tl == tr || tr < pos){
        return Vertex(INF, 0);
    }
    else{
        int tm = (tl+tr)/2;
        return combine(query_1(2*v+1, tm+1, tr, pos),query_1(2*v, tl, tm, pos));
    }
}

Vertex query_2(int v, int tl, int tr, int pos){
    if(t[v].posdiff <= pos){
        return t[v];
    }
    else if(tl == tr || tl > pos){
        return Vertex(INF, 0);
    }
    else{
        int tm = (tl+tr)/2;
        return combine(query_2(2*v, tl, tm, pos), query_2(2*v+1, tm+1, tr, pos));
    }
}

int main(){
    ios::sync_with_stdio(0);
    int n, q, op, k, x;

    cin>>n>>q;
    
    vector<int> vec(n);

    for(int i = 0; i<n; i++){
        cin>>vec[i];
    }

    build(vec, 1, 0, n-1);

    for(int i = 0; i<q; i++){
        cin>>op;

        if(op == 1){
            cin>>k>>x;
            k--;
            update(1, 0, n-1, k, x);
        }
        
        if(op == 2){
            cin>>k;
            k--;
            int aux1 = query_1(1, 0, n-1, k).sum - k;
            int aux2 = query_2(1, 0, n-1, k).diff + k;
            cout<<min(aux1,aux2)<<'\n';
        }
    }
    return 0;
}