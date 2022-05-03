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

struct person{
    int id, social;
    person(int id, int social){
        this->id = id;
        this->social = social;
    }
    bool operator < (const person &p) const{
        if(social == p.social) return id > p.id;
        return (social < p.social);
    }
};



void solve(){
    int n;
    cin>>n;
    priority_queue<person> pq;
    int x;
    rep(i,0,n){
        cin>>x;
        if(x>0){
            pq.push(person(i+1, x));
        }
    }
    vector<pair<int,int>> ans;
    while(!pq.empty()){
        person p1 = pq.top();
        pq.pop();
        if(!pq.empty()){
            person p2 = pq.top();
            pq.pop();
            ans.push_back({p1.id, p2.id});
            if(p1.social>1){
                pq.push(person(p1.id, p1.social-1));
            }
            if(p2.social>1){
                pq.push(person(p2.id, p2.social-1));
            }
        }
    }
    cout<<ans.size()<<endl;
    for(auto x: ans){
        cout<<x.first<<" "<<x.second<<endl;
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
