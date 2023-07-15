#include<bits/stdc++.h>
using namespace std;

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, m;
    cin>>n>>m;
    vector<int> a(n), b(m);
    for(int i=0; i<n; i++)cin>>a[i];
    for(int i=0; i<m; i++) cin>>b[i];
    if(m==1){
        cout<<n<<endl;
        return 0;
    }
    vector<int> v;
    for(int i=0; i<m-1; i++){
        v.push_back(b[i+1] - b[i]);
    }
    v.push_back(INT_MAX);
    for(int i=0; i<n-1; i++){
        v.push_back(a[i+1] - a[i]);
    }
    vector<int> pi(v.size(), 0);
    for(int i=1; i<v.size(); i++){
        int j = pi[i-1];
        while(j>0 && v[i]!=v[j]){
            j = pi[j-1];
        }
        if(v[i]==v[j]){
            j++;
        }
        pi[i] = j;
    }
    int ans = 0;
    for(int i=0; i<v.size(); i++){
        if(pi[i]==(m-1)){
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}
