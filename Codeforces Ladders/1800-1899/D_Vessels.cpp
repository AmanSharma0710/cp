#include<bits/stdc++.h>
using namespace std;


int main(){
    int n;
    cin>>n;
    set<int> has_space;
    vector<int> cap(n+1);
    for(int i=0; i<n; i++){
        cin>>cap[i+1];
        has_space.insert(i+1);
    }
    vector<int> filled(n+1, 0);
    int q;
    cin>>q;
    for(int qq=0; qq<q; qq++){
        int type;
        cin>>type;
        if(type==1){
            int p, x;
            cin>>p>>x;
            auto it = has_space.lower_bound(p);
            while(it!=has_space.end() && x>0){
                int idx = *it;
                int temp = min(cap[idx]-filled[idx], x);
                filled[idx] += temp;
                x -= temp;
                if(filled[idx] == cap[idx]){
                    has_space.erase(idx);
                }
                it = has_space.lower_bound(p);
            } 
        }
        else{
            int k;
            cin>>k;
            cout<<filled[k]<<endl;
        }
    }
    return 0;
}