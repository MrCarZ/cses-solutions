#include <bits/stdc++.h>
 
using namespace std;
 
int BLOCK;
const int MAXN = 2e+5;
 
struct Query{
    int l;
    int r;
    int idx;
    Query(){};
    Query(int _l, int _r, int _idx): r(_r), l(_l), idx(_idx) {};
};
 
bool compare(Query a, Query b){
        if(a.l/BLOCK != b.l/BLOCK)
                return a.l/BLOCK < b.l/BLOCK;
        if(((a.l/BLOCK)+1) % 2 == 0){
            return a.r/BLOCK > b.r/BLOCK;
        }
        return a.r/BLOCK < b.r/BLOCK;
}
 
int main(){
    ios::sync_with_stdio(0);
    
    int n, q;
    int lf, rg;
    int p;
    
    cin>>n>>q;
 
    BLOCK = int(sqrt(n));
 
    vector<int> vec(MAXN);
    vector<Query> queries(MAXN);
    
    map<int, int> compressor;
    
    vector<int> ans(MAXN);
    vector<int> counter(MAXN);
    
    
    p = 0;
 
    for(int i = 0; i<n; i++){ 
        cin>>vec[i];
        if(compressor.count(vec[i]) == 0){
            compressor[vec[i]] = p;
            p++;
        }
    }
    
    for(int i = 0; i < n; i++){
        vec[i] = compressor[vec[i]];
    }
 
    for(int i = 0; i<q; i++){ 
        cin>>lf>>rg; 
        lf--; rg--;
        queries[i] = Query(lf, rg, i);    
    }
 
    sort(queries.begin(), queries.begin() + q, compare);


    int p1 = 0;
    int p2 = -1;
    
    int cur_ans = 0;
    
    for(int i = 0; i<q; i++){
        int left = queries[i].l;
        int right = queries[i].r; 
        int id = queries[i].idx;
 
        ans[id] = cur_ans;
 
        while(p2 < right){
            p2++;
            int aux = vec[p2];
            counter[aux]++;
            if(counter[aux] == 1) cur_ans++;
        }
 
        while(p2 > right){
            int aux = vec[p2];
            counter[aux]--;
            if(counter[aux] == 0) cur_ans--;
            p2--;
        }
        // Left
        while(p1 > left){
            p1--;
            int aux = vec[p1];
            counter[aux]++;
            if(counter[aux] == 1) cur_ans++;
        }
        while(p1 < left){
            int aux = vec[p1];
            counter[aux]--;
            if(counter[aux] == 0) cur_ans--;
            p1++;
        }
        ans[id] = cur_ans;
    }
 
    for(int i = 0; i<q; i++) cout<<ans[i]<<'\n';
 
    return 0;
}