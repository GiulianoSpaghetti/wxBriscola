# wxBriscola
Il gioco della briscola a due giocatori scritto in c++ e wxwidgets.
Non ha il multiplayer e supporta il caricamento di mazzi regionali ed arbitrari e il caricamento delle localizzazioni.

Per compilare è necessario impostare le seguenti librerie di wxwidgets:
*wxbase
*wxbase net
*wxmsw
*wxmsw core

Non viene fornito alcun metodo preimpostato di compilazione (make, cmake, codeblocks, template visual studio), sentitevi liberi di usare quello che più vi pare.

Funziona con gcc, mingw e visual studio, sia con le wxwidgets stable (3.0) che development (3.1).

E' possibile inserire la propria localizzazione scaricando uno dei files .mo, sono estratti con GNU GetText, e traducendoli col blocco note o poedit. Per la localizzazione arbitraria bisogna inserire il file .mo all'interno di una cartella "LC_LOCALES" all'interno di una cartella che ha come nome il nome corto del linguaggio "it" o "it_IT" per italiano, "en_US" per inglese americano, "en_UK" per inglese regno unito o semplicemente "en" per inglese, "es_ES" per spagnolo di spagna o "es" per spagnolo e via discorrendo, tutto all'interno della cartella locale. Il programma è programmato per vedere automaticamente il nuovo file di traduzione e lo mostrerà nel menù.

Per le carte, è possibile usare 42 immagini arbitrarie, oltre a quelle preimpostate, basta creare una cartella di nome arbitrario in "Mazzi" ed inserire 40 immagini con nome da "0" a "40" e due immagini col nome "retro carte mazzo" e "retro carte pc" tutte in formato jpeg.

Il programma le vedrà in automatico e aggiornerà il menù.

Sentitevi liberi di contribuire con localizzazioni e mazzi regionali.
