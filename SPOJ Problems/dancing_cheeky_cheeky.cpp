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
    int idx = 0;
    for(int i=0; i<n; i++){
        if(pi[i]>pi[idx]) idx = i;
    }
    int len = n - pi[n-1], start_idx = n - 2*len;
    for(int i=0; i<8; i++){
        cout<<s[start_idx];
        start_idx = (start_idx+1)%len;
    }
    cout<<"..."<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}