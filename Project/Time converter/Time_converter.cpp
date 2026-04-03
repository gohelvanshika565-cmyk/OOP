#include<iostream>
using namespace std;

class time{
    int seconds, h, m, s;

    public:

    void getdata(){
        cout<<"Enter any seconds:";
        cin>>seconds;
    }

    //covert seconds into time
    void convert(){  
        h = seconds / 3600;
        m = (seconds%3600) / 60;
        s = seconds % 60;
    }

    void display(){
        cout<<endl<<h<<" hours "<<endl;
        cout<<m<<" minutes "<<endl;
        cout<<s<<" seconds"<<endl<<endl;
    
        cout<< "Time is: "<<h<< " : "<<m<<" : "<<s<<endl<<endl;
    }

    //convert time into seconds
    void convert_(){ 
        int total_seconds = (h * 3600) + (m * 60) + s;
        cout<<endl<<"Total seconds: "<<total_seconds<<endl;
    }

    void display_(){
        cout<<"Enter hours: ";
        cin>>h;
        cout<<"Enter minutes: ";
        cin>>m;
        cout<<"Enter seconds: ";
        cin>>s;

    }
};

int main(){
    time t;
    t.getdata();
    t.convert();
    t.display();

    time s;
    s.display_();
    s.convert_();

    return 0;
}
