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



void solve(){
    int n, m;
    cin>>n>>m;
    vector<vector<int>> v(n, vector<int>(m));
    rep(i,0,n){
        rep(j,0,m){
            cin>>v[i][j];
        }
    }
    if((n+m-1)%2){
        cout<<"NO"<<endl;
        return;
    }
    vector<vector<int>> v2(n, vector<int>(m, INT_MAX)), v3(n, vector<int>(m, INT_MIN));
    v2[0][0] = v[0][0];
    v3[0][0] = v[0][0];
    for(int i=1; i<n; i++){
        v2[i][0] = v2[i-1][0] + v[i][0];
        v3[i][0] = v3[i-1][0] + v[i][0];
    }
    for(int j=1; j<m; j++){
        v2[0][j] = v2[0][j-1] + v[0][j];
        v3[0][j] = v3[0][j-1] + v[0][j];
    }
    for(int i=1; i<n; i++){
        for(int j=1; j<m; j++){
            v2[i][j] = min(v2[i-1][j], v2[i][j-1]) + v[i][j];
            v3[i][j] = max(v3[i-1][j], v3[i][j-1]) + v[i][j];
        }
    }
    if((v2[n-1][m-1]<=0) && (v3[n-1][m-1]>=0)){
        cout<<"YES"<<endl;
        return;
    }
    cout<<"NO"<<endl;
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
