# ZADANIE 21
Porównanie wydajności algorytmów sortowania. Napisać osobne procedury sortowania metodami: bąbelkową,
przez wstawianie, metodą Shella (na bazie sortowania bąbelkowego) oraz quick sort. W każdej z nich należy
stosownie osadzić instrukcje zliczania wykonanych podstawień i porównań sortowanych danych. Program ge-
neruje losowo długą, testową serię liczb ( N ∼ 10 000 ) i kolejno poddaje je (te same losowe dane!) sortowaniu
wszystkimi wymienionymi metodami, rejestrując dla każdej z nich liczbę wykonanych porównań i podstawień
kluczy. Cykl ten powtarzany jest M ∼ 1000 razy, dla nowych losowych danych. Dla każdej z wymienionych
metod program powinien wyświetlić w tabeli następujące dane: maksymalna i minimalna w serii M prób liczba
wykonanych podstawień i porównań sortowanych kluczy oraz średnia liczba podstawień i porównań.