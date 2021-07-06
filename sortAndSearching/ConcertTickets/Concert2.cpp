#include <bits/stdc++.h>

using namespace std;
const int MAXN = 2e+5; 

int n;

vector<int> pai(MAXN+1,0);

int rank_find(int value, vector<int> &arr){
    int l = 1;
    int r = n+1;
    int mid;
    while(l < r){
        mid = (int) floor((l+r)/2);
        if(arr[mid] > value){
            r = mid;
        }
        else{
            l = mid+1;
        }
    }

    return r-1;
}

int find(int i){
    if(pai[i] == i){
        return i;
    }

    pai[i] = find(pai[i]); 
    return pai[i];
}

void join(int x, int y){
    pai[find(x)] = find(y);
}

int main(){
    ios::sync_with_stdio(0);
    int m;
    cin>>n>>m;
    vector<int> vec(MAXN+1,0);
    vector<int> cus(MAXN+1,0);

    for(int i = 1; i<=n; i++) {
        cin>>vec[i];
        pai[i] = i;
    }
    for(int i = 1; i<=m; i++) cin>>cus[i];
    
    sort(vec.begin(), vec.begin()+n+1);

    vec[0] = -1;
    
    for(int i = 1; i<=m; i++){
        int pos = rank_find(cus[i], vec);
        //cout<<find(pos)<<'\n';
        cout<<vec[find(pos)]<<'\n';
        join(find(pos), find(find(pos)-1));
    }
    return 0;
}