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
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    vector<int> pre(n, INT_MAX), post(n, INT_MAX);
    pre[0] = a[0];
    post[n-1] = a[n-1];
    for(int i=1; i<n; i++){
        pre[i] = min(pre[i-1], a[i]);
    }
    for(int i=n-2; i>=0; i--){
        post[i] = min(post[i+1], a[i]);
    }
    vii f, b;
    for(int i=1; i<n; i++){
        if(post[i]!=post[i-1]){
            b.push_back({post[i], 0});
        }
        if(b.size()>0 && (post[i]==post[i-1])){
            b.back().second++;
        }
    }
    for(int i=n-2; i>=0; i--){
        if(pre[i]!=pre[i+1]){
            f.push_back({pre[i], 0});
        }
        if(f.size()>0 && (pre[i]==pre[i+1])){
            f.back().second++;
        }
    }
    priority_queue<int, vi, greater<int>> pq;
    for(int i=0; i<n; i++){
        if(a[i]!=max(pre[i], post[i])){
            pq.push(a[i]);
        }
    }
    int ans = 1, places = 0, i=0, j=0;
    while(!pq.empty()){
        int x = pq.top();
        pq.pop();
        while(i<f.size() && f[i].first<x){
            places += f[i].second;
            i++;
        }
        while(j<b.size() && b[j].first<x){
            places += b[j].second;
            j++;
        }
        ans = (ans*places)%MOD;
        places--;
    }
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
