#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;
#define int long long int
#define vi vector<int>
#define pii pair<int,int>
#define vii vector<pii>
#define rep(i,a,b) for(int i=a; i<b; i++)
#define MOD 1000000007


void solve(){
    int n;
    cin>>n;
    unordered_set <int> factors;
    for(int i=2; i<=sqrt(n); i++){
        if(n%i==0){
            factors.insert(i);
            factors.insert(n/i);
        }
    }
    for(auto j=factors.begin(); j!=factors.end(); j++){
        for(auto i=j++; i!=factors.end(); i++){
            int a = *j;
            int b = *i;
            int c = n/(a*b);
            if(c!=a && c!=b && a!=b && c>1 && a*b*c==n){
                cout<<"YES"<<endl;
                cout<<a<<" "<<b<<" "<<c<<endl;
                return;
            }
        }
    }
    cout<<"NO"<<endl;
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
