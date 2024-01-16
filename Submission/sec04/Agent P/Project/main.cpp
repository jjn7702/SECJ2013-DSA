#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

class Admin{
    string username, password;

    public: 
        Admin(string u=" ",string p=" "){
            username = u;
            password = p;
        }

        string getUsername(){return username;}
        string getPassword(){return password;}
};

class Voter{
    string name,faculty,email,ic,matric,pass,voteStat;
    int age;

    public:
     Voter *next;
        Voter(string n,string f,int a,string ic,string e,string m,string pass,string s)
        {
            name = n;
            faculty = f;
            age = a;
            this->ic = ic;
            email = e;
            matric = m;
            this->pass = pass;
            voteStat = s;
            next = NULL;
        }

        string getName(){return name;}
        string getFaculty(){return faculty;}
        int getAge(){return age;}
        string getIC(){return ic;}
        string getEmail(){return email;}
        string getMatric(){return matric;}
        string getPass(){return pass;}
        string getVoteStatus(){return voteStat;}
        
        void setName(string n){name=n;}
        void setFaculty(string f){faculty=f;}
        void setAge(int a){age=a;}
        void setIC(string i){ic=i;}
        void setEmail(string e){email=e;}
        void setMatric(string m){matric=m;}
        void setPass(string p){pass=p;}
        void setVoteStatus(string v){voteStat=v;}

};

class VoterQueue
{
    Voter *head;
    Voter *tail;

    public:
        VoterQueue(){
            head = NULL;
            tail = NULL;
        }

        bool isEmpty(){return ((head==NULL)&&(tail==NULL));}

        void Enqueue(string n,string f,int a,string ic,string e,string m,string p,string s)
        {
		
            Voter *newNode = new Voter(n,f,a,ic,e,m,p,s);

            if(isEmpty())
            	head = tail = newNode;

            else{
                tail->next = newNode;
                tail = newNode;
            }
        }

        void Dequeue()
        {
            if(isEmpty())
                cout<<"The list is empty!"<<endl;
                
            else if(head==tail)
            {
            	tail = head = NULL;
			}
            
            else{
            	Voter *temp = head;
            	head = temp->next;
            	temp->next = NULL;
            	delete temp;
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
                out<<temp->getName()<<","<<temp->getFaculty()<<","<<temp->getIC()<<","<<temp->getAge()<<","<<temp->getMatric()<<","<<temp->getPass()<<","<<temp->getEmail()<<","<<temp->getVoteStatus();
                temp = temp->next;
                out<<endl;
            }
		}
		
	void facAsc(){
    Voter *temp,*temp2;
    bool sorted=false;
	string n,f,e,i,m,p,v;
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
                        p = temp2->getPass();
                        a = temp2->getAge();
                        v = temp2->getVoteStatus();
                        

                        temp2->setName(temp2->next->getName());
                        temp2->setFaculty(temp2->next->getFaculty());
                        temp2->setEmail(temp2->next->getEmail());
                        temp2->setIC(temp2->next->getIC());
                        temp2->setMatric(temp2->next->getMatric());
                        temp2->setAge(temp2->next->getAge());
                        temp2->setVoteStatus(temp2->next->getVoteStatus());
                        temp2->setPass(temp2->next->getPass());

                        temp2->next->setName(n);
                        temp2->next->setFaculty(f);
                        temp2->next->setEmail(e);
                        temp2->next->setIC(i);
                        temp2->next->setMatric(m);
                        temp2->next->setAge(a);
                        temp2->next->setPass(p);
                        temp2->next->setVoteStatus(v);
                        sorted = false;
                    }
                    }

                }
            display();
                
}

	void ascendName()
        {
            Voter *temp,*temp2;
            bool sorted=false;
			string n,f,e,i,m,p,v;
            int a;
            
            for(temp=head; (temp->next!=NULL)&&!sorted ; temp=temp->next)
            {	sorted = true;
                for(temp2=head; temp2->next!=NULL; temp2=temp2->next)
                {
                    if( temp2->getName() > (temp2->next->getName()) )
                    {
                    	cout<<"Hello"<<endl;
						n = temp2->getName();
						f = temp2->getFaculty();
                        e = temp2->getEmail();
                        i = temp2->getIC();
                        m = temp2->getMatric();
                        a = temp2->getAge();
                        p = temp2->getPass();
                        v = temp2->getVoteStatus();

                        temp2->setName(temp2->next->getName());
                        temp2->setFaculty(temp2->next->getFaculty());
                        temp2->setEmail(temp2->next->getEmail());
                        temp2->setIC(temp2->next->getIC());
                        temp2->setMatric(temp2->next->getMatric());
                        temp2->setAge(temp2->next->getAge());
                        temp2->setPass(temp2->next->getPass());
                        temp2->setVoteStatus(temp2->next->getVoteStatus());

                        temp2->next->setName(n);
                        temp2->next->setFaculty(f);
                        temp2->next->setEmail(e);
                        temp2->next->setIC(i);
                        temp2->next->setMatric(m);
                        temp2->next->setAge(a);
                        temp2->next->setPass(p);
                        temp2->next->setVoteStatus(v);
                        sorted = false;
                    }

                }
            }
            display();
        }

	void MatricAsc(){
    Voter *temp,*temp2;
    bool sorted=false;
	string n,f,e,i,m,p,v;
    int a;

     for(temp=head; (temp->next!=NULL)&&!sorted ; temp=temp->next)
            {	sorted = true;
                for(temp2=head; temp2->next!=NULL; temp2=temp2->next)
                {

                        if( temp2->getMatric() > (temp2->next->getMatric() ) )
                    {
						n = temp2->getName();
						f = temp2->getFaculty();
                        e = temp2->getEmail();
                        i = temp2->getIC();
                        m = temp2->getMatric();
                        p = temp2->getPass();
                        a = temp2->getAge();
                        v = temp2->getVoteStatus();
                        

                        temp2->setName(temp2->next->getName());
                        temp2->setFaculty(temp2->next->getFaculty());
                        temp2->setEmail(temp2->next->getEmail());
                        temp2->setIC(temp2->next->getIC());
                        temp2->setMatric(temp2->next->getMatric());
                        temp2->setAge(temp2->next->getAge());
                        temp2->setVoteStatus(temp2->next->getVoteStatus());
                        temp2->setPass(temp2->next->getPass());

                        temp2->next->setName(n);
                        temp2->next->setFaculty(f);
                        temp2->next->setEmail(e);
                        temp2->next->setIC(i);
                        temp2->next->setMatric(m);
                        temp2->next->setAge(a);
                        temp2->next->setPass(p);
                        temp2->next->setVoteStatus(v);
                        sorted = false;
                    }
                    }

                }
            display();
                
}

Voter *Voterlogin()
{
	bool found = false;
	int opt,age;
	string name,faculty,email,ic,matric,pass,pass2;
	Voter *temp;
	
			do
			{
				temp = head;
				string loginId,loginPass;
				cout<<"Please enter your ID & PASSWORD"<<endl;
				cout<<"ID : ";
				cin>>loginId;
				cout<<"PASSWORD : ";
				cin>>loginPass;
				cout<<endl;
				system("CLS");
				
				while(temp != NULL)
				{
					if((temp->getMatric() == loginId) && (temp->getPass() == loginPass))
					{
						cout<<"Welcome, "<<temp->getName()<<endl<<endl;
						found = true;
						return temp;
					}
					
					temp = temp->next;
				}
		
				if(found==false)
				{
					cout<<"ID or Password entered is wrong!"<<endl<<endl;
					cout<<"[1] Try again"<<endl;
					cout<<"[2] Sign Up as new Voter"<<endl;
					cout<<"Please choose an option : ";
					cin>>opt;
					
					if(opt==2)
					{
						system("CLS");
						cout<<"Please enter the following details =>"<<endl;
						cout<<"Name : ";
						cin>>name;
						cout<<"Faculty : ";
			            cin>>faculty;
			            cout<<"Age : ";
			            cin>>age;
			            cout<<"IC : ";
			            cin>>ic;
			            cout<<"Email ";
			            cin>>email;
			            cout<<"Matric No. : ";
			            cin>>matric;
			            
			            temp = head;
					
						while(temp != NULL)
						{
							if(temp->getMatric() == matric)
							{
								cout<<temp->getName()<<", Record already exists in system!"<<endl<<endl;
								exit(0);
							}
							
							temp = temp->next;
						}
			            system("CLS");
			            do
			            {
			            	cout<<"\nPlease enter a password. The password must at least contain 8 characters!"<<endl;
				            cout<<"Password : ";
				            cin>>pass;
						}while(pass.size()<4);
						
						do
						{
							cout<<"Renter Password : ";
					        cin>>pass2;	
						}while(pass!=pass2);
						
						Enqueue(name,faculty,age,ic,email,matric,pass,"null");
						outFile();
						outFile2();
						cout<<endl;
						
						found = false;
					}
					
					else if(opt>2)
					{
						exit(0);
					}
				}
	
		}while(found==false);
    return NULL;
}
		void profile(Voter *v)
		{
			char choice;
			string ch;
			int opt,ch2;
			cout<<"Name        : "<<v->getName()<<endl;
			cout<<"Age         : "<<v->getAge()<<endl;
			cout<<"Matric      : "<<v->getMatric()<<endl;
			cout<<"Faculty     : "<<v->getFaculty()<<endl;
			cout<<"Email       : "<<v->getEmail()<<endl;
			cout<<"IC          : "<<v->getIC()<<endl;
			cout<<"Vote Status : "<<v->getVoteStatus()<<endl;
			
			cout<<"Edit profile (y/n): ";
			cin>>choice;
			
			if(choice=='y')
			{
				cout<<"\n[1] Name"<<endl;
			    cout<<"[2] Faculty"<<endl;
			    cout<<"[3] Age"<<endl;
			    cout<<"[4] IC"<<endl;
			    cout<<"[5] Email"<<endl;
			    cout<<"[6] Matric"<<endl;
			    cout<<"Please choose an option : ";
			    cin>>opt;
			    
			    if(opt == 3){
			         cout<<"\nPlease enter the key : ";
			         cin>>ch2;
		         }
		    	 else{
			         cout<<"\nPlease enter the key : ";
			         cin.ignore();
			         getline(cin,ch);
		    	}
			    
			    switch(opt)
			    {
			    	case 1 : v->setName(ch);
			    			break;
			    	case 2 : v->setFaculty(ch);
			    			break;
			    	case 3 : v->setAge(ch2);
			    			break;
			    	case 4 : v->setIC(ch);
			    			break;
					case 5 : v->setEmail(ch);
			    			break;
			    	case 6 : v->setMatric(ch);
			    			break;
				}
				
			}
		} 
	
		void voteStat(Voter *v)
		{
			string stat = "voted";
			v->setVoteStatus(stat);
			//cout<<v->getVoteStatus()<<endl;
		}
};

class Candidate
{
    string name,faculty,phone,ic,matric,pass,email;
    int age,voteCount;

    public:
    	Candidate *next;
        Candidate(string n,string f,int a,string ic,string p,int v,string m,string pass,string e)
        {
            name = n;
            faculty = f;
            age = a;
            this->ic = ic;
            phone = p;
            voteCount = v;
            matric = m;
            this->pass = pass;
            email = e;
            next = NULL;
        }

        string getName(){return name;}
        string getFaculty(){return faculty;}
        int getAge(){return age;}
        int getVoteCount(){return voteCount;}
        string getIC(){return ic;}
        string getPhone(){return phone;}
        string getMatric(){return matric;}
        string getPass(){return pass;}
        string getEmail(){return email;}
        
        void setName(string n){name=n;}
        void setFaculty(string f){faculty=f;}
        void setAge(int a){age=a;}
        void setVoteCount(int v){voteCount=v;}
        void setIC(string i){ic=i;}
        void setPhone(string p){phone=p;}
        void setMatric(string m){matric=m;}
        void setPass(string pa){pass=pa;}
        void setEmail(string e){email=e;}
};

class CandidateList
{
	Candidate *Chead;

    public:
		CandidateList()
		{
			Chead = NULL;
		}

        bool isEmpty()
		{
			return Chead == NULL;
		}
		
		void insertFront(string n,string f,int a,string ic,string p,int v,string m,string pass,string e) //INSERT FRONT
		{
			Candidate *nn = new Candidate(n,f,a,ic,p,v,m,pass,e);
			
			if(isEmpty())
				Chead = nn;
			else
			{
				nn->next = Chead;
				Chead = nn;
			}
		}

        Candidate *CandLogin() //CANDIDATE LOGIN
		{
			bool found = false;
			do
			{
				string loginId,loginPass;
				cout<<"Please enter your ID & PASSWORD"<<endl;
				cout<<"ID : ";
				cin>>loginId;
				cout<<"PASSWORD : ";
				cin>>loginPass;
				cout<<endl;
				system("CLS");
				
				Candidate *temp = Chead;
				
				while(temp != NULL)
				{
					if((temp->getMatric() == loginId) && (temp->getPass() == loginPass))
					{
						cout<<"\nWelcome, "<<temp->getName()<<endl<<endl;
						return temp;
					}
					
					temp = temp->next;
				}
		
				if(found==false)
					cout<<"ID or Password entered is wrong!"<<endl<<endl;
	
		}while(found==false);
    return NULL;
	} 

    void voteCand(int v[]) //VOTING FOR CANDIDATE
	{
		cout<<"\nVoted for : ";
		Candidate *temp;
		for(int i=0;i<3;i++)
		{
			temp = Chead;
			if(v[i]==1)
			{
				temp->setVoteCount(temp->getVoteCount()+1);
				cout<<"\nName    : "<<temp->getName()<<endl;
				cout<<"Faculty : "<<temp->getFaculty()<<endl;
				cout<<"Email   : "<<temp->getEmail()<<endl;
				cout<<"Vote    : "<<temp->getVoteCount()<<endl;
			}
			else
			{
				for(int j=1;j<v[i];j++)
					temp = temp->next;

				temp->setVoteCount(temp->getVoteCount()+1);
				cout<<"\nName    : "<<temp->getName()<<endl;
				cout<<"Faculty : "<<temp->getFaculty()<<endl;
				cout<<"Email   : "<<temp->getEmail()<<endl;
				cout<<"Vote    : "<<temp->getVoteCount()<<endl;
			}
		}
		
		CandFile();
	}

    void CandFile()
        {
        	ofstream out;
        	out.open("cand.csv");

            Candidate *temp = Chead;

            while(temp != NULL)
            {
                out<<temp->getName()<<","<<temp->getFaculty()<<","<<temp->getAge()<<","<<temp->getIC()<<","<<temp->getPhone()<<","<<temp->getVoteCount()<<","<<temp->getMatric()<<","<<temp->getPass()<<","<<temp->getEmail()<<endl;
                temp = temp->next;
            }
            out.close();
		}

        void insertAdmin()
		{
            system("CLS");
            Candidate *temp = Chead;
            string n,f,ic,p,m,pass,e;
            int a;
            int v = 0;
            cout<<"Please enter the following details =>"<<endl;
						cout<<"Name : ";
						cin>>n;
						cout<<"Faculty : ";
			            cin>>f;
			            cout<<"Age : ";
			            cin>>a;
			            cout<<"IC : ";
			            cin>>ic;
                        cout<<"Phone Number : ";
                        cin>>p;
			            cout<<"Email : ";
			            cin>>e;
			            cout<<"Matric No. : ";
			            cin>>m;
                        cout<<"Password : ";
                        cin>>pass;

                                    while(temp != NULL)
						{
							if(temp->getMatric() == m)
							{
								cout<<temp->getName()<<", Record already exists in system!"<<endl<<endl;
							}
							
							temp = temp->next;
						}

			Candidate *nn = new Candidate(n,f,a,ic,p,v,m,pass,e);
			
			if(isEmpty())
				Chead = nn;
			else
			{
				nn->next = Chead;
				Chead = nn;
			}
			
			CandFile();
            cout<<"The candidate is registered successfully!"<<endl;
		}

        void deleteFront()
        {
            if(isEmpty())
                cout<<"The list is empty!"<<endl;
            else{
                Candidate *temp = Chead;
                Chead = temp->next;
                temp->next = NULL;
            }
        }

        void deleteEnd()
        {
            if(isEmpty())
                cout<<"The list is empty!"<<endl;
            else{
                Candidate *temp = Chead,*temp2;
                while(temp->next != NULL){
                    temp2 = temp;
                    temp = temp->next;
                }

                temp2->next = NULL;
                delete temp;
                
            }
        }

        void deleteAtNode(int index)
        {
            if(isEmpty())
                cout<<"The list is empty!"<<endl;
            else{
                Candidate *temp = Chead,*temp2;
                
                for(int i=0;i<index-1;i++){
                    if(temp->next != NULL){
                        temp2 = temp;
                        temp = temp->next;
                    } 
                    else{
                        cout<<"The candidate does not exist";
                        exit(0);
                }   
                }
                temp2->next = temp->next;
                temp->next = NULL;
                delete temp;
            }
        }

         void delsearch(Candidate *s3){
		 Candidate* temp = Chead, *prev;
            bool found = false;
            
        	if(temp->getMatric() == s3->getMatric())
        	{
        		Chead = temp->next;
        		temp->next = NULL;
        		delete temp;
                display();
                cout<<"\nYou have successfully withdrawn!";
                CandFile();
                exit(0);
			}
			
			else
			{
	            while(temp->next != NULL){
	                if(temp->getMatric()== s3->getMatric()){
	                    found = true;
	                    break;
	                }
	
	                prev= temp;
	                temp = temp->next;
	            }
	            if(found){
	            	if(temp->next==NULL)
	            	{
	            		prev->next = NULL;
	            		delete temp;
                        display();
                        cout<<"\nYou have successfully withdrawn!";
                        CandFile();
                        exit(0);
					}
					else
					{
						prev->next = temp->next;
		                temp->next = NULL;
		                delete temp;
		                display();
                        cout<<"\nYou have successfully withdrawn!";
                        CandFile();
                        exit(0);
					}
	            }
            
        }
	}
	


	
};
