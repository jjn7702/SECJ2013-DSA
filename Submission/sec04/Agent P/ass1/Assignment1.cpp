#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cstdlib>
using namespace std;

class Candidate
{
    string name,faculty,phone,ic;
    int age,voteCount;

    public:
        Candidate(){}
        Candidate(string n,string f,int a,string ic,string p,int v)
        {
            name = n;
            faculty = f;
            age = a;
            this->ic = ic;
            phone = p;
            voteCount = v;
        }

        string getName(){return name;}
        string getFaculty(){return faculty;}
        int getAge(){return age;}
        int getVoteCount(){return voteCount;}
        string getIC(){return ic;}
        string getPhone(){return phone;}
};
void NameAscending(Candidate c[],int size)
{
    Candidate temp;
    for(int last=size-1;last>=1;last--)
    {
        int largeIndex = 0;

        for(int x=1;x<=last;x++)
        {
            if(c[x].getName()>c[largeIndex].getName())
                largeIndex = x;
        }

        //cout<<c[largeIndex].getName()<<endl;
        Candidate temp = c[largeIndex];
        c[largeIndex] = c[last];
        c[last] = temp;
    }
}

void NameDescending(Candidate c[],int size)
{
    Candidate temp;
    for(int last=size-1;last>=1;last--)
    {
        int smallIndex = 0;

        for(int x=1;x<=last;x++)
        {
            if(c[x].getName()<c[smallIndex].getName())
                smallIndex = x;
        }

        //cout<<c[smallIndex].getName()<<endl;
        Candidate temp = c[smallIndex];
        c[smallIndex] = c[last];
        c[last] = temp;
    }
}

void SearchingName(Candidate c[],int size)
{
    string key;
    cout<<"Please enter the name you want to search for : ";
    cin>>key;
    for(int i=0;i<size;i++)
    {
        if(c[i].getName() == key)
        {
            cout<<"Record Found   : "<<endl;
            cout<<"Name           : "<<c[i].getName()<<endl;
            cout<<"Faculty        : "<<c[i].getFaculty()<<endl;
            cout<<"IC             : "<<c[i].getIC()<<endl;
            cout<<"Age            : "<<c[i].getAge()<<endl;
            cout<<"Vote Collected : "<<c[i].getVoteCount()<<endl;
            cout<<"Phone number   : "<<c[i].getPhone()<<endl;
            break;
        }
    }
}

void FacultyAscending(Candidate c[],int size)
{
    Candidate temp;
    bool sorted=false;

    for(int pass=1;(pass<size)&&!sorted;pass++)
    {
        sorted = true;
        for(int j=0;j<size-pass;j++)
        {
            if(c[j].getFaculty() > c[j+1].getFaculty())
            {
                temp = c[j];
                c[j] = c[j+1];
                c[j+1] = temp;
                sorted = false;
            }
        }
    }
}

void FacultyDescending(Candidate c[],int size)
{
    Candidate temp;
    bool sorted=false;

    for(int pass=1;(pass<size)&&!sorted;pass++)
    {
        sorted = true;
        for(int j=0;j<size-pass;j++)
        {
            if(c[j].getFaculty() < c[j+1].getFaculty())
            {
                temp = c[j];
                c[j] = c[j+1];
                c[j+1] = temp;
                sorted = false;
            }
        }
    }
}

void SearchingFaculty(Candidate c[],int size)
{
    string key;
    cout<<"Please enter the faculty you want to search for : ";
    cin>>key;
    for(int i=0;i<size;i++)
    {
        if(c[i].getFaculty() == key)
        {
            cout<<"\nRecord Found   : "<<endl;
            cout<<"Name           : "<<c[i].getName()<<endl;
            cout<<"Faculty        : "<<c[i].getFaculty()<<endl;
            cout<<"IC             : "<<c[i].getIC()<<endl;
            cout<<"Age            : "<<c[i].getAge()<<endl;
            cout<<"Vote Collected : "<<c[i].getVoteCount()<<endl;
            cout<<"Phone number   : "<<c[i].getPhone()<<endl;
            break;
        }
    }
}

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
    cout<<"|       Name       "<<" | "<<"      Faculty      "<<" | "<<"      IC     "<<" | "<<"   Age  "<<" | "<<" | "<<"  Vote Count  "<<" | "<<"Phone Number"<<" | "<<endl;
    cout<<"----------------------------------------------------------------------------------------------------------------"<<endl;
    for(int i=0;i<size;i++)
    {
        cout<<left<<"|  "<<setw(16)<<c[i].getName()<<" |       "<<setw(13)<<c[i].getFaculty()<<" |  "<<setw(8)<<c[i].getIC()<<" |     "<<setw(4)<<c[i].getAge()<<" |    "<<setw(9)<<c[i].getVoteCount()<< "|  "<<setw(10)<<c[i].getPhone()<<"  |"<<endl;
        cout<<"----------------------------------------------------------------------------------------------------------------"<<endl;
}
}

int main()
{
    Candidate c[10];
    ifstream in("cand.txt");
    string name,faculty,phone,ic;
    int id,age,vote;
    int i = 0;

    if(!in){
        cout<<"File cannot be opened!"<<endl;
        return 0;
    }
    
    //Reading from the file
    getline(in,name,',');
    while(!in.eof())
    {
        getline(in,faculty,',');
        in>>age;
        in.ignore();
        getline(in,ic,',');
        getline(in,phone,',');
        in>>vote;
        cout<<name<<" "<<faculty<<" "<<phone<<" "<<ic<<" "<<" "<<age<<" "<<vote<<endl;
        c[i] = Candidate(name,faculty,age,ic,phone,vote);
        getline(in,name,',');
        i++;
        //cout<<c[i].getIC()<<c[i].getName()<<" "<<c[i].getFaculty()<<" "<<c[i].getAge()<<" "<<c[i].getId()<<" "<<c[i].getIC()<<" "<<c[i].getPhone()<<" "<<c[i].getVoteCount()<<endl;
    }



    int opt1,opt2,opt3; //Storing user selection options
    menu(opt1,opt2,opt3); //User interface for the menu
    system("CLS");

    switch(opt1)
    {
        case 1:
            switch(opt2)
            {
                case 1 : if(opt3 == 1)
                            NameAscending(c,3);
                         else
                            NameDescending(c,3);
                        display(c,3);
                        break;
                case 2: if(opt3 == 1)
                            FacultyAscending(c,3);
                         else
                            FacultyDescending(c,3);
                        display(c,3);
                        break;
            }
            break;
        
        case 2:
            switch(opt2)
            {
                case 1: Searching(c,3);
                        break;

            }
            break;
    }

    display(c,3); //Displaying the candidates of election
    system("pause");
    return 0;

}