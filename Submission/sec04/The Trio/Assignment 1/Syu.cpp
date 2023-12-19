#include<iostream>
#include<fstream>
#include<string>
using namespace std;

class Customer{
              private:
                string name;
                int age;
                string IC;
                string phoneNum;
              public:
                void setName(string n){ return name = n;}
                void setAge(int a){age = a;}
                void setIC(string ic){IC = ic;}
                void setPhone(string p){phoneNum = p ;}
                string getName(){return name;}
                int getAge(){return age;}
                string getIC(){return IC;}
                string getPhone(){return phoneNum;}
};
//Sort customers based on phone number
void SortingPhone(Customer data[] , int size){

              Customer temp;
              bool sorted = false;

              for (int pass = 1; (pass <size) && ! sorted; ++pass){
                sorted = true;
                for(int x = 0 ; x <size-pass;x++){
                        if(data[x].getPhone()>data[x+1].getPhone()){

                temp.setName(data[x].getName());
                temp.setAge(data[x].getAge());
                temp.setIC(data[x].getIC());
                temp.setPhone(data[x].getPhone());

              data[x].setName(data[x+1].getName());
              data[x].setAge(data[x+1].getAge());
              data[x].setIC(data[x+1].getIC());
              data[x].setPhone(data[x+1].getPhone());
              data[x+1].setName(temp.getName());
              data[x+1].setAge(temp.getAge());
              data[x+1].setIC(temp.getIC());
              data[x+1].setPhone(temp.getPhone());
                  sorted = false;

                        }
                }
              }
}//end of sort based on phone number
//Search key based on age 

void SearchAge(int searchKey, Customer data[], int size){

      int index = -1 //-1 means record is not found
      for(int i = 0 ; i<size ; i++){

        if(searchKey == data[i].getAge()){
              index = i // assign current array index 
                break; // terminate searching 
        }
      }

          if(index == -1)
              cout<<"\nNot found..." <<endl;
          else 
      {  
          cout<<"\nName: " << data[index].getName() <<endl << "Age:" << data[index].getAge() <<endl << "IC Number:" << data[index].getIC() <<endl <<"Phone Number: " <<data[index].getPhone() << endl;
      }//end of search for age 


int main(){
        Customer customer[100];
        int custNum = 0 ;
        string name , IC , phoneNum ; 
        int age ; 

          ifstream input("Assignment_1.txt");
            if(!input){

              cout<< "Cannot open the file\n";
              return 1;
            }

          while(getline(input, name, '/'))
            {
                input>>age;
                input.ignore();
                getline(input,IC,'/');
                input>>phoneNum;
                input.ignore();

                customer[custNum].setName(name);
                customer[custNum].setAge(age);
                customer[custNum].setIC(IC);
                customer[custNum].setPhone(phoneNum);

                custNum++;
            }
            input.close();
}


  
  
      
