#include<bits/stdc++.h>
using namespace std;
#define int long long int


void solve(){
    int n, k;
    cin>>n>>k;
    string s;
    cin>>s;
    vector<int> v;
    int ans = 0;
    while(!s.empty()){
        char x = s.back();
        s.pop_back();
        if(!v.empty() && v.back() == x){
            v.pop_back();
            ans ++;
        }
        else{
            v.push_back(x);
        }
    }
    cout<< (ans%k + 1) <<endl;
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
