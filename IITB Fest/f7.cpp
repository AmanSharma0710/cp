#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define vi vector<int>


signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;
    cin>>n;
    vi v(n), pre(n), post(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    sort(v.begin(), v.end());
    for(int i=0;i<n;i++){
        pre[i]=v[i]+n-i-1;
        post[i]=v[i] + n -i;
    }
    for(int i=1; i<n; i++){
        pre[i] = max(pre[i], pre[i-1]);
        post[n-i-1] = max(post[n-i-1], post[n-i]);
    }
    int ans = 1;
    if(v[0]+n >=post[1]){
        ans++;
    }
    for(int i=1; i<n-1; i++){
        v[i]+=n;
        if(v[i]>=pre[i-1] && v[i]>=post[i+1]){
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}
