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
    vector<deque<char>> q;
    vector<int> ans;
    int pushed=0;
    deque<char> d;
    for(int i=0; i<s.size(); i++){
        if(s[i]=='('){
            d.push_back(s[i]);
            pushed++;
        }
        else if(s[i]==')'){
            d.push_back(s[i]);
            pushed--;
        }
        if(pushed==0){
            q.push_back(d);
            ans.push_back(INT_MAX);
            d.clear();
        }
    }
    for(int i=0; i<q.size(); i++){
        int cnt=0;
        char front = q[i].front();
        char back = q[i].back();
        while(front=='('){
            cnt++;
            q[i].pop_front();
            front = q[i].front();
        }
        ans[i] = min(ans[i], cnt);
        cnt=0;
        while(back==')'){
            cnt++;
            q[i].pop_back();
            if(q[i].empty())
                break;
            back = q[i].back();
        }
        ans[i] = min(ans[i], cnt);
    }
    int answer=INT_MAX;
    for(int i=0; i<ans.size(); i++){
        answer = min(answer, ans[i]);
    }
    cout<<answer<<endl;
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
