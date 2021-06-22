#include "./classes/Genetic.cpp"
#include <bits/stdc++.h>

int main(int argc, char const *argv[])
{
    srand(time(NULL));
    std::cout << "Raa vs.2!" << std::endl;

    //Incializar
    std::vector<int> array = {6, 5, 1, 2, 4, 3, 0, 7};
    Genetic test = Genetic(array, 0.3, 10, 3);
    test.iniciar();

    //Cleaning
    array.clear();
    return 0;
}
