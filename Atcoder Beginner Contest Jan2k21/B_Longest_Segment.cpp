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
    vii points(n);
    rep(i,0,n){
        cin>>points[i].first>>points[i].second;
    }
    double max_dist = 0;
    rep(i,0,n){
        double dist = 0;
        rep(j,0,n){
            if(i!=j){
                dist = sqrt(pow(points[i].first-points[j].first,2) + pow(points[i].second-points[j].second,2));
            }
            if(dist > max_dist){
                max_dist = dist;
            }
        }
    }
    cout<<fixed<<setprecision(10)<<max_dist<<endl;
    return 0;
}
