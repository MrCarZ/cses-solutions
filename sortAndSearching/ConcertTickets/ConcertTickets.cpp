    #include <bits/stdc++.h>
    
    using namespace std;
    const int MAXN = 2e+5;
    
    vector<int> go(MAXN+1, 0);
    int n;
    
    void update(int pos, int value){
        for( ; pos <= n; pos += pos & -pos){
            go[pos] += value;
        }
    }
    
    int get(int pos){
        int ans = 0;
        for( ; pos > 0 ; pos -= pos & -pos){
            ans += go[pos];
        }
        return ans;
    }
    
    int rank_find(int value, vector<int> &arr){
        int l = 1;
        int r = n+1;
        int mid;
        while(l < r){
            mid = (l+r)/2;
            if(arr[mid] > value){
                r = mid;
            }
            else{
                l = mid+1;
            }
        }
    
        return r-1;
    }
    
    int binaria_fenwick(int value){
        int acc = value;
        int idx = 0;
        int bitMask = 1 << (int)log2(n);
        int currIdx;
        
        while(bitMask != 0){
            currIdx = idx + bitMask;
            bitMask >>= 1;    
            if(currIdx > n)
                currIdx = n;

            if(currIdx+go[currIdx] <= acc){
                acc -= go[currIdx];
                idx = currIdx;
            }
            //cout<<idx<<' '<<acc<<'\n';
        }

        return idx;
    }
    
    int main(){
        ios::sync_with_stdio(0);
        int m;
    
        cin>>n>>m;
    
        vector<int> vec(MAXN+1, 0), cus(MAXN+1, 0);
    
        for(int i = 1; i<=n; i++){
            cin>>vec[i];
        }
        for(int i = 1; i<=m; i++){
            cin>>cus[i];
        }
    
        sort(vec.begin(), vec.begin()+(n+1));
    
        vec[0] = -1;
        for(int i = 1; i<=m; i++){
            /*for(int j = 1; j<= n; j++) cout<<j+get(j)<<" ";
            cout<<'\n';*/
            int posf = rank_find(cus[i], vec);         
            int desl = get(posf);          
            int aux = posf+desl;               
            int prev;
            int curr = aux + get(aux);
            int r = binaria_fenwick(aux);
            
            if(aux > 0){
                prev = aux-1 + get((aux)-1); 
                cout<<vec[aux]<<'\n';    
                update(aux, prev-curr);      
                update(r+1, -(prev-curr));
            }
            else{
                prev = 0;
                cout<<-1<<'\n';
            }
            
            /*cout<<"r: "<<r<<'\n';
            cout<<"posf:"<<posf<<"\n";
            cout<<"desl:"<<desl<<'\n';
            cout<<"prev:"<<prev<<'\n';
            cout<<"curr: "<<curr<<'\n';              
            */
        }
        
    
    }