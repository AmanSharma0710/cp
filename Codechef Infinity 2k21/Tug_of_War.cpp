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
    int n, m;
    cin>>n>>m;
    vector<int> a(n), b(m);
    vii v;
    rep(i,0,n){
        cin>>a[i];
        v.push_back({a[i], i});
    } 
    rep(i,0,m) cin>>b[i];
    sort(b.begin(), b.end());
    if(*max_element(a.begin(), a.end())>*max_element(b.begin(), b.end())){
        cout<<"NO"<<endl;
        return;
    }
    if(*max_element(a.begin(), a.end())<*max_element(b.begin(), b.end())){
        cout<<"YES"<<endl;
        for(auto &i:b){
            cout<<i<<" ";
        }
        cout<<endl;
        return;
    }
    vector<int> post_max(n);
    post_max[n-1]=a[n-1];
    for(int i=n-2; i>=0; i--){
        post_max[i]=max(post_max[i+1], a[i]);
    }
    vector<int> ans;
    for(int i=0; i<n; i++){
        if(b.size()==0){
            cout<<"NO"<<endl;
            return;
        }
        if(a[i]==post_max[i]){
            if(b.back()<a[i]){
                cout<<"NO"<<endl;
                return;
            }
            if(b.back()==a[i]){
                ans.push_back(b.back());
                b.pop_back();
            }
            continue;
        }
    }
    if(b.size()==0){
        cout<<"NO"<<endl;
        return;
    }
    if(ans.size()>0){
        ans.push_back(b.back());
        b.pop_back();
    }
    for(auto &i:ans){
        b.push_back(i);
    }
    cout<<"YES"<<endl;
    for(auto &i:b){
        cout<<i<<" ";
    }
    cout<<endl;
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
