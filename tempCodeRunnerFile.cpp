#include<iostream>
using namespace std;

int main(){

    int i, j;

    for(i = 0; i< 5; i++){
        for(j= 1; j<=i; j++){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}