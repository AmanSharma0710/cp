#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define vi vector<int>


vector<int> tree;
int sum(int index, int start_index, int end_index, int query_start, int query_end){
    if(start_index>=query_start && query_end>=end_index){
        return tree[index];
    }
    if(start_index>query_end || query_start>end_index){
        return 0;
    }
    return sum(index*2, start_index, (start_index+end_index)/2, query_start, query_end) 
    + sum(index*2 + 1, (start_index+end_index)/2 + 1, end_index, query_start, query_end)
    + tree[index];
}
 
void update(int index, int start_index, int end_index, int query_start, int query_end, int val){
    if(start_index>=query_start && query_end>=end_index){
        tree[index] += val;
        return;
    }
    if(start_index>query_end || query_start>end_index){
        return;
    }
    update(index*2, start_index, (start_index+end_index)/2, query_start, query_end, val);
    update(index*2 + 1, (start_index+end_index)/2 + 1, end_index, query_start, query_end, val);
    return; 
}
 

void solve(){
    int n, q;
    cin>>n>>q;
    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin>>v[i];
    }
    sort(v.begin(), v.end());
    while(__builtin_popcount(n)!=1){
        n++;
    }
    tree.assign(2*n, 0);
    for(int i=0; i<q; i++){
        int l, r;
        cin>>l>>r;
        l--; r--;
        update(1, 0, n-1, l, r, 1);
    }
    vector<int> counts(v.size());
    for(int i=0; i<v.size(); i++){
        counts[i] = sum(1, 0, n-1, i, i);
    }
    sort(counts.begin(), counts.end());
    int ans=0;
    for(int i=0; i<v.size(); i++){
        ans+= counts[i]*v[i];
    }
    cout<<ans<<endl;
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
