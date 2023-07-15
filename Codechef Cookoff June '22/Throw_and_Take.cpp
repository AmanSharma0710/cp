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
    int n;
    cin>>n;
    vi a(n), b(n);
    rep(i,0,n){
        cin>>a[i];
    }
    rep(i,0,n){
        cin>>b[i];
    }
    vector<int>v;
    for(int i=0; i<n; i++){
        if(a[i]%2){
            v.push_back(b[i]);
        }
    }
    if(v.size()==0){
        cout<<"0"<<endl;
        return;
    }
    for(int i= (int)v.size() - 2; i>=0; i--){
        v[i] = max(v[i], v[i+1]);
    }
    vector<int>v1;
    v1.push_back(v[0]);
    for(int i=0; i<(int)v.size()-1; i++){
        if(v[i]!=v[i+1]){
            v1.push_back(v[i+1]);
        }
    }
    vector<vector<int>>dp(v1.size()+1, vector<int>(2));
    int m = v1.size();
    //dp[i][0] -> A has the turn
    //dp[i][0] = max(dp[i+1][0], dp[i+1][1] + v1[i])
    //dp[i][1] -> B has the turn
    //dp[i][1] = min(dp[i+1][0] - v1[i], dp[i+1][1])
    for(int i=0; i<m; i++){
        dp[i][0] = INT_MIN;
        dp[i][1] = INT_MAX;
    }
    dp[m][0] = 0;
    dp[m][1] = 0;
    for(int i=m-1; i>=0; i--){
        dp[i][0] = max(dp[i+1][0], dp[i+1][1] + v1[i]);
        dp[i][1] = min(dp[i+1][0] - v1[i], dp[i+1][1]);
    }
    cout<<dp[0][0]<<endl;
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
