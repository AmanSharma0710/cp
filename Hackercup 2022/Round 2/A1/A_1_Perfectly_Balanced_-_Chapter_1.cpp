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
    string s;
    cin>>s;
    int ans = 0;
    int n=s.length();
    vector<vector<int>> prefix(n+1, vector<int>(26, 0));
    for(int i=0; i<n; i++){
        prefix[i+1]=prefix[i];
        prefix[i+1][s[i]-'a']++;
    }
    int q;
    cin>>q;
    while(q--){
        int l, r;
        cin>>l>>r;
        if((r-l)%2){
            continue;
        }
        vector<int> freq1(26, 0), freq2(26, 0);
        int mid = (l+r)/2;
        for(int i=0; i<26; i++){
            freq1[i]=prefix[r][i]-prefix[mid][i];
            freq2[i]=prefix[mid][i]-prefix[l-1][i];
        }
        int count = 0;
        for(int i=0; i<26; i++){
            if(freq1[i]!=freq2[i]){
                if(abs(freq1[i]-freq2[i])==1){
                    count++;
                }
                else{
                    count+=10;
                    break;
                }
            }
        }
        if(count==1){
            ans++;
        }
        else{
            for(int i=0; i<26; i++){
                freq1[i]=prefix[r][i]-prefix[mid-1][i];
                freq2[i]=prefix[mid-1][i]-prefix[l-1][i];
            }
            count = 0;
            for(int i=0; i<26; i++){
                if(freq1[i]!=freq2[i]){
                    if(abs(freq1[i]-freq2[i])==1){
                        count++;
                    }
                    else{
                        count+=10;
                        break;
                    }
                }
            }
            if(count==1){
                ans++;
            }
        }
    }
    cout<<ans<<endl;
    return;
}


signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t=1, tc=1;
    cin>>t;
    while (t--){
        cout<<"Case #"<<tc++<<": ";
        solve();       
    }
    return 0;
}
