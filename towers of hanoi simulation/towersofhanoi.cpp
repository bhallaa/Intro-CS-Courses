#include <iostream>
#include <cmath>

using namespace std;

void towers(int disks, int b[3][3], int from_col, int to_col, int spare);
void print_array(int b[3][3]);
void move(int disks, int b[3][3], int from_col, int to_col);


int main() {

	int b[3][3];

	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 3; j++) {
			b[i][j] = 0;
		}
	}
	
	for(int i = 0; i < 3; i++) {
		b[i][0] = i+1;
	}
	
	print_array(b);

	towers(3, b, 0, 2, 1);

	return 0;
}


void towers(int disks, int b[3][3], int from_col, int to_col, int spare) {
	if(disks >= 1) {
		towers(disks-1, b, from_col, spare, to_col);
		move(disks, b, from_col, to_col);
		print_array(b);
		towers(disks-1, b, spare, to_col, from_col);
	}
}

void print_array(int b[3][3]) {
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 3; j++) {
			cout << b[i][j] << " ";
		}
		cout << endl;
	}
	cout << "------" << endl;
}

void move(int disks, int b[3][3], int from_col, int to_col){
	int temp = 0;
	for(int i = 0; i < 3; i++) {
		//to find the top disk, look for the first non-zero number (this is in the from_col)
		if(b[i][from_col] != 0) {
			temp = b[i][from_col]; //so that you can grab the value stored in the from_col to move into the to_col
			b[i][from_col] = 0; //reset the position it was grabbed from
			break;
		}
	}
	for(int i = 0; i < 3; i++) {
		if(b[i][to_col] != 0) {
			b[i-1][to_col] = temp;
			break;
		}
		else if (i == 2) {
			b[i][to_col] = temp;
			break;
		}
	}
}
