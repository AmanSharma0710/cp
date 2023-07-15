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

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;
    cin>>n;
    int a[n];
    rep(i,0,n) cin>>a[i];
    sort(a,a+n);
    int b[n];
    for(int i=0; i<n/2; i++){
        b[i*2] = a[i];
        b[i*2+1] = a[n/2+i+1];
    }
    b[n-1] = a[n/2];
    bool flag = true;
    for(int i=1; i<n; i+=2){
        if(b[i]<=b[i-1] || b[i]<=b[i+1]){
            flag = false;
            break;
        }
    }
    cout<<(flag?"Yes":"No")<<endl;
    return 0;
}
