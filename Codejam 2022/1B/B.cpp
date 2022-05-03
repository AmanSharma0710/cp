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
    int n, p;
    cin>>n>>p;
    vi maxx(n), minn(n);
    rep(i,0,n){
        int big=INT_MIN, small =  INT_MAX;
        rep(j,0,p){
            int x;
            cin>>x;
            big = max(big, x);
            small = min(small, x);
        }
        maxx[i] = big;
        minn[i] = small;
    }
    int ans=0;
    rep(i,0,n){
        ans+=maxx[i]-minn[i];
    }
    int dp[n][2];
    //dp[i][0] denotes cost to fill tires from i to n-1 if i is started at minn and filled till maxx
    //dp[i][1] denotes cost to fill tires from i to n-1 if i is started at maxx and filled till minn
    rep(i,0,n){
        dp[i][0] = (1ll<<60);
        dp[i][1] = (1ll<<60);
    }
    dp[n-1][0] = 0;
    dp[n-1][1] = 0;
    for(int i=n-2; i>=0; i--){
        dp[i][0] = min(dp[i+1][0] + abs(maxx[i]-minn[i+1]), dp[i+1][1] + abs(maxx[i]-maxx[i+1]));
        dp[i][1] = min(dp[i+1][0] + abs(minn[i]-minn[i+1]), dp[i+1][1] + abs(minn[i]-maxx[i+1]));
    }
    ans+=min(dp[0][0] + minn[0], dp[0][1] + maxx[0]);
    cout<<ans<<endl;
    return;
}


signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t=1, tc=1;
    cin>>t;
    while (t--){
        cout<<"Case #"<<tc++<<": ";
        solve();       
    }
    return 0;
}
