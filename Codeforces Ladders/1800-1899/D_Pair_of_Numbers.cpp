#include<bits/stdc++.h>
using namespace std;
#define int long long int


signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin>>a[i];
        if(a[i]==1){
            cout<<1<<" "<<n-1<<endl;
            cout<<1<<endl;
            return 0;
        }
    }
    vector<bool> prime(1001, true);
    prime[0] = prime[1] = false;
    for(int i=2; i*i<=1000; i++){
        if(prime[i]){
            for(int j=i*i; j<=1000; j+=i){
                prime[j] = false;
            }
        }
    }
    vector<int> primes;
    for(int i=2; i<=1000; i++){
        if(prime[i]) primes.push_back(i);
    }
    vector<map<int, int>> factors(n);
    for(int i=0; i<n; i++){
        int temp = a[i];
        for(auto p:primes){
            if(temp%p==0){
                while(temp%p==0){
                    temp/=p;
                    factors[i][p]++;
                }
            }
        }
        if(temp>1){
            factors[i][temp]++;
        }
    }
    int l=0, r=0, ans=0;
    vector<int>ans_idx;
    map<int, multiset<int>> map_cumul;
    set<pair<int, int>> set_cumul;
    set_cumul.insert({a[0], 0});
    for(auto it:factors[0]){
        map_cumul[it.first].insert(it.second);
    }
    auto check = [&](int min_elem){
        for(auto it:factors[min_elem]){
            if(map_cumul[it.first].size()==0 || *(map_cumul[it.first].begin())<it.second) return false;
        }
        return true;
    };
    while(r<n){
        int min_elem = (*set_cumul.begin()).second;
        assert(l<=r);
        cout<<l<<" "<<r<<" "<<min_elem<<endl;
        if(check(min_elem)){
            if(r-l>ans){
                ans = r-l;
                ans_idx.clear();
                ans_idx.push_back(l+1);
            }
            else if(r-l==ans){
                ans_idx.push_back(l+1);
            }
            r++;
            if(r<n){
                set_cumul.insert({a[r], r});
                for(auto it:factors[r]){
                    map_cumul[it.first].insert(it.second);
                }
            }
        }
        else{
            set_cumul.erase(set_cumul.find({a[l], l}));
            for(auto it:factors[l]){
                map_cumul[it.first].erase(map_cumul[it.first].find(it.second));
            }
            l++;
        }
    }
    cout<<ans_idx.size()<<" "<<ans<<endl;
    for(auto it:ans_idx){
        cout<<it<<" ";
    }
    cout<<endl;
    return 0;
}
