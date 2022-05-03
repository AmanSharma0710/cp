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
    int r, g, b;
    cin>>r>>g>>b;
    if(r+g<b){
        cout<<"-1"<<endl;
        return;
    }
    int n=r+g+b;
    vector<char> color(n);
    vii edges;
    color[0]='B';
    color[1]='G';
    color[2]='R';
    edges.push_back({0,1});
    edges.push_back({1,2});
    r--;
    b--;
    g--;
    int ptr=3;
    if(b){
        color[ptr]='B';
        edges.push_back({2,ptr});
        ptr++;
        b--;
    }
    while(b){
        if(r){
            color[ptr]='R';
            color[ptr+1]='B';
            r--;
            b--;
            edges.push_back({ptr,1});
            edges.push_back({ptr,ptr+1});
            ptr+=2;
            continue;
        }
        if(g){
            color[ptr]='G';
            color[ptr+1]='B';
            g--;
            b--;
            edges.push_back({ptr,2});
            edges.push_back({ptr,ptr+1});
            ptr+=2;
            continue;
        }
    }
    while(r>0 || g>0){
        if(r){
            color[ptr]='R';
            r--;
            edges.push_back({ptr,0});
            ptr++;
            continue;
        }
        if(g){
            color[ptr]='G';
            g--;
            edges.push_back({ptr,0});
            ptr++;
            continue;
        }
    }
    for(int i=0;i<n;i++){
        cout<<color[i];
    }
    cout<<endl;
    for(int i=0;i<edges.size();i++){
        cout<<edges[i].first+1<<" "<<edges[i].second+1<<endl;
    }
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
