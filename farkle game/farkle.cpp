/**********************************************************************
 * Program: Farkle
 * Author: Arjun Bhalla
 * Date: March 4, 2018
 * Description: 
 * Input: 
 * Output: 
 **********************************************************************/
#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>

/**************************************************
 * Function:
 * Description:
 * Parameters:
 * Pre-Conditions:
 * Post-Conditions:
 **************************************************/

using namespace std;

int players_num();
int* dice_roll(int &);
void print_dice(int *, int);
bool score_singleOne(int *, int);
bool score_singleFive(int *, int);
bool score_threeOne(int *roll, int len);
bool score_threeTwo(int *roll, int len);
bool score_threeThree(int *roll, int len);
bool score_threeFour(int *roll, int len);
bool score_threeFive(int *roll, int len);
bool score_threeSix(int *roll, int len);

bool is_int(string num);
int get_int(string num);

int main() {
	int player_count = players_num(), len = 6, players = 0;
//	players_num(players);
	int *dice = dice_roll(len);
	print_dice(dice, len);	
	return 0;
}

int players_num() {
	string input = "";
	do {
		cout << "Farkle requires a minimum of 2 players... \nEnter the number of players playing the game: ";
		getline(cin, input);
	} while ((is_int(input) == false) && (get_int(input) >= 2));

	int count = get_int(input);
	return count;
}

int* dice_roll(int &len) {
	int *dice = new int[len];
	int x = 0;
	srand(time(NULL));

	for(int i = 0; i < len; i++) {
		x = rand();
		x = ((x%6) + 1);
		dice[i] = x;
	}
	return dice;
}	

void print_dice(int* array, int len) {
	for (int i = 0; i < len; i++) {
		cout << "Dice roll is " << array[i] << endl;
	}
	
	//SCORE CHOICE FUNCTION INSERTED HERE
	
}

void score_choice(int* array, int len) {
	bool option1 = score_singleOne(array, len);
	cout << "single 1 - " << option1 << endl;
	bool option2 = score_singleFive(array, len);
	cout << "single 5 - " << option2 << endl;
	bool option3 = score_threeOne(array, len);
	cout << "three 1 - " << option3 << endl;
	bool option4 = score_threeTwo(array, len);
	cout << "three 2 - " << option4 << endl;
	bool option5 = score_threeThree(array, len);
	cout << "three 3 - " << option5 << endl;
	bool option6 = score_threeFour(array, len);
	cout << "three 4 - " << option6 << endl;
	bool option7 = score_threeFive(array, len);
	cout << "three 5 - " << option7 << endl;
	bool option8 = score_threeSix(array, len);
	cout << "three 6 - " << option8 << endl;
	
	cout << "SCORING OPTIONS:" << endl;
	
	cout << "Choose an option from below:" << endl;
	if(option1 == true){
		cout << "Enter "1" for Option 1" << endl;
	}
	if(option2 == true) {
		cout << "Enter "2" for Option 2" << endl;
	}
	if(option3 == true){
		cout << "Enter "3" for Option 3" << endl;
	}
	if(option4 == true) {
		cout << "Enter "4" for Option 4" << endl;
	}
	if(option5 == true){
		cout << "Enter "5" for Option 5" << endl;
	}
	if(option6 == true) {
		cout << "Enter "6" for Option 6" << endl;
	}
	if(option7 == true){
		cout << "Enter "7" for Option 7" << endl;
	}
	if(option8 == true) {
		cout << "Enter "8" for Option 8" << endl;
	}

	//PLAYER CHOICE FOR SCORING FUNCTION HERE
}


bool score_singleOne(int *roll, int len){
	for(int i = 0; i < len; i++) {
		if(roll[i] == 1) {
			return true;
		}
	}
	return false;
}

bool score_singleFive(int *roll, int len){
	for(int i = 0; i < len; i++) {
		if(roll[i] == 5) {
			return true;
		}
	}
	return false;
}

bool score_threeOne(int *roll, int len){
	int counter = 0;
	for(int i = 0; i < len; i++) {
		if(roll[i] == 1) {
			counter++;
		}
	}
	if(counter == 3) {
		return true;
	}
	else {
		return false;
	}
}

bool score_threeTwo(int *roll, int len){
	int counter = 0;
	for(int i = 0; i < len; i++) {
		if(roll[i] == 2) {
			counter++;
		}
	}
	if(counter == 3) {
		return true;
	}
	else {
		return false;
	}
}

bool score_threeThree(int *roll, int len){
	int counter = 0;
	for(int i = 0; i < len; i++) {
		if(roll[i] == 3) {
			counter++;
		}
	}
	if(counter == 3) {
		return true;
	}
	else {
		return false;
	}
}

bool score_threeFour(int *roll, int len){
	int counter = 0;
	for(int i = 0; i < len; i++) {
		if(roll[i] == 4) {
			counter++;
		}
	}
	if(counter == 3) {
		return true;
	}
	else {
		return false;
	}
}

bool score_threeFive(int *roll, int len){
	int counter = 0;
	for(int i = 0; i < len; i++) {
		if(roll[i] == 5) {
			counter++;
		}
	}
	if(counter == 3) {
		return true;
	}
	else {
		return false;
	}
}

bool score_threeSix(int *roll, int len){
	int counter = 0;
	for(int i = 0; i < len; i++) {
		if(roll[i] == 6) {
			counter++;
		}
	}
	if(counter == 3) {
		return true;
	}
	else {
		return false;
	}
}





























//void player_turn(int &len, int &player, int &player_count)

bool is_int(string num) {
	int i = 0;

	if (num.length() == 0) {
		return 0;
	}
	if (num[0] == 45) {
		i = 1;
		while(num[i] != '\0') {
			if ((num[i] > 47 && num[i] < 58)) {
				i++;
			}
			else {
				return false;
			}
		}
	}
	else {
		i = 0;
		while(num[i] != '\0') {
			if ((num[i] > 47 && num[i] < 58)) {
				i++;
			}
			else {
				return false;
			}
		}
	}
	return true;
}

int get_int(string num) {

	int result = 0;
	int i = 0;

	if (num[0] == 45)
		i = 1;
	
	while (num[i] != '\0') {
		result += (num[i] - 48)*(pow(10, num.length() - i - 1));
		i++;
	}

	if (num[0] == 45)
		result = (result * (-1));
	
	return result;
}
