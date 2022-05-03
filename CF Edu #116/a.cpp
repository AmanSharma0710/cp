#include<bits/stdc++.h>
using namespace std;

vector<long long int>v;
vector<long long int>tree;

int greaterelements(int node, int node_low, int node_high, int query_low, int query_high, int k){
    if(node_low>node_high){
        return 0;
    }
    if(node_low>query_high || node_high<query_low)
        return 0;
    if(node_low>=query_low && node_high<=query_high){
        if(tree[node]<=k)
            return 0;
    }
    if(node_low==node_high){
        return (tree[node]>k);
    }
    int mid=(node_low+node_high)/2;
    int left=greaterelements(2*node, node_low, mid, query_low, query_high, k);
    int right=greaterelements(2*node+1, mid+1, node_high, query_low, query_high, k);
    return left+right;
}

int minidx(int i, int k){
    //binary search for the minimum index
    int l=i,r=v.size()-1;
    while(l+1<r){
        int mid=(l+r)/2;
        if(greaterelements(1, 0, v.size()-1, i+1, mid, v[i])>=k && v[mid]<=v[i])
            r=mid-1;
        else
            l=mid;
    }
    if(l==i){
        return -1;
    }
    return l;
}


void solve(){
    long long int n, k;
    cin>>n>>k;
    int N=n;
    v.resize(n);
    for(long long int i=0;i<n;i++){
        cin>>v[i];
    }
    while(__builtin_popcount(n)!=1){
        v.push_back(0);
        n++;
    }
    tree.resize(2*n);
    for(int i=0; i<n; i++){
        tree[i+n] = v[i];
    }
    for(int i=n-1; i>=0; i--){
        tree[i] = max(tree[2*i],tree[2*i+1]);
    }
    for(int i=0; i<N; i++){
        cout<<minidx(i, k)<<" ";
    }
    cout<<endl;
    return;
}


int main(){
    long long int t=1;
    cin>>t;
    while (t--){
        solve();       
    }
    return 0;
}