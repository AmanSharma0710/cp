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
    string s1[2];
    cin>>s1[0]>>s1[1];
    int t, q;
    cin>>t>>q;
    int n = s1[0].size();
    set<int> s;
    for(int i=0; i<n; i++){
        if(s1[0][i] == s1[1][i]) continue;
        s.insert(i);
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for(int qq = 0; qq<q; qq++){
        while(!pq.empty() && pq.top().first == qq){
            int pos = pq.top().second;
            pq.pop();
            s.insert(pos);
        }
        int type;
        cin>>type;
        if(type == 1){
            int pos;
            cin>>pos;
            pos--;
            if(s1[0][pos] == s1[1][pos]){

            }
            else{
                s.erase(pos);
                pq.push({qq+t, pos});
            }
        }
        if(type==2){
            int which1, pos1, which2, pos2;
            cin>>which1>>pos1>>which2>>pos2;
            pos1--; pos2--;
            which1--; which2--;
            swap(s1[which1][pos1], s1[which2][pos2]);
            if(s1[0][pos1]!=s1[1][pos1]){
                s.insert(pos1);
            }
            else{
                s.erase(pos1);
            }
            if(s1[0][pos2]!=s1[1][pos2]){
                s.insert(pos2);
            }
            else{
                s.erase(pos2);
            }
        }
        if(type==3){
            cout<<(s.size()==0?"YES":"NO")<<endl;
        }
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
