#include<bits/stdc++.h>
using namespace std;
#define int long long int

bool valid(int n){
    string number = to_string(n);
    int diff = number[0] - number[1];
    for(int i=0; i<number.size()-1; i++){
        if(number[i] - number[i+1] != diff){
            return false;
        }
    }
    return true;
}

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int x;
    cin>>x;
    if(x<=10){
        cout<<x<<endl;
        return 0;
    }

    int no_of_digits = (int)log10(x)+1;
    if(no_of_digits>10){
        string number = to_string(x);
        bool greater = true;
        for(int i=1; i<number.size(); i++){
            if(number[i]>number[0]){
                greater = false;
                break;
            }
            if(number[i]<number[0]){
                greater = true;
                break;
            }
        }
        if(greater){
            for(int i=0; i<number.size(); i++){
                cout<<number[0];
            }
            cout<<endl;
            return 0;
        }
        if(number[0]=='9'){
            cout<<10;
            for(int i=1; i<number.size(); i++){
                cout<<0;
            }
            cout<<endl;
            return 0;
        }
        for(int i=0; i<number.size(); i++){
            cout<< (char)((int)number[0]+1);
        }
        cout<<endl;
        return 0;
    }
    if(no_of_digits==10){
        vector<int> v = {1111111111, 2222222222, 3333333333, 4444444444, 5555555555, 6666666666, 7777777777, 8888888888, 9876543210, 9999999999};
        if(binary_search(v.begin(), v.end(), x)){
            cout<<x<<endl;
            return 0;
        }
        cout<< *upper_bound(v.begin(), v.end(), x)<<endl;
        return 0;
    }
    if(no_of_digits==9){
        vector<int> v = {111111111, 123456789, 222222222, 333333333, 444444444, 555555555, 666666666, 777777777, 876543210, 888888888, 987654321, 999999999};
        if(binary_search(v.begin(), v.end(), x)){
            cout<<x<<endl;
            return 0;
        }
        cout<< *upper_bound(v.begin(), v.end(), x)<<endl;
        return 0;
    }
    if(no_of_digits==8){
        vector<int> v = {11111111, 12345678, 22222222, 23456789, 33333333, 44444444, 55555555, 66666666, 76543210, 77777777, 87654321, 88888888, 98765432, 99999999};
        if(binary_search(v.begin(), v.end(), x)){
            cout<<x<<endl;
            return 0;
        }
        cout<< *upper_bound(v.begin(), v.end(), x)<<endl;
        return 0;
    }
    for(int i=x; ; i++){
        if(valid(i)){
            cout<<i<<endl;
            return 0;
        }
    }
    return 0;
}