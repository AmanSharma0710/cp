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
    vector<vector<int>> a(n, vector<int>(m));
    vector<int> big, small;
    int total = 0;
    rep(i, 0, n){
        rep(j, 0, m){
            cin>>a[i][j];
            total += a[i][j];
        }
    }
    if(total%n != 0){
        cout<<-1<<endl;
        return;
    }
    int avg = total/n;
    int steps = 0;
    rep(i, 0, n){
        int sum = 0;
        rep(j, 0, m){
            sum += a[i][j];
        }
        if(sum > avg){
            big.push_back(i);
            steps+= sum-avg;
        }
        else if(sum < avg){
            small.push_back(i);
        }
    }
    cout<<steps<<endl;
    while(big.size()>0){
        int i = big.back();
        int j = small.back();
        int sum1 = 0;
        rep(k, 0, m){
            sum1 += a[i][k];
        }
        int sum2 = 0;
        rep(k, 0, m){
            sum2 += a[j][k];
        }
        for(int k=0; k<m; k++){
            if(sum1 == avg){
                big.pop_back();
                break;
            }
            if(sum2 == avg){
                small.pop_back();
                break;
            }
            if(a[i][k]==1 && a[j][k]==0){
                a[i][k] = 0;
                a[j][k] = 1;
                sum1--;
                sum2++;
                cout<<i+1<<" "<<j+1<<" "<<k+1<<endl;
            }
        }
    }
    
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
