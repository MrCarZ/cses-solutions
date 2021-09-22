#include <bits/stdc++.h>

using namespace std;
using ll = long long int;

const int MAXN = 5E+5 + 5;
const ll INF = 1E+15 + 5;

int n;
ll dp[MAXN], vec[MAXN];

struct Project{
    pair<int,int> days;
    int value;
    Project(){};
};

vector<Project> projects(MAXN, Project());

vector<ll> segtree(4*MAXN, 0);

bool compare(Project& a, Project& b){
    if(a.days.first == b.days.first){
        return a.days.second < b.days.second;
    }
    return a.days.first < b.days.first;
}

void update(int v, int tl, int tr, int pos, ll val){
    if(tl == tr) segtree[v] = max(val,segtree[v]);
    else{
        int mid = tl + tr >> 1;

        if(mid >= pos) update(2*v, tl, mid, pos, val);
        else update(2*v+1, mid + 1, tr, pos, val);

        segtree[v] = max(segtree[2*v], segtree[2*v+1]);
    }
}

ll query(int v, int tl, int tr, int l, int r){
    if(tl == l && tr == r){
        return segtree[v];
    }
    if(l > r) return -INF;
    int mid = tl + tr >> 1;
    return max(query(2*v, tl, mid, l, min(r, mid)), query(2*v+1, mid+1, tr, max(mid+1, l), r));
}

int main(){
    ios::sync_with_stdio(0);    
    cin>>n;

    set<int> numbers;
    for(int i = 1; i<=n; i++){
        cin>>projects[i].days.first>>projects[i].days.second>>projects[i].value;
        numbers.insert(projects[i].days.first);
        numbers.insert(projects[i].days.second);
    }
    
    map<int,int> comp;
    int counter = 1;

    for(auto i: numbers){
        if(comp[i] == 0){
            comp[i] = counter++;
        }
    }

    sort(projects.begin(), projects.begin() + n + 1, compare);

    for(int i = 1; i<=n; i++){
        projects[i].days.first = comp[projects[i].days.first];
        projects[i].days.second = comp[projects[i].days.second];
    }
    
    int tamanho = numbers.size() + 5;
    
    dp[n] = projects[n].value;
    update(1, 0, tamanho, projects[n].days.first, dp[n]);
    
    for(int st = n-1; st >= 0; st--){
        dp[st] = max(dp[st], (ll)query(1, 0, tamanho, projects[st].days.second+1, tamanho) + (ll)projects[st].value);
        update(1, 0, tamanho, projects[st].days.first, dp[st]);
    }
    
    cout<<dp[0]<<'\n';
    return 0;
}