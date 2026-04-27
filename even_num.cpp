#include <iostream>
using namespace std;

int main()
{

    int a[50], i, n;
    cout << "Enter Array Size: ";
    cin >> n;
    
    cout<<"Enter Element of an Array:"<<endl;
    for(i=0; i<n; i++){
        cout<<"a["<<i<<"] =";
        cin>>a[i];
    }

    cout<<"All Even number:";
    for (i = 0; i < n; i++){  
        if(a[i]% 2==0){
            cout<<a[i];
        
        if(i<n-1){
            cout<<", ";
        }
    }
    }

    return 0;
}