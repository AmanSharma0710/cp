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
int power(int x, int y, int p){
    int res = 1; 
    x = x % p;  
    while (y > 0){
        if (y & 1)
            res = (res*x) % p;
        y = y>>1;
        x = (x*x) % p;
    }
    return res;
}
unsigned mod_pow(unsigned a, unsigned b, unsigned mod) {
    unsigned result = 1;
    while (b > 0) {
        if (b & 1)
            result = unsigned(uint64_t(result) * a % mod);
        a = unsigned(uint64_t(a) * a % mod);
        b >>= 1;
    }
    return result;
}
 
bool isPrime(unsigned n) {
    if (n < 2)
        return false;
    for (unsigned p : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29})
        if (n % p == 0)
            return n == p;
    int r = __builtin_ctz(n - 1);
    unsigned d = (n - 1) >> r;
    for (unsigned a : {2, 7, 61}) {
        unsigned x = mod_pow(a % n, d, n);
        if (x <= 1 || x == n - 1)
            continue;
        for (int i = 0; i < r - 1 && x != n - 1; i++)
            x = unsigned(uint64_t(x) * x % n);
        if (x != n - 1)
            return false;
    }
    return true;
}
vector<int> tree;
 
int sum(int index, int start_index, int end_index, int query_start, int query_end){
    if(start_index>=query_start && query_end>=end_index){
        return tree[index];
    }
    if(start_index>query_end || query_start>end_index){
        return 0;
    }
    return sum(index*2, start_index, (start_index+end_index)/2, query_start, query_end) + sum(index*2 + 1, (start_index+end_index)/2 + 1, end_index, query_start, query_end);
}
 
void update(int index, int start_index, int end_index, int query_start, int query_end, int val){
    if(start_index>=query_start && query_end>=end_index){
        tree[index] = val;
        return;
    }
    if(start_index>query_end || query_start>end_index){
        return;
    }
    update(index*2, start_index, (start_index+end_index)/2, query_start, query_end, val);
    update(index*2 + 1, (start_index+end_index)/2 + 1, end_index, query_start, query_end, val);
    tree[index] = tree[index*2] + tree[index*2 + 1];
    return; 
}
 
 
void solve(){
    int n, q;
    cin>>n>>q;
    vector<int> v(n);
    for(auto &i: v){
        cin>>i;
    }
    while(__builtin_popcount(n)!=1){
        v.push_back(0);
        n++;
    }
    tree.resize(2*n);
    for(int i=0; i<n; i++){
        tree[n+i] = v[i];
    }
    for(int i=n-1; i>0; i--){
        tree[i] = tree[2*i] + tree[2*i+1];
    }
    for(int i=0; i<q; i++){
        int type;
        cin>>type;
        if(type==2){
            int l, r;
            cin>>l>>r;
            l--;
            r--;
            cout<<sum(1, 0, n - 1, l, r)<<endl;
        }
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