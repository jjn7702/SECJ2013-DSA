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

        void display() //DISPLAY CANDIDATE
        {
            Candidate *temp = Chead;
            cout<<"------------------------------------------------------------------------------------------------------------------------------------"<<endl;
            cout<<"|       Name       "<<" | "<<"      Faculty      "<<" | "<<"      IC     "<<" | "<<"   Age  "<<" | "<<"   Matric Number  "<<" | "<<"         Email            |"<<" Vote Count |"<<endl;
            cout<<"------------------------------------------------------------------------------------------------------------------------------------"<<endl;
             while(temp != NULL)
            {
                cout<<left<<"|  "<<setw(16)<<temp->getName()<<" |       "<<setw(13)<<temp->getFaculty()<<" |  "<<setw(12)<<temp->getIC()<<" |     "<<setw(4)<<temp->getAge()<<" |    "<<setw(16)<<temp->getMatric()<<"|  "<<setw(25)<<temp->getEmail()<<"|    "<<setw(8)<<temp->getVoteCount()<<"|"<<endl;
                cout<<"------------------------------------------------------------------------------------------------------------------------------------"<<endl;
                temp = temp->next;
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

    	void displayProfile(Candidate *s3){
        	 cout<<"\nName         : "<<s3->getName()<<endl;
             cout<<"Faculty      : "<<s3->getFaculty()<<endl;
             cout<<"Age          : "<<s3->getAge()<<endl;
             cout<<"IC           : "<<s3->getIC()<<endl;
             cout<<"Email        : "<<s3->getEmail()<<endl;
             cout<<"Matric       : "<<s3->getMatric()<<endl;
             cout<<"Phone number : " <<s3->getPhone() << endl;
             cout<<"Vote Count   : "<<s3->getVoteCount() << endl;
		}
	
	void facAsc(){
    Candidate *temp,*temp2;
    bool sorted=false;
	string n,f,e,i,m,p,ph;
    int a,v;

     for(temp=Chead; (temp->next!=NULL)&&!sorted ; temp=temp->next)
            {	sorted = true;
                for(temp2=Chead; temp2->next!=NULL; temp2=temp2->next)
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
                        v = temp2->getVoteCount();
                        ph = temp2->getPhone();
                        

                        temp2->setName(temp2->next->getName());
                        temp2->setFaculty(temp2->next->getFaculty());
                        temp2->setEmail(temp2->next->getEmail());
                        temp2->setIC(temp2->next->getIC());
                        temp2->setMatric(temp2->next->getMatric());
                        temp2->setAge(temp2->next->getAge());
                        temp2->setVoteCount(temp2->next->getVoteCount());
                        temp2->setPass(temp2->next->getPass());
                        temp2->setPhone(temp2->next->getPhone());

                        temp2->next->setName(n);
                        temp2->next->setFaculty(f);
                        temp2->next->setEmail(e);
                        temp2->next->setIC(i);
                        temp2->next->setMatric(m);
                        temp2->next->setAge(a);
                        temp2->next->setPass(p);
                        temp2->next->setPhone(ph);
                        temp2->next->setVoteCount(v);
                        sorted = false;
                    }
                    }

                }
            display();
                
}

	void NameAsc(){
    Candidate *temp,*temp2;
    bool sorted=false;
	string n,f,e,i,m,p,ph;
    int a,v;

     for(temp=Chead; (temp->next!=NULL)&&!sorted ; temp=temp->next)
            {	sorted = true;
                for(temp2=Chead; temp2->next!=NULL; temp2=temp2->next)
                {

                        if( temp2->getName() > (temp2->next->getName() ) )
                    {
						n = temp2->getName();
						f = temp2->getFaculty();
                        e = temp2->getEmail();
                        i = temp2->getIC();
                        m = temp2->getMatric();
                        p = temp2->getPass();
                        a = temp2->getAge();
                        v = temp2->getVoteCount();
                        ph = temp2->getPhone();
                        

                        temp2->setName(temp2->next->getName());
                        temp2->setFaculty(temp2->next->getFaculty());
                        temp2->setEmail(temp2->next->getEmail());
                        temp2->setIC(temp2->next->getIC());
                        temp2->setMatric(temp2->next->getMatric());
                        temp2->setAge(temp2->next->getAge());
                        temp2->setVoteCount(temp2->next->getVoteCount());
                        temp2->setPass(temp2->next->getPass());
                        temp2->setPhone(temp2->next->getPhone());

                        temp2->next->setName(n);
                        temp2->next->setFaculty(f);
                        temp2->next->setEmail(e);
                        temp2->next->setIC(i);
                        temp2->next->setMatric(m);
                        temp2->next->setAge(a);
                        temp2->next->setPass(p);
                        temp2->next->setPhone(ph);
                        temp2->next->setVoteCount(v);
                        sorted = false;
                    }
                    }

                }
            display();
                
}

	void MatricAsc(){
    Candidate *temp,*temp2;
    bool sorted=false;
	string n,f,e,i,m,p,ph;
    int a,v;

     for(temp=Chead; (temp->next!=NULL)&&!sorted ; temp=temp->next)
            {	sorted = true;
                for(temp2=Chead; temp2->next!=NULL; temp2=temp2->next)
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
                        v = temp2->getVoteCount();
                        ph = temp2->getPhone();
                        

                        temp2->setName(temp2->next->getName());
                        temp2->setFaculty(temp2->next->getFaculty());
                        temp2->setEmail(temp2->next->getEmail());
                        temp2->setIC(temp2->next->getIC());
                        temp2->setMatric(temp2->next->getMatric());
                        temp2->setAge(temp2->next->getAge());
                        temp2->setVoteCount(temp2->next->getVoteCount());
                        temp2->setPass(temp2->next->getPass());
                        temp2->setPhone(temp2->next->getPhone());

                        temp2->next->setName(n);
                        temp2->next->setFaculty(f);
                        temp2->next->setEmail(e);
                        temp2->next->setIC(i);
                        temp2->next->setMatric(m);
                        temp2->next->setAge(a);
                        temp2->next->setPass(p);
                        temp2->next->setPhone(ph);
                        temp2->next->setVoteCount(v);
                        sorted = false;
                    }
                    }

                }
            display();
                
}


void VoteAsc(){
    Candidate *temp,*temp2;
    bool sorted=false;
	string n,f,e,i,m,p,ph;
    int a,v;

     for(temp=Chead; (temp->next!=NULL)&&!sorted ; temp=temp->next)
            {	sorted = true;
                for(temp2=Chead; temp2->next!=NULL; temp2=temp2->next)
                {

                        if( temp2->getVoteCount() > (temp2->next->getVoteCount() ) )
                    {
						n = temp2->getName();
						f = temp2->getFaculty();
                        e = temp2->getEmail();
                        i = temp2->getIC();
                        m = temp2->getMatric();
                        p = temp2->getPass();
                        a = temp2->getAge();
                        v = temp2->getVoteCount();
                        ph = temp2->getPhone();
                        

                        temp2->setName(temp2->next->getName());
                        temp2->setFaculty(temp2->next->getFaculty());
                        temp2->setEmail(temp2->next->getEmail());
                        temp2->setIC(temp2->next->getIC());
                        temp2->setMatric(temp2->next->getMatric());
                        temp2->setAge(temp2->next->getAge());
                        temp2->setVoteCount(temp2->next->getVoteCount());
                        temp2->setPass(temp2->next->getPass());
                        temp2->setPhone(temp2->next->getPhone());

                        temp2->next->setName(n);
                        temp2->next->setFaculty(f);
                         temp2->next->setEmail(e);
                        temp2->next->setIC(i);
                        temp2->next->setMatric(m);
                        temp2->next->setAge(a);
                        temp2->next->setPass(p);
                        temp2->next->setPhone(ph);
                        temp2->next->setVoteCount(v);
                        sorted = false;
                    }
                    }

                }
            display();
                
}

	void VoteDes(){
    Candidate *temp,*temp2;
    bool sorted=false;
	string n,f,e,i,m,p,ph;
    int a,v;

     for(temp=Chead; (temp->next!=NULL)&&!sorted ; temp=temp->next)
            {	sorted = true;
                for(temp2=Chead; temp2->next!=NULL; temp2=temp2->next)
                {

                        if( temp2->getVoteCount() < (temp2->next->getVoteCount()) )
                    {	n = temp2->getName();
						f = temp2->getFaculty();
                        e = temp2->getEmail();
                        i = temp2->getIC();
                        m = temp2->getMatric();
                        p = temp2->getPass();
                        a = temp2->getAge();
                        v = temp2->getVoteCount();
                        ph = temp2->getPhone();
                        

                        temp2->setName(temp2->next->getName());
                        temp2->setFaculty(temp2->next->getFaculty());
                        temp2->setEmail(temp2->next->getEmail());
                        temp2->setIC(temp2->next->getIC());
                        temp2->setMatric(temp2->next->getMatric());
                        temp2->setAge(temp2->next->getAge());
                        temp2->setVoteCount(temp2->next->getVoteCount());
                        temp2->setPass(temp2->next->getPass());
                        temp2->setPhone(temp2->next->getPhone());

                        temp2->next->setName(n);
                        temp2->next->setFaculty(f);
                        temp2->next->setEmail(e);
                        temp2->next->setIC(i);
                        temp2->next->setMatric(m);
                        temp2->next->setAge(a);
                        temp2->next->setPass(p);
                        temp2->next->setPhone(ph);
                        temp2->next->setVoteCount(v);
                        sorted = false;
                    }
                    }

                }
            display();
                
}
void search(int opt,string key,int key2) // SEARCHING CANDIDATE
        {
            Candidate *temp = Chead;
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
	
};

int LoginUI()
{
	int opt1;
	bool found = false;
		do{
			cout<<"*****Main Menu*****";
			cout<<"\n[1] Login as Admin\n[2] Login as Voter\n[3] Login as Candidate\nPlease choose the option : ";
			cin>>opt1;
			system("CLS");
		}while(opt1<1 || opt1>3);
	
	return opt1;
}
void AdminLogin(Admin arr[],int j){
			bool found = false;
			do
			{
                cin.ignore();
				string loginId,loginPass;
				cout<<"Please enter your USERNAME & PASSWORD"<<endl;
				cout<<"USERNAME : ";
				cin>>loginId;
				cout<<"PASSWORD : ";
				cin>>loginPass;
				cout<<endl;
				system("CLS");
				
				
				for(int i=0;i<j;i++){
                    if((arr[i].getUsername() == loginId) && (arr[i].getPassword() == loginPass )){
                        cout<<"\nWelcome, "<<arr[i].getUsername()<<endl;
						found = true;
						break;
                }
                }
		
				if(found==false)
					cout<<"ID or Password entered is wrong!"<<endl<<endl;
	
		}while(found==false);
	}

    void adminVoter(VoterQueue v){
    system("CLS");
    int opt;
    cout<<"How would you like to view voters.\n";
    cout<<"\n[1] Name"<<endl;
    cout<<"[2] Faculty"<<endl;
    cout<<"[3] Matric"<<endl;
    cout<<"Please choose an option : ";
    cin>>opt;

    switch (opt){
        case(1) :   v.ascendName();
                    break;
        case(2) :   v.facAsc();
                    break;
        case(3) :   v.MatricAsc();
                    break;
    }
}

void adminCand(CandidateList c){
    system("CLS");
    int opt;
    cout<<"How would you like to view candidate.\n";
    cout<<"\n[1] Name"<<endl;
    cout<<"[2] Faculty"<<endl;
    cout<<"[3] Matric"<<endl;
    cout<<"[4] Vote Count"<<endl;
    cout<<"Please choose an option : ";
    cin>>opt;

    switch (opt){
        case(1) :   c.NameAsc();
                    break;
        case(2) :   c.facAsc();
                    break;
        case(3) :   c.MatricAsc();
                    break;
        case(4) :   c.VoteAsc();
                    break;
    }

}

int main()
{
    string name,faculty,email,ic,matric,key,pass,phone,status;
    int age,opt1,vote,count=1;
    char answer,answer2,ch;
    VoterQueue l;
    Voter *l2 = NULL;

    ifstream in;
    in.open("voter.csv");
    
    while(getline(in,name,','))
    {
        getline(in,faculty,',');
        getline(in,ic,',');
        in>>age;
        in.ignore();
        getline(in,matric,',');
        getline(in,pass,',');
        getline(in,email,',');
        getline(in,status,'\n');
        l.Enqueue(name,faculty,age,ic,email,matric,pass,status);
		
    }
    in.close();
    
    CandidateList c;
    Candidate *c2 = NULL;
    
    ifstream inp;
    inp.open("cand.csv");
    
    while(getline(inp,name,','))
    {
        getline(inp,faculty,',');
        inp>>age;
        inp.ignore();
        getline(inp,ic,',');
        getline(inp,phone,',');
        inp>>vote;
        inp.ignore();
        getline(inp,matric,',');
        getline(inp,pass,',');
        getline(inp,email,'\n');
        c.insertFront(name,faculty,age,ic,phone,vote,matric,pass,email);
		//cout<<name<<" "<<faculty<<" "<<ic<<" "<<age<<" "<<matric<<" "<<pass<<" "<<email<<" "<<phone<<" "<<vote<<endl;
        //getline(in,name,',');
    }

    string user;
    int j=0;
    Admin adm[10];

    ifstream inx;
    inx.open("admin.csv");

    
    while(getline(inx,pass,',')){
	    getline(inx,user,'\n');
	    //cout<<"User : "<<user<<" Pass : "<<pass<<endl;
	    adm[j] = Admin(user,pass);
	    j++;
    }
    	inx.close();
    opt1 = LoginUI();
    
    do
    {
    
    int voteC[3]={-1,-2,-3};
    int opt6,opt5,opt9;
    string ex;
    switch(opt1)
    {
    	case 1 : if(count==1){
         			AdminLogin(adm,j);}
                 cout<<" [1] View Voter\n [2] View Candidate\n [3] Delete Voter\n [4] Delete Candidate\n [5] Insert Candidate\n [6] Exit\n";
                 cout<<"Option : ";
                 cin>>opt5;
                 switch(opt5){
                        case 1  :   adminVoter(l);
                                    break;
                        case 2  :   adminCand(c);
                                    break;
                        case 3  :   l.display();
                                    int del;
                                    cout<<"How many voter(s) you want to delete? : ";
                                    cin>>del;
                                    for(int i=0;i<del;i++){
                                        l.Dequeue();
                                    }
                                    system("CLS");
                                    cout<<"\nVoters after deletion : \n";
                                    l.display();
                                    break;
                                     case 4  :   c.display();
                                    cout<<"\nPlease enter the position you want to delete : ";
                                    cin>>del;
                                    if(del==1){
                                    c.deleteFront();
                                    }
                                    else{
                                    c.deleteAtNode(del);
                                    }
                                    system("CLS");
                                    cout<<"Candidates after deletion : \n";
                                    c.display();
                                    break;
                        case 5  :   c.insertAdmin();
                                    break;
                        case 6 :   exit(0);
                    }
                break;
    	case 2 : if(count==1)
				 	l2 = l.Voterlogin();
                    cout<<"[1] Vote \n[2] View profile \n[3] Search for candidate\n [4] Exit\n";
    			 cout<<"Please choose an option : ";
    			 cin>>opt6;
    			 system("CLS");
    			 break;
    	case 3 : 
    			 if(count==1)
					c2 = c.CandLogin();
				 cout<<"[1] View Profile\n[2] View Candidate\n[3] Withdraw\n[4] Exit\n";
                 cout<<"Option : ";
                 cin>>opt9;
                 switch(opt9){
                        case 1  :   c.displayProfile(c2);
                                    break;
                        case 2  :   c.display();
                                    break;
                        case 3  :   c.delsearch(c2);
                                    break;
                        default : exit(0);
                    }
	}
	
	int key2,opt7;
	string key3;
	
	switch(opt6)
	{
		case 1 : 
				 if(l2->getVoteStatus()=="null")
				 {
				 	 c.facAsc();
					 cout<<"\nPlease choose 3 candidates : ";
					 cout<<"\nChoice 1 : ";
					 cin>>voteC[0];
					 do
					 {
					 	cout<<"\nChoice 2 : ";
					 	cin>>voteC[1];
					 }while(voteC[0]==voteC[1]);
					 do
					 {
					 	cout<<"\nChoice 3 : ";
					 	cin>>voteC[2];
					 }while((voteC[0]==voteC[1])||(voteC[1]==voteC[2])||(voteC[2]==voteC[0]));
					 
					 l.voteStat(l2);
					 c.voteCand(voteC);
				 }
				 else
				 	cout<<"\nYou have already voted!"<<endl;
				 break;