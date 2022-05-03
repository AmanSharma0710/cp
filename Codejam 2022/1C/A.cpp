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
    int n;
    cin>>n;
    vector<string> s(n);
    for(int i=0; i<n; i++){
        cin>>s[i];
    }
    vector<vector<int>> start(26, vector<int>(0)), end(26, vector<int>(0));
    for(int i=0; i<n; i++){
        start[s[i][0]-'A'].push_back(i);
        end[s[i][s[i].size()-1]-'A'].push_back(i);
    }
    deque<int> q, buffer;
    vector<bool> taken(n, false);
    q.push_back(0);
    taken[0] = true;
    for(int i=0; i<n-1; i++){
        bool added = false;
        int cur = q.front();
        int last_char = s[cur][0]-'A';
        for(int j=0; j<end[last_char].size(); j++){
            if(s[end[last_char][j]][0] == s[end[last_char][j]][s[end[last_char][j]].size()-1] && !taken[end[last_char][j]]){
                q.push_front(end[last_char][j]);
                taken[end[last_char][j]] = true;
                added = true;
                break;
            }
        }
        if(!added){
            int last_char = s[cur][0]-'A';
            for(int j=0; j<end[last_char].size(); j++){
                if(!taken[end[last_char][j]]){
                    q.push_front(end[last_char][j]);
                    taken[end[last_char][j]] = true;
                    added = true;
                    break;
                }
            }
        }
        cur=q.back();
        int first_char = s[cur][s[cur].size()-1]-'A';
        if(!added){
            for(int j=0; j<start[first_char].size(); j++){
                if(s[start[first_char][j]][0] == s[start[first_char][j]][s[start[first_char][j]].size()-1] && !taken[start[first_char][j]]){
                    q.push_back(start[first_char][j]);
                    taken[start[first_char][j]] = true;
                    added = true;
                    break;
                }
            }
        }
        if(!added){
            for(int j=0; j<start[first_char].size(); j++){
                if(!taken[start[first_char][j]]){
                    q.push_back(start[first_char][j]);
                    taken[start[first_char][j]] = true;
                    added = true;
                    break;
                }
            }
        }
        if(!added){
            while(!q.empty()){
                buffer.push_back(q.front());
                q.pop_front();
            }
            for(int j=0; j<n; j++){
                if(!taken[j]){
                    q.push_back(j);
                    taken[j] = true;
                    break;
                }
            }
        }
    }
    for(int i=0; i<n; i++){
        if(!taken[i]){
            cout<<"IMPOSSIBLE"<<endl;
            return;
        }
    }
    string ans="";
    while(!q.empty()){
        buffer.push_back(q.front());
        q.pop_front();
    }
    while(!buffer.empty()){
        ans+=s[buffer.front()];
        buffer.pop_front();
    }
    bool char_taken[26] = {false};
    char_taken[ans[0]-'A'] = true;
    for(int i=1; i<ans.size(); i++){
        if(char_taken[ans[i]-'A'] && ans[i]!=ans[i-1]){
            cout<<"IMPOSSIBLE"<<endl;
            return;
        }   
        char_taken[ans[i]-'A'] = true;
    }
    cout<<ans<<endl;
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
