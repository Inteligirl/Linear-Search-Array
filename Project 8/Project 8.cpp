#include<iostream>
#include<string>
#include <windows.h>  //for color

using namespace std;


/*******************************************
***			PROTOTYPES FOR FUNCTIONS ***
********************************************/
void welcome();
void dashes();
void screenHeader();
int getInput();
void validate(int& n);


/*******************************************
***			CLASS PROTOTYPE             ***
********************************************/
class Accounts
{
private:
	int userNum;
	bool match;


public:
	Accounts();
	void setUserNum(int );
	void compare(const int[], const int);
	void display();
};


/*******************************************
***			MAIN PROGRAM                ***
********************************************/
int main()
{

	screenHeader();
	welcome();


	const int SIZE = 18;
	int availableAccounts[SIZE] = { 5658845, 4520125, 7895122, 8777541, 8451277, 1302850, 
									8080152, 4562555, 5552012, 5050552, 7825877, 1250255, 
									1005231, 6545231, 3852085, 7576651, 7881200, 4581002 };


	int matchNum;		 //raw input from the user 


	Accounts existing;		 //object of class Accounts


	matchNum = getInput();		//result of getInput function stored in userNum


	existing.setUserNum(matchNum);     //move valid input userNum to class method setInputUser


	//compare values passing argument name of array and size variable that is set to size of array
	existing.compare(availableAccounts, SIZE);


	existing.display();		//display results 

	

	return 0;
}

/*******************************************
***		FUNCTION DEFINITIONS            ***
********************************************/


void welcome()	//welcome message to user
{
	cout << endl << endl;
	dashes();
	cout << "\nThis program will check to see if you account number\n";
	cout << "\nmatches any account number currently stored in the array.\n";
	dashes();
}


void dashes()		//formatting
{
	string dashes;   //output formating created dashes object of string class
	dashes.assign(57, '-');	//called assign function of string
	cout << endl << dashes << endl;
}

	void screenHeader()
	{
		HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(screen, 6);
		printf("\n                       :::::::::::::::::::::::::::::::::::::");
		printf("\n                       ::                                 ::");
		printf("\n                       ::                                 ::");
		printf("\n                       ::     ///////////////////////     ::");
		printf("\n                       ::     /                     /     ::");
		printf("\n                       ::     /      WELCOME TO     /     ::");
		printf("\n                       ::     /                     /     ::");
		printf("\n                       ::     /      Accounting     /     ::");
		printf("\n                       ::     /       Program       /     ::");
		printf("\n                       ::     /                     /     ::");
		printf("\n                       ::     ///////////////////////     ::");
		printf("\n                       ::                                 ::");
		printf("\n                       ::                                 ::");
		printf("\n                       :::::::::::::::::::::::::::::::::::::\n\n");
		SetConsoleTextAttribute(screen, 7);
	}


int getInput()
{	
	int in;		//variable to hold user entered number
	
	cout << endl;
	cout << "Enter your seven digit account number\n";
	cout << "to see if there is a match in the array. => ";
	cin >> in;
	dashes();
	
	validate(in);	//pass user entered number to validate function

	return in;
}
void validate(int& n) 		//passing by reference user entered number to check if valid
{
	HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE);
	while (n <= 0 || !cin)
	{
		cout << endl;
		cin.sync();
		cin.clear();
		SetConsoleTextAttribute(screen, 4);
		cout << "Invalid input.\n";
		cout << "You can only use seven digit account numbers containing integers.\n";
		cout << "Reenter the account number : ";
		cin >> n;
		SetConsoleTextAttribute(screen, 7);
	}
}
/*******************************************
***		CLASS METHOD DEFINITIONS         ***
********************************************/


Accounts::Accounts()		//setting the bool value to false
{
	match = false;
}


void Accounts::setUserNum(int n)	//public class method setting value of private member


{
	userNum = n;
}


//passing array arguments to compare function of class Accounts
void Accounts::compare(const int availableAccounts[], const int SIZE)
{
	for (int i = 0; i < SIZE; i++)		//loop to check each index of array
	{
		if (availableAccounts[i] == userNum) //why userNum and not InputUserAccount?
			match = true;
	}
}


void Accounts::display()		//display comparison results to user
{
	HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE);
	cout << endl;
	if (match)		//if the bool value match is true
	{
		SetConsoleTextAttribute(screen, 2);
		cout << "The account number you entered matched an existing account." << endl << endl;
	}
	else
	{
		SetConsoleTextAttribute(screen, 4);
		cout << "The account number you entered did not match an existing account" << endl << endl;
	}
	SetConsoleTextAttribute(screen, 7);
}