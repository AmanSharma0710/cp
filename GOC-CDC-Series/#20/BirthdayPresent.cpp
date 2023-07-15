#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n, k;
    cin>>n>>k;
    string s;
    cin>>s;
    int ans = 1;
    int l=0, r=0;
    vector<int> cnt(26, 0);
    auto num = [&](vector<int>& cnt){
        multiset<int> s;
        int sum = 0;
        for(int i=0; i<26; i++){
            s.insert(cnt[i]);
            sum += cnt[i];
        }
        sum -= *s.rbegin();
        sum -= *(++s.rbegin());
        return sum;

    };
    while(r<n){
        cnt[s[r]-'a']++;
        while(num(cnt)>k){
            cnt[s[l]-'a']--;
            l++;
        }
        ans = max(ans, r-l+1);
        r++;
    }
    cout<<ans<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}