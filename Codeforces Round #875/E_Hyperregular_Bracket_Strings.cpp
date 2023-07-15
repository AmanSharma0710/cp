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
#define MOD 998244353

mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count());
uniform_int_distribution<int> rnd(0,LLONG_MAX);

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

const int N = 3e5+5;

vector<int> fact(N, 1), inv(N, 1);

int catalan(int n){
    if(n%2) return 0;
    return (fact[n] * inv[n/2] % MOD * inv[n/2+1] % MOD) % MOD;
}

void solve(){
    int n, k;
    cin>>n>>k;
    vector<int> a(n+1, 0);
    for(int i=0; i<k; i++){
        int x, y;
        cin>>x>>y;
        int hash = rnd(gen);
        a[x-1] ^= hash;
        a[y] ^= hash;
    }
    for(int i=1; i<=n; i++){
        a[i] ^= a[i-1];
    }
    assert(a[n] == 0);
    map<int, int> m;
    for(int i=0; i<n; i++){
        m[a[i]]++;
    }
    int ans = 1;
    for(auto x: m){
        ans = (ans * catalan(x.second)) % MOD;
    }
    cout<<ans<<endl;
    return;
}


signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    for(int i=1; i<N; i++){
        fact[i] = (fact[i-1] * i) % MOD;
        inv[i] = power(fact[i], MOD-2, MOD);
    }
    int t=1;
    cin>>t;
    while (t--){
        solve();       
    }
    return 0;
}
