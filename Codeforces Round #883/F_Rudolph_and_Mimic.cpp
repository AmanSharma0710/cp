#include<bits/stdc++.h>
using namespace std;
#define int long long int



void solve(){
    int n;
    cin>>n;
    vector<int> objects;
    auto input = [&](int n){
        vector<int> a(n);
        for(int i=0; i<n; i++) cin>>a[i];
        return a;
    };
    auto cnt = [&](vector<int> &obj){
        vector<int> counter(10, 0);
        for(int i=0; i<obj.size(); i++){
            counter[obj[i]]++;
        }
        return counter;
    };
    objects = input(n);
    if(n==1){
        cout<<"! 1"<<endl;
        return;
    }
    vector<int> counter1 = cnt(objects);
    cout<<"- 0"<<endl;
    objects = input(n);
    vector<int> counter2 = cnt(objects);
    bool found = false;
    for(int i=1; i<=9; i++){
        if(counter1[i]<counter2[i]){
            found = true;
            int num_remove = 0;
            for(int j=0; j<n; j++){
                if(objects[j]!=i) num_remove++;
            }
            cout<<"- "<<num_remove<<" ";
            for(int j=0; j<n; j++){
                if(objects[j]!=i) cout<<j+1<<" ";
            }
            cout<<endl;
            n-=num_remove;
        }
    }
    if(!found){
        cout<<"- 0"<<endl;
        objects = input(n);
        counter2 = cnt(objects);
        for(int i=1; i<=9; i++){
            if(counter1[i]<counter2[i]){
                found = true;
                int num_remove = 0;
                for(int j=0; j<n; j++){
                    if(objects[j]!=i) num_remove++;
                }
                cout<<"- "<<num_remove<<" ";
                for(int j=0; j<n; j++){
                    if(objects[j]!=i) cout<<j+1<<" ";
                }
                cout<<endl;
                n-=num_remove;
            }
        }
    }
    found = false;
    objects = input(n);
    if(n==1){
        cout<<"! 1"<<endl;
        return;
    }
    counter1 = counter2;
    counter2 = cnt(objects);
    for(int i=1; i<=9; i++){
        if(counter1[i]<counter2[i]){
            found = true;
            int num_remove = 0;
            for(int j=0; j<n; j++){
                if(objects[j]!=i) num_remove++;
            }
            cout<<"- "<<num_remove<<" ";
            for(int j=0; j<n; j++){
                if(objects[j]!=i) cout<<j+1<<" ";
            }
            cout<<endl;
            n-=num_remove;
        }
    }
    if(!found){
        cout<<"- 0"<<endl;
        objects = input(n);
        counter2 = cnt(objects);
        for(int i=1; i<=9; i++){
            if(counter1[i]<counter2[i]){
                found = true;
                int num_remove = 0;
                for(int j=0; j<n; j++){
                    if(objects[j]!=i) num_remove++;
                }
                cout<<"- "<<num_remove<<" ";
                for(int j=0; j<n; j++){
                    if(objects[j]!=i) cout<<j+1<<" ";
                }
                cout<<endl;
                n-=num_remove;
            }
        }
    }
    objects = input(n);
    if(n==1){
        cout<<"! 1"<<endl;
        return;
    }
    assert(false);
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
