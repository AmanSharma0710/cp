#include<bits/stdc++.h>
using namespace std;

int N =1;
vector<long long> tree;

void update(int pos, long long value){
    int idx = N+pos;
    tree[idx] = value;
    idx/=2;
    while(idx>0){
        tree[idx] = max(tree[2*idx], tree[2*idx+1]);
        idx/=2;
    }
    return;
}

long long query(int idx, int lquery, int rquery, int l, int r){
    if(lquery<=l && rquery>=r) return tree[idx];
    if(rquery<l || lquery>r) return 0;
    int mid = (l+r)/2;
    return max(query(idx*2, lquery, rquery, l, mid), query(idx*2 + 1, lquery, rquery, mid+1, r));
}

int main(){
    int n;
    cin>>n;
    vector<int>h(n), a(n);
    for(int i=0; i<n; i++) cin>>h[i];
    for(int i=0; i<n; i++) cin>>a[i];
    while(N<=n) N = N<<1;
    tree.assign(2*N, 0);
    for(int i=0; i<n; i++){
        long long max_till_now = query(1, 0, h[i]-1, 0, N-1);
        update(h[i], max_till_now + a[i]);
    }
    long long ans = 0;
    for(int i=0; i<=n; i++){
        ans = max(ans, tree[N+i]);
    }
    cout<<ans<<endl;
    return 0;
}