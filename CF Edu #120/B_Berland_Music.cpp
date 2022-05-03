#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define vi vector<int>
#define pii pair<int,int>
#define vii vector<pii>
#define rep(i,a,b) for(int i=a; i<b; i++)
#define rrep(i,a,b) for(int i=a; i>=b; i--)
#define pb push_back
bool sortbysec(const pair<int,int> &a, const pair<int,int> &b){                //to sort vii by second element use sort(v.begin(), v.end(), sortbysec);
    return (a.second < b.second);
}
#define MOD 1000000007
vi a;



void solve(){
    int n;
    cin>>n;
    a.resize(n);
    rep(i,0,n){
        cin>>a[i];
    }
    string s;
    cin>>s;
    vii disliked, liked;
    rep(i,0,n){
        if(s[i]=='0'){
            disliked.pb({i,a[i]});
        }
        else{
            liked.pb({i,a[i]});
        }
    }
    sort(disliked.begin(), disliked.end(), sortbysec);
    sort(liked.begin(), liked.end(), sortbysec);
    vi rating(n);
    int cnt = 1;
    for(int i=0; i<disliked.size(); i++){
        rating[disliked[i].first] = cnt;
        cnt++;
    }
    for(int i=0; i<liked.size(); i++){
        rating[liked[i].first] = cnt;
        cnt++;
    }
    rep(i,0,n){
        cout<<rating[i]<<" ";
    }
    cout<<endl;
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
