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

int dist(int i, int j, int d){
    return min(max(i, j) - min(i, j), d - max(i, j)+min(i, j));
}

void solve(){
    int n, d;
    cin>>n>>d;
    vector<int> v;
    int x;
    cin>>x;
    v.push_back(x);
    for(int i=1; i<n; i++){
        cin>>x;
       if(x!=v.back()){
           v.push_back(x);
        }
    }
    n = v.size();
    int dp[n][n][2];
    //dp[i][j][0] -> cost of changing elements in [i,j] to v[i]
    //dp[i][j][1] -> cost of changing elements in [i,j] to v[j]
    //dp[i][j][0] = min(dp[i+1][j][0] + dist(v[i+1], v[i], d), dp[i+1][j][1] + dist(v[j], v[i], d));
    //dp[i][j][1] = min(dp[i][j-1][0] + dist(v[i], v[j], d), dp[i][j-1][1] + dist(v[j-1], v[j], d));
    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            dp[i][j][0] = INT_MAX;
            dp[i][j][1] = INT_MAX;
        }
    }
    for(int i=0; i<n; i++){
        dp[i][i][0] = 0;
        dp[i][i][1] = 0;
    }

    for(int l=0; l<n; l++){
        for(int i=0; i<n; i++){
            int j=i+l;
            if(j>=n || j<i){
                continue;
            }
            if(i==j){
                dp[i][j][0] = 0;
                dp[i][j][1] = 0;
                continue;
            }
            dp[i][j][0] = min(dp[i+1][j][0] + dist(v[i+1], v[i], d), dp[i+1][j][1] + dist(v[j], v[i], d));
            dp[i][j][1] = min(dp[i][j-1][0] + dist(v[i], v[j], d), dp[i][j-1][1] + dist(v[j-1], v[j], d));
        }
    }
    cout<<min(dp[0][n-1][0] + dist(v[0], 0, d), dp[0][n-1][1] + dist(v[n-1], 0, d))<<endl;
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
