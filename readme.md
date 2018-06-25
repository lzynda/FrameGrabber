# OpenCV - Projekt

7. Napisaæ uproszczony ‘frame grabber’. Program, ten bêdzie przetwarza³ plik filmowy a tak¿e obraz
rejestrowany z kamery na okreœlon¹ liczbê klatek w postaci plików graficznych oraz pozwala³ na ³¹czenie
plików graficznych w film. Nale¿y umo¿liwiæ zdefiniowanie liczby klatek dla zadanego przedzia³u
czasowego. Przedzia³ czasowy (pocz¹tek, koniec) jest ustalany przez u¿ytkownika. Dodatkowo, obraz z
kamery bêdzie przetwarzany do pliku wideo po naciœniêciu okreœlonego klawisza (np. 's' start) do chwili
naciœniêcia innego klawisza (np. 'e' koniec), zaœ plik wideo bêdzie przetwarzany do plików graficznych po
naciœniêciu odpowiednio klawiszy ‘s’ (start) oraz ‘e’ (koniec).<br /><br />

7.a) Umo¿liwiæ zapisanie do pliku wideo obrazu z kamery z podan¹ przez u¿ytkownika liczb¹ klatek na
sekundê (FPS - frames per second), np. 5 fps, 10 fps, 40 fps itd. W przypadku za³adowanego z pliku
filmu wideo nale¿y równie¿ umo¿liwiæ zapisanie go z ustalon¹ liczb¹ klatek na sekundê np. 5 fps, 10
fps, 40 fps itd.<br /><br />

7.b) Zrealizowaæ obs³ugê nastêpuj¹cych opcji umo¿liwiaj¹cych odtwarzanie plików wideo, z obs³ug¹
okreœlonych klawiszy:<br />
Opcja: Skrót klawiszowy:<br />
a) Beginning Ctrl+Left<br />
b) End Ctrl+Right<br />
c) Prev frame Left<br />
d) Next frame Right<br />
e) Prev keyframe Shift+Left<br />
f) Next keyframe Shift+Right<br />
g) Back 50 frames Alt+Left<br />
h) Forward 50 frames Page Down<br />
i) Prev Scene Ctrl+Shift+Left<br />
j) Next Scene Ctrl+Shift+Right<br />
Opis:<br />
a) Pocz¹tkowa klatka.<br />
b) Koñcowa klatka.<br />
c) Poprzednia klatka.<br />
d) Nastêpna klatka.<br />
e) Przesuniêcie wstecz o 15 klatek.<br />
f) Przesuniêcie do przodu o 15 klatek.<br />
g) Przesuniêcie wstecz o 50 klatek.<br />
h) Przesuniêcie do przodu o 50 klatek.<br />
i) Cofniêcie klatka po klatce z bie¿¹cej pozycji klatki do pierwszej klatki.<br />
j) Przesuniêcie do przodu klatka po klatce z bie¿¹cej pozycji do koñcowej klatki.<br /><br />
7.c) Zrealizowaæ otwarcie dwóch s¹siednich okien z odtwarzanymi plikami wideo, wykonuj¹cych opcje<br />
wymienione w punkcie 6.b). W przypadku opcji i), j):<br />

 w lewym oknie bêdzie odtwarzanie pliku wideo klatka po klatce<br />
 w prawym oknie wyœwietlona bêdzie klatka pierwsza dla opcji i) albo koñcowa klatka, jeœli wybrano opcjê j)<br /><br />
7.d) Dodaæ wyskalowany suwak, którego podzia³ka bêdzie siê automatycznie przesuwa³a po wykonaniu
okreœlonych opcji skrótami klawiszowymi, wymienionych w punkcie 6.b). Podzia³ka ma mieæ wyskalowane
numery wszystkich klatek.<br /><br />
7.e) Dodaæ obs³ugê myszy, umo¿liwiaj¹cej przemieszczanie suwaka, którego przesuniêcie (na okreœlony numer
klatki) spowoduje wyœwietlenie wskazanej klatki w dwóch s¹siednich oknach.<br /><br />
7.f) Umo¿liwiæ dodanie logo, którego po³o¿eniem mo¿na sterowaæ za pomoc¹ klawiszy strza³ek w oknie z
za³adowanym dowolnym plikiem graficznym. Umo¿liwiæ zapisanie obrazka z umieszczonym logo do pliku.<br />
Oprócz tego zrealizowaæ pozycjonowanie logo (za pomoc¹ strza³ek) w :<br />
1) W oknie z za³adowanym plikiem filmowym<br />
2) W oknie z odtwarzanym obrazem z kamery<br />
Umo¿liwiæ zapis do pliku wideo: (1) pliku filmowego (2) obrazu z kamery, z umieszczonym i
wypozycjonowanym logo, odpowiednio w punktach: 1) oraz 2).