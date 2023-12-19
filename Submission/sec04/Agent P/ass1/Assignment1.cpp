#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cstdlib>
using namespace std;

class Candidate
{
    string name,faculty,phone,ic;
    int age,id,voteCount;

    public:
        Candidate(){}
        Candidate(string n,string f,int a,int id,string ic,string p,int v)
        {
            name = n;
            faculty = f;
            age = a;
            this->id = id;
            this->ic = ic;
            phone = p;
            voteCount = v;
        }

        string getName(){return name;}
        string getFaculty(){return faculty;}
        int getAge(){return age;}
        int getId(){return id;}
        int getVoteCount(){return voteCount;}
        string getIC(){return ic;}
        string getPhone(){return phone;}
};

void menu(int &opt1,int &opt2,int &opt3)
{
    do{
    cout<<"[1] Sort \n[2] Search"<<endl;
    cout<<"You want to do sorting or searching : ";
    cin>>opt1;
    }while(opt1<1 || opt1>2);
    system("CLS");

    switch(opt1)
    {
        case 1 : do{
                 cout<<"[1] Name \n[2] Faculty \n[3] IC \n[4] Age \n[5] ID \n[6] Vote Count"<<endl;
                 cout<<"Please choose the sorting category : ";
                 cin>>opt2;
                 }while(opt2<1 || opt2>6);
                 break;
        case 2 : do{
                 cout<<"[1] Name \n[2] Faculty \n[3] IC \n[4] Age \n[5] ID \n[6] Vote Count"<<endl;
                 cout<<"Please choose the searching category : ";
                 cin>>opt2;
                 }while(opt2<1 || opt2>6);
                 break;
    }

    do{
    cout<<"[1] Ascending Order \n[2] Descending Order"<<endl;
    cout<<"You want ascending or desending order : ";
    cin>>opt3;
    }while(opt3<1 || opt3>2);
    system("CLS");

}

void display(Candidate c[],int size)
{
    cout<<"----------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<"|       Name       "<<" | "<<"      Faculty      "<<" | "<<"      IC     "<<" | "<<"   Age  "<<" | "<<"   ID  "<<" | "<<"  Vote Count  "<<" | "<<"Phone Number"<<" | "<<endl;
    cout<<"----------------------------------------------------------------------------------------------------------------"<<endl;
    for(int i=0;i<size;i++)
    {
        cout<<left<<"|  "<<setw(16)<<c[i].getName()<<" |       "<<setw(13)<<c[i].getFaculty()<<" |  "<<setw(8)<<c[i].getIC()<<" |     "<<setw(4)<<c[i].getAge()<<" |    "<<setw(5)<<c[i].getId()<<"|       "<<setw(9)<<c[i].getVoteCount()<<"|  "<<setw(10)<<c[i].getPhone()<<"  |"<<endl;
        cout<<"----------------------------------------------------------------------------------------------------------------"<<endl;
}
}

int main()
{
    Candidate c[3];
    ifstream in;
    in.open("candU.csv");
    string name,faculty,phone,ic,id,age,vote;

    if(!in){
        cout<<"File thoraka mudiyala da mayiru!"<<endl;
        return 0;
    }

    int i=0;
    
    //Reading from the file
    while(getline(in,name,','))
    {
        getline(in,faculty,',');
        getline(in,age,',');
        getline(in,id,',');
        getline(in,ic,',');
        getline(in,phone,',');
        getline(in,vote,'\n');

        c[i] = Candidate(name,faculty,stoi(age),stoi(id),ic,phone,stoi(vote));
        //cout<<c[i].getName()<<" "<<c[i].getFaculty()<<" "<<c[i].getAge()<<" "<<c[i].getIC()<<" "<<c[i].getId()<<" "<<c[i].getPhone()<<" "<<c[i].getVoteCount()<<endl;
        i++;
    }



    int opt1,opt2,opt3; //Storing user selection options
    menu(opt1,opt2,opt3); //User interface for the menu
    system("CLS");

    display(c,3); //Displaying the candidates of election
    system("pause");
    return 0;

}
