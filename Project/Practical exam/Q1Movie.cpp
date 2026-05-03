#include<iostream>
#include<string>
using namespace std;

class movie{
    public:
        string title, genre;
        int released_year;

    movie(){}
    movie(string t,string g, int y):title(t),genre(g),released_year(y){}

};

int main(){
    movie m[3],i;

    m[0] = movie("Guntur kaaram","Action",2024);
    m[1] = movie("Pushpa","Action",2021);
    m[2] = movie("RRR","Drama",2022);

    for(int i=0; i<3; i++){
        cout<<"Movie"<<i+1<<": "<<m[i].title<<" || genre: "<<m[i].genre<<" || Movie: "<<m[i].released_year<<endl;
    }
    return 0;
}