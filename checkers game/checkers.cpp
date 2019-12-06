/****************************************************************************************************************
 * Program Filename: Checkers
 * Author: Arjun Bhalla
 * Date: March 18, 2018
 * Description: Read the README.txt
 * Input: Command Line Argument to get the size of the board + Player input for move
 * Output: The board (repeatedly) and eventually the winner of the game
 ****************************************************************************************************************/

#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <cstring>

using namespace std;

void add_character(char**, char);
int char_to_size(char*);

int** initialize_board(int);
void print_board(int**, int);
void player_move(int**, int);
bool valid_move (int**, int, int, int, int, int, bool &);
void run_move (int**, int, int, int, int, bool);
int check_win(int**, int);
void change_to_king(int**, int);
char* get_move();

/*************************************************************************************
 * Function: 
 * Description:
 * Parameters:
 * Pre-Conditions:
 * Post-Conditions:
 *************************************************************************************/

int main(int argc, char** argv) {

	//TESTING OUT THE COMMAND LINE INPUT WITH THE C STYLE STRING
	//give credit to shannon ernst for command line argument styling
	char* board_input;
	if (argc != 2) {
		//getting input if command line argument is incorrectly used
		board_input = new char;
		*board_input = '\0';
		cout << "Please enter a number to represent the size of the board (An even number - If number is not even it will round down to the closest even number): ";
		while(cin.peek() != '\n') {
			add_character(&board_input, cin.get());
		}
		cin.ignore();
		cin.clear();
	}
	else {
		//putting the input from command line (if used correctly)
		board_input = new char[strlen(argv[1]) + 1];
		strcpy(board_input, argv[1]);
	}

	//SETTING THE SIZE OF THE BOARD FOR DIMENSIONS AND BOARD INITIALIZATION (deleting char array for command line argument)
	int size = char_to_size(board_input);
	if (size%2 == 1) {
		size = (size/2)*2;
	}
	delete [] board_input; board_input = NULL;

	//INITIALIZING THE BOARD
	int** board;
	board = initialize_board(size);
	print_board(board, size);
//	board[0][0] = 2;
//	change_to_king(board, size);
//	print_board(board, size);
	
	player_move(board, size);

	//DELETES THE BOARD
	for(int i = 0; i < size; i++) {
		delete [] board[i];	
	}
	delete [] board; board = NULL;
	
	return 0;
}



/*************************************************************************************
 * Function:
 * Description:
 * Parameters:
 * Pre-Conditions:
 * Post-Conditions:
 *************************************************************************************/

//IF GIVEN BAD COMMAND LINE INPUT BY THE USER - USES THIS FUNCTION TO TAKE INPUT INTO A NEW C STYLE STRING IN MAIN FUNCTION
//give credit to shannon ernst for this function
void add_character(char** input, char c) {
	char* temp = new char[strlen(*input)+2];
	for(int i = 0; i < strlen(*input); i++) {
		temp[i] = (*input)[i];
	}
	temp[strlen(*input)] = c;
	temp[strlen(*input) + 1] = '\0';
	delete [] (*input);
	(*input) = new char[strlen(temp) + 1];
	strcpy((*input), temp);
	delete [] temp;
}

/*************************************************************************************
 * Function:
 * Description:
 * Parameters:
 * Pre-Conditions:
 * Post-Conditions:
 *************************************************************************************/

int char_to_size(char* input) {
	int size = 0;
	for (int i = 0; i < strlen(input); i++) {
		if ((input)[i] >= '0' && (input)[i] <= '9') {
			size += ((input)[i] - 48)*(pow(10, strlen((input)) - i - 1));
		}
	}
	if (size == 0) {
		cout << "Rerun program and enter valid input for dimensions" << endl;
		return 0;
	}
	return size;
}

/*************************************************************************************
 * Function:
 * Description:
 * Parameters:
 * Pre-Conditions:
 * Post-Conditions:
 *************************************************************************************/

int** initialize_board(int size) {
		
	//CREATES THE BOARD
	int** array;
	array = new int*[size];
	for(int i = 0; i < size; i++) {
		array[i] = new int[size];
	}

	//POPULATES THE BOARD WITH INITIAL PIECES

	//section 1 of the board (red player)
	int i = 0, j = 0;
	while (i < ((size/2)-1)) {
		if (i%2 == 0) {
			while (j < size) {
				if (j%2 == 0) {
					array[i][j] = 3; j++;
				}
				else {
					array[i][j] = 0; j++;
				}
			}
			i++; j = 0;
		}
		else {
			while (j < size) {
				if (j%2 == 0) {
					array[i][j] = 0; j++;
				}
				else {
					array[i][j] = 3; j++;
				}
			}
			i++; j = 0;
		}
	}

	//section 2 of the board (no pieces initially)
	j = 0;
	while (i == (size/2) || i == ((size/2)-1)) {
		if (i%2 == 0) {
			while (j < size) {
				if (j%2 == 0) {
					array[i][j] = 10; j++;
				}
				else {
					array[i][j] = 0; j++;
				}
			}
			i++; j = 0;
		}
		else {
			while (j < size) {
				if (j%2 == 0) {
					array[i][j] = 0; j++;
				}
				else {
					array[i][j] = 10; j++;
				}
			}
			i++; j = 0;
		}
	}
	
	//section 3 of the board (white player)
	j = 0;
	while (i > (size/2) && i < size) {
		if (i%2 == 0) {
			while (j < size) {
				if (j%2 == 0) {
					array[i][j] = 1; j++;
				}
				else {
					array[i][j] = 0; j++;
				}
			}
			i++; j = 0;
		}
		else {
			while (j < size) {
				if (j%2 == 0) {
					array[i][j] = 0; j++;
				}
				else {
					array[i][j] = 1; j++;
				}
			}
			i++; j = 0;
		}
	}
	return array;
}

/*************************************************************************************
 * Function:
 * Description:
 * Parameters:
 * Pre-Conditions:
 * Post-Conditions:
 *************************************************************************************/

void print_board(int** board, int size) {
	cout << endl;
	for (int i = 0; i < size; i++) {
		cout << " " << char('A'+i) << " ";
	}

	cout << endl;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (board[i][j] == 0) {
				cout << "\u001b[48;5,0m \u001b[38;5;196m  \033[0m"; //blank white space
			}
			if (board[i][j] == 10) {
				cout << "\u001b[48;5;0m \u001b[38;5;15m  \033[0m"; //blank black space
			}
			if (board[i][j] == 1) {
				cout << "\u001b[48;5;0m \u001b[38;5;15m• \033[0m"; //black space reg white piece
			}
			if (board[i][j] == 2) {
				cout << "\u001b[48;5;0m \u001b[38;5;15m* \033[0m"; //black space kinged white piece
			}
			if (board[i][j] == 3) {
				cout << "\u001b[48;5;0m \u001b[38;5;196m• \033[0m"; //black space reg red piece
			}
			if (board[i][j] == 4) {
				cout << "\u001b[48;5;0m \u001b[38;5;196m* \033[0m"; //black space kinged red piece
			}
		}
		cout << " " << i+1 << endl;
	}
	cout << "\u001b[0m" << endl;

}

/*************************************************************************************
 * Function:
 * Description:
 * Parameters:
 * Pre-Conditions:
 * Post-Conditions:
 *************************************************************************************/

void player_move(int** board, int size) {
	int player = 1, from_num = 0, from_letter = 0, to_num = 0, to_letter = 0, commas = 0, store_i = 0;
	bool capture = false, validity = false;
	do {
		//GET THE MOVE FROM THE PLAYER
		char* move = new char;
		move = get_move();
		for (int i = 0; commas < 1; i++) {
			if (move[i] >= 'A' && move[i] <= 'Z' && commas == 0) {
				from_letter = int(move[i] - 'A');
			}
			if (move[i] >= 'A' && move[i] <= 'Z' && commas == 1) {
				to_letter = int(move[i] - 'A');
			}
			if (move[i] >= '0' && move[i] <= '9' && commas == 0) {
				from_num = int(move[i] - '0');
			}
			if (move[i] >= '0' && move[i] <= '9' && commas == 1) {
				to_num = int(move[i] - '0');
			}
			if (move[i] == ',') {
				commas++;
			}
			if (commas == 2) {
				store_i = i;
			}
		}
		
		validity = valid_move(board, player, from_num, from_letter, to_num, to_letter, capture);
		
		if (validity == true && store_i != (strlen(move))) {
			do {
				cout << "test " << endl;
				from_num = to_num; from_letter = to_letter;
				run_move(board, from_num, from_letter, to_num, to_letter, capture);
				commas = 0;
				for (int i = store_i; commas < 1; i++) {
					if (move[i] >= 'A' && move[i] <= 'Z') {
						to_letter = int(move[i] - 'A');
					}
					if (move[i] >= '0' && move[i] <= '9') {
						to_num = int(move[i] - '0');
					}
					if (move[i] == ',') {
						commas++;
					}
					store_i = i;
				}
			} while (store_i < strlen(move) && validity == true);
		}

	} while (check_win(board, size) == 0);

		print_board(board, size);
		
		if (player == 1) {
			player = 2;
		}
		if (player == 2) {
			player = 1;
		}

		cout << "YOUR TURN IS NOW OVER! IT IS NOW THE TURN OF PLAYER " << player << endl;

	//END GAME RESULT - POSSIBLY A DIFFERENT FUNCTION?
	if (check_win(board, size) == 1) {
		cout << endl << endl << endl << endl << "Player 1 wins the game!" << endl << endl << endl << endl;
		return;
	}
	if (check_win(board, size) == 2) {
		cout << endl << endl << endl << endl << "Player 2 wins the game!" << endl << endl << endl << endl;
		return;
	}
}

/*************************************************************************************
 * Function:
 * Description:
 * Parameters:
 * Pre-Conditions:
 * Post-Conditions:
 *************************************************************************************/

char* get_move() {
	char* input = new char;
	*input = '\0';

	cout << "Please enter a valid move! (Refer to README.txt for proper syntax on move input)" << endl << "Move - ";
	while(cin.peek() != '\n') {
		add_character(&input, cin.get());
	}
	cin.ignore();
	cin.clear();

	return input;
}

/*************************************************************************************
 * Function:
 * Description:
 * Parameters:
 * Pre-Conditions:
 * Post-Conditions:
 *************************************************************************************/

bool valid_move(int** board, int player, int from_row, int from_col, int to_row, int to_col, bool &capture) {
	int validity = 0; bool kinged = false;

	if (board[to_row][to_col] != 10) {
		return false;
	}

	if (player == 1) {
		if (board[from_row][from_col] == 1) {
			validity++; kinged = false;
		}
		if (board[from_row][from_col] == 2) {
			validity++; kinged = true;
		}
	}
	if (player == 2) {
		if (board[from_row][from_col] == 3) {
			validity++; kinged = false;
		}
		if (board[from_row][from_col] == 4) {
			validity++; kinged = true;
		}
	}
	if (kinged == true) {
		if (from_row == to_row+1 || from_row == to_row-1) {
			if (from_col == to_col+1 || from_col == to_col-1) {
				validity++;
			}
		}
	}
	if (kinged == false && player == 1) {
		if (from_row == to_row-1) {
			if (from_col == to_col+1 || from_col == to_col-1) {
				validity++;
			}
		}
	}
	if (kinged == false && player == 2) {
		if (from_row == to_row+1) {
			if (from_col == to_col+1 || from_col == to_col-1) {
				validity++;
			}
		}
	}

	if (validity == 2) {
		return true;
	}
	if (validity != 2) {
		return false;
	}
}

/*************************************************************************************
 * Function:
 * Description:
 * Parameters:
 * Pre-Conditions:
 * Post-Conditions:
 *************************************************************************************/

void run_move(int** board, int from_row, int from_col, int to_row, int to_col, bool capture) {
	int piece = 0;

	piece = board[from_row][from_col];
	board[from_row][from_col] = 10;
	board[to_row][to_col] = piece;
}

/*************************************************************************************
 * Function:
 * Description:
 * Parameters:
 * Pre-Conditions:
 * Post-Conditions:
 *************************************************************************************/

int check_win(int** board, int size) {
	int p1counter = 0, p2counter = 0;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (board[i][j] == 1 || board[i][j] == 2) {
				p1counter++;
			}
			if (board[i][j] == 3 || board[i][j] == 4) {
				p2counter++;
			}
		}
	}
	if (p1counter == 0) {
		return 2;
	}
	if (p2counter == 0) {
		return 1;
	}
	return 0;
}

/*************************************************************************************
 * Function:
 * Description:
 * Parameters:
 * Pre-Conditions:
 * Post-Conditions:
 *************************************************************************************/

void change_to_king(int** board, int size) {
	for (int i = 0; i == 0; i++) {
		for (int j = 0; j < size; j++) {
			if (board[i][j] == 1) {
				board[i][j] = 2;
			}
		}
	}
	for (int i = (size-1); i == (size-1); i++){
		for (int j = 0; j < size; j++) {
			if (board[i][j] == 3) {
				board[i][j] = 4;
			}
		}
	}
}
