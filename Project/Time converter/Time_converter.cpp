#include<iostream>
using namespace std;

class time{
    int seconds, h, m, s;

    public:

    void getdata(){
        cout<<"Enter any seconds:";
        cin>>seconds;
    }

    void convert(){
        h = seconds / 3600;
        m = (seconds%3600) / 60;
        s = seconds % 60;
    }

    void display(){
        cout<<endl<<h<<" hours "<<endl;
        cout<<m<<" minutes "<<endl;
        cout<<s<<" seconds"<<endl<<endl;
    
        cout<<h<< " : "<<m<<" : "<<s<<endl<<endl;

        cout<<"Total seconds: "<<(h*3600)+(m*60)+s<<endl<<endl;
    }
};

int main(){
    time t;
    t.getdata();
    t.convert();
    t.display();

    return 0;
}
