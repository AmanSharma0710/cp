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
    vector<pair<int,int>> v;
    rep(i,0,n){
        int a,b;
        cin>>a>>b;
        v.push_back({a,b});
    }
    sort(v.begin(), v.end());
    int taken = 0, rightmost = -1;
    vector<bool> vis(n, false);
    for(int i=0; i<n; i++){
        if(v[i].first<=rightmost || vis[i]){
            continue;
        }
        else{
            //find another to match that intersects and has the least rightmost
            auto inter = [](pair<int,int> a, pair<int,int> b){
                if(a.first<=b.first && a.second>=b.first){
                    return true;
                }
                else if(b.first<=a.first && b.second>=a.first){
                    return true;
                }
                else{
                    return false;
                }
            };
            int min_right = INT_MAX, min_right_index = -1;
            for(int j=i+1; j<n; j++){
                if(j==i) continue;
                if(inter(v[i], v[j]) && v[j].second<min_right && !vis[j]){
                    min_right = v[j].second;
                    min_right_index = j;
                }
            }
            if(min_right_index!=-1){
                taken+=2;
                rightmost = max(v[i].second, v[min_right_index].second);
                vis[i] = true;
                vis[min_right_index] = true;
            }
        }
    }
    cout<<n-taken<<"\n";
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
