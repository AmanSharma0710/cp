#include<bits/stdc++.h>
using namespace std;


int main(){
    string s;
    cin>>s;
    int n = s.length();
    vector<int>pi(n, 0);
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
    vector<int> ans(n+1, 0);
    for(int i=0; i<n; i++){
        ans[pi[i]]++;
    }
    for(int i=n-1; i>0; i--){
        ans[pi[i-1]] += ans[i];
    }
    for(int i=0; i<=n; i++){
        ans[i]++;
    }
    set<pair<int, int>>p;
    int i=n;
    while(i>0){
        p.insert({i, ans[i]});
        i = pi[i-1];
    }
    cout<<p.size()<<endl;
    for(auto it:p){
        cout<<it.first<<" "<<it.second<<endl;
    }
    return 0;
}