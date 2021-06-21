#ifndef INDIVIDUAL_HPP
#define INDIVIDUAL_HPP
#include <vector>
#include <iostream>
// #include <bits/stdc++.h>

class Individual
{
private:
  std::vector<int> array;
  std::vector<int> copy_array;
  std::vector<bool> estado;
  int fit_;

public:
  Individual(std::vector<int> &);
  std::vector<int> getArray();
  bool operator<(Individual &) const;
  void set_array(std::vector<int> &);
  void suffle();
  int get_len();
  void set_fitness(int);
  int get_fitness();
  void fitness();
  void print();
  void mutar(int);
  void l_suffle();
  void exe();
};
#endif
