#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

const int placeholder = 30;
void seatsavro(char[][placeholder], vector<int>&);
void total_money(char[][placeholder], double[], vector<double>&);
void seatsavtot(char[][placeholder]);
void display_chat(char[][placeholder]);
char menu();

int main() {
	vector<int>seatav(15);
	vector<double>ilovemoney(15);
	const int rows = 15, cols = 30;
	int row, col, numtickets;
	double price[rows];
	double total = 0.0;
	char choice, ch;
	char cinema[rows][cols];
	cout << "\t\t\t\tPINE BLUFF THEATER\n\n";
	cout << "Welcome, and proceed to enter the price of each row. Press Enter to Continue.\n";
	cin.get(ch);
	for (int i = 0; i < rows; i++) {
		cout << "Enter the price of Row " << setw(2) << (i + 1) << " seats ($): ";
		cin >> price[i];
		if (price[i] < 0 || price[i] > 100) {
			cout << "Seat prices range between $1-$100.\n";
			cout << "Enter the price of Row " << setw(2) << (i + 1) << " seats ($): ";
			cin >> price[i];
		}
	}
	for (int i = 0; i < rows; i++) {
		for (int z = 0; z < cols; z++) {
			cinema[i][z] = '*';
		}
	}
	do
	{
		choice = menu();
		switch (choice) {
		case 'A':
		{
			//Displaying chat
			cout << "\t\t\t\t\t\tSeats\n";
			cout << "\t    ";
			for (int z = 1; z <= 30; z++) {
				cout << setw(2) << z << " ";
			}
			cout << endl;

			for (int i = 0; i < rows; i++) {
				cout << "Row " << setw(3) << (i + 1) << "     ";
				for (int z = 0; z < cols; z++) {
					cout << setw(2) << cinema[i][z] << " ";
				}
				cout << endl;
			}
			cout << "Key: (* represents unoccupied seats.), (# represents occupied seats.)\n\n";
			// End of chat
			cout << "Procede to purchase the ticket.\n";
			cout << "How many tickets do you want to purchase: ";
			cin >> numtickets;
			while (numtickets < 0) {
				cout << "You can not purchase below zero tickets.\n";
				cout << "How many tickets do you want to purchase: ";
				cin >> numtickets;
			}

			//Buying the tickets
			for (int i = 0; i < numtickets; i++) {
				cout << "Ticket " << (i + 1) << endl;
				cout << "Which Row do you want to purchase from (1-15): ";
				cin >> row;
				//validation of rows
				while (row < 1 || row > 15) {
					cout << "There is Row 1-15 only.\n";
					cout << "Which Row do you want to purchase from (1-15): ";
					cin >> row;
				}
				//end of validation of rows
				cout << "Enter the seat number(refer to table) in Row " << row << " (1-30): ";
				cin >> col;
				//validation of rows
				while (col < 1 || row > 30) {
					cout << "There is Places 1-30 only.\n";
					cout << "Enter the seat number(refer to table) in Row " << row << " (1-30): ";
					cin >> col;
				}
				//end of validation of rows

				//Validation of occupancy
				while (cinema[(row - 1)][(col - 1)] == '#') {
					cout << "The position is already occupied. Refer to table to get unoccupied spaces.\n";
					cout << "Ticket " << (i + 1) << endl;
					cout << "Which Row do you want to purchase from (1-15): ";
					cin >> row;
					//validation of rows
					while (row < 1 || row > 15) {
						cout << "There is Row 1-15 only.\n";
						cout << "Which Row do you want to purchase from (1-15): ";
						cin >> row;
					}
					//end of validation of rows
					cout << "What position(refer to table) in Row " << row << " (1-30): ";
					cin >> col;
					//validation of rows
					while (col < 1 || row > 30) {
						cout << "There is Places 1-30 only.\n";
						cout << "What position(refer to table) in Row " << row << " (1-30): ";
						cin >> col;
					}
					//end of validation of rows
				}//end of occupancy validation
				total += price[(row - 1)];
				char taken = '#';
				cinema[(row - 1)][(col - 1)] = taken;
			}
			cout << "That will be a total of $" << setprecision(2) << total << endl;
			total = 0;
			break;
		}
		case 'B': {
			total_money(cinema, price, ilovemoney);
			break;
		}
		case 'C': {
			seatsavro(cinema, seatav);
			break;
		}
		case 'D': {
			seatsavtot(cinema);
			break;
		}
		case 'E': {
			display_chat(cinema);
			break;
		}
		case 'Q': {
			break;
		}
		}
	} while (choice != 'Q');

	cout << "Thank you. Enjoy the show.\n";
	return 0;
}

char menu() {
	char ch;
	cout << "\nSelect the option you want from the following.\n";
	cout << "A. Buy Tickets.\n";
	cout << "B. Show the total revenue.\n";
	cout << "C. Show how many seats are available per row.\n";
	cout << "D. Show total number of seats available.\n";
	cout << "E. Display current Auditorium seating status.\n";
	cout << "Q. Quit Program.\n";
	cout << "Enter your choice: ";
	cin >> ch;
	ch = toupper(ch);
	return ch;
}

/*
* This function is used to determine the available seats in a row
* it takes in 3 arguments.
* The chart (char)
* a vector that stores the number of seats available in a row vector<int>
* The row being determined for.int
*/
void seatsavro(char chart[][placeholder], vector<int>& numseats) {
	int keep_track = 0, somenum;
	cout << "Which row would you like to check for the number of available sits for: ";
	cin >> somenum;
	//Input Validation
	while (somenum < 1 || somenum>15) {
		cout << "\nYou can only choose a row number between 1 - 15.\n"
			<< "Please input the correct number.\n";
		cin >> somenum;
	}

	//Find number of seats available in row
	for (int i = 0; i < 15; i++)
	{
		//because role user selects is actully -1 the int argument has 1 subtracted from it
		if (i == (somenum - 1)) {
			for (int x = 0; x < placeholder; x++)
			{
				//Determine number of seats sold
				if (chart[i][x] == '*')
				{
					//keep track of seats available
					keep_track += 1;
				}
			}
			//place number of seats available in vector on the rows place value
			numseats.at(somenum - 1) = keep_track;
		}
	}
	cout << "\nThere is a total of " << numseats.at(somenum - 1) << " seat(s) available in row " << somenum << endl;
}



/*
* This function takes in 3 arguments
* The chart array
* the price array
* a vector to store money made for a row in its position
*
*/
void total_money(char chart[][placeholder], double money[], vector<double>& money_made) {
	//Declare Variables
	double rtotal = 0, monmade = 0;

	//loop through chart
	for (int i = 0; i < 15; i++) {
		for (int x = 0; x < placeholder; x++) {
			//Determine seats bought
			if (chart[i][x] == '#') {
				//add money to running total
				rtotal += money[i];
			}
		}
		//save running total of row position in vector
		money_made.at(i) = rtotal;
		//Reset running total
		rtotal = 0;
	}
	//add all the money made
	for (int i = 0; i < 15; i++) {
		monmade += money_made.at(i);
	}
	//Display total
	cout << "\nThe total revenue is $" << monmade << endl;
}


void seatsavtot(char chart[][placeholder]) {
	int keep_track = 0;

	//Find number of seats available in row
	for (int i = 0; i < 15; i++)
	{

		for (int x = 0; x < placeholder; x++)
		{
			//Determine number of seats sold
			if (chart[i][x] == '*')
			{
				//keep track of seats available
				keep_track += 1;
			}
		}
	}
	cout << "\nThere is a total of " << keep_track << " seat(s) available in the auditorium" << endl;
}

void display_chat(char arrangeMent[][placeholder]) {
	//Displaying chat
	cout << "\t\t\t\t\t\tSeats\n";
	cout << "\t    ";
	for (int z = 1; z <= 30; z++) {
		cout << setw(2) << z << " ";
	}
	cout << endl;

	for (int i = 0; i < 15; i++) {
		cout << "Row " << setw(3) << (i + 1) << "     ";
		for (int z = 0; z < 30; z++) {
			cout << setw(2) << arrangeMent[i][z] << " ";
		}
		cout << endl;
	}
	cout << "Key: (* represents unoccupied seats.), (# represents occupied seats.)\n\n";
}


