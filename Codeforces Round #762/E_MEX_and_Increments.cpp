#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define vi vector<int>
#define pii pair<int,int>
#define vii vector<pii>
#define rep(i,a,b) for(int i=a; i<b; i++)
#define rrep(i,a,b) for(int i=a; i>=b; i--)
#define pb push_back
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

void print_vector(vector<int> &v) {
    for (int i : v)
        cout << i << " ";
    cout << endl;
}


void solve(){
    int n;
    cin>>n;
    vi a(n), count(n+1);
    rep(i,0,n){
        cin>>a[i];
        count[a[i]]++;
    }
    vi prefix(n+1), ans(n+1, 0);
    prefix[0] = count[0];
    rep(i,1,n+1) prefix[i] = prefix[i-1] + count[i];
    int end=n+1;
    for(int i=1; i<=n; i++){
        if(prefix[i-1]<i){
            for(int j=i; j<=n; j++){
                ans[j] = -1;
            }
            end=i;
            break;
        }
    }
    vi extra;
    int rollover=0;
    for(int i=0; i<=n; i++){
        if(i==end) break;
        ans[i] += count[i];
        if(i>0){
            if(count[i-1]==0){
                assert(extra.size()>0);
                rollover += i-1 - extra.back();
                extra.pop_back();
            }
        }
        ans[i] += rollover;
        if(count[i]>1){
            for(int j=count[i]; j>1; j--){
                extra.pb(i);
            }
        }
    }
    print_vector(ans);
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
