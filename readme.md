# OpenCV - Projekt

7. Napisa� uproszczony �frame grabber�. Program, ten b�dzie przetwarza� plik filmowy a tak�e obraz
rejestrowany z kamery na okre�lon� liczb� klatek w postaci plik�w graficznych oraz pozwala� na ��czenie
plik�w graficznych w film. Nale�y umo�liwi� zdefiniowanie liczby klatek dla zadanego przedzia�u
czasowego. Przedzia� czasowy (pocz�tek, koniec) jest ustalany przez u�ytkownika. Dodatkowo, obraz z
kamery b�dzie przetwarzany do pliku wideo po naci�ni�ciu okre�lonego klawisza (np. 's' start) do chwili
naci�ni�cia innego klawisza (np. 'e' koniec), za� plik wideo b�dzie przetwarzany do plik�w graficznych po
naci�ni�ciu odpowiednio klawiszy �s� (start) oraz �e� (koniec).
7.a) Umo�liwi� zapisanie do pliku wideo obrazu z kamery z podan� przez u�ytkownika liczb� klatek na
sekund� (FPS - frames per second), np. 5 fps, 10 fps, 40 fps itd. W przypadku za�adowanego z pliku
filmu wideo nale�y r�wnie� umo�liwi� zapisanie go z ustalon� liczb� klatek na sekund� np. 5 fps, 10
fps, 40 fps itd.
7.b) Zrealizowa� obs�ug� nast�puj�cych opcji umo�liwiaj�cych odtwarzanie plik�w wideo, z obs�ug�
okre�lonych klawiszy:
Opcja: Skr�t klawiszowy:
a) Beginning Ctrl+Left
b) End Ctrl+Right
c) Prev frame Left
d) Next frame Right
e) Prev keyframe Shift+Left
f) Next keyframe Shift+Right
g) Back 50 frames Alt+Left
h) Forward 50 frames Page Down
i) Prev Scene Ctrl+Shift+Left
j) Next Scene Ctrl+Shift+Right
Opis:
a) Pocz�tkowa klatka.
b) Ko�cowa klatka.
c) Poprzednia klatka.
d) Nast�pna klatka.
e) Przesuni�cie wstecz o 15 klatek.
f) Przesuni�cie do przodu o 15 klatek.
g) Przesuni�cie wstecz o 50 klatek.
h) Przesuni�cie do przodu o 50 klatek.
i) Cofni�cie klatka po klatce z bie��cej pozycji klatki do pierwszej klatki.
j) Przesuni�cie do przodu klatka po klatce z bie��cej pozycji do ko�cowej klatki.
7.c) Zrealizowa� otwarcie dw�ch s�siednich okien z odtwarzanymi plikami wideo, wykonuj�cych opcje
wymienione w punkcie 6.b). W przypadku opcji i), j):

- w lewym oknie b�dzie odtwarzanie pliku wideo klatka po klatce
- w prawym oknie wy�wietlona b�dzie klatka pierwsza dla opcji i) albo ko�cowa klatka, je�li wybrano opcj� j)
7.d) Doda� wyskalowany suwak, kt�rego podzia�ka b�dzie si� automatycznie przesuwa�a po wykonaniu
okre�lonych opcji skr�tami klawiszowymi, wymienionych w punkcie 6.b). Podzia�ka ma mie� wyskalowane
numery wszystkich klatek.
7.e) Doda� obs�ug� myszy, umo�liwiaj�cej przemieszczanie suwaka, kt�rego przesuni�cie (na okre�lony numer
klatki) spowoduje wy�wietlenie wskazanej klatki w dw�ch s�siednich oknach.
7.f) Umo�liwi� dodanie logo, kt�rego po�o�eniem mo�na sterowa� za pomoc� klawiszy strza�ek w oknie z
za�adowanym dowolnym plikiem graficznym. Umo�liwi� zapisanie obrazka z umieszczonym logo do pliku.
Opr�cz tego zrealizowa� pozycjonowanie logo (za pomoc� strza�ek) w :
1) W oknie z za�adowanym plikiem filmowym
2) W oknie z odtwarzanym obrazem z kamery
Umo�liwi� zapis do pliku wideo: (1) pliku filmowego (2) obrazu z kamery, z umieszczonym i
wypozycjonowanym logo, odpowiednio w punktach: 1) oraz 2).