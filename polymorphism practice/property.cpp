#include "./property.h"

Property::Property(int num_tenants, int property_value) {
    this->num_tenants = num_tenants;
    this->property_value = property_value;
}

bool Property::operator>(const Property& p2) {
  if ( (num_tenants > p2.num_tenants) && (property_value > p2.property_value) ) { return true; }
  return false;
}

bool Property::operator<(const Property& p2) {
  if ( (num_tenants < p2.num_tenants) && (property_value < p2.property_value) ) { return true; }
  return false;
}
