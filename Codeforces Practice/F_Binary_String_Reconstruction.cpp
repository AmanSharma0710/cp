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
    int n1,n2,n3;
    cin>>n1>>n2>>n3;
    string s;
    if(n1||n2){
        s.push_back('0');
    }
    for(int i=0; i<n1; i++){
        s.push_back('0');
    }
    for(int i=0; i<n2/2; i++){
        s.push_back('1');
        s.push_back('0');
    }
    if(n2%2==1){
        s.push_back('1');
    }
    if(n3==0){
        cout<<s<<endl;
        return;
    }
    bool flag=false;
    if(s[s.size()-1]=='1'){
        n3--;
    }
    else{
        if(s.size()){
            s.pop_back();
            flag=true;
        }
    }
    for(int i=0; i<=n3; i++){
        s.push_back('1');
    }
    if(flag){
        s.push_back('0');
    }
    cout<<s<<endl;
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
