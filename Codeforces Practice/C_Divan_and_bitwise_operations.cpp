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


vector<bitset<32>> table;
void update(int index, int start_index, int end_index, int query_start, int query_end, bitset<32> &val){
    if(start_index>=query_start && query_end>=end_index){
        table[index] = table[index]& val;
        return;
    }
    if(start_index>query_end || query_start>end_index){
        return;
    }
    update(index*2, start_index, (start_index+end_index)/2, query_start, query_end, val);
    update(index*2 + 1, (start_index+end_index)/2 + 1, end_index, query_start, query_end, val);
    return; 
}

void propagate(int index, int n){
    if(index*2<n){
        table[index*2] = table[index]& table[index*2];
        propagate(index*2, n);
    }
    if(index*2+1<n){
        table[index*2 + 1] = table[index]& table[index*2 + 1];
        propagate(index*2+1, n);
    }
    return;
}


void solve(){
    int n, m, N;
    cin>>n>>m;
    N=n;
    while(__builtin_popcount(N)!=1){
        N++;
    }
    table.resize(2*N, bitset<32>((1ll<<32) - 1));
    bitset<32>x;
    for(int i=0; i<m; i++){
        int a, b, c;
        cin>>a>>b>>c;
        a--; b--;
        x = c;
        //cout<< x.to_ulong()<<" ";
        update(1, 0, N-1, a, b, x);
    }
    propagate(1, 2*N);
    for(int i=1; i<n; i++){
        table[N] = table[N]|table[N+i];
    }
    int ans = power(2, n-1, MOD);
    ans *= table[N].to_ulong()%MOD;
    ans %= MOD;
    cout<<ans<<endl;
    table.clear();
    return;
}


signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t=1;
    cin>>t;
    while (t--){
        solve();       
    }
    return 0;
}
