#include<bits/stdc++.h>
using namespace std;
#define int long long int

vector<int> tree;

void fill_tree(int n, int isXOR){
    if(n<2){
        return;
    }
    for(int i=n-1; i>=n/2; i--){
        if(isXOR){
            tree[i] = tree[2*i]^tree[2*i+1];
        }
        else{
            tree[i] = tree[2*i]|tree[2*i+1];
        }
    }
    if(isXOR){
        fill_tree(n/2, 0);
    }
    else{
        fill_tree(n/2, 1);
    }
    return;
}

void update(int n, int i, int isXOR){
    if(n<2){
        return;
    }
    if(isXOR){
        tree[i] = tree[2*i]^tree[2*i+1];
    }
    else{
        tree[i] = tree[2*i]|tree[2*i+1];
    }
    if(isXOR){
        update(n/2, i/2, 0);
    }
    else{
        update(n/2, i/2, 1);
    }
    return;
}



void solve(){
    int n, m;
    cin>>n>>m;
    n = 1<<n;
    tree.resize(2*n);
    for(int i=0; i<n; i++){
        cin>>tree[n+i];
    }
    fill_tree(n, 0);
    for(int i=0; i<m; i++){
        int p, b;
        cin>>p>>b;
        p--;
        tree[n+p] = b;
        update(n, (n+p)/2, 0);
        cout<<tree[1]<<endl;
    }
    return;
}


signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t=1;
    //cin>>t;
    while (t--){
        solve();       
    }
    return 0;
}
