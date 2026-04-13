#include <iostream>
using namespace std;

class Train
{
    int no;
    string name, src, dest, time;

public:
    static int count;

    // Constructor
    Train(){
        cout<<"\nEnter Train No: ";
        cin>>no;
        cin.ignore(1000, '\n');

        cout<<"Enter Name: ";
        getline(cin, name);

        cout<<"Source: ";
        getline(cin, src);

        cout<<"Destination: ";
        getline(cin, dest);

        cout<<"Time: ";
        getline(cin, time);

    }

    // Destructor
    ~Train(){
        cout << "\nTrain No " << no << " removed from system.";
    }

    void show()
    {
        cout<<"\nNo: " <<no;
        cout<<"\nName: " <<name;
        cout<<"\nFrom: " <<src;
        cout<<"\nTo: " <<dest;
        cout<<"\nTime: " <<time<<endl;
    }

    int getNo(){ 
        return no; 
    }
};

int Train::count = 0;

int main()
{
    Train *t[50];
    int ch, num;

    do
    {
        cout<<"\n\n1.Add";
        cout<<"\n2.Show";
        cout<<"\n3.Search";
        cout<<"\n4.Exit";
        cout<<"\n\nChoice: ";
        cin>>ch;

        switch (ch){
            case 1:
                if (Train::count < 50){
                    t[Train::count] = new Train();
                    Train::count++; 
                }
                else{
                    cout <<"Full!";
                }
                break;

            case 2:
                if (Train::count == 0){
                    cout << "No records found!!";
                } 
                else{
                    cout << "\nTotal Trains: " << Train::count;

                    for (int i = 0; i < Train::count; i++) {
                        cout << "\n--- Train " << i+1 << " ---";
                        t[i]->show();
                    }
                    break;
                }

            case 3:{
                bool found = false;
                cout << "Enter Train No: ";
                cin >> num;

                for (int i = 0; i < Train::count; i++){
                    if (t[i]->getNo() == num){
                        t[i]->show();
                        found = true;
                        break;
                    }
                }
                if (!found)
                    cout << "Not Found!";
                break;
            }

            case 4:
                cout << "Exit"<<endl<<endl;
                break;

            default:
                cout<<"\nRong Choice..."<<endl;
        }

    } while (ch != 4);

    for (int i = 0; i < Train::count; i++)
        delete t[i];

    return 0;
}