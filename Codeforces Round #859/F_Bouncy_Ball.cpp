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
    int n, m, i, j, x, y;
    string s;
    cin>>n>>m>>i>>j>>x>>y>>s;
    string s0 = "";
    int ans = 0;
    int currx = i, curry = j;
    do{ 
        //Check if bounce
        if((currx == 1) && (curry == 1) && (s=="UL")){
            s = "DR";
            ans++;
        }
        else if((currx == 1) && (curry == m) && (s=="UR")){
            s = "DL";
            ans++;
        }
        else if((currx == n) && (curry == 1) && (s=="DL")){
            s = "UR";
            ans++;
        }
        else if((currx == n) && (curry == m) && (s=="DR")){
            s = "UL";
            ans++;
        }
        else if((currx == 1) && (s=="UL")){
            s = "DL";
            ans++;
        }
        else if((currx == 1) && (s=="UR")){
            s = "DR";
            ans++;
        }
        else if((currx == n) && (s=="DL")){
            s = "UL";
            ans++;
        }
        else if((currx == n) && (s=="DR")){
            s = "UR";
            ans++;
        }
        else if((curry == 1) && (s=="UL")){
            s = "UR";
            ans++;
        }
        else if((curry == 1) && (s=="DL")){
            s = "DR";
            ans++;
        }
        else if((curry == m) && (s=="UR")){
            s = "UL";
            ans++;
        }
        else if((curry == m) && (s=="DR")){
            s = "DL";
            ans++;
        }
        if((currx==i)&&(curry==j)&&(s==s0)) break;
        if(s0==""){
            s0 = s;
        }
        //Move to next position
        if(s=="DL"){
            currx++;
            curry--;
        }
        else if(s=="DR"){
            currx++;
            curry++;
        }
        else if(s=="UL"){
            currx--;
            curry--;
        }
        else if(s=="UR"){
            currx--;
            curry++;
        }
    }while( (((currx==x)&&(curry==y)) || ((currx==i)&&(curry==j)&&(s==s0))) == 0 );
    if( ((currx==i)&&(curry==j)&&(s==s0))){
        cout<<-1<<endl;
        return;
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
