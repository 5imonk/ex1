#include <city.hpp>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <numeric>
#include <iomanip>
#include <map>

#include <cstddef>
#include <string>

#include <stdio.h>  // defines FILENAME_MAX
#include <unistd.h> // for getcwd()

std::string getcwd_str();
std::map<std::string, std::vector<City>> read_file(std::string);

std::string largest_city(std::map<std::string, std::vector<City>>, const std::string);
std::string largest_city(std::map<std::string, std::vector<City>>);
double average_population(std::map<std::string, std::vector<City>>);
double average_population(std::map<std::string, std::vector<City>>, const std::string);

double avg(std::vector<int>);

int main (int argc, char *argv[]) {

  if(argc < 3) {
    std::cout << "Error: expecting 2 input files" << std::endl;
    return EXIT_FAILURE;
  }

  std::map<int, std::map<std::string, std::vector<City>>> Year_Cities;
  std::vector<std::string> continents;
  int years[2];

  for (int i=0; i<2; i++) {
    int year;
    std::string inp_file{argv[i+1]};
    std::cout << inp_file << '\n';
    year = std::stoi(inp_file.substr(inp_file.size() - 8));
    // std::cout << year << '\n';
    years[i] = year;

    std::map< std::string, std::vector<City> > Cities(read_file(inp_file));

    if (i<1) {
      for(auto const& c: Cities) {
        continents.push_back(c.first);
      }
    }
    Year_Cities[year] = Cities;
  }

  std::ofstream outp_file, outp_file2;

  outp_file.open (getcwd_str() + "/leveling_analysis_1.txt");
  outp_file << "Year,AveragePopulation,LargestCity";
  outp_file << std::fixed << std::setprecision(0);

  outp_file2.open (getcwd_str() + "/leveling_analysis_2.txt");
  outp_file2 << "Year,Continent,AveragePopulation,LargestCity";
  outp_file2 << std::fixed << std::setprecision(0);
  for(auto const& [year, Cities]: Year_Cities) {
    //leveling_analysis_1
    outp_file << "\n" << year << ",";
    outp_file << average_population(Cities) << ",";
    outp_file << largest_city(Cities);

    /*
    //leveling_analysis_2
    for (std::vector<std::string>::iterator t=continents.begin(); t!=continents.end(); ++t) {
        outp_file2 << "\n" << year << "," << *t << ",";
        outp_file2 << average_population(Cities, *t) << ",";
        outp_file2 << largest_city(Cities, *t);
      }
      */
      for (auto const& t: continents) {
        outp_file2 << "\n" << year << "," << t << ",";
        outp_file2 << average_population(Cities, t) << ",";
        outp_file2 << largest_city(Cities, t);
      }
  }

  outp_file.close();
  outp_file2.close();

  std::ofstream outp_file3;
  outp_file3.open (getcwd_str() + "/leveling_analysis_3.txt");
  outp_file3 << "CityName,Continent,Population" << years[0] << ",Popluation" << years[1] << ",AbsolutePopulationChange,RelativePopulationChange";

  std::map<int, std::map<std::string, int>> population;
  std::map<std::string, std::string> city_continents;

  int y0{years[0]}, y1{years[1]};

  for (auto const& Cities: Year_Cities) {
    for (auto const& contCities: Cities.second) {
      for (auto const& c: contCities.second) {
        population[Cities.first][c.get_name()] = c.get_population();
        if (Cities.first==y0) {
          city_continents[c.get_name()] = contCities.first;
        }
      }
    }
  }

  for (auto const& c: city_continents) {
    int pop0 = population[y0][c.first];
    int pop1 = population[y1][c.first];
    int abs_change = pop1 - pop0;
    double rel_change = (double(abs_change)) /( double(pop0)) * 100.0;

    outp_file3 << std::fixed << std::setprecision(0);
    outp_file3 << "\n" << c.first << "," << c.second << "," << pop0 << "," << pop1 << "," << abs_change << ",";
    outp_file3 << std::fixed << std::setprecision(2);
    outp_file3 << rel_change << "%";
  }

  outp_file3.close();

  return 0;
}

std::map<std::string, std::vector<City>> read_file(std::string file_name) {
  std::map<std::string, std::vector<City>> Cities;
  //std::vector<std::string> continents;

  int population;
  std::string name, country, continent, population_str;
  std::ifstream is (getcwd_str() + "/" + file_name);

  if (is.is_open()) {
    while (std::getline(is, name, ',') && std::getline(is, country, ',') && std::getline(is, continent, ',') && std::getline(is, population_str)) {
      /*
      if (std::find(continents.begin(), continents.end(), continent) != continents.end())
      {
        continents.push_back (continent);
      }
      */
      std::stringstream population_(population_str);
      population_ >> population;
      Cities[continent].push_back (City(population, name));
    }
    is.close();
  }
  else {
    std::cout << "Unable to open file";
  }
  return Cities;
}

std::string largest_city(std::map<std::string, std::vector<City>> allCities, const std::string continent) {
  std::string large_city;
  int large_population{-1};

  std::vector<City> Cities (allCities[continent]);
  int s(Cities.size());
  for (int i=0; i < s; i++) {
    if (Cities.at(i).get_population() > large_population) {
      large_population = Cities.at(i).get_population();
      large_city = Cities.at(i).get_name();
    }
  }
  return large_city;
}

std::string largest_city(std::map<std::string, std::vector<City>> allCities) {

  std::string large_city;
  int large_population{-1};

  for (auto const & contCities: allCities) {
    for (auto const & city: contCities.second) {
      if (city.get_population() > large_population) {
        large_population = city.get_population();
        large_city = city.get_name();
      }
    }
  }
  return large_city;
}

double avg1(std::vector<int> const& v) {
    return 1.0 * std::accumulate(v.begin(), v.end(), 0LL) / v.size();
}

double average_population(std::map<std::string, std::vector<City>> allCities, const std::string continent) {
  std::vector<int> population_vector;

  for (auto const& city: allCities[continent]){
    population_vector.push_back (city.get_population());
  }
  return avg1(population_vector);
}

double average_population(std::map<std::string, std::vector<City>> allCities) {
  std::vector<int> population_vector;

  for (auto const& contCities: allCities){
    for (auto const & city: contCities.second) {
      population_vector.push_back (city.get_population());
    }
  }
  return avg1(population_vector);
}

std::string getcwd_str() {
  std::string cwd("\0",FILENAME_MAX+1);
  return getcwd(&cwd[0],cwd.capacity());
}
