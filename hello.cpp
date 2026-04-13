#include<iostream>
using namespace std;

class x{
    int a=5;
    friend class y;
};
class y{
    public:
        void show(x obj){
            cout<<obj.a<<endl;
        }
};
int main(){
    y s;
    x obj;        
    s.show(obj); 
    return 0;

}