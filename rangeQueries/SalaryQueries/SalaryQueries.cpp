    #include <bits/stdc++.h>
    
    using namespace std;
    
    const int INF = 1e+9+5;
    
    struct Vertex{
        int leafmin;
        int leafmax;
        int leafq;
        int l, r;
    };
    
    Vertex newVert(int tl, int tr){
        Vertex ans;
        ans.leafmin = tl;
        ans.leafmax = tr;
        ans.leafq = 0;    
        ans.l = ans.r = 0;
        return ans;
    }

    vector<Vertex> t;

    void update(int v, int tl, int tr, int pos, char c){
        
        if(tl == tr && tl == pos){
            if(c == '+') ++t[v].leafq;
            if(c == '-') --t[v].leafq;
        }
        else{
            int tm = (tr+tl)/2;
            if(tm >= pos){
                if(t[v].l == 0){
                    t.push_back(newVert(tl, tm));
                    t[v].l = t.size()-1;
                }
                update(t[v].l, tl, tm, pos, c);
            }
            else{
                if(t[v].r == 0){
                    t.push_back(newVert(tm+1, tr));
                    t[v].r = t.size()-1;
                }
                update(t[v].r, tm+1, tr, pos, c);    
            }
            
            int p1 = t[v].l;
            int p2 = t[v].r;
            t[v].leafmax = max(t[p2].leafmax, t[p1].leafmax);
            t[v].leafmin = min(t[p2].leafmin, t[p1].leafmin);       
            
            if(t[v].r == 0) t[v].leafq = t[p1].leafq;
            else if(t[v].l == 0) t[v].leafq = t[p2].leafq;
            else t[v].leafq = t[p2].leafq + t[p1].leafq;
        }
    }

    
    int minmax_query(int v, int mi, int ma){
        if(t[v].leafmax <= ma && t[v].leafmin >= mi){
            return t[v].leafq;
        }
        else if((t[v].leafmax < mi) || (t[v].leafmin > ma)) return 0; // Disjuntos
        else{
            if(t[v].r != 0 && t[v].l != 0) return minmax_query(t[v].l, mi, ma) +  minmax_query(t[v].r, mi, ma);
            else if(t[v].l != 0) return minmax_query(t[v].l, mi, ma);
            else if(t[v].r != 0) return minmax_query(t[v].r, mi, ma);
            else return 0;
        }
    }
    
    
    int main(){
        ios::sync_with_stdio(0);
        int n, q;
        char op;
        int l, r;
        int ans;

        t.clear();
        t.push_back(newVert(INF, -INF));
        t.push_back(newVert(INF, -INF));
        
        cin>>n>>q;
    
        vector<int> vec(n);
    
        for(int i = 0; i<n; i++){
            cin>>vec[i];
        }
    
        for(int i = 0; i<n; i++){
            update(1, 1, 1e+9, vec[i], '+');
        }
    

        for(int i = 0; i<q; i++){
            cin>>op;
            if(op == '!'){
                cin>>l>>r;
                l--;
                update(1, 1, 1e+9, vec[l], '-');
                vec[l] = r;
                update(1, 1, 1e+9, r, '+');
            }
            if(op == '?'){
                cin>>l>>r;
                ans = minmax_query(1, l, r);
                cout<<ans<<'\n';               
            }

        }
    
        return 0;
    }   