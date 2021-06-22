#include "./includes/Individual.hpp"

Individual::Individual(std::vector<int> &_array)
{
  array = _array;
  copy_array = _array;
  std::sort(copy_array.begin(), copy_array.end());
  fit_ = 0;
  estado.resize(array.size());
}

std::vector<int> Individual::getArray()
{
  return array;
}

bool Individual::operator<(Individual &_a) const
{
  return (fit_ < _a.fit_);
}

void Individual::set_array(std::vector<int> &_new_a)
{
  array = _new_a;
  fitness();
}

int Individual::get_len()
{
  return array.size();
}

void Individual::set_fitness(int _s_fit)
{
  fit_ = _s_fit;
}

int Individual::get_fitness()
{
  return fit_;
}

void Individual::fitness()
{
  suffle();
  int fit = 0;
  for (int i = 0; i < get_len(); ++i)
  {
    if (array[i] == copy_array[i])
      ++fit;
  }
  set_fitness(fit);
}

void Individual::suffle()
{
  int tmp, rand_idx;
  for (int i = 0; i < get_len(); ++i)
  {
    tmp = array[i];
    rand_idx = rand() % get_len();

    array[i] = array[rand_idx];
    array[rand_idx] = tmp;
  }
}

void Individual::print()
{
  for (auto i : array)
    std::cout << i << " ";
  std::cout << "fit:" << get_fitness();
  std::cout << "\n";
}

/// Bust_ imple
void Individual::mutar(int genes)
{
  std::cout << "Mutando"
            << "\n";
  int mejora = get_fitness() + genes;
  while (get_fitness() <= mejora)
  {
    l_suffle();
    print();
  }
}

void Individual::l_suffle()
{
  int tmp, rand_idx;
  std::vector<int> per;
  per.resize(array.size() - get_fitness());

  int j = 0;
  for (int i = 0; i < get_len(); i++)
  {
    if (estado[i] == false)
    {
      per[j] = array[i];
      j++;
    }
  }

  for (int i = 0; i < per.size(); ++i)
  {
    tmp = per[i];
    rand_idx = rand() % per.size();

    per[i] = per[rand_idx];
    per[rand_idx] = tmp;
  }

  j = 0;
  for (int i = 0; i < get_len(); i++)
  {
    if (estado[i] == false)
    {
      array[i] = per[j];
      j++;
    }
  }

  int fit = 0;
  for (int i = 0; i < get_len(); ++i)
  {
    if (array[i] == copy_array[i])
    {
      ++fit;
      estado[i] = true;
    }
  }
  set_fitness(fit);
}
//Bust imple

void Individual::exe()
{
  suffle();
  fitness();
}
