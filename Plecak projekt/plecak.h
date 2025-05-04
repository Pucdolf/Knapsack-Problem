#ifndef PLECAK_H
#define PLECAK_H

#include <iostream>
#include <vector>
#include<string>
#include <list>

/** \struct Params
* \brief Struktura przyjmujaca wprowadzone dane - odpowiednie dla przelacznikow nazwy plikow i wartosci - do programu.
* \param itemsFile Zmienna typu string przyjmujaca nazwe pliku z przedmiotami.
* \param solutionFile Zmienna typu string przyjmujaca nazwe pliku z zapisem wyniku.
* \param float Zmienna typu float przyjmujaca pojemnosc plecaka.
* \param generations Zmienna typu int przyjmujaca ilosc generacji.
* \param amountOfSpecimens Zmienna typu int przyjmujaca ilosc osobnikow w pokoleniu.
*/
struct Params
{
	std::string itemsFile = "";
	std::string solutionFile = "";
	float capacity = 0;
	int generations = 0;
	int amountOfSpecimens = 0;
};

/** \struct Item
 *\brief struktura przechowujaca dane z pliku powiazanego z przelacznikiem -i.
* \param name Zmienna typu string przyjmujaca nazwe przedmiotu.
* \param weight Zmienna typu float przyjmujaca wage przedmiotu.
 *\param price Zmienna typu float przyjmujaca cene przedmiotu.
 */
struct Item
{
	std::string name = "";
	float weight = 0;
	float price = 0;
};


/** \struct Backpack
 * \brief Struktura pelniaca role plecaka z przedmiotami
 * \param items Lista typu Items przechowujaca przedmioty znajdujace sie w plecaku.
 * \param capacity Zmienna float okreslajaca pojemnosc plecaka.
 * \param value Zmienna int okreslajaca wartosc plecaka.
 */
struct Backpack
{
	std::list<Item> items = std::list<Item>();
	float capacity = 0;
	int value = 0;
};


/**
* \brief Funkcja sprawujaca kontrole nad wlasciwym dostarczeniem przelacznikow do programu.
* \param param Zmienna struktury pozwalajaca na poslugiwanie sie plikami i wartosciami, ktore byly dostarczone przez przelaczniki.
* \param Liczba_parametrow Zmienna przyjmujaca wartosc od argc - ilosc parametrow.
* \param parametry Zmienna przyjmujaca wartosc od argv - wartosci parametrow.
* \return false blad przy czytaniu przelacznikow - niewlasciwy format / kolejnosc.
* \return true brak bledow
*/
bool Load_parameters(Params& param, const int& Liczba_parametrow, char* parametry[]);


/**
 * \brief Funkcja dostarczajaca dane z przelacznika - i do Listy typu Items w strukturze Backpack.
 * \param items Lista typu Items przechowujaca przedmioty znajdujace sie w plecaku.
 * \param input Strumien ifstream pobierajacy dane z pliku z przelacznika -i.
 */
void move_items(std::list<Item>& items, std::ifstream& input);


/**
 * \brief Funkcja zapisujaca wynik programu do pliku o nazwie podanej w przelaczniku -o.
 * \param backpack Zmienna typu Backpack umozliwiajaca obsluge struktury Backpack.
 * \param output_o Strumien typu ofstream zapsujacy zmienne do pliku.
 * \param params Zmienna typu Param - zapis danych plecaka do pliku.
 */
void to_file(Backpack& backpack, std::ofstream& output_o, Params& params);


/**
 * \brief Funkcja odrzucajaca przedmioty o wadze wiekszej niz pojemnosc plecaka - przygotowanie poczatkowych plecakow
 * \param items Lista typu Items przechowujaca przedmioty znajdujace sie w plecaku.
 * \param backpackCapacity Zmienna typu float okreslajaca pojemnosc plecaka.
 * \return zwraca liste przedmiotow pasujacych do plecaka
 */
std::list<Item> findFittingItems(std::list<Item>& items, float backpackCapacity);


/**
 * \brief Funkcja losujaca przedmioty do plecakow initial
 * \param items Lista typu Items przechowujaca przedmioty znajdujace sie w plecaku.
 * \return zwraca losowo wybrany przedmiot z listy rzeczy pasujacych do plecaka.
 */
Item drawItem(std::list<Item>& items);


/**
 * \brief Funkcja odpowiadajaca za przygotowanie wstepnych plecakow - populacja poczatkowa.
 * \param items Lista typu Items przechowujaca przedmioty znajdujace sie w plecaku.
 * \param amountOfBackpack Zmienna typu int okreslajaca ilosc osobnikow w pokoleniu.
 * \param backpackWeight Zmienna typu float okreslajaca wage przedmiotow w plecaku.
 * \return zwraca vector plecakow przygotowanych pod krzyzowanie.
 */
std::vector<Backpack> generateInitialBackpacks(std::list<Item>& items, int amountOfBackpacks, float backpackWeight);


/**
 * \brief Funkcja odpowiadajaca za krzyzowanie plecakow.
 * \param first Zmienna struktury Backpack stworzona w celu porownywania 2 plecakww.
 * \param second Zmienna struktury Backpack stworzona w celu porownywania 2 plecakow.
 * \param backpackCapacity Zmienna typu float okreslajaca ilosc wolnego miejsca w plecaku temporary.
 * \return zwraca nowy plecak, otrzymany w wyniku krzyzowania 2 sasiednich.
 */
Backpack mixBackpacks(Backpack& first, Backpack& second, float backpackCapacity);


/**
 * \brief Funkcja odpowiadajaca za wybieranie najlepszego plecaka z poprzedniego pokolenia, szukanie najlepszych opcji.
 * \param Vector zawierajacy przygotowane plecaki - osobniki.
 * \return zwraca plecak o najwiekszej wartosci - algorytm max.
 */
Backpack findBest(std::vector<Backpack>& generationToSearch);


/**
 * \brief Funkcja odpowiadajaca za tworzenie nowych plecakow.
 * \param generationToMix Vector zawierajacy osobniki - plecaki do krzywowania.
 * \param backpackCapacity Zmienna typu float okreslajaca pojemnosc plecaka.
 */
void createGeneration(std::vector<Backpack>& generationToMix, float backpackCapacity);


/**
 * \brief Funkcja odpowiadajaca za tworzenie nowych, coraz lepszych pokolen.
 * \param generation Vector zawierajacy pokolenie plecakow do krzyzowania - pokolenie initial.
 * \param generations Zmienna typu int okreslajaca ilosc pokolen.
 * \param backpackCapacity Zmienna typu float okreslajaca pojemnosc plecaka.
 * \return zwraca najlepsze rozwiazanie dla uzyskanych generacji.
 */
Backpack findSolution(std::vector<Backpack>& generation, int generations, float backpackCapacity);


#endif  // !PLECAK_H
