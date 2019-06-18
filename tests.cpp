#include<iostream>
#include <vector>
using namespace std;
void test_pointers(){
    int num1=10;
    cout << "num1=" << num1<<endl;
    int *p_num1;
    p_num1=&num1;
    cout << "adres of p_num1= " <<p_num1<<endl;
    *p_num1+=2;
    cout << "num1 is now="<<num1<<endl;
    cout << "num1 is now="<<*p_num1<<endl;
}

void test_reference(){
    int num2=20;
    int &r_num2=num2;
    r_num2+=2;
    cout << "num1 is now="<<num2<<endl;
    cout << "num1 is now="<<r_num2<<endl;
    
}
void test_cin(){
    int n;
    cout<<"enter a number"<<endl;
    cin>>n;
    cout<<"the number is:"<<n;
}
void test_string(){
    string name;
    name="yakir";
    cout << name <<endl;
}
void test_vector(){
    vector<int> vec_int;
    int i;
    for(i=0;i<5;i++)
    {
        vec_int.push_back(i);
    }
    // for(i=0;i<vec_int.size();i++)
    // {
    //     cout<<vec_int[i];
    // }
}
int main2(){
    //test_pointers();
    //test_reference();
    //test_cin();
    // test_string();
    // test_vector();
    vector<int> vec_t;
    int i;
    for(i=0;i<5;i++)
    {
        vec_t.push_back(i);
    }
    for(i=0;i<vec_t.size();i++)
    {
        cout<<vec_t[i];
    }
    return 0;
    
    
}