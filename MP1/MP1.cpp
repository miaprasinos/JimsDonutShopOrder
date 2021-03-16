// MP1 
// 09-10-2020
// Mia Prasinos
// Calculates the cost of an order of donuts at Jim's Donut Shop. 
// It calculates the tax and total cost of an order, and how much exact change is needed based on how much the customer pays. 

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>   
using namespace std;

int main()
{
	
	// get amount of regular and fancy donuts customer wants to buy
	int regDonuts; // stores amount of regular donuts customer orders
	int fanDonuts; // stores amount of fancy donuts customer orders

	cout << "Number of regular donuts ordered: ";
	cin >> regDonuts;

	cout << "Number of fancy donuts ordered: ";
	cin >> fanDonuts;

	// calculate how many dozens and single regular and fancy donuts are in the order
	int dozRegDonuts = regDonuts / 12;
	int dozFanDonuts = fanDonuts / 12;

	int singleRegDonuts = regDonuts % 12;
	int singleFanDonuts = fanDonuts % 12;

	// calculate cost of the single and dozen regular and fancy to get cost of order (w/o tax)
	double regDonutCost = (singleRegDonuts * 0.75) + (dozRegDonuts * 7.99);
	double fanDonutCost = (singleFanDonuts * 0.85) + (dozFanDonuts * 8.49);
	double cost = regDonutCost + fanDonutCost;

	// calculate tax of order and determine total cost of order with tax
	double taxP = 0.075;


	double tax = (taxP * cost);
	int percent = tax * 1000;
	int taxR = percent % 10; // taxR calculates the final value of the tax amount to round up


	// rounds the calculated tax to the nearest 0.05
	if (taxR >= 5)
	{


		tax = (tax + 0.005);
		string roundUp = to_string(tax);
		int twoDec = roundUp.find('.');
		string roundedTax = roundUp.substr(0, (twoDec + 3));
		tax = stod(roundedTax);


	}
	else if (taxR < 5)
	{
		taxR = taxR / 1000;
		tax = tax - taxR;
	}
	else {
		cout << " YOU DONE GOOFED UP SOMETHING " << endl;
	}

	double totalOrder = cost + tax;
	


	// Get input for how much the customer paid and calculate how much change is needed
	// Displays how much customer owes, how much customer pays, and how much change is owed. 

	cout << "Customer owes $" << fixed << setprecision (2) << totalOrder << endl;
	
	double paid = 999999;
	double change = 9999;

	cout << "Customer pays $";
	cin >> paid;

	change = paid - totalOrder;



	if (change == 0) {
		cout << "Exact payment received - no change owed." << endl;
	}
	else {
		cout << "Change owed is $" << change << " - ";
	}


	// Calculate the amount of change needed in dollars and coins

	int dollars = 0;
	int quarters = 0;
	int dimes = 0;
	int nickels = 0;
	int pennies = 0;


	while (change > 0) {
		if (change > 0.99) {
			change = change - 1.00;
			dollars = dollars + 1;
		}
		else if (change > 0.24) {
			change = change - 0.25;
			quarters = quarters + 1;
		}
		else if (change > 0.09) {
			change = change - 0.10;
			dimes = dimes + 1;
		}
		else if (change > 0.04) {
			change = change - 0.05;
			nickels = nickels + 1;
		}
		else if (change > 0.000001) {
			change = change - 0.01;
			pennies = pennies + 1;
		}
		else {
			change = 0;
		}

	}


	// Displays the specific coins for change that are needed

	if (dollars > 0) {
		if (quarters > 0 || dimes > 0 || nickels > 0 || pennies > 0) {
			if (dollars == 1) {
				cout << dollars << " dollar, ";
			}
			else {
				cout << dollars << " dollars, ";
			}
		}
		else {
			if (dollars == 1) {
				cout << dollars << " dollar.";
			}
			else {
				cout << dollars << " dollars.";
			}
		}
		
	}

	if (quarters > 0) {
		if (dimes > 0 || nickels > 0 || pennies > 0) {
			if (quarters == 1) {
				cout << quarters << " quarter, ";
			}
			else {
				cout << quarters << " quarters, ";
			}
		}
		else {
			if (quarters == 1) {
				cout << quarters << " quarter.";
			}
			else {
				cout << quarters << " quarters.";
			}
		}
	}

	if (dimes > 0) {
		if (nickels > 0 || pennies > 0) {
			if (dimes == 1) {
				cout << dimes << " dime, ";
			}
			else {
				cout << dimes << " dimes, ";
			}
		}
		else {
			if (dimes == 1) {
				cout << dimes << " dime.";
			}
			else {
				cout << dimes << " dimes.";
			}
		}
	}

	if (nickels > 0) {
		if (pennies > 0) {
			if (nickels == 1) {
				cout << nickels << " nickel, ";
			}
			else {
				cout << nickels << " nickels, ";
			}
		}
		else {
			if (nickels == 1) {
				cout << nickels << " nickel.";
			}
			else {
				cout << nickels << " nickels.";
			}
		}
	}

	if (pennies > 0) {
		if (pennies == 1) {
			cout << pennies << " penny.";
		}
		else {
			cout << pennies << " pennies.";
		}
	}

	return 0;











}