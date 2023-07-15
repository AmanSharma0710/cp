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


signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;
    cin>>n;
    vector<int> v(n);
    int maxx = INT_MIN, total = 0;
    for(int i=0; i<n; i++){
        cin>>v[i];
        maxx = max(maxx, v[i]);
        total += v[i];
    }
    int low = 1, high = 1000000000, mid, ans;
    while(low<high){
        mid = low + (high - low)/2;
        bool can_fill = true;
        int carry = 0;
        for(int i=0; i<n; i++){
            carry = (carry + mid - v[i]);
            if(carry<0){
                can_fill = false;
            }
        }
        if(carry<0){
            can_fill = false;
        }
        if(can_fill){
            high = mid;
            ans = mid;
        }
        else{
            low = mid+1;
        }
    }
    int q;
    cin>>q;
    for(int i=0; i<q; i++){
        int t;
        cin>>t;
        if(t<ans){
            cout<<-1<<endl;
            continue;
        }
        cout<< total / t + (total%t>0)<<endl;
    }
    return 0;
}
