#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    set<int> f;

    int n;
    int aux;

    cin>>n;

    for(int i = 0; i<n; i++){
        cin>>aux;
        f.insert(aux);
    }

    cout<<f.size()<<'\n';
    return 0;
}