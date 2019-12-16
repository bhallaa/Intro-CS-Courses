/*********************************************************************
 * ** Program Filename: Calculator
 * ** Author: Arjun Bhalla
 * ** Date: 2/16/18
 * ** Description: Allows the user to choose and excute a binary to decimal, decimal to binary, grade, or standard calculator
 * ** Input: choice of calculator; binary number, decimal number, number of grades, grades, weight, equation
 * ** Output: the resulting calculations
 * *********************************************************************/

#include <iostream>
#include <cmath>
#include <string>

using namespace std;

//function declararions

bool bin_check(string);
string bin_input();
int convert_btd(string);

bool is_int(string);
int get_int(string);
string input_num();
string convert_dtb(int);
string rev_str(string);

int grade_amt();
float input_grade(int);
float weight(float);

string get_equation();
float find_equation(string);
float get_float(string);
bool is_float(string);

/*********************************************************************
 * ** Function: Main
 * ** Description: Executes the calculators and allows the user to choose which calcultor to run
 * ** Parameters: none
 * ** Pre-Conditions: none
 * ** Post-Conditions: answers, asking if user would like to choose another calculator
 * *********************************************************************/
int main(){

	int choose2=0;
	do{
		int choose=0;

		cout << "What calculator do u want to use? 1-Binary to Decimal, 2-Decimal to Binary, 3-Standard Calc, 4-Grade Calc" << endl;
		cin >> choose;

		if (choose == 1){
			//binary to decimal
			string bin = bin_input();
			int res = convert_btd(bin);
			cout << "The decimal result is: " << res << endl;
			cout << "Do you want you want to run another calculator? 1-Yes 0-No" << endl;
			cin >> choose2;
		}
		if (choose == 2){
			//decimal to binary
			string fin = input_num();
			int fin2 = get_int(fin);
			string new1 = convert_dtb(fin2);
			string res2 = rev_str(new1);
			cout << "The binary result is: " << res2 << endl;
			cout << "Do you want you want to run another calculator? 1-Yes 0-No" << endl;
			cin >> choose2;
		}
		if (choose == 3){
			//standard calc
			string eq = get_equation();
			float eq2 = find_equation(eq);
			cout << "The answer is: " << eq2 << endl;
			cout << "Do you want you want to run another calculator? 1-Yes 0-No" << endl;
			cin >> choose2;
		}
		if (choose == 4){
			//grade calc
			int gr_amt = grade_amt();
			float grades = input_grade(gr_amt);
			float res3 = weight(grades);
			cout << "Do you want you want to run another calculator? 1-Yes 0-No" << endl;
			cin >> choose2;
		}
	}while(choose2 == 1);
	return 0;
}

//binary to decimal

/*********************************************************************
 * ** Function: bin_check
 * ** Description: checks if strin gis valid binary number
 * ** Parameters: string bin
 * ** Pre-Conditions: string input
 * ** Post-Conditions: boolean value
 * *********************************************************************/
bool bin_check(string bin){

	for(int i=0; i<bin.length(); i++){
		if (bin[i] != '0' && bin[i] != '1'){
			return false;
		}
	}
	return true;
}
/*********************************************************************
 * ** Function: bin_input
 * ** Description: receives string from user
 * ** Parameters: none
 * ** Pre-Conditions: string input
 * ** Post-Conditions: string bin
 * *********************************************************************/
string bin_input(){
	cin.ignore();
	string bin = "";

	do{
		cout << "Input a binary number" << endl;
		getline(cin, bin);

	}while(bin_check(bin) == false);

	return bin;
}
/*********************************************************************
 * ** Function: convert_btd
 * ** Description: conversion process of binary number to decimal number
 * ** Parameters: string bin
 * ** Pre-Conditions: accurate binary number
 * ** Post-Conditions: int res
 * *********************************************************************/
int convert_btd(string bin){
	int len = bin.length();
	int res = 0;
	for(int i=0; i < len; i++){
		if (bin[i] == '1'){
			res += pow(2, (len-i-1));
		}
	}
	return res;

}

//decimal to binary
/*********************************************************************
 * ** Function: is_int
 * ** Description: Determines if string is integer
 * ** Parameters: string num
 * ** Pre-Conditions: valid string input
 * ** Post-Conditions: boolean
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

string input_num(){
	cin.ignore();
	string num = "";

	do{
		cout << "Input a decimal number" << endl;
		getline(cin, num);

	}while(is_int(num) == false);

	return num;
}
/*********************************************************************
 * ** Function: convert_dtb
 * ** Description: converts decimal value to a binary number
 * ** Parameters: int dec
 * ** Pre-Conditions: integer input
 * ** Post-Conditions: string
 * *********************************************************************/
string convert_dtb(int dec){

	string final_bin = "";

	while (dec != 0){
		if (dec%2 == 0){
			dec = dec/2;
			final_bin += "0";
		}
		if (dec%2 == 1){
			dec = dec/2;
			final_bin += "1";
		}
	}
	if (dec == 0){
		return final_bin;
	}
}
/*********************************************************************
 * ** Function: rev_str
 * ** Description: reverses the order of the string to output correct binary number
 * ** Parameters: string final_bin
 * ** Pre-Conditions: string
 * ** Post-Conditions: string
 * *********************************************************************/
string rev_str(string final_bin){

	string fb = "";
	int len = final_bin.length();
	int i = len-1;

	while(i >= 0){
		fb += final_bin[i];
		i--;
	}
	return fb;
}
//standard calc
/*********************************************************************
 * ** Function: get_equation
 * ** Description: receives equation from user
 * ** Parameters: none
 * ** Pre-Conditions: valid string input
 * ** Post-Conditions: string
 * *********************************************************************/
string get_equation(){
	cin.ignore();
	string equation = "";

	cout << "Enter an equation: " << endl;
	getline(cin, equation);

	return equation;
}
/*********************************************************************
 * ** Function: find_equation
 * ** Description: parses through the string to determine when to operate; operates
 * ** Parameters: string equation
 * ** Pre-Conditions: valid string input
 * ** Post-Conditions: float output
 * *********************************************************************/
float find_equation(string equation){
	string a = "";
	string b = "";
	int operator_spot=0, i=0, space=0;
	bool op = false;
	float num1 = 0, num2 = 0;
	int len = equation.length();

	while(i < len){
		if (space%2 == 1){
			op = false;
		}
		if (space%2 == 0){
			op = true;
		}
		if ( (space == 3) || (i == '\0') || (space > 3 && (space%2==1)) ){
			if (is_int(b) == true){
				num2 = get_int(b);
			}
			if (is_float(b) == true){
				num2 = get_float(b);
			}
			if (equation[operator_spot]=='+'){
				num1 = num1 + num2;
			}
			if (equation[operator_spot]=='-'){
				num1 = num1 - num2;
			}
			if (equation[operator_spot]=='*'){
				num1 = num1 * num2;
			}
			if (equation[operator_spot]=='/'){
				num1 = num1 / num2;
			}
			if (i == '\0'){
				return num1;
			}
		}
		if ( (equation[i] >= 48 && equation[i] <= 57) || (equation[i] == '-' && op == true) || equation[i] == '.'){
			cout << "dfkadfasdfasfasdf" << endl;
			if (space == 0){
				a += equation[i];
				if (is_int(a) == true){
					num1 = get_int(a);
				}
				if (is_float(a) == true){
					num1 = get_int(a);
				}
				i++;
			}
			if (space >= 1){
				b += equation[i];
				i++;
			}
		}
		if (equation[i] == ' '){
			i++;
			space++;
		}
		if ( (equation[i] == '+') || (equation[i] == '-') || (equation[i] == '*') || (equation[i] == '/') ){
			operator_spot = i;
		}
	}
}
/*********************************************************************
 * ** Function: is_float
 * ** Description: Checks if valid float
 * ** Parameters: string num
 * ** Pre-Conditions: none
 * ** Post-Conditions: bool
 * *********************************************************************/

bool is_float(string num){
	int i = 0, dec = 0;
	int len = num.length();

	while (i < len){
		if (num[i] == 0){
			i++;
			break;
		}
		if (num[i] == '.'){
			i++;
			dec++;
			break;
		}
		if (num[i] >= 48 && num[i] <= 57){
			i++;
			break;
		}
	}
	if (dec == 1){
		return true;
	}
	else{
		return false;
	}
}
/*********************************************************************
 * ** Function: get_float
 * ** Description: Checks if valid float, returns as valid float
 * ** Parameters: string num
 * ** Pre-Conditions: none
 * ** Post-Conditions: float
 * *********************************************************************/
float get_float(string num){
	int i = 0, dec = 0, res = 0;

	while(is_float(num) == 1 && num.length() != 0){
		if(num[0] == '-'){
			i++;
		}
		while (i < num.length()){
			if (num[i] == '-'){
				dec == i;
				break;
			}
			else{
				i++;
			}

		}
		i = 0;
		while (i < num.length()){
			if(i < dec){
				res += ((int(num[i]-48))*pow(10,num.length()-i-2));
				i++;
			}
			if (i == dec){
				i++;
			}
			if (i > dec){
				res += ((int(num[i]-48))*pow(10,(dec-i)));
				i++;
			}
		}
		if (num[0] == '-'){
			res = res*(-1);
		}
	}
	return res;
}

//grade calculator

/*********************************************************************
 * ** Function: grade_amt
 * ** Description: Receives number of grades from userr
 * ** Parameters: none
 * ** Pre-Conditions: integer input
 * ** Post-Conditions: integer
 * *********************************************************************/

int grade_amt(){

	int amt = 0;

	cout << "Enter number of grades: " << endl;
	cin >> amt;
	cin.ignore();

	return amt;
}
/*********************************************************************
 * ** Function: input_grade
 * ** Description: Receives user input for individual scores and the average is returned
 * ** Parameters: int amt
 * ** Pre-Conditions: valid float score
 * ** Post-Conditions: float
 * *********************************************************************/

float input_grade(int amt){

	int i=0;
	float score=0.0;
	float val=0.0;
	float avg_val=0.0;

	while (i < amt){
		cout << "Enter your score" << endl;
		cin >> score;
		val += score;
		i++;
	}
	avg_val = float(val/amt);

	return avg_val;
}
/*********************************************************************
 * ** Function: weight
 * ** Description: if the user chooses, they can multiply the avg by a weight
 * ** Parameters: float avg_val
 * ** Pre-Conditions: valid float input
 * ** Post-Conditions: float
 * *********************************************************************/

float weight(float avg_val){

	int ans = 0;
	float weight_val = 0.0;
	float result = 0.0;

	cout << "Would you like to enter a weight? 1-Yes, 0-No" << endl;
	cin >> ans;

	if (ans == 0){
		cout << "Your grade is: " << avg_val << endl;
	}
	if (ans == 1){
		cout << "Enter the weight: " << endl;
		cin >> weight_val;

		result = float(weight_val*avg_val);
		cout << "Your grade is: " << result << endl;
	}
}
