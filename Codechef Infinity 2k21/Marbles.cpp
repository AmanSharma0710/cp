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

bool isVowel(char c){
    if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u') return true;
    return false;
}

int calc(string s, string t, char c){
    for(int i=0; i<s.size(); i++){
        if(s[i]=='?'){
            s[i]=c;
        }
    }
    for(int i=0; i<t.size(); i++){
        if(t[i]=='?'){
            t[i]=c;
        }
    }
    int ans=0;
    for(int i=0; i<s.size(); i++){
        if(s[i]==t[i]){
            continue;
        }
        if(isVowel(s[i]) != isVowel(t[i])){
            ans++;
        }
        else{
            ans+=2;
        }
    }
    return ans;
}

void solve(){
    int n;
    string s, t;
    cin>>n>>s>>t;
    int cost = INT_MAX;
    for(char c='a'; c<='z'; c++){
        cost = min(cost, calc(s, t, c));
    }
    cout<<cost<<endl;
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
