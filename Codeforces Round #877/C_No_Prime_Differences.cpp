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

vector<bool> prime(1005, true);

void solve(){
    int n, m;
    cin>>n>>m;
    if(!prime[m]){
        int cnt = 1;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cout<<cnt++<<" ";
            }
            cout<<endl;
        }
        return;
    }
    if(!prime[n]){
        vector<vector<int>> v(n, vector<int>(m));
        int cnt = 1;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                v[j][i] = cnt++;
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cout<<v[i][j]<<" ";
            }
            cout<<endl;
        }
        return;
    }
    vector<vector<int>> v(n, vector<int>(m));
    int cnt = 1;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            v[i][j] = cnt++;
        }
    }
    vector<vector<int>> ans(n);
    for(int i=0; i<=n/2; i++){
        ans[i*2] = v[i];
        if(i*2+1<n){
            ans[i*2+1] = v[n/2+1+i];
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return;
}


signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    prime[0] = prime[1] = false;
    for(int i=2; i*i<=1000; i++){
        if(prime[i]){
            for(int j=i*i; j<=1000; j+=i){
                prime[j] = false;
            }
        }
    }
    int t;
    cin>>t;
    while(t--){
        solve();
        cout<<endl;
    }
    return 0;
}
