#include <iostream>
using namespace std;


string printstuff(){    //normal function
    cout<<"hello ";
    return "stuff";
}

int sum(int a,int b){   // parametrize function
    int c;
    c = a+b;
    return c;
}

int main(){
    cout<<printstuff()<<endl;
    cout<<sum(2,4);
    return 0;
}