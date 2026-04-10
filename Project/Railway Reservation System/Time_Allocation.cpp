#include <iostream>
using namespace std;

class train
{

    int train_no;
    string train_name;
    string source;
    string destination;
    string time;

public:
    static int count;

    train()
    {
        train_no;
        train_name;
        source;
        destination ;
        time;
    }
    ~train()
    {
        // cout << "Train object destroyed\n";
    }

    void input()
    {

        cout << "Enter Train Number : ";
        cin >> train_no;

        cin.ignore();

        cout << "Enter name : ";
        getline(cin, train_name);

        cout << "Enter Source : ";
        getline(cin, source);

        cout << "Enter Destination : ";
        getline(cin, destination);

        cout << "Enter Time : ";
        getline(cin, time);

        count++;
        cout << "\nTrain record added successfully." << endl<< endl;
    }
    void display()
    {

        cout << "\n Train Number : " << train_no;
        cout << "\n Name : " << train_name;
        cout << "\n Source : " << source;
        cout << "\n Destination : " << destination;
        cout << "\n Time : " << time << endl;
    }

    int getnumber()
    {

        return train_no;
    }
};

int train ::count = 0;

int main()
{

    train t[20];
    int ch, num;
    bool found = false;

    do
    {
        cout << "\n1. Add";
        cout << "\n2. Display";
        cout << "\n3. Search";
        cout << "\n4. Exit \n";

        cout << "Enter Choice : ";
        cin >> ch;

        switch (ch)
        {
        case 1:
            if (train::count < 20)
            {
                t[train::count].input();
            }
            else
            {
                cout << "Record system is full.!" << endl;
            }
            break;

        case 2:

            if (train::count == 0)
            {
                cout << "No buses record found.!!";
            }
            else
            {
                for (int i = 0; i < train::count; i++)
                {
                    cout << "\n Train - " << i + 1 << endl;
                    t[i].display();
                }
            }
            break;

        case 3:

            if (train::count == 0)
            {
                cout << "No train record found.!!";
            }
            else
            {
                cout << "Enter number to search : ";
                cin >> num;

                for (int i = 0; i < 20; i++)
                {
                    if (t[i].getnumber() == num)
                    {
                        found = true;
                        t[i].display();
                    }
                }

                if (!found)
                {
                    cout << "Train not Found";
                }
            }
            break;

        case 4:
            cout << "Exit";
            break;
        }
    } while (ch != 4);

    return 0;
}
