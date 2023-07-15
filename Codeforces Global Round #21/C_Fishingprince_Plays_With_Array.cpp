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
    vi a(n);
    rep(i,0,n) cin>>a[i];
    int k;
    cin>>k;
    vi b(k);
    rep(i,0,k) cin>>b[i];
    if(abs(n-k)%(m-1)!=0){
        cout<<"No"<<endl;
        return;
    }
    queue<pii> q;
    for(int i=0; i<n; i++){
        q.push({a[i],1});
    }
    for(int i=0; i<n; i++){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        while(x%m==0){
            x/=m;
            y*=m;
        }
        q.push({x,y});
    }
    bool possible = true;
    for(int i=0; i<k; i++){
        if(q.empty()){
            possible = false;
            break;
        }
        if(b[i]<q.front().first){
            possible = false;
            break;
        }
        if(b[i]==q.front().first){
            q.front().second--;
            if(q.front().second==0){
                q.pop();
            }
            continue;
        }
        if((b[i]%q.front().first)==0){
            int cnt = b[i]/q.front().first;
            int val = q.front().first;
            while(cnt>0){
                if(q.empty()){
                    possible = false;
                    break;
                    }
                bool multiple = false;
                int x = q.front().first;
                while(x<=b[i]){
                    if(x==b[i]){
                        multiple = true;
                        break;
                    }
                    x*=m;
                }
                if(!multiple){
                    possible = false;
                    break;
                }
                if(q.front().first!=val){
                    possible = false;
                    break;
                }
                if(q.front().second>cnt){
                    q.front().second-=cnt;
                    cnt=0;
                }
                else{
                    cnt-=q.front().second;
                    q.pop();
                }
            }
        }
        else{
            possible = false;
            break;
        }
    }
    if(!q.empty()){
        possible = false;
    }
    cout<<(possible?"Yes":"No")<<endl;
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
