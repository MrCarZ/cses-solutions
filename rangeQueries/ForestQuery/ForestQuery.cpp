#include<bits/stdc++.h>

using namespace std;

const int MAXN = 1e+3; 

int t[4*MAXN][4*MAXN];

void buildy(vector<vector<int>>& a, int v, int ly, int ry, int lx, int rx, int vx){
    if(ly == ry){
        if (lx == rx) {t[vx][v] = a[ly][lx];}
        else {t[vx][v] = t[2*vx][v] + t[2*vx+1][v];} 
    }
    else{
        int my = (ly+ry)/2;
        buildy(a, 2*v, ly, my, lx, rx, vx);
        buildy(a, 2*v+1, my+1, ry, lx, rx, vx);
        t[vx][v] = t[vx][2*v] + t[vx][2*v+1];
    }
}

void buildx(vector<vector<int>>& a, int n, int v, int lx, int rx){
    if(lx != rx){
        int mx = (rx+lx)/2;
        buildx(a, n, 2*v, lx, mx);
        buildx(a, n, 2*v+1, mx+1, rx);
    }
    buildy(a, 1, 0, n-1, lx, rx, v);
}

void updatey(int vx, int vy, int lx, int rx, int ly, int ry, int posy, int value){
    if(ly == ry){
        if (lx == rx) t[vx][vy] = value;
        else t[vx][vy] = t[2*vx][vy] + t[2*vx+1][vy]; 
    }
    else{
        int my = (ly+ry)/2;
        if(my >= posy){
            updatey(vx, 2*vy, lx, rx, ly, my, posy, value);
        }
        else{
            updatey(vx, 2*vy+1, lx, rx, my+1, ry, posy, value);
        }
        t[vx][vy] = t[vx][2*vy] + t[vx][2*vy+1]; 
    }
}

void updatex(int vx, int n, int lx, int rx, int posx, int posy, int value){
    if(lx != rx){
        int mx = (lx+rx)/2;
        if(mx >= posx){
            updatex(2*vx, n, lx, mx, posx, posy, value);
        }
        else{
            updatex(2*vx+1, n, mx+1, rx, posx, posy, value);
        }
    }
    updatey(vx, 1, lx, rx,0, n-1, posy, value);
};

int queryy(int vy, int vx, int ly, int ry, int l, int r){
    if(l > r) return 0;
    if(ly == l && ry == r) return t[vx][vy];
    int my = (ly+ry)/2;       
    return queryy(2*vy, vx, ly, my, l, min(r, my)) + queryy(2*vy+1, vx, my+1, ry, max(l, my+1), r);
}

int queryx(int n, int vx, int lx, int rx, int l1, int r1, int l2, int r2){    
    if(l1 > r1) return 0;
    if(lx == l1 && rx == r1) return queryy(1, vx, 0, n-1, l2, r2);
    int mx = (lx+rx)/2;       
    return queryx(n, 2*vx, lx, mx, l1, min(r1, mx), l2, r2) + queryx(n, 2*vx+1, mx+1, rx, max(l1, mx+1), r1, l2, r2);
}

int main(){
    ios::sync_with_stdio(0);
    int n, q, l1, r1, l2, r2, op;
    char c;
    
    cin>>n>>q;
    
    vector<vector<int>> vec(n, vector<int>(n));
    
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){        
            cin>>c;
            c == '*' ? vec[i][j] = 1 : vec[i][j] = 0;
        }
    }

    buildx(vec, n, 1, 0, n-1);

    for(int i = 0; i<q; i++){
        cin>>op;

        if(op == 1){
            cin>>l2>>l1>>r2>>r1;
            l1--;l2--;r1--;r2--;
            cout<<queryx(n, 1, 0, n-1, l1, r1, l2, r2)<<endl;
        }   
        if(op == 2){
            cin>>l1>>r1>>l2;
            l1--;r1--;
            updatex(1, n, 0, n-1, l1, r1, l2);
        }     
    
    }

    
    
    return 0;
}