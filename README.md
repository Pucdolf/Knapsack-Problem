# Projekt Plecak

Profesjonalne repozytorium Git dla projektu rozwiązującego problem plecakowy (0/1 Knapsack) za pomocą algorytmu dynamicznego w C++.

---

## Spis treści

* [Opis](#opis)
* [Funkcjonalności](#funkcjonalności)
* [Technologie](#technologie)
* [Wymagania wstępne](#wymagania-wstępne)
* [Instalacja](#instalacja)
* [Użytkowanie](#użytkowanie)
* [Struktura katalogów](#struktura-katalogów)
* [Dokumentacja](#dokumentacja)
* [Testy](#testy)
* [Wkład](#wkład)
* [Licencja](#licencja)
* [Kontakt](#kontakt)

---

## Opis

Projekt „Plecak” to implementacja rozwiązania problemu plecakowego typu 0/1, opartego na algorytmie dynamicznego programowania. Aplikacja umożliwia wyznaczenie maksymalnej łącznej wartości przedmiotów mieszczących się w plecaku o zadanej pojemności.

## Funkcjonalności

* Rozwiązanie problemu plecakowego 0/1 za pomocą dynamicznego programowania
* Wczytywanie danych z pliku tekstowego lub z konsoli
* Wizualizacja wartości optymalnego zbioru przedmiotów (raport tekstowy)
* Możliwość kompilacji w konfiguracjach Debug oraz Release

## Technologie

* C++17
* Visual Studio 2022 (Platform Toolset v143)

## Wymagania wstępne

* System operacyjny: Windows 10 lub nowszy
* Visual Studio 2022 z zainstalowanym modułem C++

## Instalacja

1. Sklonuj repozytorium:

   ```bash
   git clone https://github.com/<TwojeUżytkownik>/<repozytorium>.git
   ```
2. Otwórz w Visual Studio plik `Plecak projekt.sln` znajdujący się w katalogu `Plecak projekt`.
3. Wybierz konfigurację (Debug/Release) i zbuduj projekt (Build > Build Solution).

## Użytkowanie

Po zbudowaniu w trybie Release znajdziesz plik wykonywalny w `Plecak projekt/x64/Release/Plecak projekt.exe`.

### Przykład uruchomienia

```bash
Plecak\x64\Release\Plecak projekt.exe <ścieżka_do_pliku_wejściowego> <pojemność_plecaka>
```

#### Format pliku wejściowego

```
<n> <W>
w1 v1
w2 v2
...
w_n v_n
```

* `n` – liczba przedmiotów
* `W` – pojemność plecaka
* `w_i` – waga i-tego przedmiotu
* `v_i` – wartość i-tego przedmiotu

## Struktura katalogów

```
Plecak projekt/
├── Plecak projekt.sln       # Plik rozwiązania Visual Studio
├── refman.pdf               # Szczegółowa dokumentacja
├── x64/
│   ├── Debug/               # Build Debug
│   └── Release/             # Build Release (plik wykonywalny)
└── src/                     # (opcjonalnie: katalog z kodem źródłowym)
```

> **Uwaga:** Jeżeli katalog `src/` nie istnieje, skorzystaj z widoku Solution Explorer w Visual Studio.

## Dokumentacja

Pełna dokumentacja techniczna dostępna jest w pliku `refman.pdf`.

## Testy

Brak zautomatyzowanych testów w tej wersji projektu. Zachęcamy do dodania testów jednostkowych.

## Wkład

Wnioski do projektu i zgłaszanie problemów prosimy kierować przez Issues na GitHubie. Pull requesty są mile widziane!

## Licencja

Projekt nie zawiera jeszcze pliku LICENSE. Dodaj plik z odpowiednią licencją (np. MIT, GPL) według potrzeb.

## Kontakt

* Autor: Imię Nazwisko
* Email: [twoj.email@domena.com](mailto:twoj.email@domena.com)
* Strona GitHub: [https://github.com/](https://github.com/)\<TwojeUżytkownik>
