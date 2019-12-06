#include "./state_facts.h"

/*
Function: create_states
Description: create the State array
Parameters: int
Return: state *
Pre-conditions: user inputs a number of states
Post-conditions: state_arr has been created
*/
state *create_states(int state_count) {
  state* states = new state[state_count];
  return states;
}
/*
Function: create_counties
Description: creates an array of Counties
Parameters: int
Return: county*
Pre-conditions:  the data about the number of counties has already been inputted into the respective State
Post-conditions: County* is created on the heap
*/
county *create_counties(int county_count) {
  county* counties = new county[county_count];
  return counties;
}
/*
Function: create_cities
Description: creates an array of cities
Parameters: int
Return: string*
Pre-conditions: the data about the number of cities has already been inputted into the respective County
Post-conditions: string* is created on the heap
*/
string *create_cities(int city_count) {
  return new string[city_count];
}

/*
Function: get_state_data
Description: gets the state information
Parameters: State* states, int state_count, ifstream& input
Return: none
Pre-conditions: state data has been collected
Post-conditions: county data is stored
*/
void get_state_data(state *states, int state_count, ifstream &input) {
  /*  string temp = "", state_name = "", population = "", counties = "";
  int state_population = 0, num_of_counties = 0; spaces = 0;
  for (int i = 0; i < state_count; i++) {
    getline(input, temp);
    for (int j = 0; j < temp.length(); j++) {
      if (temp[i] == ' ') {
        spaces++;
      }
      if (spaces == 0) {
        state_name.push_back(temp[i]);
      }
      if (spaces == 1) {
        population.push_back(temp[i]);
      }
      if (spaces == 2) {
        counties.push_back(temp[i]);
      }
    }
    state_population = atoi(population);
    num_of_counties = atoi(counties);


    //INSERT FUNCTION CALL FOR CREATING COUNTIES STRUCT ARRAY
    states[i].counties = create_counties(states[i].counties);
    //INSERT FUNCTION CALL FOR POPULATION COUNTIES STRUCT ARRAY
    //temp = "", state_name = "", population = "", counties = "";
  } */

  for (int i = 0; i < state_count; i++) {

    input >> states[i].name;
		input >> states[i].population;
		input >> states[i].counties;

    states[i].county_array = create_counties(states[i].counties); //This creates the array of counties within the state struct based off of the new data

    for (int j = 0; j < states[i].counties; j++) {
      get_county_data(states[i].county_array, j, input);

      states[i].county_array[j].city = create_cities(states[i].county_array[j].cities);
      for (int k = 0; k < states[i].county_array[j].cities; k++) {
        get_city_data(states[i].county_array[j].city, k, input);
      }

    }

  }
}
/*
Function: get_county data
Description: gets the county information
Parameters: county* counties, int county_num, ifstream& input
Return: none
Pre-conditions: state data has been collected
Post-conditions: county data is stored
*/
void get_county_data(county *counties, int county_num, ifstream &input) {

  input >> counties[county_num].name;
  input >> counties[county_num].population;
  input >> counties[county_num].avg_income;
  input >> counties[county_num].avg_house;
  input >> counties[county_num].cities;

}
/*
Function: get_city_data
Description: gets the names of the cities
Parameters: string* city, int city_num, ifstream& input
Return: none
Pre-conditions: county data has been collected
Post-conditions: city data is stored
*/
void get_city_data(string *city, int city_num, ifstream &input) {

  input >> city[city_num];

}

/*
Function: largest_state
Description: finds the state with the largest population
Parameters: state*, int
Return: void
Pre-conditions: user chooses this function
Post-conditions: largest pop is displayed
*/
void largest_state(state *states, int state_count) {
  int state_num = 0;
	int largest = states[0].population;

	for (int i = 0; i < state_count; i++) {
		if (states[i].population > largest) {
			largest = states[i].population;
			state_num = i;
		}
	}
	cout <<"The state with the largest population is " << states[state_num].name
	<< " which has a population of " << largest << "." << endl;
}
/*
Function: largest_county
Description: finds the county with the largest population
Parameters: state*, int
Return: void
Pre-conditions: user chooses this function
Post-conditions: largest county is displayed
*/
void largest_county(state *states, int state_count) {
  int state_num, county_num;
	int largest = states[0].county_array[0].population;

	for (int i = 0; i < state_count; i++) {
		for (int j = 0; j < states[i].counties; j++) {
			if (states[i].county_array[j].population > largest) {
				largest = states[i].county_array[j].population;
				county_num = j;
			 	state_num = i;
			}
		}
	}
	cout << "The county with the largest population is " <<
	states[state_num].county_array[county_num].name << " in " << states[state_num].name
	<< " with a population of " << largest << ".";
}

/*
Function: house_income_above_threshold
Description: finds the counties with an income above a user specified amount
Parameters: State*, int
Return: void
Pre-conditions: user chooses this function
Post-conditions: county names are displayed
*/
void house_income_above_threshold(state *states, int state_count) {
  float income;
	cout <<"Please enter an income value as a minimum to test against: ";
	cin >> income;

	for (int i = 0; i < state_count; i++) {
		cout << "In " << states[i].name;
		cout <<" the counties with an income above " << income << " are: " << endl;
		for (int j = 0; j < states[i].counties; j++) {
			if (states[i].county_array[j].avg_income >= income) {
				  cout << states[i].county_array[j].name << endl;
			}
		}
	}
}
/*
Function: avg_house_cost
Description: finds the average house cost in each state
Parameters: state*, int
Return: void
Pre-conditions: user chooses to have the house cost displayed
Post-conditions: displays house cost
*/
void avg_house_cost(state *states, int state_count) {
  float total = 0.0;
	float avg = 0.0;

	for (int i = 0; i < state_count; i++) {
		cout << "In " << states[i].name;
		for (int j = 0; j < states[i].counties; j++) {
			total += states[i].county_array[j].avg_house;
		}
		avg = total/states[i].counties;
		cout <<" the average house cost is " << avg << endl;
		total = 0.0;
		avg = 0.0;
	}
}

/*
Function: state_name_sort
Description: organizes the stats by name
Parameters: state*, int
Return: void
Pre-conditions: user chooses to have states organized by name, sort is created
Post-conditions: sort array is deleted, organized states are outputted
*/
void state_name_sort(state *states, int state_count) {
  state sort[state_count];
  state temp;

  for (int t = 0; t < state_count; t++) {
    sort[t] = states[t];
  }

  for (int a = 0; a < state_count; a++) {
    for (int i = 0; i < (state_count - 1); i++) {
      if (sort[i].name[0] >= sort[i+1].name[0]) {
        swap(sort[i], sort[i+1]);
      }
    }
  }

  //PRINTED TO THE SCREEN
  cout <<"The states organized alphabetically are: " << endl;
	for (int j = 0; j < state_count; j++) {
		cout << sort[j].name << endl;
	}

}
/*
Function: state_pop_sort
Description: sorts the states by population
Parameters: state*, int
Return: void
Pre-conditions: user chooses to have the states sorted by population
Post-conditions: sort is deleted, states are organized by pop
*/
void state_pop_sort(state *states, int state_count) {
  state sort[state_count];

	for (int t = 0; t < state_count; t++) {
		sort[t] = states[t];
	}

	for (int a = 0; a < state_count; a++) {
		for (int i = 0; i < (state_count - 1); i++) {
			if (sort[i].population < sort[i+1].population) {
				swap(sort[i], sort[i+1]);
			}
		}
	}

	cout <<"The states organized by population are: " << endl;
	for (int j = 0; j < state_count; j++) {
		cout << sort[j].name << endl;
	}

}

/*
Function: county_name_sort
Description: Sorts the names of the counties in each states
Parameters: state*, int
Return: void
Pre-conditions: user chooses to sort the county names, sort array is created
Post-conditions: sort array is deleted
*/
void county_name_sort(state *states, int state_count) {
  state sort[state_count];

	for (int k = 0; k < state_count; k++) {
		sort[k] = states[k];
	}


	for (int i = 0; i < state_count; i++) {
		for (int t = 0; t < sort[i].counties; t++) {
			for (int m = 0; m < (sort[i].counties - 1); m++) {
				if (sort[i].county_array[m].name[0] >= sort[i].county_array[m+1].name[0])
					swap(sort[i].county_array[m], sort[i].county_array[m+1]);
			}
		}
	}

	for (int a = 0; a < state_count; a++) {
		cout << "The counties in " << sort[a].name << " organized by name are: " << endl;
		for (int b = 0; b < states[a].counties; b++) {
			cout << sort[a].county_array[b].name << endl;
		}
	}
}
/*
Function: county_pop_sort
Description: Sorts the counties by population
Parameters: state*, int
Return: void
Pre-conditions: user chooses to have counties sorted, sort array is created
Post-conditions: sort array is deleted
*/
void county_pop_sort(state *states, int state_count) {
  state sort[state_count];

	for (int k = 0; k < state_count; k++) {
		sort[k] = states[k];
	}

	for (int i = 0; i < state_count; i++) {
		for (int t = 0; t < states[i].counties; t++) {
			for (int m = 0; m < (states[i].counties - 1); m++) {
				if (sort[i].county_array[m].population < sort[i].county_array[m+1].population)
					swap(sort[i].county_array[m], sort[i].county_array[m+1]);
			}
		}
	}

	for (int a = 0; a < state_count; a++) {
		cout << "The counties in " << sort[a].name << " organized by population are: " << endl;
		for (int b = 0; b < states[a].counties; b++) {
			cout << sort[a].county_array[b].name << endl;
		}
	}
}

/*
Function: display_stats
Description: displays all the data that was read in from the sheet
Parameters: state*, int
Return: void
Pre-conditions: user chooses this function
Post-conditions: data is displayed
*/
void display_stats(state* states, int state_count) {

	for (int i = 0; i < state_count; i++) {
	cout << states[i].name << " ";
	cout << states[i].population << " ";
	cout << states[i].counties << endl;
		for (int j = 0; j < states[i].counties; j++) {
			cout << states[i].county_array[j].name << " ";
			cout << states[i].county_array[j].population<< " ";
			cout << states[i].county_array[j].avg_income << " ";
			cout << states[i].county_array[j].avg_house << " ";
			cout << states[i].county_array[j].cities << " ";

			for (int k = 0; k < states[i].county_array[j].cities; k++) {
					cout << states[i].county_array[j].city[k] << " ";
				}
			cout << endl;
		}
	}
}
/*
Function: print_info
Description: print info
Parameters: state* states, int state_count
Return: none
Pre-conditions: user chooses this function
Post-conditions: information is printed
*/
void print_info(state* states, int state_count) {

	int repeat = 1;

	while (repeat == 1) {

		int choice;

		cout << endl;
		cout << "What information would you like to find out? Select: " << endl;
		cout << "1 - the state with the largest population" << endl;
		cout << "2 - the county with the largest population" << endl;
		cout << "3 - the counties with an income above a specfic amount" << endl;
		cout << "4 - the average household cost for all counties in each state" << endl;
		cout << "5 - the states in sorted order by name" << endl;
		cout << "6 - the states in sorted order by population" << endl;
		cout << "7 - the counties within states sorted by name" << endl;
		cout << "8 - the counties within states sorted by population" << endl;
		cout << "9 - display all state statistics" << endl;
		cout << "0 - close menu" << endl;

		cin >> choice;

		if (choice == 0) {repeat = 0;}
		if (choice == 1) {largest_state(states, state_count);}
		if (choice == 2) {largest_county(states, state_count);}
		if (choice == 3) {house_income_above_threshold(states, state_count);}
		if (choice == 4) {avg_house_cost(states, state_count);}
		if (choice == 5) {state_name_sort(states, state_count);}
		if (choice == 6) {state_pop_sort(states, state_count);}
		if (choice == 7) {county_name_sort(states, state_count);}
		if (choice == 8) {county_pop_sort(states, state_count);}
		if (choice == 9) {display_stats(states, state_count);}

    cout << endl;

	}

}


bool is_valid_arguments(char *info[], int argc) {
  int count = 0;

	for (int j = 1; j < argc; j += 2) {
		if (info[j][1] == 's' || info[j][1] == 'f') {
			count++;
		}
	}

	for (int i = 0; i < argc; i++) {
		if (info[i][0] == ' ')
			return false;
	}

	if (count == 2)
		return true;
	else
		return false;
}

void get_new_data(int* num_ptr, string* file_ptr) {

	cout << "Enter a new number of states: " << endl;
	cin >> *num_ptr;
	cout << "Enter a new file name: " << endl;
	cin>> *file_ptr;

}

bool good_file(char* info[], int argc, string* file_ptr) {

	string file;

	for (int a = 0; a < argc; a++) {
		if (info[a][1] == 'f') {
			file = info[a+1];
			if (file == "states.txt" || file == "states2.txt") {
				*file_ptr = info[a+1];
				return true;
			}
		}
	}
	return false;
}

bool good_int(char* info[], int argc, int* num_ptr) {

	for (int a = 0; a < argc; a++) {
		if (info[a][1] == 's') {
			if (info[a+1][0] >= 48 && info[a+1][0] <= 57) {
				*num_ptr = atoi(info[a+1]);
				return true;
			}
		}
	}
	return false;
}

void get_data(int argc, char* info[], int* num_ptr, string* file_ptr) {

	if (is_valid_arguments(info, argc) == false) {
		cout << "Sorry, you did not supply inputs in the -s, -f format." << endl;
		exit(0);
	}

	if (good_int(info, argc, num_ptr) == false) {
		cout <<"Sorry, you did not enter a valid number of states. Enter a positive integer." << endl;
		cin >> *num_ptr;
	}

	if (good_file(info, argc, file_ptr) == false) {
		cout <<"Sorry, you did not enter a valid file name. Enter a new one." << endl;
		cin >> *file_ptr;
	}

}

/*
Function: delete_info
Description: deletes the State array off of the heap
Parameters: states
Return: void
Pre-conditions: the user chooses to either exit the program or input new info
Post-conditions: the allocated memory is cleared
*/
void delete_info(state *states, int state_count) {
  for (int i = 0; i < state_count; i++) {

		for (int j = 0; j < states[i].counties; j++) {
			delete[] states[i].county_array[j].city;
		}

		delete[] states[i].county_array;

	}

	delete[] states;

}
