#include "./state_facts.h"

/* -------------------------------------------------------------------------------------------------------
Program: State Facts
Author: Arjun Bhalla
Date: 04/15/2018
Description: A program that reads in data about states and their respective counties and provides analysis of
the information.
Input: User inputs the number of states and the file that they want to program to read.
Output: The analysis of the information.
---------------------------------------------------------------------------------------------------------- */

int main (int argc, char* info[]) {
  int repeat = 1;

  int state_count;
  int* num_ptr = &state_count;
  string file; // a variable for the name of the file
  string* file_ptr = &file;

  get_data(argc, info, num_ptr, file_ptr); // get the data on number of states and the file

  cout << "File: " << file << endl;
  cout << "Number of states: " << state_count << endl;

  while (repeat == 1) {

    ifstream input;
    input.open(file.c_str());
    while (input.fail()) {
      cout <<"Not a valid file type" << endl;
    }

    state* states = create_states(state_count);
    get_state_data(states, state_count, input);

    /*int choice = 0;
    cout << "Would you like to have the information printed to the screen or be put into a file?" << endl;
    cout << "0 for printed on screen, 1 for printed into a file" << endl;
    cin >> choice;
    */

    print_info(states, state_count);
    delete_info(states, state_count);

    input.close();

    cout << "Would you like to input a new number of states and file?" << endl;
    cout << "0 for No, 1 for Yes" << endl;
    cin >> repeat;

    if (repeat == 0)
      exit(0);
    if (repeat == 1)
      get_new_data(num_ptr, file_ptr);
      cout << "File: " << file << endl;
      cout << "Number of states: " << state_count << endl;

  }

  return 0;
}
