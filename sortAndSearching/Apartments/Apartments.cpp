#include <bits/stdc++.h>
#define ll long long 

using namespace std;

const int MAXN = 2e+5;

int main(){
    int n, m, k;

    cin>>n>>m>>k;

    vector<int> person(MAXN, 0);
    vector<int> ap(MAXN, 0);
    
    int p1 = 0;
    int p2 = 0;

    for(int i = 0; i<n; i++){
        cin>>person[i];
    }
    for(int i = 0; i<m; i++){
        cin>>ap[i];
    }

    int ans = 0;

    sort(person.begin(), person.begin()+n);
    sort(ap.begin(), ap.begin()+m);
    
    while(p2 < m){
        ll aux1 = person[p1]+k;
        ll aux2 = person[p1]-k;
        
        if(ap[p2] <= aux1 && ap[p2] >= aux2){
            ans++;
            p1++;
            p2++;
        }
        else{
            if(aux2 > ap[p2]){
                p2++;
            }
            else{
                p1++;
            }
        }
    }

    cout<<ans<<'\n';
    return 0;
}