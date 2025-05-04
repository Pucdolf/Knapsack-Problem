#include <iostream>
#include<fstream>
#include<list>

#include"plecak.h"

int main(int argc, char* argv[])
{
	Params param;
	Backpack backpack;
	std::list<Item> listOfItems;

	if (Load_parameters(param, argc, argv))
	{

		std::ifstream input_i(param.itemsFile);
		std::ofstream output_o(param.solutionFile);

		if (!input_i)
		{
			std::cerr << "Blad! Nie udalao sie poprawnie otworzyc pliku z danymi plecaka! \n ";

			return -1;
		}

		move_items(listOfItems, input_i);

		std::vector<Backpack>initialGeneration = generateInitialBackpacks(listOfItems, param.amountOfSpecimens, param.capacity);
		backpack = findSolution(initialGeneration, param.generations, param.capacity);

		to_file(backpack, output_o, param);

	}
	else
		return -1;

}

