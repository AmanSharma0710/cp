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
    set<int> s;
    for(int i=0; i<n; i++){
        while(v[i]>n){
            v[i]/=2;
        }
        while(s.find(v[i])!=s.end()){
            v[i]/=2;
            if(!v[i]){
                cout<<"NO"<<endl;
                return;
            }
        }
        s.insert(v[i]);
    }
    cout<<"YES"<<endl;
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
