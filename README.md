# wxBriscola
Il gioco della briscola a due giocatori scritto in c++ e wxwidgets.
Non ha il multiplayer e supporta il caricamento di mazzi regionali ed arbitrari e il caricamento delle localizzazioni.

Per compilare è necessario impostare le seguenti librerie di wxwidgets:

wxbase

wxmsw core

Non viene fornito alcun metodo preimpostato di compilazione (make, cmake, codeblocks, template visual studio), sentitevi liberi di usare quello che più vi pare.

Funziona con gcc, mingw e visual studio, sia con le wxwidgets stable (3.0) che development (3.1).

E' possibile inserire la propria localizzazione scaricando uno dei files .mo, sono estratti con GNU GetText, e traducendoli col blocco note o poedit. Per la localizzazione arbitraria bisogna inserire il file .mo all'interno di una cartella "LC_LOCALES" all'interno di una cartella che ha come nome il nome corto del linguaggio "it" o "it_IT" per italiano, "en_US" per inglese americano, "en_UK" per inglese regno unito o semplicemente "en" per inglese, "es_ES" per spagnolo di spagna o "es" per spagnolo e via discorrendo, tutto all'interno della cartella locale. Il programma è programmato per vedere automaticamente il nuovo file di traduzione e lo mostrerà nel menù.

Per le carte, è possibile usare 42 immagini arbitrarie, oltre a quelle preimpostate, basta creare una cartella di nome arbitrario in "Mazzi" ed inserire 40 immagini con nome da "0" a "40" e due immagini col nome "retro carte mazzo" e "retro carte pc" tutte in formato jpeg.

Il programma le vedrà in automatico e aggiornerà il menù.

Sentitevi liberi di contribuire con localizzazioni e mazzi regionali.>

# Problemi di localizzazione
Ho provveduto a localizzare la wxbriscola in italiano, spagnolo e inglese.
Su windows non tutto il programma esce localizzato. I files di localizzazione delle librerie wxwidgets sono inclusi e le chiamate alle librerie di sistema si basano sulla lingua di sistema, per cui se si prova a mettere la lingua spagnola, la schermata del font non sarà tradotta in spagnolo e per averla bisogna cambiare la linga del sistema operativo.

Su GNU/Linux c'è bisogno del package di localizzazione di wxwidgets (wxwidgets-i18n) ma il programma risulterà tutto correttamente localizzato.
Potrebbe comparire il messaggio d'errore all'inizio "Locale xx_xx cannot be set) ed è perché il sistema non in uso non ha installate tutte le librerie di traduzioni (tipicamente quelle di gnome), però il programma risulterà lo stesso correttamente localizzato.
Si ringrazia una certa Alice Victoria delle mie parti per la contribuzione della localizzazione spagnola.

In alcune occasioni, potrebbe apparire il programma in lingua italiana, solo che al posto di avere gli accenti ha gli apostrofi, questo accade quando non trova la libreria di localizzazione richiesta e quindi mostra le stringhe senza nessuna traduzione.
Per ovviare al problema e vedere quindi correttamente gli accenti italiani, bisogna assicurarsi che il file wxBirscola.mo si trovi nella cartella LC_LOCALES sotto locale nella directory di esecuzione del programma.
