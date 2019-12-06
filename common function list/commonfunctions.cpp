/**********************************************************************
 * Program: Functions List
 * Author: Arjun Bhalla
 * Date: Januar 29, 2018
 * Description: 16 functions that have hard coded inputs (with the exception of two). These functions are being designed to be used in future projects.
 * Input: Hard coded input (except for get_int and get_float
 * Output: Expected output + ™PASS/FAIL test table for each function
 **********************************************************************/
#include <iostream>
#include <cmath>
#include <string>

using namespace std;


bool check_range(int lower_bound, int upper_bound, int test_value);
bool is_int(string num);
bool is_float(string num);
bool is_capital(char letter);
bool is_even(int num);
bool is_odd(int num);
int equality_test(int num1, int num2);
bool float_is_equal(float num1, float num2, float precision);
bool numbers_present(string sentence);
bool letters_present(string sentence);
bool contains_sub_string(string sentence, string sub_string);
int word_count(string sentence);
string to_upper(string sentence);
string to_lower(string sentence);
int get_int();
float get_float();

string bool_test(bool func_result);
string string_test(string func_result, string expected);
string int_test(int func_result, int expected);
string float_test(float func_result, float expected);

int main() {

	bool bool_result = false;
	int int_result = 0;
	string string_result = "";
	float float_result = 0.0;

	cout << endl << endl; // JUST FOR OUTPUT READABILITY

//CHECK_RANGE
	cout << "CHECK_RANGE FUNCTION:" << endl;
	cout << "Expected TRUE Case:" << endl;
	bool_result = check_range(0,10,5);
	cout << "Expected Output: PASS"  << "   Actual Output: " << bool_test(bool_result) << endl << endl;
	cout << "Expected FAIL Case:" << endl;
	bool_result = check_range(0,10,20);
	cout << "Expected Output: FAIL"  << "   Actual Output: " << bool_test(bool_result) << endl << endl;
	
//IS_INT
	cout << endl << endl;
	cout << "IS_INT FUNCTION:" << endl;
	cout << "Expected TRUE Case:" << endl;
	bool_result = is_int("23");
	cout << "Expected Output: PASS"  << "   Actual Output: " << bool_test(bool_result) << endl << endl;
	cout << "Expected FAIL Case:" << endl;
	bool_result = is_int("1.1");
	cout << "Expected Output: FAIL"  << "   Actual Output: " << bool_test(bool_result) << endl << endl;

//IS_FLOAT
	cout << endl << endl;
	cout << "IS_FLOAT FUNCTION:" << endl;
	cout << "Expected TRUE Case:" << endl;
	bool_result = is_float("23.9");
	cout << "Expected Output: PASS"  << "   Actual Output: " << bool_test(bool_result) << endl << endl;
	cout << "Expected FAIL Case:" << endl;
	bool_result = is_float("13");
	cout << "Expected Output: FAIL"  << "   Actual Output: " << bool_test(bool_result) << endl << endl;

//IS_CAPITAL
	cout << endl << endl;
	cout << "IS_CAPITAL FUNCTION:" << endl;
	cout << "Expected TRUE Case:" << endl;
	bool_result = is_capital('A');
	cout << "Expected Output: PASS"  << "   Actual Output: " << bool_test(bool_result) << endl << endl;
	cout << "Expected FAIL Case:" << endl;
	bool_result = is_capital('f');
	cout << "Expected Output: FAIL"  << "   Actual Output: " << bool_test(bool_result) << endl << endl;

//IS_EVEN
	cout << endl << endl;
	cout << "IS_EVEN FUNCTION:" << endl;
	cout << "Expected TRUE Case:" << endl;
	bool_result = is_even(824);
	cout << "Expected Output: PASS"  << "   Actual Output: " << bool_test(bool_result) << endl << endl;
	cout << "Expected FAIL Case:" << endl;
	bool_result = is_even(111);
	cout << "Expected Output: FAIL"  << "   Actual Output: " << bool_test(bool_result) << endl << endl;

//IS_ODD
	cout << endl << endl;
	cout << "IS_ODD FUNCTION:" << endl;
	cout << "Expected TRUE Case:" << endl;
	bool_result = is_odd(913);
	cout << "Expected Output: PASS"  << "   Actual Output: " << bool_test(bool_result) << endl << endl;
	cout << "Expected FAIL Case:" << endl;
	bool_result = is_odd(728);
	cout << "Expected Output: FAIL"  << "   Actual Output: " << bool_test(bool_result) << endl << endl;

//EQUALITY_TEST
	cout << endl << endl;
	cout << "EQUALITY_TEST FUNCTION:" << endl;
	cout << "Expected EQUAL Case:" << endl;
	int_result = equality_test(541, 541);
	cout << "Expected Output: PASS"  << "   Actual Output: " << int_test(int_result, 0) << endl << endl;
	cout << "Expected NUM1 < NUM2 Case:" << endl;
	int_result = equality_test(728, 945);
	cout << "Expected Output: PASS"  << "   Actual Output: " << int_test(int_result, -1) << endl << endl;
	cout << "Expected NUM1 > NUM2 Case:" << endl;
	int_result = equality_test(1000, 500);
	cout << "Expected Output: PASS"  << "   Actual Output: " << int_test(int_result, 1) << endl << endl;
	cout << endl << endl;

//FLOAT_IS_EQUAL
	cout << "FLOAT_IS_EQUAL FUNCTION:" << endl;
	cout << "Expected TRUE Case:" << endl;
	bool_result = float_is_equal(1.003, 1.005, 0.004);
	cout << "Expected Output: PASS"  << "   Actual Output: " << bool_test(bool_result) << endl << endl;
	cout << "Expected FAIL Case:" << endl;
	bool_result = float_is_equal(7.007, 8.008, 0.001);
	cout << "Expected Output: FAIL"  << "   Actual Output: " << bool_test(bool_result) << endl << endl;


//NUMBERS_PRESENT
	cout << endl << endl;
	cout << "NUMBERS_PRESENT FUNCTION:" << endl;
	cout << "Expected TRUE Case:" << endl;
	bool_result = numbers_present("I am 18 years old.");
	cout << "Expected Output: PASS"  << "   Actual Output: " << bool_test(bool_result) << endl << endl;
	cout << "Expected FAIL Case:" << endl;
	bool_result = numbers_present("There are no numbers in this string!");
	cout << "Expected Output: FAIL"  << "   Actual Output: " << bool_test(bool_result) << endl << endl;

//LETTERS_PRESENT
	cout << endl << endl;
	cout << "LETTERS_PRESENT FUNCTION:" << endl;
	cout << "Expected TRUE Case:" << endl;
	bool_result = letters_present("123abc");
	cout << "Expected Output: PASS"  << "   Actual Output: " << bool_test(bool_result) << endl << endl;
	cout << "Expected FAIL Case:" << endl;
	bool_result = letters_present("1234567890");
	cout << "Expected Output: FAIL"  << "   Actual Output: " << bool_test(bool_result) << endl << endl;

//CONTAINS_SUB_STRING
	cout << endl << endl;
	cout << "CONTAINS_SUB_STRING FUNCTION:" << endl;
	cout << "Expected TRUE Case:" << endl;
	bool_result = contains_sub_string("Hey my name is Arjun!", "Arjun");
	cout << "Expected Output: PASS"  << "   Actual Output: " << bool_test(bool_result) << endl << endl;
	cout << "Expected FAIL Case:" << endl;
	bool_result = contains_sub_string("Hey what is your name?", "Arjun");
	cout << "Expected Output: FAIL"  << "   Actual Output: " << bool_test(bool_result) << endl << endl;

//WORD_COUNT
	cout << endl << endl;
	cout << "WORD_COUNT FUNCTION:" << endl;
	cout << "Expected PASS Case:" << endl;
	int_result = word_count("Hello my name is Arjun!");
	cout << "Expected Output: PASS"  << "   Actual Output: " << int_test(int_result, 5) << endl << endl;
	cout << "Expected PASS Case:" << endl;
	int_result = word_count("Hello     my name is Arjun!");
	cout << "Expected Output: FAIL"  << "   Actual Output: " << int_test(int_result, 9) << endl << endl;

//TO_UPPER
	cout << endl << endl;
	cout << "TO_UPPER FUNCTION:" << endl;
	string_result = to_upper("Hello my name is Arjun!");

//TO_LOWER
	cout << endl << endl;
	cout << "TO_LOWER FUNCTION:" << endl;
	string_result = to_lower("HeLLo my NAME is ARJUN!");

//GET_INT
	cout << endl << endl;
	cout << "GET_INT FUNCTION:" << endl;
	cout << "Expected TRUE Case:" << endl;
	int_result = get_int();

//GET_FLOAT
	cout << endl << endl;
	cout << "GET_FLOAT FUNCTION:" << endl;
	float_result = get_float();
	
	return 0;
	
}


string bool_test(bool func_result) {
	
	string testing = "";
	
	if (func_result == 1) {
		testing = "PASS ";
	}
	else {
		testing = "FAIL ";
	}

	return testing;
}


string string_test(string func_result, string expected) {

	string testing = "";
	
	if (func_result == expected) {
		testing = "PASS ";
	}
	else {
		testing = "FAIL ";
	}

	return testing;

}


string int_test(int func_result, int expected) {

	string testing = "";
	
	if (func_result == expected) {
		testing = "PASS ";
	}
	else {
		testing = "FAIL ";
	}

	return testing;

}



/**************************************************
 * Function: CHECK_RANGE
 * Description: This function checks if an input (currently hardcoded) is between two range bounds (currently hardcoded)
 * Parameters: lower_bound, upper_bound, test_value (all are int)
 * Pre-Conditions: Assumes that the input is a valid integer
 * Post-Conditions: 
 **************************************************/

bool check_range(int lower_bound, int upper_bound, int test_value) {
	
//	cout << "Testing if the value of " << test_value << " is between the bounds of " << lower_bound << " and " << upper_bound << endl;
	cout << "Lower Bound: " << lower_bound << " Upper Bound: " << upper_bound << " Test Value: " << test_value << endl;
	if (test_value >= lower_bound && test_value <= upper_bound) {
	//	cout << test_value << " is within the bounds given!" << endl;
		return true;
	}
	else {
	//	cout << test_value << " is NOT within the bounds given!" << endl;
		return false;
	}
}

/**************************************************
 * Function: IS_INT
 * Description: This function checks if an input from a string is an integer data type.
 * Parameters: string num
 * Pre-Conditions: None
 * Post-Conditions: 
 **************************************************/

bool is_int(string num) {
	
	cout << "Entered Input: " << num << endl;
	
	int i = 0;

	if (num.length() == 0) {
		cout << "Please enter a string into the function" << endl;
		return 0;
	}

	if (num[0] == 45) {
		i = 1;
		while(num[i] != '\0') {
			if ((num[i] > 47 && num[i] < 58)) {
				i++;
			}
			else {
			//	cout << num << " is NOT an integer!" << endl;
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
			//	cout << num << " is NOT an integer!" << endl;
				return false;
			}
		}
	}

//	cout << num << " is an integer!" << endl;
	return true;
}

/**************************************************
 * Function: IS_FLOAT
 * Description: This function checks if an input from a string is a float data type.
 * Parameters: string num
 * Pre-Conditions: None
 * Post-Conditions: 
 **************************************************/

bool is_float(string num) {

	cout << "Entered Input: " << num << endl;

	int i = 0;
	int dec_counter = 0;

	if (num.length() == 0) {
		cout << "Please enter a string into the function" << endl;
		return 0;
	}
	
	if (num[0] == 45) { //If first character is a negative symbol
		i = 1;
	}

	if (num[0] == 46) { //If first character is a decimal
		dec_counter = 1; 
		i = 1;
	}

	while (num[i] != '\0') {
		if (num[i] >= 48 && num[i] <= 57) {
			i++;
		}
		if (num[i] == 46) {
			dec_counter++; 
			i++;		
		}
		else if ((num[i] < 48 && num[i] > 57) && (num[i] != 46)) {
		//	cout << num << " is NOT a float!" << endl;
			return false;
		}
	}

	if (dec_counter == 1) {
	//	cout << num << " is a float!" << endl;
		return true;
	}
	if (dec_counter != 1) {
	//	cout << num << " is NOT a float!" << endl;
		return false;
	}

}

/**************************************************
 * Function: IS_CAPITAL
 * Description: This function checks if the input from a character is a capital character.
 * Parameters: char letter
 * Pre-Conditions: Assumes that the input is a valid char data type.
 * Post-Conditions: 
 **************************************************/

bool is_capital(char letter) {
	
	cout << "Entered Character: " << letter << endl;

	if(((int)letter >= 65 && (int)letter <= 90)) {
		cout << letter << " is a capital letter!" << endl;
		return true;
	}
	cout << letter << " is not a capital letter!" << endl;
	return false;	

}

/**************************************************
 * Function: IS_EVEN
 * Description: This function checks if the integer input is an even integer.
 * Parameters: int num
 * Pre-Conditions: Assumes that the input is a valid int data type.
 * Post-Conditions:
 **************************************************/

bool is_even(int num) {
	
	cout << "Entered integer: " << num << endl;

	if (num%2 == 0){
		cout << num << " is an even integer!" << endl;
		return true;
	}
	cout << num << " is NOT an even integer!" << endl;
	return false;
	
}	

/**************************************************
 * Function: IS_ODD
 * Description: This function checks if the integer input is an odd integer.
 * Parameters: int num
 * Pre-Conditions: Assumes that the input is a valid int data type.
 * Post-Conditions:
 **************************************************/

bool is_odd(int num) {

	cout << "Entered integer: " << num << endl;

	if (num%2 == 1){
		cout << num << " is an odd integer!" << endl;
		return true;
	}
	cout << num << " is NOT an odd integer!" << endl;
	return false;

}

/**************************************************
 * Function: EQUALITY_TEST
 * Description: This function checks if two integer numbers are equivalent or not (if not - which one is larger)
 * Parameters: int num1, int num2
 * Pre-Conditions: Assumes that there is input for both variables and they are the correct data types.
 * Post-Conditions:
 **************************************************/

int equality_test(int num1, int num2) {
	
	int result = 0;

	if (num1 == num2) {
		result = 0;
		cout << num1 << " is equal to " << num2 << "!" << endl;
		return result;
	}
	else if (num1 < num2) {
		result = -1;
		cout << num1 << " is less than " << num2 << "!" << endl;
		return result;
	}
	else if (num1 > num2) {
		result = 1;
		cout << num1 << " is greater than " << num2 << "!" << endl;
		return result;
	}
	
}

/**************************************************
 * Function: FLOAT_IS_EQUAL
 * Description: This function takes the input of two float numbers 
 * Parameters:
 * Pre-Conditions:
 * Post-Conditions:
 **************************************************/

bool float_is_equal(float num1, float num2, float precision) {
	
	float result = 0.0;

	cout << "Num1: " << num1 << " Num2: " << num2 << " Precision: " << precision << endl;
	
	result = (num1 - num2);
	result = abs(result);

	if (result <= precision)
		return true;
	else if (result > precision)
		return false;
	
}

/**************************************************
 * Function: NUMBERS_PRESENT
 * Description: This function takes the input of a string and checks if there are any numbers within the string
 * Parameters:
 * Pre-Conditions:
 * Post-Conditions:
 **************************************************/

bool numbers_present(string sentence) {

	cout << "Entered Sentence: " << sentence << endl;
	
	int i = 0;

	if (sentence.length() == 0) {
		cout << "Please enter a string into the function" << endl;
		return 0;
	}

	while(sentence[i] != '\0') {
		if (sentence[i] >= 48 && sentence[i] <= 57) {
			cout << "The sentence contains numbers!" << endl;
			return true;
		}
		else {
			i++;
		}
	}

	cout << "The sentence contains no numbers!" << endl;
	return false;

}

/**************************************************
 * Function: LETTERS_PRESENT
 * Description: 
 * Parameters:
 * Pre-Conditions:
 * Post-Conditions:
 **************************************************/

bool letters_present(string sentence) {
	
	cout << "Entered Sentence: " << sentence << endl;
	
	int i = 0;

	if (sentence.length() == 0) {
		cout << "Please enter a string into the function" << endl;
		return 0;
	}

	while(sentence[i] != '\0') {
		if ((sentence[i] >= 65 && sentence[i] <= 90) || (sentence[i] >= 97 && sentence[i] <= 122)){
			cout << "The sentence contains letters!" << endl;
			return true;
		}
		else {
			i++;
		}
	}

	cout << "The sentence contains no letters!" << endl;
	return false;
}

/**************************************************
 * Function: CONTAINS_SUB_STRING
 * Description: This function checks a string for if it contains another smaller sub string within it (verbatim)
 * Parameters: string sentence, string sub_string
 * Pre-Conditions:
 * Post-Conditions:
 **************************************************/

bool contains_sub_string(string sentence, string sub_string) {
	
	int x = 0;
	int y = 0;

	if (sentence.length() == 0) {
		cout << "Please enter a valid sentence!" << endl;
		return 0;
	}
	if (sub_string.length() == 0) {
		cout << "Please enter a valid sub string!" << endl;
		return 0;
	}
	if (sentence.length() < sub_string.length()) {
		cout << "Sentence is not longer than sub string!" << endl;
		return 0;
	}

	while (sentence[x] != '\0') {
		if (sentence[x] == sub_string[y]) {
			if (y == (sub_string.length() - 1)) {
				cout << "Sub string was found within the sentence!" << endl;
				return true;
			}
			x++; y++;
		}
		else {
			x++; y = 0;
		}
	}

	cout << "Sub string was NOT found within the sentence!" << endl;
	return false;

}

/**************************************************
 * Function: WORD_COUNT
 * Description: This function checks how many words are present in a sentence.
 * Parameters: string sentence
 * Pre-Conditions: Assumes that every character/series of characters surrounded by spaces is considered a word.
 * Post-Conditions:
 **************************************************/

int word_count(string sentence) {
	
	int x = 0; // temp space counter
	int i = 0; // iterator
	int space_counter = 0; // to calculate number of words (space_counter + 1)
	int count = 0; // count = space_counter + 1

	if (sentence.length() == 0) {
		cout << "Please enter a valid sentence!" << endl << endl;
		return 0;
	}

	while (sentence[i] != '\0') {
		if (x == 0 && sentence[i] == 32) {
			x++; i++; space_counter++;
		}
		else if (x != 0 && sentence[i] == 32) {
			x++; i++;
		}
		else if (sentence[i] != 32) {
			x = 0; i++;
		}
	}
	
	count = space_counter + 1;
	cout << "The sentence contains " << count << " words!" << endl;
	return count;
}

/**************************************************
 * Function: TO_UPPER
 * Description: Changes all lowercase letters to uppercase in the string
 * Parameters:
 * Pre-Conditions:
 * Post-Conditions:
 **************************************************/

string to_upper(string sentence) {

	cout << "INPUT: " << sentence << endl;

	int i = 0;

	if (sentence.length() == 0)
		cout << "Please enter a valid sentence!" << endl << endl;

	while (sentence[i] != '\0') {
		if (sentence[i] >= 97  && sentence[i] <= 122) {
			sentence[i] = sentence[i] - 32;
			i++;
		}
		else
			i++;
	}

	cout << "Modified Sentence: " << sentence << endl;
	return sentence;

}

/**************************************************
 * Function: TO_LOWER
 * Description: Changes all uppercase letters to lowercase in the string
 * Parameters:
 * Pre-Conditions:
 * Post-Conditions:
 **************************************************/

string to_lower(string sentence) {

	cout << "INPUT: " << sentence << endl;

	int i = 0;

	if (sentence.length() == 0)
		cout << "Please enter a valid sentence!" << endl << endl;

	while (sentence[i] != '\0') {
		if (sentence[i] >= 65 && sentence[i] <= 90) {
			sentence[i] = sentence[i] + 32;
			i++;
		}
		else {
			i++;
		}
	}

	cout << "Modified Sentence: " << sentence << endl;
	return sentence;

}

/**************************************************
 * Function: GET_INT
 * Description: 
 * Parameters:
 * Pre-Conditions:
 * Post-Conditions:
 **************************************************/

int get_int() {

	int result = 0;
	int i = 0;
	string num = "";

	do {
		cout << "Please enter a valid string as a prompt: ";
		getline(cin, num);	
	} while ((num.length() == 0) || (is_int(num) == false));

	if (num[0] == 45)
		i = 1;
	
	while (num[i] != '\0') {
		result += (num[i] - 48)*(pow(10, num.length() - i - 1));
		i++;
	}

	if (num[0] == 45)
		result = (result * (-1));
	
	cout << "Integer returned: " << result << endl;
	return result;
	
}

/**************************************************
 * Function:
 * Description: 
 * Parameters:
 * Pre-Conditions:
 * Post-Conditions:
 **************************************************/

float get_float() {

	float result = 0;
	int i = 0;
	int dec = 0;
	string num = "";
	
	do {
		cout << "Please enter a valid string as a prompt: ";
		getline(cin, num);
	} while ((num.length() == 0) || (is_float(num) == false));

	while (num[i] != '\0') {
		if (num[i] == 46) {
			dec = i;
			break;
		}
		else if (num[i] != 46)
			i++;
	}
	
	i = 0;

	if (num[0] == 45)
		i = 1;
	
	while (num[i] != '\0') {
		if (i < dec) {
			result += (num[i] - 48)*(pow(10, num.length() - dec - i - 2));
			i++;
		}
		else if (i == dec)
			i++;
		else if (i > dec) {
			result += (num[i] - 48)*(pow(10, dec - i));
			i++;
		}
	}
	
	if (num[0] == 45)
		result = (result * (-1));

	cout << "Float returned: " << result << endl;
	return result;
}
