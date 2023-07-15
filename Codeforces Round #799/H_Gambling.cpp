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
    vi av(n);
    rep(i,0,n)
        cin>>av[i];
    map<int, vector<int>> m;
    rep(i,0,n){
        m[av[i]].push_back(i);
    }
    int ans = INT_MIN;
    int a, l, r;
    for(auto it: m){
        if(it.second.size()==1){
            if(ans<1){
                a = it.first;
                l = it.second[0];
                r = l;
                ans = 1;
            }
            continue;
        }
        vector<int> &v = it.second;
        int max_so_far = 1, max_ending_here = 1, l1=0, templ=0, tempr=0;
        for(int i=1; i<v.size(); i++){
            max_ending_here += 2-(v[i]-v[i-1]);
            if(max_ending_here>max_so_far){
                max_so_far = max_ending_here;
                templ = l1;
                tempr = i;
            }
            if(max_ending_here<1){
                max_ending_here = 1;
                l1 = i;
            }
        }
        int tempans = 2*(tempr - templ+1) - (v[tempr]- v[templ]+1);
        if(tempans>ans){
            ans = tempans;
            a = it.first;
            l = v[templ];
            r = v[tempr];
        }
    }
    cout<<a<<" "<<l+1<<" "<<r+1<<endl;
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
