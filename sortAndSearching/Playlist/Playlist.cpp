#include <bits/stdc++.h>

using namespace std;
const int MAXN = 2E+5;

int main(){
    ios::sync_with_stdio(0);
    int n;
    set<int> rep;
    map<int,int> nums;
    cin>>n;

    vector<int> vec(MAXN, 0), pos(MAXN, 0);
    
    for(int i = 0; i<n; i++){ 
        cin>>vec[i];
    }

    int p1 = 0;
    int p2 = 0;
    int ans = 0 ;
    int ans_mesmo = 0;
    
    while(p2 < n){
        if(!rep.count(vec[p2])){
            rep.insert(vec[p2]);
            nums[vec[p2]] = p2;
            p2++;
            ans++;
            ans_mesmo = max(ans_mesmo, ans);
        }
        else{
            ans_mesmo = max(ans_mesmo, ans);
            while(p1 < nums[vec[p2]]){
                rep.erase(vec[p1]);
                nums[vec[p1]] = 0;
                p1++;
                ans--;
            }
            nums[vec[p2]] = p2;
        }
    }

    cout<<ans_mesmo<<'\n';

    return 0;
}