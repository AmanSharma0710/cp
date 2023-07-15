#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define vi vector<int>
#define pii pair<int,int>
#define vii vector<pii>
#define rep(i,a,b) for(int i=a; i<b; i++)
bool sortbysec(const pair<int,int> &a, const pair<int,int> &b){                //to sort vii by second element use sort(v.begin(), v.end(), sortbysec);
    return (a.second < b.second);
}
#define MOD 998244353


int fact(int n){
    int ans = 1;
    for(int i=1; i<=n; i++){
        ans = (ans*i)%MOD;
    }
    return ans;
}

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int k;
    cin>>k;
    int teams = 1ll<<k;
    vector<int>v(teams);
    for(int i=0; i<teams; i++) cin>>v[i];
    int ans = 1;
    for(int i=1; i<=k; i++){
        int block_size = 1ll<<i;
        int changed1 = 0, changed2 = 1;
        for(int block = 0; block<teams/block_size; block++){
            int neg = 0, thres = 1ll<<(k-i), cnt = 0;
            for(int j=block*block_size; j<(block+1)*block_size; j++){
                if(v[j]==-1) neg++;
                else if(v[j]>thres) cnt++;
            }
            if(cnt==block_size || (cnt + neg < block_size-1)){
                cout<<0<<endl;
                return 0;
            }
            if(cnt == block_size-1){
                continue;
            }
            changed1++;
            changed2 = (changed2*neg)%MOD;
            for(int j=block*block_size; j<(block+1)*block_size; j++){
                if(v[j]==-1){
                    v[j] = teams;   //assign a very large value so that it is not considered in the next iteration
                    break;
                }
            }
        }
        ans = (ans*changed2)%MOD;
        ans = (ans*fact(changed1))%MOD;
    }
    cout<<ans<<endl;
    return 0;
}
