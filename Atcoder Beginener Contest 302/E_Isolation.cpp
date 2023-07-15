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
    vector<int> degree(n+1, 0);
    set<pair<int, int>> s1;
    int vertices = n;
    for(int qq=0; qq<q; qq++){
        int type;
        cin>>type;
        if(type==1){
            int u, v;
            cin>>u>>v;
            if(degree[u]==0) vertices--;
            if(degree[v]==0) vertices--;
            degree[u]++;
            degree[v]++;
            s1.insert({u, v});
            s1.insert({v, u});
        }
        else if(type==2){
            int u;
            cin>>u;
            if(degree[u]==0);
            else{
                //delete all edges of u
                vector<int> neigh;
                auto it = s1.lower_bound({u, 0});
                while(it!=s1.end() && it->first==u){
                    neigh.push_back(it->second);
                    it++;
                }
                for(auto x: neigh){
                    s1.erase({u, x});
                    s1.erase({x, u});
                    degree[x]--;
                    if(degree[x]==0) vertices++;
                }
                degree[u]=0;
                vertices++;
            }
        }
        cout<<vertices<<endl;
    }
    return 0;
}
