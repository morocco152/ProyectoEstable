#include "./includes/GenPoblacion.hpp"

GenPoblacion::GenPoblacion(std::vector<int> &_pas, int _t)
{
  array = _pas;
  num_ind = _t;
}

int GenPoblacion::get_num()
{
  return num_ind;
}

std::vector<Individual> GenPoblacion::Generar()
{
  std::vector<Individual> new_pobl;
  for (int i = 0; i < get_num(); ++i)
  {
    Individual a = Individual(array);
    a.exe();
    new_pobl.push_back(a);
  }
  return new_pobl;
}