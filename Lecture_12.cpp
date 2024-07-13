#include <iostream>
using namespace std;

int main(){

/* ---WHILE LOOP---
    int password;
    cout<<"Enter a password: "<<endl;
    cin>>password;

    while(password<9999){
        cout<<"Password is short re-enter it: "<<endl;
        cin>>password;
    }
    cout<<"Password Entered: "<<endl;
*/
    int password;
    cout<<"Enter a password: "<<endl;
    
    
    // do while loop

    do{
        cin>>password;    
    }
    while(password<9999);

    //infinite loop
    int count = 0;
        do{
            cout<<"Ice Cream ";
            count++;
            if(count == 100) break;
        }while(1>0);

    for(int i = 0; ;i++){
        cout<<i<<" ";
        if(i > 100)break;
    }

    return 0;
}