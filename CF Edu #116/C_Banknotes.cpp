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
int power(int x, int y){
    int res = 1; 
    x = x;  
    while (y > 0){
        if (y & 1)
            res = (res*x);
        y = y>>1;
        x = (x*x);
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
    int n, k;
    cin>>n>>k;
    k++;
    vi a(n);
    rep(i,0,n){
        cin>>a[i];
    }
    sort(a.begin(), a.end());
    vi v(n, 0);
    int i=0;
    while(k>0){
        if(i==n-1){
            v[i]+= k;
            k -= k;
            continue;
        }
        int diff = a[i+1] - a[i];
        if(power(10, diff)-1<k){
            v[i]+= power(10, diff)-1;
            k -= power(10, diff)-1;
        }
        else{
            v[i]+= k;
            k -= k;
        }
        i++;
    }
    int ans = 0;
    for(int i=0; i<n; i++){
        ans += power(10, a[i])*v[i];
    };
    cout<<ans<<endl;
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
