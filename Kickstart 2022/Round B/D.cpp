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
vector<vector<int>> v;

void print_odd_row_first_line(int c){
    if(c==1){
        cout<<"S";
    }
    else{
        cout<<"E";
    }
    for(int i=1; i<c; i++){
        if(i==c-1){
            cout<<"ES";
        }
        else{
            cout<<"EE";
        }
    }
    return;
}

void print_odd_row_second_line(int curr_row, int c, bool last){
    for(int i=c-1; i>0; i--){
            if(v.size()==curr_row+1){
                cout<<"WW";
            }
            else{
                if(v[curr_row+1][i]==1){
                    cout<<"SSWNNW";
                }
                else{
                    cout<<"WW";
                }
            }
        }
            if(last){
                cout<<"W";
            }
            else{
                cout<<"S";
            }
    return;
}

void solve(){
    int r, c;
    cin>>r>>c;
    v.assign(r, vector<int>(c));
    rep(i,0,r){
        rep(j,0,c){
            char x;
            cin>>x;
            if(x=='*'){
                v[i][j]=1;
            }
            else{
                v[i][j]=0;
            }
        }
    }
    cout<<"E";
    for(int i=0; i<r; i++){
        if(i%2==0){
            print_odd_row_first_line(c);
            if(i==r-1){
                print_odd_row_second_line(i, c, true);
            }
            else{
                print_odd_row_second_line(i, c, false);
            }
        }
        else{
            if(i==r-1){
                cout<<"SW";
            }
            else{
                cout<<"SS";
            }
        }
    }
    for(int i=0; i<r; i++){
        if(i==r-1){
            cout<<"N";
        }
        else{
            cout<<"NN";
        }
    }
    cout<<endl;
    v.clear();
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
