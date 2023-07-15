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
    int n; cin>>n;
    string arr[n];
    rep(i, 0, n){
        cin>>arr[i];
    }
    int xcount, ocount, xcount_max = 0, occurences = 0, vector_index = 0;
    vector<pair<int, int>> v;
    bool answer = false;
    rep(i, 0, n){
        xcount = 0;
        ocount = 0;
        int k=0;
        rep(j, 0, n){
            if(arr[i][j]=='X'){
                xcount++;
            }
            if(arr[i][j]=='O'){
                ocount++;
            }
            if(arr[i][j]=='.'){
                k=j;
            }
        }
        if(ocount==0){
            answer = true;
            if(xcount == xcount_max){
                occurences++;
            }
            if(xcount>xcount_max){
                xcount_max=xcount;
                occurences=1;
            }
            if(xcount == n-1){
                //v[vector_index].first = i;
                //v[vector_index].second = k;
                v.push_back({i, k});
                vector_index++;
            }
        }
    }
    rep(i, 0, n){
        xcount = 0;
        ocount = 0;
        int k;
        rep(j, 0, n){
            if(arr[j][i]=='X'){
                xcount++;
            }
            if(arr[j][i]=='O'){
                ocount++;
            }
            if(arr[j][i]=='.'){
                k=j;
            }
        }
        if(ocount==0){
            answer = true;
            if(xcount == xcount_max){
                occurences++;
            }
            if(xcount>xcount_max){
                xcount_max=xcount;
                occurences=1;
            }
            if(xcount == n-1){
                //v[vector_index].first = k;
                //v[vector_index].second = i;
                v.push_back({k, i});
                vector_index++;
            }
        }
    }
    sort(v.begin(), v.end());
    rep(i, 0, vector_index-1){
        if(v[i].first==v[i+1].first && v[i].second==v[i+1].second){
            occurences--;
        }
    }

    if(!answer){
        cout<<"Impossible"<<endl;
        return;
    }
    cout<<(n - xcount_max)<<" "<<occurences<<endl;
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
