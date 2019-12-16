/*********************************************************************
 * ** Program Filename: Farkle
 * ** Author: Arjun Bhalla
 * ** Date: 3/1/18
 * ** Description: Farkle game simulation
 * *********************************************************************/

#include <iostream>
#include <cmath>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int *dice_roll(int &);
int user_input(int &);
bool is_int();
int get_int(string);
//void print_roll(int*);
bool single1(int *, int&, int&);
bool single5(int *, int &, int &);
bool three1(int *, int&, int&);
bool three2(int *, int&, int&);
bool three3(int *, int &, int &);
bool three4(int *, int &, int &);
bool three5(int *, int &, int &);
bool three6(int *, int &, int &);
bool four_of(int*, int&, int&);
bool five_of(int*, int&, int&);
bool six_of(int*, int&, int&);
int removing (int *, int&, int&, int&);
//void change_score(int &, int *, int);
int scores(int &);


/*********************************************************************
 * ** Function: main
 * ** Description: Executes the calculators and allows the user to choose which calcultor to run
 * ** Parameters: none
 * ** Pre-Conditions: none
 * ** Post-Conditions: answers, asking if user would like to choose another calculator
 * *********************************************************************/
int main(){

	int players = 0;
	int len = 6; int counter = 0;
	int choice = 0;
//	int score[p][2];
	user_input(players);
	int *dice = dice_roll(len);
	bool option = removing(dice, len, counter, choice);
//	change_score(choice, score, players);
	scores(players);

	delete [] dice;
	return 0;
}

/*********************************************************************
 * ** Function: user_input
 * ** Description:
 * ** Parameters:
 * ** Pre-Conditions:
 * ** Post-Conditions:
 * *********************************************************************/

int user_input(int &player){

	string players = "";

	do{
		cout << "Enter the number of players, making sure there are 2 or more players." << endl;
		getline(cin, players);

	}while(get_int(players)== false);

	player = get_int(players);

	return player;
}

/*********************************************************************
 * ** Function: dice_roll
 * ** Description: conducts the dice roll and fills it into an array; prints it out
 * ** Parameters: int &len
 * ** Pre-Conditions: integer input
 * ** Post-Conditions: array dice
 * *********************************************************************/

int *dice_roll(int &len){

	int *dice = new int[6];

	int x;
	srand(time(NULL));


	for (int i = 0; i < len; i++){

		x = rand();
		x = x%6 + 1;

		dice[i] = x;

	}
	for (int i = 0; i < len; i++){

		cout << "Dice " << i+1 << " is " <<  dice[i] << endl;
	}
	return dice;
}


/**********************************************************************
 * ** Function: removing
 * ** Description: Determines what dice you can remove
 * ** Parameters: int *dice, int &len, int &counter
 * ** Pre-Conditions: dice are printed, length is determined
 * ** Post-Conditions: various dice removal options
 * *********************************************************************/
int removing(int *dice, int &len, int &counter, int &choice){

	if (single1(dice, len, counter) == true) {
		cout << "would you like to remove a 1" << endl;
		cout << "Press 1 to for this option" << endl << endl;
	}
	if (single5(dice, len, counter) == true){
		cout << "would you like to remove a 5" << endl;
		cout << "Press 2 to for this option" << endl << endl;
	}
	if (three1(dice, len, counter) == true){
		cout << "would you like to remove three 1s" << endl;
		cout << "Press 3 to for this option" << endl << endl;
	}
	if (three2(dice, len, counter) == true){
		cout << "would you like to remove three 2s" << endl;
		cout << "Press 4 to for this option" << endl << endl;
	}
	if (three3(dice, len, counter) == true){
		cout << "would you like to remove three 3s" << endl;
		cout << "Press 5 to for this option" << endl << endl;
	}
	if (three4(dice, len, counter) == true){
		cout << "would you like to remove three 4s" << endl;
		cout << "Press 6 to for this option" << endl << endl;
	}
	if (three5(dice, len, counter) == true){
		cout << "would you like to remove three 5s" << endl;
		cout << "Press 7 to for this option" << endl << endl;
	}
	if (three6(dice, len, counter) == true){
		cout << "would you like to remove three 6s" << endl;
		cout << "Press 8 to for this option" << endl << endl;
	}
	if (four_of(dice, len, counter) == true){
		cout << "would you like to remove four of a kind?" << endl;
		cout << "Press 9 to for this option" << endl << endl;
	}
	if (five_of(dice, len, counter) == true){
		cout << "would you like to remove four of a kind?" << endl;
		cout << "Press 10 to for this option" << endl << endl;
	}
	if (six_of(dice, len, counter) == true){
		cout << "would you like to remove four of a kind?" << endl;
		cout << "Press 11 to for this option" << endl << endl;
	}

	cout << "\n\nOption Chosen: ";
	cin >> choice;
}

/**********************************************************************
 * ** Function: change_score
 * ** Description: determines if there is one dice of value 1
 * ** Parameters: int *dice, int &len, int &counter
 * ** Pre-Conditions: dice array, dice roll
 * ** Post-Conditions: boolean
 * *********************************************************************/
/*void change_score(int &choice, int *score, int player){
	if(choice == 1){
		score[player-1][1] += 100;
	}
	if (choice == 2){
		score[player-1][1] += 50;
	}
	if (choice == 3){
		score[player-1][1] += 300;
	}
	if (choice == 4){
		score[player-1][1] += 200;
	}
	if (choice == 5){
		score[player-1][1] += 300;
	}
	if (choice == 6){
		score[player-1][1] += 400;
	}
	if (choice == 7){
		score[player-1][1] += 500;
	}
	if (choice == 8){
		score[player-1][1] += 600;
	}
	if (choice == 9){
		score[player-1][1] += 1000;
	}
	if (choice == 10){
		score[player-1][1] += 2000;
	}
	if (choice == 11){
		score[player-1][1] += 3000;
	}

}
*/

/**********************************************************************
 * ** Function: single1
 * ** Description: determines if there is one dice of value 1
 * ** Parameters: int *dice, int &len, int &counter
 * ** Pre-Conditions: dice array, dice roll
 * ** Post-Conditions: boolean
 * *********************************************************************/

bool single1(int *dice, int &len, int &counter){
	counter = 0;
	for (int i = 0; i < len; i++){
		if(dice[i] == 1){
			counter++;
		}
	}
	cout << "number of 1s - " << counter << endl;
	if(counter > 0 && counter != 3) {
		return true;
	}

	else{
		return false;
	}
}

/**********************************************************************
 * ** Function: single5
 * ** Description: determines if there is one dice of value 5
 * ** Parameters: int *dice, int &len, int &counter
 * ** Pre-Conditions: dice array, dice roll
 * ** Post-Conditions: boolean
 * *********************************************************************/
bool single5(int *dice, int &len, int &counter){
	counter = 0;
	for (int i = 0; i < len; i++){
		if(dice[i] == 5){
			counter++;
		}
	}
	cout << "number of 5s - " << counter << endl;
	if(counter > 0 && counter != 3) {

		return true;
	}
	else {
		return false;
	}
}
/**********************************************************************
 * ** Function: three1
 * ** Description: determines if there are three dice of value 1
 * ** Parameters: int *dice, int &len, int &counter
 * ** Pre-Conditions: dice array, dice roll
 * ** Post-Conditions: boolean
 * *********************************************************************/

bool three1(int *dice, int &len, int &counter){
	counter = 0;
	for (int i = 0; i < len; i++){
		if (dice[i] == 1){
			counter++;
		}
	}
	cout << "three 1s: " << counter/3 << endl;
	if(counter == 3){
		return true;
	}
	else{
		return false;
	}
}
/**********************************************************************
 * ** Function: three2
 * ** Description: determines if there are three dice of value 2
 * ** Parameters: int *dice, int &len, int &counter
 * ** Pre-Conditions: dice array, dice roll
 * ** Post-Conditions: boolean
 * *********************************************************************/
bool three2(int *dice, int &len, int &counter){
	counter = 0;
	for (int i = 0; i < len; i++){
		if (dice[i] == 2){
			counter++;
		}
	}
	cout << "three 2s: " << counter/3 << endl;
	if(counter == 3){
		return true;
	}
	else{
		return false;
	}
}
/**********************************************************************
 * ** Function: three3
 * ** Description: determines if there are three dice of value 3
 * ** Parameters: int *dice, int &len, int &counter
 * ** Pre-Conditions: dice array, dice roll
 * ** Post-Conditions: boolean
 * *********************************************************************/

bool three3(int *dice, int &len, int &counter){
	counter = 0;
	for (int i = 0; i < len; i++){
		if (dice[i] == 3){
			counter++;
		}
	}
	cout << "three 3s: " << counter/3 << endl;
	if(counter == 3){
		return true;
	}
	else{
		return false;
	}
}
/**********************************************************************
 * ** Function: three4
 * ** Description: determines if there are three dice of value 4
 * ** Parameters: int *dice, int &len, int &counter
 * ** Pre-Conditions: dice array, dice roll
 * ** Post-Conditions: boolean
 * *********************************************************************/
bool three4(int *dice, int &len, int &counter){
	counter = 0;
	for (int i = 0; i < len; i++){
		if (dice[i] == 4){
			counter++;
		}
	}
	cout << "three 4s: " << counter/3 << endl;
	if(counter == 3){
		return true;
	}
	else{
		return false;
	}
}

/**********************************************************************
 * ** Function: three5
 * ** Description: determines if there are three dice of value 5
 * ** Parameters: int *dice, int &len, int &counter
 * ** Pre-Conditions: dice array, dice roll
 * ** Post-Conditions: boolean
 * *********************************************************************/
bool three5(int *dice, int &len, int &counter){
	counter = 0;
	for (int i = 0; i < len; i++){
		if (dice[i] == 5){
			counter++;
		}
	}
	cout << "three 5s: " << counter/3 << endl;
	if(counter == 3){
		return true;
	}
	else{
		return false;
	}
}

/**********************************************************************
 * ** Function: three6
 * ** Description: determines if there are three dice of value 6
 * ** Parameters: int *dice, int &len, int &counter
 * ** Pre-Conditions: dice array, dice roll
 * ** Post-Conditions: boolean
 * *********************************************************************/
bool three6(int *dice, int &len, int &counter){
	counter = 0;
	for (int i = 0; i < len; i++){
		if (dice[i] == 6){
			counter++;
		}
	}
	cout << "three 6s: " << counter/3 << endl;
	if(counter == 3){
		return true;
	}
	else{
		return false;
	}
}

/**********************************************************************
 * ** Function: four_of
 * ** Description: determines if there are four of a kind
 * ** Parameters: int *dice, int &len, int &counter
 * ** Pre-Conditions: dice array, dice roll
 * ** Post-Conditions: boolean
 * *********************************************************************/
bool four_of(int *dice, int &len, int &counter){
	int num1 = 0, num2 = 0, num3 = 0,  num4 = 0, num5 = 0, num6 = 0;

	for(int i = 0; i < len; i++){
		if(dice[i] == 1) {
			num1++;
			i++;
		}
		if(dice[i] == 2){
			num2++;
			i++;
		}
		if(dice[i] == 3){
			num3++;
			i++;
		}
		if(dice[i] ==4){
			num4++;
			i++;
		}
		if(dice[i] = 5){
			num5++;
			i++;
		}
		if(dice[i] = 6){
			num6++;
			i++;
		}
	}
	if(num1 == 4 || num2 ==4|| num3 ==4 || num4 ==4 || num5 == 4|| num6 == 4){
		cout << "four of a kind: 1" << endl;
		return true;

	}
	else{
		cout << "four of a kind: 0" << endl;
		return false;
	}



}

/**********************************************************************
 * ** Function: five_of
 * ** Description: determines if there are five of a kind
 * ** Parameters: int *dice, int &len, int &counter
 * ** Pre-Conditions: dice array, dice roll
 * ** Post-Conditions: boolean
 * *********************************************************************/
bool five_of(int *dice, int &len, int &counter){
	int num1 = 0, num2 = 0, num3 = 0,  num4 = 0, num5 = 0, num6 = 0;

	for(int i = 0; i < len; i++){
		if(dice[i] == 1) {
			num1++;
			i++;
		}
		if(dice[i] == 2){
			num2++;
			i++;
		}
		if(dice[i] == 3){
			num3++;
			i++;
		}
		if(dice[i] ==4){
			num4++;
			i++;
		}
		if(dice[i] = 5){
			num5++;
			i++;
		}
		if(dice[i] = 6){
			num6++;
			i++;
		}
	}
	if(num1 == 5 || num2 ==5 || num3 ==5 || num4 ==5 || num5 == 5|| num6 == 5){
		cout << "five of a kind: 1" << endl;
		return true;
	}
	else{
		cout << "five of a kind: 0" << endl;
		return false;
	}
}
/**********************************************************************
 * ** Function: six_of
 * ** Description: determines if there are six of a kind
 * ** Parameters: int *dice, int &len, int &counter
 * ** Pre-Conditions: dice array, dice roll
 * ** Post-Conditions: boolean
 * *********************************************************************/
bool six_of(int *dice, int &len, int &counter){
	counter = 0;
	for(int i = 0; i < len; i++){
		if(dice[0] == dice[i]){
			counter++;
			i++;
		}
		else{
			cout << "six of a kind: 0" << endl;
			return false;
		}
	}
	if(counter == 6){
		cout << "six of a kind: 1" << endl;
		return true;
	}
}

/*********************************************************************
 * ** Function: is_int
 * ** Description: check if given string is a valid integer
 * ** Parameters: string num
 * ** Pre-Conditions: none
 * ** Post-Conditions: bool
 * *********************************************************************/

bool is_int(string num){
	int len = num.length();
	int i = 0;

	if (len != 0){
		if (num[0] == 45){
			while ( i < len){
				if (num[i] >= 48 &&  num[i] <= 57){
					i++;
				}
				else{
					return false;
				}
			}
		}
		else{
			while (i < len){
				if (num[i] >= 48 && num[i] <= 57){
					i++;
				}
				else{
					return false;
				}
			}
		}
		return true;
	}
}

/*********************************************************************
 * ** Function: get_int
 * ** Description: check if given string is valid integer and returns string as integer
 * ** Parameters: string num
 * ** Pre-Conditions: none
 * ** Post-Conditions: int
 * *********************************************************************/
int get_int(string num){
	int i = 0;
	int dec = 0;

	if(is_int(num) == 1 && num.length() != 0){
		while (i < num.length()){
			dec += (num[i] - '0') * pow(10, (num.length()-i-1));
			i++;
		}
	}
	return dec;
}

/*********************************************************************
 * ** Function: scores
 * ** Description: prints the scores
 * ** Parameters: int &p
 * ** Pre-Conditions: scores determined
 * ** Post-Conditions: integer array
 * *********************************************************************/
int scores(int &p) {
	int score[p][2];
	for(int i = 0; i<p; i++){
		for(int j = 0; j<2; j++){
			score[i][j] = 0;
		}
		score[i][0] = i+1;

	}
	cout << "\n\nScoreboard" << endl;
	cout << "Player # / Score" << endl;
	for(int i = 0; i<p; i++){
		for(int j = 0; j<2; j++){
			cout << score[i][j] << " ";
		}
		cout << endl;
	}

}
