#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e+5;

int binary(int value, vector<pair<int,int>>& array, int n){
    int l = 0;
    int r = n-1;
    int mid;

    while(l <= r){
        mid = l+r >> 1;
        if(array[mid].first < value){
            l = mid+1;
        }
        else if(array[mid].first > value){
            r = mid-1;
        }
        else{
            return mid;
        }
    }

    return -1;
}

int main(){
    int n, x;

    cin>>n>>x;


    vector<pair<int,int>> vec(MAXN, {0,0});
    
    for(int i = 0; i<n; i++) {   
        cin>>vec[i].first;
        vec[i].second = i;
    }
    sort(vec.begin(), vec.begin()+n);

    for(int i = 0; i<n; i++){
        if(vec[i].first < x){
            int aux = x - vec[i].first;
            int ans = binary(aux, vec, n);
            if(ans != -1 && vec[ans].second != vec[i].second){
                cout<<vec[i].second+1<<' '<<vec[ans].second+1<<'\n';
                return 0;
            }
        }
    }

    cout<<"IMPOSSIBLE\n";
    return 0;
}