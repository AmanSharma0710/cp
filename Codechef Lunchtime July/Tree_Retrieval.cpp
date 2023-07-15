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

void query(vector<int> &v){
    cout<<"? ";
    cout<<accumulate(v.begin(), v.end(), 0ll)<<" ";
    for(int i=0; i<v.size(); i++){
        if(v[i]==1)
            cout<<i+1<<" ";

    }
    cout<<endl;
    return;
}

void solve(){
    int n;
    cin>>n;
    vi a(n, 1);
    query(a);
    vector<pair<int,int>> edges;
    int leaf1, leaf2, last1, last2, total;
    cin>>leaf1>>total;
    leaf2 = total-leaf1;
    for(int i=0; i<n-2; i++){
        last1 = leaf1;
        last2 = leaf2;
        a[leaf1 -1] = 0;
        query(a);
        cin>>leaf1>>total;
        leaf2 = total-leaf1;
        if(leaf1==last2){
            swap(leaf1, leaf2);
        }
        edges.push_back({leaf1, last1});
    }
    edges.push_back({leaf2, leaf1});
    cout<<"!"<<endl;
    for(int i=0; i<edges.size(); i++){
        cout<<edges[i].first<<" "<<edges[i].second<<endl;
    }
    int judge;
    cin>>judge;
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
