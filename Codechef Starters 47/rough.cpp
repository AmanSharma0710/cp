#include <iostream>

#include <vector>

using namespace std;
 class Person{
public:
    Person(string name) { pName_ = new string(name); } 
    ~Person() { delete pName_;} 
    void printName() { cout << *pName_; }


private:
    string* pName_;
};


int main(){

    vector<Person> persons;
    persons.push_back(Person("George")); 
    persons[0].printName();
    cout<<" bye!" << endl;
    return 0;

}