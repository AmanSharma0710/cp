#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define vi vector<int>
#define pii pair<int,int>
#define vii vector<pii>
#define rep(i,a,b) for(int i=a; i<b; i++)
bool sortbysec(const pair<int,int> &a, const pair<int,int> &b){                //to sort vii by second element use sort(v.begin(), v.end(), sortbysec);
    return (a.second < b.second);
}
#define MOD 1000000007

vector<int> tree;
 
int minimum(int index, int start_index, int end_index, int query_start, int query_end){
    if(start_index>=query_start && query_end>=end_index){
        return tree[index];
    }
    if(start_index>query_end || query_start>end_index){
        return 0;
    }
    return min(minimum(index*2, start_index, (start_index+end_index)/2, query_start, query_end),
                 minimum(index*2 + 1, (start_index+end_index)/2 + 1, end_index, query_start, query_end));
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
    tree[index] = min(tree[index*2], tree[index*2 + 1]);
    return; 
}
 
 
void solve(){
    int n, q, x;
    cin>>q>>n;
    x=n;
    vector<int> v(n);
    for(auto &i: v){
        i=0;
    }
    while(__builtin_popcount(n)!=1){
        v.push_back(INT_MAX);
        n++;
    }
    tree.resize(2*n);
    for(int i=0; i<n; i++){
        tree[n+i] = v[i];
    }
    for(int i=n-1; i>0; i--){
        tree[i] = min(tree[2*i], tree[2*i+1]);
    }
    for(int i=0; i<q; i++){
        int index;
        cin>>index;
        index %= x;
        update(1, 0, n-1, index, index, 1);
        int ans = minimum(1, 0, n-1, 0, n-1);
        int multiple = tree[n+ans];
        cout<<(multiple*x)+ans<<"\n";
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