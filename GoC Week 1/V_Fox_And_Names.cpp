#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;
    cin>>n;
    adj.resize(26);
    string s[n];
    for(int i=0;i<n;i++){
        cin>>s[i];
    }
    for(int i=0; i<n-1; i++){
        if(s[i].size()<=s[i+1].size()){
            for(int j=0; j<s[i].size(); j++){
                if(s[i][j]!=s[i+1][j]){
                    adj[s[i][j]-'a'].push_back(s[i+1][j]-'a');
                    break;
                }
            }
        }
        else{
            int j=0;
            for(j=0; j<s[i+1].size(); j++){
                if(s[i][j]!=s[i+1][j]){
                    adj[s[i][j]-'a'].push_back(s[i+1][j]-'a');
                    break;
                }
            }
            if(j==s[i+1].size()){
                cout<<"Impossible"<<endl;
                return 0;
            }
        }
    }
    int visitednodes = 0;
    vector<int> indegree(26,0);
    for(int i=0; i<26; i++){
        for(int j=0; j<adj[i].size(); j++){
            indegree[adj[i][j]]++;
        }
    }
    queue<int> q;
    for(int i=0; i<26; i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    vector<char> ans;
    while(!q.empty()){
        int front = q.front();
        ans.push_back(front+'a');
        q.pop();
        visitednodes++;
        for(int i=0; i<adj[front].size(); i++){
            indegree[adj[front][i]]--;
            if(indegree[adj[front][i]]==0){
                q.push(adj[front][i]);
            }
        }
    }
    if(visitednodes!=26){
        cout<<"Impossible"<<endl;
    }
    else{
        for(int i=0; i<ans.size(); i++){
            cout<<ans[i];
        }   
        cout<<endl;
    }
    return 0;
}
