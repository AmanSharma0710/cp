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
    string s, t;
    cin>>s>>t;
    int cntsa=0, cntsb=0, cntsc=0, cntta=0, cnttb=0, cnttc=0;
    bool a=false, c = false;
    vector<int> prea(n+1), prec(n+1);
    vector<pair<int, int>>apr(n), cpr(n);
    rep(i,0,n){
        if(s[i]=='a'){
            apr[cntsa].first = i;
            cntsa++;
            prea[i+1] = 1;
        }
        else if(s[i]=='b'){
            cntsb++;
        }
        else{
            cpr[cntsc].first = i;
            cntsc++;
            prec[i+1] = 1;
        }
        if(t[i]=='a'){
            apr[cntta].second = i;
            cntta++;
            prea[i+1] = 1;
        }
        else if(t[i]=='b'){
            cnttb++;
        }
        else{
            cpr[cnttc].second = i;
            cnttc++;
            prec[i+1] = 1;
        }
        if((cntta>cntsa) || (cnttc<cntsc)){
            cout<<"NO"<<endl;
            return;
        }
    }
    if((cntsa!=cntta) || (cntsb!=cnttb) || (cntsc!=cnttc)){
        cout<<"NO"<<endl;
        return;
    }
    for(int i=1; i<=n; i++){
        prea[i] = prea[i-1] + prea[i];
        prec[i] = prec[i-1] + prec[i];
    }
    for(int i=0; i<cntsa; i++){
        if(prec[max(apr[i].first, apr[i].second)+1]>prec[min(apr[i].first, apr[i].second)]){
            cout<<"NO"<<endl;
            return;
        }
    }
    for(int i=0; i<cntsc; i++){
        if(prea[max(cpr[i].first, cpr[i].second)+1]>prea[min(cpr[i].first, cpr[i].second)]){
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;
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
