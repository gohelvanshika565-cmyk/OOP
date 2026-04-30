#include<iostream>
using namespace std;

int sumArray(int arr[], int size){

    int sum = 0, i;

    for(i = 0; i<size;i++ ){
        sum = sum + arr[i];
    }
    return sum;
}

int main(){

    int a[5],i;

    cout<<"Enter 5 elements: ";
    for(i=0; i<5; i++){
        cin>>a[i];
    }

    int result = sumArray(a,5);
    cout<<result;
    return 0;
}