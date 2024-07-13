#include <iostream>
using namespace std;


void printHi(){
    cout<<"Hi"<<endl;
}
int sum(int a,int b){
    return a+b;
}

int main(){
    printHi();
    int a,b;
    a = 10;
    b = 20;
    int d = sum(a,b);
    cout<<d<<"Value of a is: "<<a;

    return 0;
}