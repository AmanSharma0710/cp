#include<iostream>
using namespace std;

struct A{
    int x{0};
    int get(){ return x++; }
    int get() const { return x; }
};


int main(){
    A a;
    auto x = a.get();
    auto y = a.get();
    cout << x << y << endl;
    return 0;
}