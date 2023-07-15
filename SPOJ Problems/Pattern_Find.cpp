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
    string s, t;
    cin>>s>>t;
    t += '#';
    vector<int> pi(t.size(), 0);
    int pi_cur = 0;
    for(int i=1; i<t.size(); i++){
        int j = pi[i-1];
        while(j>0 && t[i]!=t[j]){
            j = pi[j-1];
        }
        if(t[i]==t[j]){
            j++;
        }
        pi[i] = j;
    }
    int ans = 0;
    vector<int> ans_idx;
    for(int i=0; i<s.size(); i++){
        int j = pi_cur;
        while(j>0 && s[i]!=t[j]){
            j = pi[j-1];
        }
        if(s[i]==t[j]){
            j++;
        }
        pi_cur = j;
        if(pi_cur==t.size()-1){
            ans++;
            ans_idx.push_back(i-t.size()+3);
        }
    }
    if(ans==0){
        cout<<"Not Found"<<endl;
        return;
    }
    else cout<<ans<<endl;
    for(auto i: ans_idx){
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
        if(t) cout<<endl;
    }
    return 0;
}
