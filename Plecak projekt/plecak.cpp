#include <iostream>
#include <vector>
#include<string>
#include<fstream>
#include <iomanip>
#include "plecak.h"
#include <random>
#include <sstream>


bool Load_parameters(Params& param, const int& Liczba_parametrow, char* parametry[])
{
	std::vector <std::string> temp;
	if (Liczba_parametrow != 11)
	{
		std::cerr << "Podano bledna liczbe parametrow! Prosze podac 5 parametrow wraz z ich przelacznikami w nastepujacy sposob:\n"
			"-i (text.txt) | sciezka do pliku z danymi o przedmiotach\n"
			"-o (text.txt) | sciezka do pliku z odpowiedziami\n"
			"-p (liczba calkowita dodatnia) | pojemnosc plecaka\n"
			"-g (liczba calkowita dodatnia) | ilosc pokolen\n"
			"-n (liczba calkowita dodatnia) | liczba odnosnikow w pokoleniu\n";

		return false;
	}
	for (int i = 0; i < Liczba_parametrow; i++)
		temp.push_back(std::string(parametry[i]));

	//pierwsza wartosc argv to "main.cpp"
	for (int i = 0; i < temp.size(); i++)
	{
		if (temp[i] == "-i")
			param.itemsFile = parametry[i + 1];
		else if (temp[i] == "-o")
			param.solutionFile = parametry[i + 1];
		else if (temp[i] == "-p")
		{
			std::istringstream converted(parametry[i + 1]);
			converted >> param.capacity;
		}
		else if (temp[i] == "-g")
		{
			std::istringstream converted(parametry[i + 1]);
			converted >> param.generations;
		}
		else if (temp[i] == "-n")
		{
			std::istringstream converted(parametry[i + 1]);
			converted >> param.amountOfSpecimens;
		}

	}
	return true;
}

void move_items(std::list<Item>& items, std::ifstream& input)
{
	Item item;


	while (input >> item.name >> item.weight >> item.price)
	{

		items.push_back(item);

	}

}

void to_file(Backpack& backpack, std::ofstream& output_o, Params& params)
{
	output_o << std::setw(20) << std::left << "NAZWA" << std::setw(20) << "WAGA" << std::setw(20) << "CENA" << std::endl;
	for (const auto& item : backpack.items)
	{
		output_o << std::setw(20) << std::left << item.name << std::setw(20) << std::left << item.weight << std::setw(20) << std::left << item.price << std::right << std::endl;
	}

	output_o << std::setw(20) << std::left << "POJEMNOSC PLECAKA: " << params.capacity << "\n";
	output_o << std::setw(20) << std::left << "ILOSC POKOLEN: " << params.generations << "\n";
	output_o << std::setw(20) << std::left << "ILOSC OSOBNIKOW W POKOLENIU: " << params.amountOfSpecimens << "\n";
}

std::list<Item> findFittingItems(std::list<Item>& items, float backpackCapacity)
{
	std::list<Item> itemsThatFit;
	for (auto item : items)
	{
		if (item.weight <= backpackCapacity)
			itemsThatFit.push_back(item);
	}
	return itemsThatFit;
}

Item drawItem(std::list<Item>& items)
{
	int index = 0;
	std::random_device device;
	std::default_random_engine generator(device());
	std::uniform_int_distribution<int> distribution(0, items.size() - 1);
	int drawIndex = distribution(generator);
	for (Item item : items)
	{
		if (index == drawIndex)
			return item;
		index++;
	}
}

std::vector<Backpack> generateInitialBackpacks(std::list<Item>& items, int amountOfBackpacks, float backpackMaxWeight)
{
	std::vector<Backpack> initialBackpacks;
	std::list<Item> itemsThatWillFit = findFittingItems(items, backpackMaxWeight);

	for (int i = 0; i < amountOfBackpacks; i++)
	{
		Backpack temporaryBackpack;
		std::list<Item> itemsThatFitNow = itemsThatWillFit;
		while (itemsThatFitNow.size() != 0)
		{
			Item drawnItem = drawItem(itemsThatFitNow);
			temporaryBackpack.items.push_back(drawnItem);
			temporaryBackpack.capacity += drawnItem.weight;
			temporaryBackpack.value += drawnItem.price;
			itemsThatFitNow = findFittingItems(itemsThatFitNow, backpackMaxWeight - temporaryBackpack.capacity);
		}
		initialBackpacks.push_back(temporaryBackpack);
	}
	return initialBackpacks;
}


Backpack mixBackpacks(Backpack& first, Backpack& second, float backpackCapacity)
{
	Backpack newBackpack;
	bool finihMixing = false;

	while (!finihMixing)
	{
		std::list<Item> itemsThatFitFromFirst = findFittingItems(first.items, backpackCapacity - newBackpack.capacity);
		std::list<Item> itemsThatFitFromSecond = findFittingItems(second.items, backpackCapacity - newBackpack.capacity);

		//sproboj jeszcze raz paraz
		Item firstItem, secondItem;
		if (itemsThatFitFromFirst.size() == 0 and itemsThatFitFromSecond.size() == 0)
		{
			finihMixing = true;
			break;
		}

		if (itemsThatFitFromFirst.size() > 0)
		{
			firstItem = drawItem(itemsThatFitFromFirst);
		}

		if (itemsThatFitFromSecond.size() > 0)
		{
			secondItem = drawItem(itemsThatFitFromSecond);
		}

		if (firstItem.price > secondItem.price)
		{
			newBackpack.items.push_back(firstItem);
			newBackpack.capacity += firstItem.weight;
			newBackpack.value += firstItem.price;
		}
		else
		{
			newBackpack.items.push_back(secondItem);
			newBackpack.capacity += secondItem.weight;
			newBackpack.value += secondItem.price;
		}
	}
	return newBackpack;
}

Backpack findBest(std::vector<Backpack>& generationToSearch)
{
	//max
	Backpack best = generationToSearch[0];
	for (int i = 1; i < generationToSearch.size(); i++)
	{
		if (best.value < generationToSearch[i].value)
			best = generationToSearch[i];
	}
	return best;
}

void createGeneration(std::vector<Backpack>& generationToMix, float backpackCapacity)
{
	std::vector<Backpack> newGeneration;
	for (int i = 0; i < generationToMix.size() - 1; i++)
	{
		Backpack mixed = mixBackpacks(generationToMix[i], generationToMix[i + 1], backpackCapacity);
		newGeneration.push_back(mixed);
	}
	//najlepszy z poprzedniego pokolenia
	newGeneration.push_back(findBest(generationToMix));
	generationToMix = newGeneration;
}

Backpack findSolution(std::vector<Backpack>& generation, int generations, float backpackCapacity)
{
	for (int i = 0; i < generations; i++)
	{
		createGeneration(generation, backpackCapacity);
	}
	return findBest(generation);

}