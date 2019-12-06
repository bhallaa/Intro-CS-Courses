#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <cstring>

using namespace std;

struct state {
  string name; //Name of state
  int population; //Total population of state
  int counties; //Number of counties in state
  struct county *county_array; //Array of counties
};

struct county {
  string name; //Name of county
  int population; //Total population of county
  float avg_income; //Average household income
  float avg_house; //Average household price
  int cities; //Number of cities in county
  string* city; //Array of city names in county
};

bool is_valid_arguments(char *[], int);
state *create_states(int);
void get_state_data(state *, int, ifstream &);
county *create_counties(int);
void get_county_data(county *, int, ifstream &);
void delete_info(state*, int);

string *create_cities(int);
void get_city_data(string *, int, ifstream &);

void largest_state(state *, int);
void largest_county(state *, int);

void house_income_above_threshold(state *, int);
void avg_house_cost(state *, int);

void state_name_sort(state *, int);
void state_pop_sort(state *, int);

void county_name_sort(state *, int);
void county_pop_sort(state *, int);

void display_stats(state *, int);
void print_info(state *, int);

void get_new_data(int *, string *);
bool good_file(char* [], int, string*);
bool good_int(char* [], int, int*);
void get_data(int, char* [], int*, string*);
