#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define vi vector<int>
#define pii pair<int,int>
#define vii vector<pii>
#define rep(i,a,b) for(int i=a; i<b; i++)
bool sortbysec(const pair<int,int> &a, //to sort vii by second element use sort(v.begin(), v.end(), sortbysec);
              const pair<int,int> &b)
{
    return (a.second < b.second);
}
#define mod 1000000007

    
    



void solve(){
    int n, m, a, b;
    cin>>n>>m>>a>>b;

    if(a<m+n-1 || b<m+n-1){
        cout<<"Impossible\n";
        return;
    }
    int arr[n][m];
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            arr[i][j] = 1;
        }
    }
    arr[0][0] = a - m - n + 2;
    arr[0][m-1] = b - m - n + 2;
    cout<<"Possible\n";
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    return;
}


signed main(){
    int t, count = 1;
    cin>>t;
    while (t--){
        printf("Case #%d: ", count++);
        solve();       
    }
    return 0;
}
