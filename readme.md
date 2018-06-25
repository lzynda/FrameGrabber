# OpenCV - Projekt

7. Napisaæ uproszczony ‘frame grabber’. Program, ten bêdzie przetwarza³ plik filmowy a tak¿e obraz
rejestrowany z kamery na okreœlon¹ liczbê klatek w postaci plików graficznych oraz pozwala³ na ³¹czenie
plików graficznych w film. Nale¿y umo¿liwiæ zdefiniowanie liczby klatek dla zadanego przedzia³u
czasowego. Przedzia³ czasowy (pocz¹tek, koniec) jest ustalany przez u¿ytkownika. Dodatkowo, obraz z
kamery bêdzie przetwarzany do pliku wideo po naciœniêciu okreœlonego klawisza (np. 's' start) do chwili
naciœniêcia innego klawisza (np. 'e' koniec), zaœ plik wideo bêdzie przetwarzany do plików graficznych po
naciœniêciu odpowiednio klawiszy ‘s’ (start) oraz ‘e’ (koniec).
7.a) Umo¿liwiæ zapisanie do pliku wideo obrazu z kamery z podan¹ przez u¿ytkownika liczb¹ klatek na
sekundê (FPS - frames per second), np. 5 fps, 10 fps, 40 fps itd. W przypadku za³adowanego z pliku
filmu wideo nale¿y równie¿ umo¿liwiæ zapisanie go z ustalon¹ liczb¹ klatek na sekundê np. 5 fps, 10
fps, 40 fps itd.
7.b) Zrealizowaæ obs³ugê nastêpuj¹cych opcji umo¿liwiaj¹cych odtwarzanie plików wideo, z obs³ug¹
okreœlonych klawiszy:
Opcja: Skrót klawiszowy:
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
a) Pocz¹tkowa klatka.
b) Koñcowa klatka.
c) Poprzednia klatka.
d) Nastêpna klatka.
e) Przesuniêcie wstecz o 15 klatek.
f) Przesuniêcie do przodu o 15 klatek.
g) Przesuniêcie wstecz o 50 klatek.
h) Przesuniêcie do przodu o 50 klatek.
i) Cofniêcie klatka po klatce z bie¿¹cej pozycji klatki do pierwszej klatki.
j) Przesuniêcie do przodu klatka po klatce z bie¿¹cej pozycji do koñcowej klatki.
7.c) Zrealizowaæ otwarcie dwóch s¹siednich okien z odtwarzanymi plikami wideo, wykonuj¹cych opcje
wymienione w punkcie 6.b). W przypadku opcji i), j):

- w lewym oknie bêdzie odtwarzanie pliku wideo klatka po klatce
- w prawym oknie wyœwietlona bêdzie klatka pierwsza dla opcji i) albo koñcowa klatka, jeœli wybrano opcjê j)
7.d) Dodaæ wyskalowany suwak, którego podzia³ka bêdzie siê automatycznie przesuwa³a po wykonaniu
okreœlonych opcji skrótami klawiszowymi, wymienionych w punkcie 6.b). Podzia³ka ma mieæ wyskalowane
numery wszystkich klatek.
7.e) Dodaæ obs³ugê myszy, umo¿liwiaj¹cej przemieszczanie suwaka, którego przesuniêcie (na okreœlony numer
klatki) spowoduje wyœwietlenie wskazanej klatki w dwóch s¹siednich oknach.
7.f) Umo¿liwiæ dodanie logo, którego po³o¿eniem mo¿na sterowaæ za pomoc¹ klawiszy strza³ek w oknie z
za³adowanym dowolnym plikiem graficznym. Umo¿liwiæ zapisanie obrazka z umieszczonym logo do pliku.
Oprócz tego zrealizowaæ pozycjonowanie logo (za pomoc¹ strza³ek) w :
1) W oknie z za³adowanym plikiem filmowym
2) W oknie z odtwarzanym obrazem z kamery
Umo¿liwiæ zapis do pliku wideo: (1) pliku filmowego (2) obrazu z kamery, z umieszczonym i
wypozycjonowanym logo, odpowiednio w punktach: 1) oraz 2).