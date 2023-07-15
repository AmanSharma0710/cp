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
    vi a(n);
    rep(i,0,n){
        cin>>a[i];
    }
    vector<vector<int>>v(20, vector<int>(0));
    vector<int> addv(20);
    for(int k=0; k<20; k++){
        int add = 0;
        int x = (1ll<<k);
        int y = (1ll<<(k+1));
        for(int j=0; j<=n/x; j++){
            int maxx = INT_MIN;
            int minn = INT_MAX;
            for(int i=j*y; i<min(j*y+y, n); i++){
                if((i&x) == 0){
                    maxx = max(maxx, a[i]);
                }
                else{
                    minn = min(minn, a[i]);
                }
            }
            if(maxx>=minn){
                add = max(add, maxx-minn+1);
            }
        }
        for(int i=0; i<n; i++){
            if(i&x){
                v[k].push_back(i+1);
                a[i] += add;
            }
        }
        addv[k] = add;
        assert(add<=1000000);
    }
    int cnt = 0;
    for(int i=0; i<20; i++){
        if(v[i].size()>0 && addv[i]>0){
            cnt++;
        }
    }
    cout<<cnt<<endl;
    for(int i=0; i<20; i++){
        if(v[i].size()>0 && addv[i]>0){
            cout<<v[i].size()<<" "<<addv[i]<<endl;
            for(int j=0; j<v[i].size(); j++){
                cout<<v[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    bool sorted = true;
    for(int i=0; i<n-1; i++){
        if(a[i]>a[i+1]){
            sorted = false;
            break;
        }
    }
    assert(sorted);
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
