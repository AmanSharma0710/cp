#include<bits/stdc++.h>
using namespace std;

void solve(){
    string s;
    cin>>s;
    int n = s.length();
    vector<int> pi(n, 0);
    for(int i=1; i<n; i++){
        int j = pi[i-1];
        while(j>0 && s[i]!=s[j]){
            j = pi[j-1];
        }
        if(s[i]==s[j]){
            j++;
        }
        pi[i] = j;
    }
    int ans = n - pi[n-1];
    if(n%ans){
        cout<<n<<endl;
    }
    else{
        cout<<ans<<endl;
    }
    return;
}


signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t=1;
    cin>>t;
    while (t--){
        solve();
        if(t) cout<<endl;
    }
    return 0;
}
