#include<bits/stdc++.h>
using namespace std;
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
    vector<vector<pair<int, int>>> a(n+1, vector<pair<int, int>>());
    vector<int> b(n);
    for(int i=0; i<n; i++){
        cin>>b[i];
    }
    vector<pair<int, int>> temp(n);
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        temp[i] = {b[i], x};
    }
    sort(temp.begin(), temp.end());
    for(int i=0; i<n; i++){
        int x = temp[i].first;
        int y = temp[i].second;
        if(a[x].size() == 0){
            a[x].push_back({y, 1});
        }
        else{
            if(a[x].back().first == y){
                a[x].back().second++;
            }
            else{
                a[x].push_back({y, 1});
            }
        }
    }
    long long ans = 0;
    for(int i=1; i<=n; i++){
        for(int j=i+1; (long long)j*i<=2*n && j<=n; j++){
            long long prod = i*j;
            if(a[i].size()<a[j].size()){
                for(auto x:a[i]){
                    int req = prod - x.first;
                    auto it = lower_bound(a[j].begin(), a[j].end(), make_pair(req, 0));
                    if(it == a[j].end() || it->first!=req) continue;
                    long long cnt = it->second;
                    ans += cnt*x.second;
                }
            }
            else{
                for(auto x:a[j]){
                    int req = prod - x.first;
                    auto it = lower_bound(a[i].begin(), a[i].end(), make_pair(req, 0));
                    if(it == a[i].end() || it->first!=req) continue;
                    long long cnt = it->second;
                    ans += cnt*x.second;
                }
            }
        }
    }
    for(int i=1; (long long)i*i<=2*n && i<=n; i++){
        long long prod = i*i;
        for(auto x:a[i]){
            int req = prod - x.first;
            if(req>x.first) continue;
            auto it = lower_bound(a[i].begin(), a[i].end(), make_pair(req, 0));
            if(it == a[i].end() || it->first!=req) continue;
            long long cnt = it->second;
            if(req == x.first){
                ans += (cnt*(cnt-1))/2;
            }
            else{
                ans += cnt*x.second;
            }
        }
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
