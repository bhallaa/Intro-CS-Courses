#include <iostream>

using namespace std;

class Property {
  public:
    int num_tenants;
    int property_value;
    Property(int, int);
    bool operator>(const Property&);
    bool operator<(const Property&);
};
