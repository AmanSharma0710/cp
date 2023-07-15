#include<bits/stdc++.h>
using namespace std;
#define int long long int


void solve(){
    int n;
    cin>>n;
    vector<int> factors;
    for(int i=1; i*i<=n; i++){
        if(n%i==0){
            factors.push_back(i);
            if(i!=n/i) factors.push_back(n/i);
        }
    }
    sort(factors.begin(), factors.end());
    string ans = "";
    for(int i=0; i<n; i++){
        vector<int> mex(26, 0);
        for(int j=0; j<factors.size(); j++){
            if(i-factors[j]>=0){
                mex[ans[i-factors[j]]-'a'] = 1;
            }
            else break;
        }
        for(int j=0; j<26; j++){
            if(mex[j]==0){
                ans += (char)(j+'a');
                break;
            }
        }
    }
    cout<<ans<<endl;
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
