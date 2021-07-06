#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2E+5 + 3;

vector<int> pai(MAXN, 0);

int find(int a){
    if(pai[a] == a){
        return pai[a];
    }
    return pai[a] = find(pai[a]);
}

int binary(int value, int m, vector<int> &arr){
    int l = 0;
    int r = m-1;
    int mid;

    while(l <= r){
        mid = l + r >> 1;
        if(arr[mid] < value){
            l = mid+1;
        }
        else if(arr[mid] > value){
            r = mid -1;
        }
        else{
            return mid;
        }
        
    }
}

int main(){
    ios::sync_with_stdio(0);
    int n, m, aux;

    cin>>n>>m;

    vector<int> ans(MAXN, 0);
    vector<int> up(MAXN, 0);
    vector<int> query;
    up[0] = n;

    for(int i = 1; i<=m; i++){
        int p;
        cin>>p;
        up[i]=p;
        query.push_back(p);
        pai[i-1] = i-1;
    }

    reverse(query.begin(), query.end());
    sort(up.begin(), up.begin()+m+1);

    int curr_max = -1e+9;
    for(int i = 0; i<=m; i++){
        ans[i] = abs(up[i] - up[i-1]);
        curr_max = max(curr_max, ans[i]);
    }

    vector<int> final_ans;
    
    for(int i = 0; i<m; i++){
        final_ans.push_back(curr_max);
        int position = binary(query[i], m+1, up);
        int dad = find(position);
        ans[dad] += ans[position+1];
        curr_max = max(curr_max, ans[dad]);
        pai[position+1] = pai[dad];
    }

    for(int i = m-1; i>0; i--){
        cout<<final_ans[i]<<' ';
    }
    cout<<final_ans[0]<<'\n';

    return 0;
}