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


signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, q;
    cin>>n>>q;
    vector<string> s(n);
    rep(i,0,n)
        cin>>s[i];
    vector<int> happiness(n);
    vector<int> left(n,0), right(n,0);
    for(int i=0; i<n; i++){
        int cnt = 0;
        for(int j=0; j<s[i].size(); j++){
            if(s[i][j]=='1')
                cnt++;
        }
        if(2*cnt>n){
            happiness[i] = 2*cnt-n;
        }
        else{
            happiness[i] = 0;
        }
        int ans = 0;
        for(int j=0; j<s[i].size(); j++){
            if(s[i][j]=='1'){
                ans++;
            }
            else{
                ans--;
            }
            left[i] = max(left[i],ans);
        }
        ans = 0;
        for(int j=s[i].size()-1; j>=0; j--){
            if(s[i][j]=='1'){
                ans++;
            }
            else{
                ans--;
            }
            right[i] = max(right[i],ans);
        }
    }
    for(int qq=0; qq<q; qq++){
        int l, r;
        cin>>l>>r;
        l--;
        r--;
        int ans = 0;
        int lmaxidx=-1, rmaxidx=-1, lmaxidx2=-1, rmaxidx2=-1;
        for(int i=0; i<n; i++){
            if(happiness[i]>0){
                ans += happiness[i];
            }
            else{
                if(lmaxidx == -1){
                    lmaxidx = i;
                }
                else if(left[i]>left[lmaxidx]){
                    lmaxidx2 = lmaxidx;
                    lmaxidx = i;
                }
                if(rmaxidx==-1){
                    rmaxidx = i;
                }
                else if(right[i]>right[rmaxidx]){
                    rmaxidx2 = rmaxidx;
                    rmaxidx = i;
                }
            }
        }
        if(lmaxidx!=-1){
            if(lmaxidx!=rmaxidx){
                ans += left[lmaxidx]+right[rmaxidx];
            }
            else if(lmaxidx2!=-1){
                ans += max(left[lmaxidx] + right[rmaxidx2], left[lmaxidx2] + right[rmaxidx]);
            }
            else{
                ans += max(left[lmaxidx], right[rmaxidx]);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
