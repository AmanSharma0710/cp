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
    int n, k;
    cin>>n>>k;
    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    int sqsum=0, sum=0;
    for(int i=0; i<n; i++){
        sum+=a[i];
        for(int j=i+1; j<n; j++){
            sqsum+=a[i]*a[j];
        }
    }
    if(sqsum==0){
        cout<<0<<endl;
        return;
    }
    if(sum==0){
        cout<<"IMPOSSIBLE"<<endl;
        return;
    }
    if(abs(sum)<=abs(sqsum)){
        if(sqsum%sum==0){
            cout<<-sqsum/sum<<endl;
            return;
        }
    }
    cout<<sqsum<<" "<<sum<<endl;
    vector<int> v;
    int x=sqsum%sum;
        v.push_back(-x);
        cout<<x<<endl;
        sqsum += sum*(-x);
        sum += -x;
        if(abs(sum)<=abs(sqsum)){
            if(sqsum%sum==0){
                for(int j=0; j<v.size(); j++){
                    cout<<v[j]<<" ";
                }
                cout<<endl;
                return;
            }
        }
    for(int i=1; i<k; i++){
        int x=sqsum/sum;
        v.push_back(-x);
        cout<<x<<endl;
        sqsum += sum*(-x);
        sum += -x;
        if(abs(sum)<=abs(sqsum)){
            if(sqsum%sum==0){
                for(int j=0; j<v.size(); j++){
                    cout<<v[j]<<" ";
                }
                cout<<endl;
                return;
            }
        }
    }
    cout<<"IMPOSSIBLE"<<endl;
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
