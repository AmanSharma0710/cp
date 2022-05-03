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
#define MOD 1000000007

int value(int mid, int k){
    if(mid<=k){
        return (mid*(mid+1))/2;
    }
    int ans=k*k;
    ans -= (2*k-mid - 1)*(2*k-mid)/2;
    return ans;
}

void solve(){
    int k, x;
    cin>>k>>x;
    if(x >= k*k){
        cout<<(2*k-1)<<endl;
        return;
    }
    int ans = 0;
    int left=0, right=2*k-1, mid;
    while(left<=right){
        mid = (left+right)/2;
        int val = value(mid, k);
        if(val==x){
            break;
        }
        if(val < x){
            left = mid+1;
        }
        else{
            right = mid-1;
        }
    }
    if(value(mid, k)==x){
        cout<< mid <<endl;
        return;
    }
    if(value(mid, k)<x){
        cout<< mid+1 <<endl;
        return;
    }
    cout<< mid <<endl;
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
