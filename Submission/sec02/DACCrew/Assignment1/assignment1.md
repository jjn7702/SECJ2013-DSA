//Banking Transaction System

	#include<iostream>
	#include<iomanip>
	#include<string>

	using namespace std;

	class Account
	{
	private:
	string name;
	string accNum;
	string ic; 
  	string pin;
	double accBalance;

	public:
	Account (string n="", string a=0, string i="", double b=0.0)
		:name(n),accNum(a),ic(i),accBalance(b){}

	string getName(string name)
	{
		return name;  
	}

	string getAccNum(string accNum)
	{
		return accNum;
	}

	string getIc(string ic)
	{
		return ic;
	}

	double getBalance(double accBalance)
	{
		return accBalance;
	}

	void setName(string name)
	{
		name = name;
	}

	void setAccNum(string accNum)
	{
		accNum = accNum;
	}

	void setName(string ic)
	{
		ic = ic;
	}

	void setName(string name)
	{
		name = name;
	}

	void Withdraw()
	{

	}

	void Deposit()
	{

	}

	void display()
	{
		//display account details (all attributes)
		//what have been done this withdraw/deposit
	}
};

void swap()
{

}

void quickSort()
{

}

void partitionByName()
{
	
}

void displaySortedData()
{

}

int search()
{

}

int main()
{

	return 0;
}


