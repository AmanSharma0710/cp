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

vector<int> arr;
bool func(int n){
    int l=0, r=n-1, del = 0;
    while(l<r){
        if(arr[l]==arr[r]){
            l++;
            r--;
        }
        else{
            if(del==0){
                del=arr[l];
            }
            if(arr[l]==del){
                l++;
            }
            else if(arr[r]==del){
                r--;
            }
            else return false;
        }
    }
    return true;
}
bool func1(int n){
    int l=0, r=n-1, del = 0;
    while(l<r){
        if(arr[l]==arr[r]){
            l++;
            r--;
        }
        else{
            if(del==0){
                del=arr[r];
            }
            if(arr[l]==del){
                l++;
            }
            else if(arr[r]==del){
                r--;
            }
            else return false;
        }
    }
    return true;
}

void solve(){
    int n;
    cin>>n;
    arr.resize(n);
    rep(i,0,n){
        cin>>arr[i];
    }
    if(func(n) || func1(n)){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
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
