#include<bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace __gnu_pbds;
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

#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>



void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin>>a[i];
    // vector<int> b(n+1, 0);
    int ans = 0;
    for(int i=0; i<n; i++){
        // b.assign(n+1, 0);
        int beauty = 0;
        set<pair<int, int>> s1;
        vector<int> v(n, 0);
        ordered_set s;
        for(int j=i; j<n; j++){
            int pos = s.order_of_key(a[j]);
            if(i+pos != j){
                int l = i+pos, r = j;
                auto it = s1.upper_bound({r, -1});
                if(it!=s1.begin()){
                    it--;
                    l = min(l, (*it).first);
                }
                if(l>0){
                    beauty = v[l-1];
                }
                else{
                    beauty = 0;
                }
                beauty += r-l;
                // b[i+pos]++;
                // b[j+1]--;
            }
            v[j] = beauty;
            ans += beauty;
            s.insert(a[j]);
        }
        // for(int j=1; j<=n; j++) b[j] += b[j-1];
        // cout<<"b:";
        // for(int j=0; j<=n; j++) cout<<b[j]<<" ";
        // cout<<endl;
        // int beauty = 0, l=0;
        // for(int j=0; j<n; j++){
        //     if(b[j] != 0 && (b[j+1]!=0)){
        //         beauty ++;
        //     }
        //     ans += beauty;
        // }
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
