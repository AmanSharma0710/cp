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

struct segment{
    int a, b, c;
    bool operator<(const segment &other) const{
        if(a == other.a && b == other.b)
            return c < other.c;
        if(a==other.a)
            return b>other.b;
        return a>other.a;
    }
};


void solve(){
    int n;
    cin>>n;
    priority_queue<segment> left, right, coverage;
    rep(i,0,n){
        int a, b, c;
        cin>>a>>b>>c;
        left.push({a,c, b});
        right.push({-b,c, a});
        coverage.push({a - b, c, a});
        segment l = left.top();
        segment r = right.top();
        segment max_coverage = coverage.top();
        int left_edge = l.a;
        int right_edge = -r.a;
        int curr_cost = INT_MAX;
        if(right_edge-left_edge == -max_coverage.a){
            curr_cost = min(curr_cost, max_coverage.b);
        }
        if(l.c==right_edge){
            curr_cost = min(curr_cost, l.b);
        }
        if(r.c==left_edge){
            curr_cost = min(curr_cost, r.b);
        }
        curr_cost = min(curr_cost, l.b + r.b);
        cout<<curr_cost<<endl;
    }
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
