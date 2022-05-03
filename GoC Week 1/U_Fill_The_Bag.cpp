#include<bits/stdc++.h>
using namespace std;
#define int long long int



void solve(){
    int n, m;
    cin>>n>>m;
    vector<int> v(m);
    for(int i=0; i<m; i++){
        cin>>v[i];
    }
    int ans = accumulate(v.begin(), v.end(), 0ll);
    if(ans==n){
        cout<<"0"<<endl;
        return;
    }
    if(ans<n){
        cout<<-1<<endl;
        return;
    }
    vector<int> number;
    while(n){
        number.push_back(n%2);
        n/=2;
    }
    while(number.size()<64){
        number.push_back(0);
    }
    map<int, int> mp;
    for(int i=0; i<32; i++){
        mp[1<<i] = i;
    }
    vector<int> available(64, 0);
    for(int i=0; i<m; i++){
        available[mp[v[i]]]++;
    }
    for(int i=0; i<64; i++){
        if(number[i]==1){
            available[i]--;
        }
    }
    ans=0;
    for(int i=0; i<63; i++){
        if(available[i]>0){
            available[i+1]+=available[i]/2;
            available[i]%=2;
        }
        if(available[i]<0){
            for(int j=i; j<64; j++){
                if(available[j]>0){
                    available[j]--;
                    available[i]+= (1<<(j-i));
                    ans+=(j-i);
                    break;
                }
            }
            available[i+1]+=available[i]/2;
            available[i]%=2;
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
