#include<bits/stdc++.h>
using namespace std;
#define int long long int



void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    int prefix[n+1] = {0}, postfix[n+1] = {0};
    int prefix1[n+1] = {0}, postfix1[n+1] = {0};
    for (int i=1; i<=n; i++){
        prefix[i] = prefix[i-1];
        prefix1[i] = prefix1[i-1];
        if (s[i-1] == 'V') prefix[i]++;
        if (s[i-1] == 'M') prefix1[i]++;
    }
    for(int i=n-1; i>=0; i--){
        postfix[i] = postfix[i+1];
        postfix1[i] = postfix1[i+1];
        if (s[i] == 'M') postfix[i]++;
        if (s[i] == 'V') postfix1[i]++;
    }
    int ans = 0;
    for (int i=0; i<n; i++){
        if (s[i] == 'V'){
            int after = postfix[i+1];
            after = (after*(after-1))/2;
            ans += prefix[i]*after;
        }
        if (s[i] == 'M'){
            int after = postfix1[i+1];
            after = (after*(after-1))/2;
            ans += prefix1[i]*after;
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
