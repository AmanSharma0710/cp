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
int power(int x, int y){
    int res = 1; 
    x = x;  
    while (y > 0){
        if (y & 1)
            res = (res*x);
        y = y>>1;
        x = (x*x);
    }
    return res;
}
set<int> likes;
vector<int> v;

void solve(){
    int key;
    cin>>key;
    int left = 0;
    int right = v.size() - 1;
 
    int count = 0;
 
    while (left <= right) {
        int mid = (right + left) / 2;
        if (v[mid] <= key) {
            count = mid + 1;
            left = mid + 1;
        }
        else
            right = mid - 1;
    }
    cout<<count<<endl;
    return;
}


signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t=1;
    for(int i=1; ;i++){
        if(i*i>1e9){
            break;
        }
        likes.insert(i*i);
    }
    for(int i=1; ;i++){
        if(i*i*i>1e9){
            break;
        }
        likes.insert(i*i*i);
    }
    for(auto i:likes){
        v.push_back(i);
    }
    cin>>t;
    while (t--){
        solve();       
    }
    return 0;
}
