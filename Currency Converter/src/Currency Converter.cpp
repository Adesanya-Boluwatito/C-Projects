//============================================================================
// Name        : Currency.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cctype>
#include <iomanip>
#include <string>
#include <algorithm>

using namespace std;


double USD_to_NGN(double money) {
	double result = (double)money * 1000;
	return result;
}

double CAD_to_NGN(double money) {
	double result = money * 800;
	return result;
}

double GBP_to_NGN(double money) {
	double result = money * 1300;
	return result;
}

double EUR_to_NGN(double money) {
	double result = money * 1100;
	return result;
}

double NGN_to_USD(double money) {
	double result = money/ 1150.0;
	return result;
}

double NGN_to_CAD(double money) {
	double result = money/ 850;
	return result;

}

double NGN_to_GBP(double money) {
	double result = money/ 1400;
	return result;
}

double NGN_to_EUR(double money) {
	double result = money/ 1200;
	return result;

}


int main() {




do {

	cout<<"Welcome to my Currency Converter."<<endl;


	cout<<"Here are our available options:"<<endl;
	cout<<"A. Would you like to convert NGN to Foreign Currency? "<<endl;
	cout<<"B. Would you like to convert from a Foreign Currency to NGN?"<<endl;



	cout<<"------------------------------------------------------------------------"<<endl;

	cout<<endl;





	cout << "Enter 'A' for conversion from NGN or 'B' for conversion to NGN: "<<endl;
	char input;
	cin >> input;
	input = toupper(static_cast<unsigned char>(input));

	switch(input) {

		case  'A':
			cout<<"Here are our options: "<<endl;

			cout<<"1. NGN -> USD"<<endl;
			printf("2. NGN -> EUR\n");
			printf("3. NGN -> CAD\n");
			printf("4. NGN -> GBP\n");


			cout << "Enter your choice: "<<flush;
			int option;
			cin>>option;

			if(option == 1) {
				cout<<"How much are you converting?   ₦"<<flush;
				double money;
				cin>>money;
				double result = NGN_to_USD(money);
				cout<<"The equivalent is: $"<< fixed<< setprecision(4) <<result <<endl;
			}


			if(option == 2) {
				cout<<"How much are you converting?   ₦"<<flush;
				double money;
				cin>>money;
				double result = NGN_to_EUR(money);
				cout<<"The equivalent is: €"<< fixed<< setprecision(4) <<result <<endl;
			}


			if(option == 3) {
				cout<<"How much are you converting?   ₦"<<flush;
				double money;
				cin>>money;
				double result = NGN_to_CAD(money);
				cout<<"The equivalent is: CA$"<< fixed<< setprecision(4)<< result <<endl;
			}

			if(option == 4) {
				cout<<"How much are you converting?  ₦"<<flush;
				double money;
				cin>>money;
				double result = NGN_to_GBP(money);
				cout<<"The equivalent is:  £"<< fixed<< setprecision(4)<<result <<endl;
			}



			break;


		case 'B':
			cout<< "Here are the options: "<<endl;

			printf("1. USD -> NGN\n");
			printf("2. EUR -> NGN\n");
			printf("3. CAD -> NGN\n");
			printf("4. GBP -> NGN\n");

			cout << "Enter your choice: "<<flush;
			int choice;
			cin>>choice;

			if(choice == 1) {
				cout<<"How much are you converting?   $"<<flush;
				double money;
				cin>>money;
				double result = USD_to_NGN(money);
				cout<<"The equivalent is: ₦"<<fixed<< setprecision(2)<< result <<endl;
			}

			if(choice == 2) {
				cout<<"How much are you converting?   €"<<flush;
				double money;
				cin>>money;
				double result = EUR_to_NGN(money);
				cout<<"The equivalent is: ₦"<<fixed<< setprecision(2)<< result <<endl;
			}

			if(choice == 3) {
				cout<<"How much are you converting?  CA$"<<flush;
				double money;
				cin>>money;
				double result = CAD_to_NGN(money);
				cout<<"The equivalent is: ₦"<<fixed<< setprecision(2)<< result <<endl;
			}

			if(choice == 4) {
				cout<<"How much are you converting?   £"<<flush;
				double money;
				cin>>money;
				double result = GBP_to_NGN(money);
				cout<<"The equivalent is: ₦"<<fixed<< setprecision(2)<< result <<endl;

			}


			break;


		default:
			cout<<"Invalid option"<<endl;
			break;

	}

		cout << "Do you want to perform another operation? (yes/no): ";
	        string answer;
	        cin >> answer;

	        string uppercaseAnswer = answer;
	        transform(uppercaseAnswer.begin(), uppercaseAnswer.end(), uppercaseAnswer.begin(), ::toupper);

	        if (uppercaseAnswer != "YES") {
	            cout << "Exiting the program. Thank you!" << endl;
	            break;
	        }







} while(true);








	return 0;
}
