#ifndef GENETIC_HPP
#define GENETIC_HPP

#include <vector>
#include "./Individual.hpp"
#include <algorithm>

class Genetic
{
private:
  std::vector<Individual> population;
  std::vector<int> for_sort;
  std::vector<int> target;
  float mutation_chance;
  int num_individuos;
  int cant_cruce;

public:
  Genetic(std::vector<int> &, float, int, int);
  std::vector<Individual> sorted();
  std::vector<Individual> selection();
  std::vector<Individual> reproduction();
  std::vector<Individual> mutation();
  std::vector<int> cruzar(std::vector<int> &, std::vector<int> &, std::vector<int> &);
  std::vector<int> vec_menor(std::vector<int> &, std::vector<int> &);
  int random_pos(int);
  int key_bett();
  bool is_sorted_();
  void print_pop();
  void iniciar();
};

#endif
