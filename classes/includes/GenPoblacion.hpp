#ifndef GENPOBLACION_HPP
#define GENPOBLACION_HPP
#include <vector>
#include "./Individual.hpp"
class GenPoblacion
{
private:
  std::vector<int> array;
  int num_ind;

public:
  GenPoblacion(std::vector<int> &, int);
  int get_num();
  std::vector<Individual> Generar();
};
#endif
