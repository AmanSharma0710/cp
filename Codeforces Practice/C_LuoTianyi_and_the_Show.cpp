#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n, m;
    cin>>n>>m;
    vector<int>v(m+1, 0);
    int first=0;
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        if(x<0) first++;
        if(x>0) v[x]=1;
    }
    if(first>=m){
        cout<<m<<endl;
        return;
    }
    int ans = INT_MAX, count=0;
    for(int i=1; i<=first; i++){
        count+=v[i];
    }
    ans = min(ans, count);
    for(int i=first+1; i<=m; i++){
        count+=v[i];
        count-=v[i-first];
        ans = min(ans, count);
    }
    cout<< (first + accumulate(v.begin(), v.end(), 0) - ans)<<endl;
    return;
}

int main(){
    // ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
