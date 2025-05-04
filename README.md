# Plecak Projekt

**Projekt:** Rozwiązywanie problemu plecakowego (0/1 knapsack) za pomocą algorytmu genetycznego w C++

## Spis treści

* [Opis](#opis)
* [Funkcjonalności](#funkcjonalności)
* [Technologie](#technologie)
* [Instalacja](#instalacja)
* [Budowanie](#budowanie)
* [Użytkowanie](#użytkowanie)
* [Parametry](#parametry)
* [Przykład](#przykład)
* [Dokumentacja](#dokumentacja)
* [Struktura projektu](#struktura-projektu)
* [Kontakt](#kontakt)

## Opis

Plecak Projekt to aplikacja napisana w C++14, która wykorzystuje algorytm genetyczny do znajdowania przybliżonego rozwiązania problemu plecakowego (0/1 knapsack). Umożliwia dynamiczne konfigurowanie parametrów działania oraz wczytywanie danych z pliku.

## Funkcjonalności

* **Algorytm genetyczny**: selekcja, krzyżowanie, mutacja
* **Konfigurowalne parametry**: rozmiar populacji, liczba pokoleń, pojemność plecaka
* **Wejście/Wyjście**: wczytywanie danych z pliku tekstowego, zapisywanie wyników do pliku
* **Statystyki**: wyświetlanie najlepszego rozwiązania oraz statystyk algorytmu
* **Dokumentacja**: generowana za pomocą Doxygen (plik `refman.pdf`)

## Technologie

* **C++17**
* **Visual Studio 2019/2022** (Microsoft Visual C++)
* **CMake** (opcja wieloplatformowa)
* **Doxygen**

## Instalacja

1. Sklonuj repozytorium:

   ```bash
   git clone https://github.com/Pucdolf/Knapsack-Problem.git
   cd Knapsack-Problem
   ```
2. Zainstaluj Visual Studio z komponentami C++.

## Użytkowanie

Program wymaga podania pięciu przełączników:

```bash
./PlecakProjekt \
  -i <ścieżka_do_pliku_z_danymi> \
  -o <ścieżka_do_pliku_wynikowego> \
  -p <pojemność_plecaka> \
  -g <liczba_pokoleń> \
  -n <rozmiar_populacji>
```

## Parametry

* `-i <ścieżka_do_pliku_z_danymi>`: plik z listą przedmiotów (np. `sklep2.txt`)
* `-o <ścieżka_do_pliku_wynikowego>`: plik wyjściowy do zapisu najlepszego rozwiązania (np. `solutions.txt`)
* `-p <pojemność_plecaka>`: maksymalna pojemność plecaka (float)
* `-g <liczba_pokoleń>`: liczba generacji w algorytmie (int)
* `-n <rozmiar_populacji>`: liczba osobników w populacji (int)

## Budowanie

### Visual Studio

1. Otwórz folder `Plecak projekt` i plik `Plecak projekt.sln` w Visual Studio.
2. Wybierz konfigurację (Debug/Release).
3. Zbuduj projekt (Build → Build Solution).

### Debugowanie w Visual Studio

Jeśli korzystasz z Visual Studio i chcesz debugować program z argumentami:

1. Otwórz właściwości projektu (prawy klik na projekt → **Properties**).
2. Przejdź do **Configuration Properties** → **Debugging**.
3. W polu **Command Arguments** wprowadź:

   ```bash
   -i <ścieżka_do_pliku_z_danymi> \
   -o <ścieżka_do_pliku_wynikowego> \
   -p <pojemność_plecaka> \
   -g <liczba_pokoleń> \
   -n <rozmiar_populacji>
   ```
4. Zastosuj zmiany i uruchom debugowanie (F5).

## Przykład

```bash
./PlecakProjekt -i sklep2.txt -o solutions.txt -p 50 -g 200 -n 100
```

Wyjście przykładowe:

```
Najlepsze rozwiązanie:
Nazwa   Waga   Wartość
...
Całkowita pojemność: 50
Całkowita wartość: 1234
```

[Przykładowy plik wynikowy znajduje się w `Plecak projekt/solutions.txt` w repozytorium.]

## Dokumentacja

Dokumentacja generowana za pomocą Doxygen znajduje się w pliku `refman.pdf` w głównym katalogu repozytorium.

## Struktura projektu

```
Knapsack-Problem/                # Główne repozytorium GitHub
├── Plecak projekt/              # Visual Studio project folder
│   ├── 8kB.txt                  # Przykładowy plik danych
│   ├── Plecak projekt.vcxproj   # Projekt Visual Studio
│   ├── Plecak projekt.vcxproj.filters # Filtry projektu
│   ├── main.cpp                 # Główny plik źródłowy
│   ├── plecak.cpp               # Implementacja klasy Plecak
│   ├── plecak.h                 # Deklaracja klasy Plecak
│   ├── przyklad.txt             # Przykładowe dane wejściowe
│   ├── sklep1.txt               # Przykładowe dane sklepu 1
│   ├── sklep2.txt               # Przykładowe dane sklepu 2
│   └── solutions.txt            # Przykładowy plik wynikowy
├── README.md                    # Ten plik z instrukcją
├── .gitignore                   # Pliki ignorowane przez Git
├── .gitattributes               # Atrybuty Git
└── refman.pdf                   # Dokumentacja Doxygen
```

## Kontakt

* Autor: Pucdolf - Jakub ([jakub.jh@interia.pl](mailto:jakub.jh@interia.pl))
* Repozytorium: [https://github.com/Pucdolf/Knapsack-Problem](https://github.com/Pucdolf/Knapsack-Problem)
