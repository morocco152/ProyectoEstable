#include "./includes/Genetic.hpp"
#include "./GenPoblacion.cpp"
#include "./Individual.cpp"

Genetic::Genetic(std::vector<int> &_arr, float mt_ch, int nm_ind, int ct_cr)
{
  for_sort = _arr;
  target = _arr;
  num_individuos = nm_ind;
  std::sort(target.begin(), target.end());
  // Aqui me genero el error por eso quitamos los tipos genericos
  GenPoblacion p = GenPoblacion(for_sort, num_individuos);
  population = p.Generar();
  cant_cruce = ct_cr;
}

std::vector<Individual> Genetic::selection()
{
  puts("Seleccionado");
  std::sort(population.begin(), population.end());
  return population;
}

std::vector<Individual> Genetic::reproduction()
{
  puts("Reproduciendo");
  std::vector<Individual> better;

  for (int i = key_bett(); i < this->population.size(); ++i)
    better.push_back(population[i]);

  int _tt = better.size();
  for (int i = 0; i < _tt; ++i)
  {
    std::vector<int> padre = better[random_pos(_tt)].getArray();
    std::vector<int> madre = better[random_pos(_tt)].getArray();
    std::vector<int> _new = vec_menor(padre, madre);
    population[i].set_array(_new);

    madre.clear();
    padre.clear();
    _new.clear();
  }

  better.clear();
  return population;
}

std::vector<int> Genetic::vec_menor(std::vector<int> &_p, std::vector<int> &_m)
{
  std::vector<int> neww;
  for (int i = 0; i < _p.size(); ++i)
  {
    if (_p[i] < _m[i])
    {
      if ((std::find(neww.begin(), neww.end(), _p[i]) != neww.end()) == false)
        neww.push_back(_p[i]);
    }
    if (_p[i] > _m[i])
    {
      if ((std::find(neww.begin(), neww.end(), _p[i]) != neww.end()) == false)
        neww.push_back(_p[i]);
    }
    else if (_m[i] > _p[i])
    {
      if ((std::find(neww.begin(), neww.end(), _m[i]) != neww.end()) == false)
        neww.push_back(_m[i]);
    }
    else if (_p[i] == _m[i])
    {
      if ((std::find(neww.begin(), neww.end(), _p[i]) != neww.end()) == false)
        neww.push_back(_p[i]);
    }
  }

  return neww;
}

int Genetic::random_pos(int _size)
{
  int position_rand;
  position_rand = rand() % _size;
  return position_rand;
}

int Genetic::key_bett()
{
  int init = population.size() - cant_cruce;
  return init;
}

bool Genetic::is_sorted_()
{
  return false;
}

void Genetic::print_pop()
{
  for (int i = 0; i < population.size(); ++i)
    population[i].print();
  std::cout << "\n";
}

void Genetic::iniciar()
{
  for (auto i = 0; i < 3; i++)
  {
    print_pop();
    selection();
    print_pop();
    reproduction();
  }

  selection();
  population[population.size() - 1].mutar(2);
}

//random fx

template <typename T>
void printvec(std::vector<T> &_a)
{
  for (auto i : _a)
    std::cout << i << " ";
  std::cout << "\t";
}
