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


void solve(){
    string s;
    cin >> s;
    int n = s.size();
    vector<int> c(n, 0);
    int open=0, close=0;
    for(int i=0; i<n; i++){
        if(s[i]=='?'){
            c[i] = 1;
        }
        else if(s[i]=='('){
            open++;
        }
        else{
            close++;
        }
    }
    open = n/2 - open;
    close = n/2 - close;
    for(int i=0; i<n; i++){
        if(s[i]=='?'){
            if(open>0){
                s[i] = '(';
                open--;
            }
            else{
                s[i] = ')';
                close--;
            }
        }
    }
    vector<int> ropen(n)
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
