#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2E+5;


int main(){
    int n;

    cin>>n;

    vector<int> vec(MAXN, 0);

    for(int i =0;i<n; i++) cin>>vec[i];

    multiset<int> towers;
    multiset<int>::iterator pos;

    for(int i = 0; i<n; i++){
        if(towers.size()){
            pos = towers.upper_bound(vec[i]);
            if(pos != towers.end()){
                towers.erase(pos);
            }
        }
        towers.insert(vec[i]);
    }
    
    cout<<towers.size()<<'\n';
}