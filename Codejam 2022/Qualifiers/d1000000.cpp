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
    int n;
    cin>>n;
    vector<int> v(n);
    for(auto &i:v){
        cin>>i;
    }
    sort(v.begin(), v.end());
    int ans = INT_MAX;
    for(int i=n-1; i>=0; i--){
        int required_height = ans - (n-1-i);
        if(required_height<=0){
            cout<<(n-1-i)<<endl;
            return;
        }
        if(required_height>v[i]){
            ans = v[i] + (n-1-i);
        }
    }
    cout<<n<<endl;
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
