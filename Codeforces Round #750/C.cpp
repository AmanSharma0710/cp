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
    string s;
    cin>>s;
    bool pal=true;
    for(int i=0; i<n/2; i++){
        if(s[i]!=s[n-1-i]){
            pal=false;
        }
    }
    if(pal==true){
        cout<<"0\n";
        return;
    }
    int final_ans=INT_MAX;
    for(char c='a'; c<='z'; c++){
        int l=0, r=n-1, ans=0;
        while(l<=r){
            if(s[l]==s[r]){
                l++;
                r--;
                continue;
            }
            if(s[l]==c){
                l++;
                ans++;
                continue;
            }
            if(s[r]==c){
                r--;
                ans++;
                continue;
            }
            if(s[l]!=s[r]){
                break;
            }
        }
        if(l>=r){
            final_ans=min(final_ans, ans);
        }
    }
    if(final_ans==INT_MAX){
        cout<<"-1"<<endl;
        return;
    }
    cout<<final_ans<<endl;
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
