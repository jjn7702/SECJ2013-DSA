
#include <iostream>
using namespace std;

class Voter{
    string name,faculty,email,ic,matric;
    int age;

    public:
     Voter *next;
        Voter(string n,string f,int a,string ic,string e,string m)
        {
            name = n;
            faculty = f;
            age = a;
            this->ic = ic;
            email = e;
            matric = m;
            next = NULL;
        }

        string getName(){return name;}
        string getFaculty(){return faculty;}
        int getAge(){return age;}
        string getIC(){return ic;}
        string getEmail(){return email;}
        string getMatric(){return matric;}

        void setName(string n){name = n;}
        void setFaculty(string f){ faculty = f;}
        void setAge(int a){age = a;}
        void setIC(string ic){this->ic = ic;}
        void setEmail(string e){email = e;}
        void setMatric(string m){matric = m;}

};

class List
{
    Voter *head;

    public:
        List(){
            head = NULL;
        }

        bool isEmpty(){return head==NULL;}

        void insertFront(string n,string f,int a,string ic,string e,string m)
        {
            Voter *newNode = new Voter(n,f,a,ic,e,m);
            
            Voter *temp = head;
            bool found = false;
            
            while(temp!=NULL)
            {
            	if(temp->getMatric() == newNode->getMatric()){
            		found = true;
            		cout<<"Voter already exist!"<<endl;
            	}
            	temp = temp->next;
			}
			
			if(found == false){
            if(isEmpty())
                head = newNode;
            else{
                newNode->next = head;
                head = newNode;
            }
        }
        }

        void deleteFront()
        {
            if(isEmpty())
                cout<<"The list is empty!"<<endl;
            else{
                Voter *temp = head;
                head = temp->next;
                temp->next = NULL;
            }
        }

        void insertend(string n,string f,int a,string ic,string e,string m)
        {
            Voter *newNode = new Voter(n,f,a,ic,e,m);
            Voter *temp = head;

            if(isEmpty())
                head = newNode;

            else{
                while(temp->next != NULL)
                {
                    temp = temp->next;
                }
                temp->next = newNode;
            }
        }

        void deleteEnd()
        {
            if(isEmpty())
                cout<<"The list is empty!"<<endl;
            
            else{
                Voter *temp = head,*temp2;
                while(temp->next != NULL){
                    temp2 = temp;
                    temp = temp->next;
                }
                temp2->next = NULL;
                delete temp;
            }
        }

        void insertAtNode(string n,string f,int a,string ic,string e,string m,int index)
        {
            Voter *newNode = new Voter(n,f,a,ic,e,m);
            Voter *temp = head;
            
            if(isEmpty())
                head = newNode;
            else{
                for(int i=0;i<index-2;i++)
                    temp = temp->next;

                newNode->next = temp->next;
                temp->next = newNode;
            }
        }

        void deleteAtNode(int index)
        {
             if(isEmpty())
                cout<<"The list is empty!"<<endl;
            else{
                Voter *temp = head,*temp2;
                for(int i=0;i<index-1;i++){
                    temp2 = temp;
                    temp = temp->next;
                }
                temp2->next = temp->next;
                temp->next = NULL;
                delete temp;
            }
        }

        
void search(int opt,string key,int key2)
        {
            Voter *temp = head;
            bool found = false;

            if(isEmpty()){
                cout<<"The list is empty!"<<endl;
                return;
            }

            else{
            switch(opt)
            {
                case 1 : 
                    while(temp != NULL)
                    {
                        if(temp->getName() == key)
                        {
                            cout<<"\nName  : "<<temp->getName()<<endl;
                            cout<<"Faculty : "<<temp->getFaculty()<<endl;
                            cout<<"Age     : "<<temp->getAge()<<endl;
                            cout<<"IC      : "<<temp->getIC()<<endl;
                            cout<<"Email   : "<<temp->getEmail()<<endl;
                            cout<<"Matric  : "<<temp->getMatric()<<endl;
                            found = true;
                        }
                        temp = temp->next;
                    }
                    break;
                case 2:
                    while(temp != NULL)
                    {
                        if(temp->getFaculty() == key)
                        {
                            cout<<"\nName  : "<<temp->getName()<<endl;
                            cout<<"Faculty : "<<temp->getFaculty()<<endl;
                            cout<<"Age     : "<<temp->getAge()<<endl;
                            cout<<"IC      : "<<temp->getIC()<<endl;
                            cout<<"Email   : "<<temp->getEmail()<<endl;
                            cout<<"Matric  : "<<temp->getMatric()<<endl;
                            found = true;
                        }
                        temp = temp->next;
                    }
                    break;

                    case 3: 
                        while(temp != NULL)
                    {
                        if(temp->getAge() == key2)
                        {
                            cout<<"\nName  : "<<temp->getName()<<endl;
                            cout<<"Faculty : "<<temp->getFaculty()<<endl;
                            cout<<"Age     : "<<temp->getAge()<<endl;
                            cout<<"IC      : "<<temp->getIC()<<endl;
                            cout<<"Email   : "<<temp->getEmail()<<endl;
                            cout<<"Matric  : "<<temp->getMatric()<<endl;
                            found = true;
                        }
                        temp = temp->next;
                    }
                    break; 

                    case 4:
                        while(temp != NULL)
                        {
                            if(temp->getIC() == key)
                            {
                                cout<<"\nName  : "<<temp->getName()<<endl;
                                cout<<"Faculty : "<<temp->getFaculty()<<endl;
                                cout<<"Age     : "<<temp->getAge()<<endl;
                                cout<<"IC      : "<<temp->getIC()<<endl;
                                cout<<"Email   : "<<temp->getEmail()<<endl;
                                cout<<"Matric  : "<<temp->getMatric()<<endl;
                                found = true;
                            }
                            temp = temp->next;
                        }
                        break;
                    case 5:
                        while(temp != NULL)
                        {
                            if(temp->getEmail() == key)
                        {
                            cout<<"\nName  : "<<temp->getName()<<endl;
                            cout<<"Faculty : "<<temp->getFaculty()<<endl;
                            cout<<"Age     : "<<temp->getAge()<<endl;
                            cout<<"IC      : "<<temp->getIC()<<endl;
                            cout<<"Email   : "<<temp->getEmail()<<endl;
                            cout<<"Matric  : "<<temp->getMatric()<<endl;
                            found = true;
                        }
                            temp = temp->next;
                        }
                        break;
                    case 6:
                    while(temp != NULL)
                    {
                        if(temp->getMatric() == key)
                        {
                            cout<<"\nName  : "<<temp->getName()<<endl;
                            cout<<"Faculty : "<<temp->getFaculty()<<endl;
                            cout<<"Age     : "<<temp->getAge()<<endl;
                            cout<<"IC      : "<<temp->getIC()<<endl;
                            cout<<"Email   : "<<temp->getEmail()<<endl;
                            cout<<"Matric  : "<<temp->getMatric()<<endl;
                            found = true;
                        }
                        temp = temp->next;
                    }
                    break;
			}
            if(!found)
                    cout<<"Data was not found. Try again later !"<<endl;
			}
		}

         void display()
        {
            Voter *temp=head;
            cout<<"-----------------------------------------------------------------------------------------------------------------------"<<endl;
            cout<<"|       Name       "<<" | "<<"      Faculty      "<<" | "<<"      IC     "<<" | "<<"   Age  "<<" | "<<"   Matric Number  "<<" | "<<"         Email            |"<<endl;
            cout<<"-----------------------------------------------------------------------------------------------------------------------"<<endl;
             while(temp != NULL)
            {
                cout<<left<<"|  "<<setw(16)<<temp->getName()<<" |       "<<setw(13)<<temp->getFaculty()<<" |  "<<setw(12)<<temp->getIC()<<" |     "<<setw(4)<<temp->getAge()<<" |    "<<setw(16)<<temp->getMatric()<<"|  "<<setw(25)<<temp->getEmail()<<"|"<<endl;
                cout<<"-----------------------------------------------------------------------------------------------------------------------"<<endl;
                temp = temp->next;
            }
        }

	    void outFile2()
        {
        	ofstream out;
        	out.open("voter2.txt");
        	Voter *temp=head;
        	out<<"-----------------------------------------------------------------------------------------------------------------------"<<endl;
            out<<"|       Name       "<<" | "<<"      Faculty      "<<" | "<<"      IC     "<<" | "<<"   Age  "<<" | "<<"   Matric Number  "<<" | "<<"         Email            |"<<endl;
            out<<"-----------------------------------------------------------------------------------------------------------------------"<<endl;
            while(temp != NULL)
            {
                out<<left<<"|  "<<setw(16)<<temp->getName()<<" |       "<<setw(13)<<temp->getFaculty()<<" |  "<<setw(12)<<temp->getIC()<<" |     "<<setw(4)<<temp->getAge()<<" |    "<<setw(16)<<temp->getMatric()<<"|  "<<setw(25)<<temp->getEmail()<<"|"<<endl;
                out<<"-----------------------------------------------------------------------------------------------------------------------"<<endl;
                temp = temp->next;
            }
		}

        void outFile()
        {
        	ofstream out;
        	out.open("voter.csv");

            Voter *temp=head;

            while(temp != NULL)
            {
                out<<temp->getName()<<","<<temp->getFaculty()<<","<<temp->getIC()<<","<<temp->getAge()<<","<<temp->getMatric()<<","<<temp->getEmail()<<endl;
                temp = temp->next;
            }
		}

		void ascendName()
        {
            Voter *temp,*temp2;
            bool sorted=false;
			string n,f,e,i,m;
            int a;
            

            for(temp=head; (temp->next!=NULL)&&!sorted ; temp=temp->next)
            {	sorted = true;
                for(temp2=head; temp2->next!=NULL; temp2=temp2->next)
                {
                    if( temp2->getName() > (temp2->next->getName()) )
                    {
						n = temp2->getName();
						f = temp2->getFaculty();
                        e = temp2->getEmail();
                        i = temp2->getIC();
                        m = temp2->getMatric();
                        a = temp2->getAge();

                        temp2->setName(temp2->next->getName());
                        temp2->setFaculty(temp2->next->getFaculty());
                        temp2->setEmail(temp2->next->getEmail());
                        temp2->setIC(temp2->next->getIC());
                        temp2->setMatric(temp2->next->getMatric());
                        temp2->setAge(temp2->next->getAge());

                        temp2->next->setName(n);
                        temp2->next->setFaculty(f);
                        temp2->next->setEmail(e);
                        temp2->next->setIC(i);
                        temp2->next->setMatric(m);
                        temp2->next->setAge(a);
                        sorted = false;
                    }

                }
            }
        }
        
        void descendName()
        {
        Voter *temp = head;
        string n,f,e,i,m;
        int a;

        while(temp){
        Voter *min = temp;
        Voter *next = temp->next;

        while(next != NULL){
            if(min->getName()<next->getName())
                min = next;
            next = next->next;
        }

        n = temp->getName();
		f = temp->getFaculty();
        e = temp->getEmail();
        i = temp->getIC();
        m = temp->getMatric();
        a = temp->getAge();

        temp->setName(min->getName());
        temp->setFaculty(min->getFaculty());
        temp->setEmail(min->getEmail());
        temp->setIC(min->getIC());
        temp->setMatric(min->getMatric());
        temp->setAge(min->getAge());

        min->setName(n);
        min->setFaculty(f);
        min->setEmail(e);
        min->setIC(i);
        min->setMatric(m);
        min->setAge(a);

        temp = temp->next;
    }
        }

void AgeAsc() { 
    Voter *temp,*temp2;
            bool sorted=false;
			string n,f,e,i,m;
            int a;
            

           for(temp=head; (temp->next!=NULL)&&!sorted ; temp=temp->next)
            {	sorted = true;	
                for(temp2=head; temp2->next!=NULL; temp2=temp2->next)
                {
                    if( temp2->getAge() > (temp2->next->getAge()) )
                    {
						n = temp2->getName();
						f = temp2->getFaculty();
                        e = temp2->getEmail();
                        i = temp2->getIC();
                        m = temp2->getMatric();
                        a = temp2->getAge();

                        temp2->setName(temp2->next->getName());
                        temp2->setFaculty(temp2->next->getFaculty());
                        temp2->setEmail(temp2->next->getEmail());
                        temp2->setIC(temp2->next->getIC());
                        temp2->setMatric(temp2->next->getMatric());
                        temp2->setAge(temp2->next->getAge());

                        temp2->next->setName(n);
                        temp2->next->setFaculty(f);
                        temp2->next->setEmail(e);
                        temp2->next->setIC(i);
                        temp2->next->setMatric(m);
                        temp2->next->setAge(a);
                        sorted = false;
                    }

                }
            }
} 

void AgeDes() { 
    Voter *temp = head;
    string n,f,e,i,m;
    int a;

    while(temp){
        Voter *min = temp;
        Voter *next = temp->next;

        while(next != NULL){
            if(min->getAge()<next->getAge())
                min = next;
            next = next->next;
        }

        n = temp->getName();
		f = temp->getFaculty();
        e = temp->getEmail();
        i = temp->getIC();
        m = temp->getMatric();
        a = temp->getAge();

        temp->setName(min->getName());
        temp->setFaculty(min->getFaculty());
        temp->setEmail(min->getEmail());
        temp->setIC(min->getIC());
        temp->setMatric(min->getMatric());
        temp->setAge(min->getAge());

        min->setName(n);
        min->setFaculty(f);
        min->setEmail(e);
        min->setIC(i);
        min->setMatric(m);
        min->setAge(a);

        temp = temp->next;
    }
} 

void facAsc(){
    Voter *temp,*temp2;
    bool sorted=false;
	string n,f,e,i,m;
    int a;

     for(temp=head; (temp->next!=NULL)&&!sorted ; temp=temp->next)
            {	sorted = true;
                for(temp2=head; temp2->next!=NULL; temp2=temp2->next)
                {

                        if( temp2->getFaculty() > (temp2->next->getFaculty()) )
                    {
						n = temp2->getName();
						f = temp2->getFaculty();
                        e = temp2->getEmail();
                        i = temp2->getIC();
                        m = temp2->getMatric();
                        a = temp2->getAge();

                        temp2->setName(temp2->next->getName());
                        temp2->setFaculty(temp2->next->getFaculty());
                        temp2->setEmail(temp2->next->getEmail());
                        temp2->setIC(temp2->next->getIC());
                        temp2->setMatric(temp2->next->getMatric());
                        temp2->setAge(temp2->next->getAge());

                        temp2->next->setName(n);
                        temp2->next->setFaculty(f);
                        temp2->next->setEmail(e);
                        temp2->next->setIC(i);
                        temp2->next->setMatric(m);
                        temp2->next->setAge(a);
                        sorted = false;
                    }
                    }

                }
}

void facDes(){
    Voter *temp = head;
    string n,f,e,i,m;
    int a;

    while(temp){
        Voter *min = temp;
        Voter *next = temp->next;

        while(next != NULL){
            if(min->getFaculty()<next->getFaculty())
                min = next;
            next = next->next;
        }

        n = temp->getName();
		f = temp->getFaculty();
        e = temp->getEmail();
        i = temp->getIC();
        m = temp->getMatric();
        a = temp->getAge();

        temp->setName(min->getName());
        temp->setFaculty(min->getFaculty());
        temp->setEmail(min->getEmail());
        temp->setIC(min->getIC());
        temp->setMatric(min->getMatric());
        temp->setAge(min->getAge());

        min->setName(n);
        min->setFaculty(f);
        min->setEmail(e);
        min->setIC(i);
        min->setMatric(m);
        min->setAge(a);

        temp = temp->next;
    }
}

void matasc(){
    Voter *temp,*temp2;
            bool sorted=false;
			string n,f,e,i,m;
            int a;
            

            for(temp=head; (temp->next!=NULL)&&!sorted ; temp=temp->next)
            {	sorted = true;	
                for(temp2=head; temp2->next!=NULL; temp2=temp2->next)
                {
                    if( temp2->getMatric() > (temp2->next->getMatric()) )
                    {
						n = temp2->getName();
						f = temp2->getFaculty();
                        e = temp2->getEmail();
                        i = temp2->getIC();
                        m = temp2->getMatric();
                        a = temp2->getAge();

                        temp2->setName(temp2->next->getName());
                        temp2->setFaculty(temp2->next->getFaculty());
                        temp2->setEmail(temp2->next->getEmail());
                        temp2->setIC(temp2->next->getIC());
                        temp2->setMatric(temp2->next->getMatric());
                        temp2->setAge(temp2->next->getAge());

                        temp2->next->setName(n);
                        temp2->next->setFaculty(f);
                        temp2->next->setEmail(e);
                        temp2->next->setIC(i);
                        temp2->next->setMatric(m);
                        temp2->next->setAge(a);
                        sorted = false;
                    }

                }
            }
}

void matDes(){
    Voter *temp = head;
    string n,f,e,i,m;
    int a;

    while(temp){
        Voter *min = temp;
        Voter *next = temp->next;

        while(next != NULL){
            if(min->getMatric()<next->getMatric())
                min = next;
            next = next->next;
        }
        n = temp->getName();
		f = temp->getFaculty();
        e = temp->getEmail();
        i = temp->getIC();
        m = temp->getMatric();
        a = temp->getAge();

        temp->setName(min->getName());
        temp->setFaculty(min->getFaculty());
        temp->setEmail(min->getEmail());
        temp->setIC(min->getIC());
        temp->setMatric(min->getMatric());
        temp->setAge(min->getAge());

        min->setName(n);
        min->setFaculty(f);
        min->setEmail(e);
        min->setIC(i);
        min->setMatric(m);
        min->setAge(a);

        temp = temp->next;
    }

}
void emailasc(){
    Voter *temp,*temp2;
            bool sorted=false;
			string n,f,e,i,m;
            int a;

            for(temp=head; (temp->next!=NULL)&&!sorted ; temp=temp->next)
            {	sorted = true;	
                for(temp2=head; temp2->next!=NULL; temp2=temp2->next)
                {
                    if( temp2->getEmail() > (temp2->next->getEmail()) )
                    {
                        n = temp2->getName();
						f = temp2->getFaculty();
                        e = temp2->getEmail();
                        i = temp2->getIC();
                        m = temp2->getMatric();
                        a = temp2->getAge();

                        temp2->setName(temp2->next->getName());
                        temp2->setFaculty(temp2->next->getFaculty());
                        temp2->setEmail(temp2->next->getEmail());
                        temp2->setIC(temp2->next->getIC());
                        temp2->setMatric(temp2->next->getMatric());
                        temp2->setAge(temp2->next->getAge());

                        temp2->next->setName(n);
                        temp2->next->setFaculty(f);
                        temp2->next->setEmail(e);
                        temp2->next->setIC(i);
                        temp2->next->setMatric(m);
                        temp2->next->setAge(a);
                        sorted = false;
                    }}}
}

void emailDes(){
    Voter *temp = head;
    string n,f,e,i,m;
    int a;

    while(temp){
        Voter *min = temp;
        Voter *next = temp->next;

        while(next != NULL){
            if(min->getEmail()<next->getEmail())
                min = next;
            next = next->next;
        }
         n = temp->getName();
		f = temp->getFaculty();
        e = temp->getEmail();
        i = temp->getIC();
        m = temp->getMatric();
        a = temp->getAge();

        temp->setName(min->getName());
        temp->setFaculty(min->getFaculty());
        temp->setEmail(min->getEmail());
        temp->setIC(min->getIC());
        temp->setMatric(min->getMatric());
        temp->setAge(min->getAge());

    }

}


};

void VoterDetials(string &n,string &f,int &a,string &ic,string &e,string &m)
{
    cin.ignore();
    cout<<"\nPlease enter your details "<<endl;
    cout << "Name : ";
    getline(cin,n);
    cout<<"Faculty : ";
    getline(cin,f);
    cout<<"Email : ";
    cin>>e;
    cout<<"IC : ";
    cin>>ic;
    cout<<"Matric Number : ";
    cin>>m;
    cout<<"Age : ";
    cin>>a;
}

void insertUI(int &opt1,int &opt2,List l)
{
    cout<<"\n[1] Insert at Front"<<endl;
    cout<<"[2] Insert at End"<<endl;
    cout<<"[3] Insert at Position"<<endl;
    cout<<"Please choose an option : ";
    cin>>opt1;

    if(opt1 == 3)
    {   l.display();
        cout<<"Please enter the position you want to insert : ";
        cin>>opt2;
    }
}

void deleteUI(int &opt1,int &opt2, List l)
{
    cout<<"\n[1] Delete at Front"<<endl;
    cout<<"[2] Delete at End"<<endl;
    cout<<"[3] Delete at Position"<<endl;
    cout<<"Please choose an option : ";
    cin>>opt1;

    if(opt1 == 3)
    {   
        l.display();
        cout<<"Please enter the position you want to delete : ";
        cin>>opt2;
    }
}

int searchUI(string &key,int &key2)
{

    int opt;
    cout<<"\n[1] Name"<<endl;
    cout<<"[2] Faculty"<<endl;
    cout<<"[3] Age"<<endl;
    cout<<"[4] IC"<<endl;
    cout<<"[5] Email"<<endl;
    cout<<"[6] Matric"<<endl;
    cout<<"Please choose an option : ";
    cin>>opt;
	cin.ignore();
    
    if(opt == 3){
        cout<<"\nPlease enter the key : ";
        cin>>key2;
    }

    else{
        cout<<"\nPlease enter the key : ";
        getline(cin,key);
    }

    return opt;
}



int main()
{
    string name,faculty,email,ic,matric,key;
    int age,opt1,opt2,num,key2,opt5,opt6;
    char answer,answer2;
    List l;

    ifstream in;
    in.open("voter.csv");
    
    getline(in,name,',');
    while(!in.eof())
    {
        getline(in,faculty,',');
        getline(in,ic,',');
        in>>age;
        in.ignore();
        getline(in,matric,',');
        getline(in,email,'\n');
        l.insertFront(name,faculty,age,ic,email,matric);
		//cout<<name<<" "<<faculty<<" "<<ic<<" "<<age<<" "<<matric<<" "<<email<<endl;
        getline(in,name,',');
    }

    cout<<"[1] Insert\n[2] Delete\n[3] Search\n[4] Sorting\n";
    cout<<"Please choose an option : ";
    cin>>opt1;

    do{
    
        if(opt1==1){
            cout<<"\nPlease enter number of voters needed to be inserted >> ";
            cin>>num;

            do{
                insertUI(opt1,opt2,l);
                VoterDetials(name,faculty,age,ic,email,matric);
                switch(opt1){
                    case 1 : l.insertFront(name,faculty,age,ic,email,matric);
                            break;
                    case 2 : l.insertend(name,faculty,age,ic,email,matric);
                            break;
                    case 3 : l.insertAtNode(name,faculty,age,ic,email,matric,opt2);
                            break;
                }
                num--;
            }while(num>0);

            cout<<"\nView voters (y/n) : ";
            cin>>answer2;
        if(answer2 == 'y' || answer2 == 'Y')
	        l.display();
        }
        else if(opt1==2)
        {
            deleteUI(opt1,opt2,l);
            switch(opt1){
                    case 1 : l.deleteFront();
                            break;
                    case 2 : l.deleteEnd();
                            break;
                    case 3 : l.deleteAtNode(opt2);
                            break;
                }

            cout<<"\nView voters (y/n) : ";
            cin>>answer2;

            if(answer2 == 'y' || answer2 == 'Y')
                l.display();
        }

        else if(opt1 == 3)
        {
            opt2 = searchUI(key,key2);
            l.search(opt2,key,key2);
        }

        else if(opt1 == 4)
        {
            opt5 = sortingUI(opt6);
            switch(opt5)
            {
            	case 1 : 
					if(opt6 == 1)
						l.ascendName();
					else
						l.descendName();
                    l.display();
					break;
                case 2 : 
                    if(opt6==1)
                        l.facAsc();
                    else
                        l.facDes();
                    l.display();
                    break; 
                case 3: 
                    if(opt6 == 1)
                        l.AgeAsc();
                    else 
                        l.AgeDes();
}
