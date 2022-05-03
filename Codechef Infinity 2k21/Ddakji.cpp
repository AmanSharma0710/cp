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


void solve(){
    int n;
    int gcd_positive=0, gcd_negative=0;
    int positive=0, negative=0, zeros=0; 
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++){
        cin>>a[i];
        if(a[i]==0){
            zeros++;
            continue;
        }
        if(a[i]>0){
            positive++;
            gcd_positive= gcd(gcd_positive, a[i]);
        }
        else{
            negative++;
            gcd_negative= gcd(gcd_negative, a[i]);
        }
    }
    if(positive>1){
        zeros+=positive-1;
    }
    if(negative>1){
        zeros+=negative-1;
    }
    if(zeros && gcd_positive && gcd_negative){
        cout<<(2*gcd(gcd_positive, gcd_negative))<<endl;
        return;
    }
    cout<<(gcd_positive+gcd_negative)<<endl;
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
