#include<bits/stdc++.h>
using namespace std;


class Solution {
  public:
    int maxLength(string S) {
        map<char, int> mp;
        for(int i=0; i<S.size(); i++){
            mp[S[i]]++;
        }
        vector<pair<int, int>> v;
        for(auto it=mp.begin(); it!=mp.end(); it++){
            v.push_back(make_pair(it->second, it->second));
        }
        for(int i=0; i<26; i++){
            for(int j=(int)v.size()-1; j>0; j--){
                if(v[j].first == v[j-1].first && v[j-1].first > 0){
                    v[j-1].first--;
                }
            }
            sort(v.begin(), v.end());
        }
        for(auto it=mp.begin(); it!=mp.end(); it++){
            for(auto it2=v.begin(); it2!=v.end(); it2++){
                if(it->second == it2->second){
                    it->second = it2->first;
                    v.erase(it2);
                    break;
                }
            }
        }
        string s = "";
        for(auto it=S.begin(); it!=S.end(); it++){
            if(mp[*it]>0){
                s += *it;
                mp[*it]--;
            }
        }
        return s;
    }
};


signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t=1;
    cin>>t;
    while (t--){
        int n, x;
        cin>>n>>x;
        vector<int> A(n);
        for(int i=0; i<n; i++){
            cin>>A[i];
        }
        Solution obj;
        auto ans = obj.solve(n, x, A);
        cout<<ans<<endl;    
    }
    return 0;
}
