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


string add(string a, string b){
    string ans;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    while(a.size()!=b.size()){
        if(a.size()<b.size()){
            a.push_back('0');
        }
        else{
            b.push_back('0');
        }
    }
    int curr=0;
    while(curr<a.size()){
        int x = a[curr]-'0';
        int y = b[curr]-'0';
        int sum = x+y;
        if(sum<=9){
            ans.push_back(sum+'0');
        }
        else{
            ans.push_back(sum%10+'0');
            ans.push_back(sum/10+'0');
        }
        curr++;
    }
    while(ans.back()=='0'){
        ans.pop_back();
    }
    return ans;
}



void solve(){
    string s, a, b="";
    cin>>a>>s;
    reverse(s.begin(), s.end());
    reverse(a.begin(), a.end());
    while(a.size()<s.size()){
        a.push_back('0');
    }
    int p1=0, p2=0;
    while(p1<a.size() && p2<s.size()){
        if(s[p2]>=a[p1]){
            b.push_back(s[p2] - a[p1] + '0');
            p1++;
            p2++;
        }
        else{
            b.push_back((s[p2]-'0') + 10*(s[p2+1]-'0') - (a[p1] - '0') + '0');
            p2+=2;
            p1++;
        }
    }
    while(b.back()=='0'){
        b.pop_back();
    }
    reverse(b.begin(), b.end());
    reverse(a.begin(), a.end());
    for(int i=0; i<b.size(); i++){
        if(b[i]<'0' || b[i]>'9'){
            cout<<"-1"<<endl;
            return;
        }
    }
    string ans=add(a, b);
    if(ans==s){
        cout<<b<<endl;
    }
    else{
        cout<<"-1"<<endl;
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
