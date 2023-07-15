#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;
    cin>>n;
    vector<int> a(n);
    for(auto &i:a) cin>>i;
    vector<int> m(2e5+1, 0);
    int offset = 1e5;
    m[offset+0] = 1;
    int ans = 0;
    for(int i=0; i<n; i++){
        vector<int> temp(2e5+1, 0);
        for(int j=0; j<2e5+1; j++){
            if(m[j]){
                temp[j-a[i]]  = (m[j]+temp[j-a[i]])%mod;
                temp[j+a[i]] = (m[j]+temp[j+a[i]])%mod;
            }
        }
        ans += temp[offset];
        ans %= mod;
        temp[offset]++;
        m = temp;
    }
    cout<<ans<<endl;
    return 0;
}
