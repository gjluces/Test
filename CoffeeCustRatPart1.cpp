/* Name: Gabriel Luces
Date: 10/16/2022
Section:COP3363-0011.fa22
Assignment: Make a program that run a menu-driven program with arrays
Due Date: 10/16/2022
About this project: Write a C++ program that run a menu-driven program to display number of the ratings per option, change a rating, display the average rating or quiit according to the user.
Assumptions: NA
All work below was performed by Gabriel Luces */

#include <iostream>

using namespace std;

//Constant
const int NUM_CUSTOMERS = 113;
//Function Section

int getValidRating() {
	int number;
	while (true) {
		cout << "Please enter in the rating (1-5) ..." << endl;
		cin >> number;
		if (number >= 1 && number <= 5) {
			return number;
		}
	}
	cout << endl;
}
int getValidCustumer() {
	int number;
	while (true) {
		cout << "Please enter in a number" << endl;
		cin >> number;
		if (number >= 1 && number <= NUM_CUSTOMERS) {
			return number;
		}
	}
	cout << endl;
}

void displayRatings(int productRating[NUM_CUSTOMERS]) {
	for (int i = 0; i < NUM_CUSTOMERS; i++) {
		if (i % 9 == 0) {
			cout << endl;
		}
		cout << productRating[i];
	}
	cout << endl;
	return;
}

void changeARating(int productRatings[NUM_CUSTOMERS]) {
	int position;
	int number;
	cout << "Please enter in the number of the customer..." << endl;
	cin >> position;
	number = getValidRating();
	productRatings[position] = number;
	displayRatings(productRatings);
	cout << endl;
}
//displayAverageRating function
void displayAverageRating(int productRatings[NUM_CUSTOMERS]) {
	\
		int acummulator = 0;
	float average = 0; 
	for (int i = 0; i < NUM_CUSTOMERS; i++) {
		acummulator = acummulator + productRatings[i];
	}
	average = acummulator / NUM_CUSTOMERS;
	cout << "The average of the ratings is: " << average << endl;
}
int main() {

	//Welcome message
	cout << "Welcome to the Starbucks Coffee Customer Ratings Program!" << endl;
	//Array of numbers
	int productRatings[NUM_CUSTOMERS] = {
4, 4, 4, 2, 3, 4, 5, 4, 5, 4,
4, 3, 4, 4, 5, 4, 4, 4, 4, 3,
2, 5, 5, 5, 4, 4, 4, 5, 4, 5,
3, 4, 2, 3, 3, 4, 3, 5, 4, 3,
5, 5, 4, 5, 3, 3, 3, 4, 3, 5,
3, 4, 4, 5, 5, 3, 4, 2, 5, 3,
4, 3, 4, 4, 2, 3, 4, 5, 4, 3,
3, 3, 4, 4, 2, 2, 3, 5, 4, 4,
4, 4, 3, 4, 5, 4, 4, 5, 3, 3,
3, 3, 4, 4, 3, 3, 4, 4, 4, 4,
3, 3, 4, 5, 3, 2, 5, 4, 3, 5,
3, 4, 1 };
	int Counter[5] = { 0 };
	int choice = 0;
	int position;
	int number;
	while (true) {
		cout << "1)  Display number of the ratings per option " << endl;
		cout << "2) Change a rating" << endl;
		cout << "3) Display the average rating" << endl;
		cout << "4) Quit" << endl;
		cout << "Select an option (1..4)" << endl;
		cin >> choice;
		if (choice == 1) {
			displayRatings(productRatings);
			for (int i = 0; i < NUM_CUSTOMERS; i++) {
				if (productRatings[i] == 1) {
					Counter[0] = Counter[0] + 1;
				}
				if (productRatings[i] == 2) {
					Counter[1] = Counter[1] + 1;
				}
				if (productRatings[i] == 3) {
					Counter[2] = Counter[2] + 1;
				}
				if (productRatings[i] == 4) {
					Counter[3] = Counter[3] + 1;
				}
				if (productRatings[i] == 5) {
					Counter[4] = Counter[4] + 1;
				}
			}
			cout << endl;
			cout << "Count by rating" << endl;
			for (int i = 0; i <= 4; i++) {
				cout << i + 1 << " : " << Counter[i] << endl;
			}
			cout << endl;
		}
		else if (choice == 2) {
			displayRatings(productRatings);
			changeARating(productRatings);
		}
		else if (choice == 3) {
			displayRatings(productRatings);
			displayAverageRating(productRatings);
		}
		else if (choice == 4) {
			break;
		}
	}

	return 0;
}