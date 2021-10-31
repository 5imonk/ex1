#pragma once
#include <cstddef>
#include <string>
#include <iostream>
#include <sstream>

class City {
  int population;
  std::string name, country, continent;
public:
  City ();
  City (int, std::string);
  City (int, std::string, std::string, std::string);
  std::string get_continent();
  int get_population() const;
  std::string get_name() const;
  void print();
};

City::City (int a, std::string s) {
  population = a;
  name = s;
}

City::City (int  a, std::string s, std::string t, std::string u) {
  population = a;
  name = s;
  country = t;
  continent = u;
}

std::string City::get_continent() {
  return continent;
}

int City::get_population() const {
  return population;
}

std::string City::get_name() const {
  return name;
}

void City::print() {
  std::cout << name + '\n' << population << '\n';
}
