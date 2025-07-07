#include <iostream>
using namespace std;

void Input_Validation (int &x) {
	while(!(cin>>x)) {
		cout <<"Invalid Input, Please enter only X or O depending on your chosen letter."<< endl;
		cin.clear();
		cin.ignore(1214,'\n');
	}
	return;
}

void Duplicate (int x, int y) {
	while (x == y) {
		cout <<"Please enter a space that is not yet occupied." << endl;
		cin.clear();
		cin.ignore(1214,'\n');
		Input_Validation(y);
	}
}

void layout (char arr[][3]) {
	cout <<"   "<< arr[0][0] << " | " << arr[1][0] << " | " << arr[2][0] << endl;
	cout <<"   "<< "----------" << endl;
	cout <<"   "<< arr[0][1] << " | " << arr[1][1] << " | " << arr[2][1] << endl;
	cout <<"   "<< "----------" << endl;
	cout <<"   "<< arr[0][2] << " | " << arr[1][2] << " | " << arr[2][2] << endl << endl;
}

void menu () {
	cout << "TIKTAK TOE!!" <<endl << endl
			 << "Choose the number on where you would like to put your shape." << endl
			 <<"1. Top Left." << endl
			 <<"2. Top Middle." << endl
			 <<"3. Top Right." << endl
			 <<"4. Middle Left." << endl
			 <<"5. Middle Middle." << endl
			 <<"6. Middle Right." << endl
			 <<"7. Bottom Left." << endl
			 <<"8. Bottom Middle." << endl
			 <<"9. Bottom Right." << endl
			 <<"10. Exit." << endl;
}

bool win (char arr[][3]) {
	char a, b, c;
	/* 0 1 2
		 0 1 2
		 0 1 2*/
	//Vertical Win
	for (int i = 0; i < 3; i++) {
		a = arr[i][0];
		b = arr[i][1];
		c = arr[i][2];
		if(a == b && a == c && a != ' ') {
			return true;
		}
		//Horizontal Win
		a = arr[0][i];
		b = arr[1][i];
		c = arr[2][i];
		if(a == b && a == c && a != ' ') {
			return true;
		}
	}
	//Diagonal Win
	a = arr[0][0];
	b = arr[1][1];
	c = arr[2][2];
	if(a == b && a == c && a != ' ') {
		return true;
	}
	a = arr[2][0];
	c = arr[0][2];
	if(a == b && a == c && a != ' ') {
		return true;
	}
	return false;
}

int main() {
	bool w = false;
	int choice, choice_checker[9];
	char arr[3][3] = {{' ',' ',' '}, {' ',' ',' '}, {' ',' ',' '}};
	for ( int i = 0;i < 9; i++) {
		char shape = 'X';
		choice = 0;
		if (i%2 == 1) {
			shape = 'O';
		}
		layout(arr);
		menu();
		Input_Validation(choice);
		for(int i = 0; i < 9; i++) {
			Duplicate(choice_checker[i], choice);
			choice_checker[i] = choice;
		}
		switch (choice) {
			case 1:
				arr[0][0] = shape;
				break;

			case 2:
				arr[1][0] = shape;
				break;
			
			case 3:
				arr[2][0] = shape;
				break;

			case 4:
				arr[0][1] = shape;
				break;

			case 5:
				arr[1][1] = shape;
				break;

			case 6:
				arr[2][1] = shape;
				break;

			case 7:
				arr[0][2] = shape;
				break;

			case 8:
				arr[1][2] = shape;
				break;

			case 9:
				arr[2][2] = shape;
				break;

			case 10:
				cout <<"Exiting Pogram..." << endl;
				return 0;
				break;

			default:
				cout <<"Please choose a number from (1-10) for your choice;" << endl;
				i--;
				break;
		}
		w = win(arr);
		if (w) {
			if(i%2 == 0) {
				cout << "Congratulations!! X Player Won!" << endl;
			} else {
				cout << "Congratulations!! O Player Won!" << endl;
			}
			layout(arr);
			return 0;
		} else if (!w && i == 9) {
			cout << "It seems like it was a draw!" << endl;
			layout(arr);
			return 0;
		}
	}
}