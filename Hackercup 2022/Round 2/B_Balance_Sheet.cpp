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
int power(int x, int y, int p){
    int res = 1; 
    x = x % p;  
    while (y > 0){
        if (y & 1)
            res = (res*x) % p;
        y = y>>1;
        x = (x*x) % p;
    }
    return res;
}
unsigned mod_pow(unsigned a, unsigned b, unsigned mod) {
    unsigned result = 1;
    while (b > 0) {
        if (b & 1)
            result = unsigned(uint64_t(result) * a % mod);
        a = unsigned(uint64_t(a) * a % mod);
        b >>= 1;
    }
    return result;
}

bool isPrime(unsigned n) {
    if (n < 2)
        return false;
    for (unsigned p : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29})
        if (n % p == 0)
            return n == p;
    int r = __builtin_ctz(n - 1);
    unsigned d = (n - 1) >> r;
    for (unsigned a : {2, 7, 61}) {
        unsigned x = mod_pow(a % n, d, n);
        if (x <= 1 || x == n - 1)
            continue;
        for (int i = 0; i < r - 1 && x != n - 1; i++)
            x = unsigned(uint64_t(x) * x % n);
        if (x != n - 1)
            return false;
    }
    return true;
}

class client{
    public:
    int a, b, x, y;
    bool operator<(const client &c) const{
        if(x!=c.x) return x<c.x;
        return y < c.y;
    }
};

void solve(){
    int n, k;
    cin>>n>>k;
    vector<client> v(n);
    for(int i=0; i<n; i++){
        int a, b, x, y;
        cin>>a>>b>>x>>y;
        v[i].a = a;
        v[i].b = b;
        v[i].x = x;
        v[i].y = y;
    }
    vector<vector<int>> profit(n, vector<int>(1, 0));
    map<int, vector<int>> end_dates, start_dates;
    for(int i=0; i<n; i++){
        if(end_dates.find(v[i].b) == end_dates.end()){
            end_dates[v[i].b] = vector<int>();
        }
        end_dates[v[i].b].push_back(i);
        if(start_dates.find(v[i].a) == start_dates.end()){
            start_dates[v[i].a] = vector<int>();
        }
        start_dates[v[i].a].push_back(i);
    }
    //WHEN YOU REACH A NODE:
    //IF NO NODES START AT THE END VALUE, ADD 0 TO PROFIT
    //ELSE FOR THAT END VALUE, FIND THE K MAX PROFITS FOR ALL THE NODES WITH START VALUE THAT AND FOR ALL THE NODES WITH THIS END VALUE ADD THAT TO THE PROFIT
    for(auto it = end_dates.rbegin(); it!=end_dates.rend(); it++){
        int end = it->first;
        vector<int> end_indices = it->second;
        sort(end_indices.begin(), end_indices.end(), [&](int i, int j){         //TODO: TRY CHANGING THIS LATER
            return v[i].x < v[j].x;
        });
        if(start_dates.find(end) == start_dates.end()){
            continue;
        }
        else{
            vector<int> start_indices = start_dates[end];   //Array containing indices of days that have start date = end date for current
            sort(start_indices.begin(), start_indices.end(), [&](int i, int j){
                return v[i].y < v[j].y;
            });
            priority_queue<int, vector<int>, greater<int>> pq;
            // for(auto idx: start_indices){
            //     // cout<<"INDEX: "<<idx<<endl;
            //     for(auto p: profit[idx]){
            //         // cout<<"P: "<<p<<endl;
            //         if(pq.size() < k){
            //             pq.push(p + v[idx].x);
            //         }
            //         else{
            //             if(pq.top() < p+v[idx].x){
            //                 pq.pop();
            //                 pq.push(p+v[idx].x);
            //             }
            //         }
            //     }
            // }
            // //NOW WE ADD THE PROFITS TO THE NODES WITH END DATE = CURRENT END DATE
            // vector<int> profits_curr(0);
            // cout<<"Printing pq for end date "<<end<<": ";
            // while(!pq.empty()){
            //     cout<<pq.top()<<" ";
            //     profits_curr.push_back(pq.top());
            //     pq.pop();
            // }
            // cout<<endl;
            // for(auto idx: end_indices){
            //     //we populate the profit array for the current node
            //     cout<<"Populating profit for index "<<idx<<endl;
            //     for(auto p: profits_curr){
            //         if(p - v[idx].y > 0){
            //             profit[idx].push_back(p - v[idx].y);
            //             cout<<"Pushing "<<p-v[idx].y<<endl;
            //         }
            //     }
            // }
            int i=(int)start_indices.size()-1, j=(int)end_indices.size()-1;
            while(j>=0){
                while(i>=0 && v[start_indices[i]].x > v[end_indices[j]].y){
                    for(auto p: profit[start_indices[i]]){
                        if(pq.size() < k){
                            pq.push(p + v[start_indices[i]].x);
                        }
                        else{
                            if(pq.top() < p+v[start_indices[i]].x){
                                pq.pop();
                                pq.push(p+v[start_indices[i]].x);
                            }
                        }
                    }
                    i--;
                }
                vector<int> profits_curr(0);
                while(!pq.empty()){
                    profits_curr.push_back(pq.top());
                    pq.pop();
                }
                for(auto p: profits_curr){
                    if(p - v[end_indices[j]].y > 0){
                        profit[end_indices[j]].push_back(p - v[end_indices[j]].y);
                    }
                }
                while(profits_curr.size()>0){
                    pq.push(profits_curr.back());
                    profits_curr.pop_back();
                }
                j--;
            }
        }
    }
    priority_queue<int, vector<int>, greater<int>> final;
    for(int i=0; i<profit.size(); i++){
        for(int j=0; j<profit[i].size(); j++){
            if(final.size() < k){
                final.push(profit[i][j]);
            }
            else{
                if(final.top() < profit[i][j]){
                    final.pop();
                    final.push(profit[i][j]);
                }
            }
        }
    }
    int ans = 0;
    while(!final.empty()){
        ans = (ans+final.top())%MOD;
        final.pop();
    }
    cout<<ans<<endl;
    return;
}


signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t=1, tc=1;
    cin>>t;
    while (t--){
        cout<<"Case #"<<tc++<<": ";
        solve();       
    }
    return 0;
}
