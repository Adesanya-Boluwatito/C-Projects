#include <iostream>
#include <algorithm>
#include <fstream>
#include <regex>
#include <string>
#include <functional>
#include <sstream>
using namespace std;

void NewUser();
void Login();
bool valid_Email(const string&);
bool valid_UserName(const string&);
bool valid_FirstName(const string);
bool valid_Password(const string& password, int minlength, int);
bool verifyLogin(const string& username, const string& password);
size_t hashString(const string& password);







int main() {
//   Welcome message when the website is launched
	string choice;
	cout<<"Welcome to Boluwatito's sample project"<<endl;
	cout<<endl;
	while(true) {
		cout<<"Please type Yes if you want to register as new user or type No if you want to Login as an existing user"<<endl;
		cout<<"Please type your choice here: "<<flush;

		cin>> choice;
		string uppercaseAnswer = choice;
		transform(uppercaseAnswer.begin(), uppercaseAnswer.end(), uppercaseAnswer.begin(), ::toupper);
		if( uppercaseAnswer== "YES") {
			NewUser();
			break;
		}
		else if (uppercaseAnswer == "NO"){
			Login();
			break;
		}
		else{
			cout<< "Invalid Option"<<endl;
			cout<<endl;
		}
	}



	return 0;
}
















void NewUser() {

	unsigned int minLength = 8;
	unsigned int maxLength = 20;

	ofstream db("user_db.txt", ios::app);

	if(db.is_open()) {

		string firstname,lastname, email,  password, username ;
		size_t hash_password = 0;
		while (true) {
		cout<<"Enter First name: "<<flush;
		cin>> firstname;

		    if (valid_FirstName(firstname)) {
		        cout << "Valid First name." << endl;
		        break;
		    } else {
		        cout << "The first name is not valid. Please try again." << endl;
		        cout << "The first name should not contain any numbers or symbols." << endl;

		    }
		}


		cout<<endl;
		while (true) {
		cout<<"Enter Last name: "<<flush;
		cin>> lastname;

		    if (valid_FirstName(lastname)) {
		        cout << "Valid last name." << endl;
		        break;
		    } else {
		        cout << "The last name is not valid. Please try again." << endl;
		        cout << "The last name should not contain any numbers or symbols." << endl;

		    }
		}

		cout<<endl;

		while(true){
		cout<<"Enter Username: "<<flush;
		cin>>username;
		if(valid_UserName(username)) {
			cout<<"Valid Username"<<endl;
			break;
		} else{
			cout<< "The username is invalid. Please try again."<<endl;
			cout<< "The username should not contain '| * @ #'"<<endl;

		}


	}
		cout<<endl;
		while(true) {
		cout<<"Enter Email: "<<flush;
		cin>>email;
		if(valid_Email(email)) {
			cout<< "Valid email"<<endl;
			break;
		}else {
			cout<<"Invalid email"<<endl;
		}

		}

		cout<<endl;

		while(true){
		cout<<"Enter Password: "<<flush;
		cin>>password;

		if(valid_Password(password, minLength,maxLength)){
			cout<<"Valid Password."<<endl;
			hash_password = hashString(password);
			break;

		}else{
			cout<<"Invalid Password."<<endl;
			cout<<"Ensure the password is at least 8 characters long"<<endl;
		}



	}
		db << firstname << '\t' << lastname << '\t' << username << '\t' << email << '\t' << hash_password << '\n';

		db.close();

		cout<< "Registration Successful"<<endl;

	}
	else {
		cerr << "Error: Unable to open the file for writing.\n";
	}


}


void Login() {
	string username, password;


	cout<<"Enter Username: "<<flush;
	cin>>username;

	cout<<"Enter Password"<<endl;
	cin>>password;



	if(verifyLogin(username, password)){
		cout<< "Login Successful"<<endl;
	}
	else {
		cout<< "Login Failed. Invalid Username or Password."<<endl;
	}


}


bool valid_FirstName(string name) {

	regex NameCheck("^[a-zA-Z]+$");

	if(regex_match(name, NameCheck))
		return true;
	else
		return false;
}

bool valid_UserName(const string& username){
	regex usernamePattern("^[a-zA-Z0-9_]{3,}$");
	if (regex_match(username, usernamePattern))
		return true;

	else
		return false;


}

bool valid_Email(const string& email){
	regex emailPattern(R"([a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,})");

	if(regex_match(email, emailPattern))
		return true;

	else
		return false;


}

bool valid_Password(const string& password, int minLength, int maxLength) {

    if(password.size() >= minLength && password.size() <= maxLength)
    	return true;
    else
    	return false;

}

size_t hashString(const string& password) {
    hash<string> hasher;
    return hasher(password);
}


bool verifyLogin(const string& username, const string& enteredpassword) {
	ifstream file("user_db.txt");

	if (file.is_open()) {
		string line;
		while(getline(file, line)) {
			istringstream iss(line);
			string firstname, lastname, storedUsername,email, storedPassword;

			iss >> firstname >> lastname >> storedUsername >> email >> storedPassword;

			if (storedUsername == username){
				size_t enteredHashedPassword = hashString(enteredpassword);
				if (enteredHashedPassword == stoul(storedPassword)){
					file.close();
					return true;
				}

			}
		}
		file.close();
	}
	return false;
}
