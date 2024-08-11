:it: Made in Italy. Da oltre 20 anni al vostro fianco.

Questo software offre i primi dlc per un gioco free software.

Questo software offre la prima versione di un progetto wxwidgets destinato al pubblico su windows arm64.

![Napoli-Logo](https://github.com/user-attachments/assets/fc1773c1-6823-429d-8760-e7d7e79f7d8f)
![made in parco grifeo](https://github.com/user-attachments/assets/c1d40b56-101a-462f-9970-006c81937300)


## Sviluppi futuri

É ora di svegliarsi. Dal momento che la wxbriscola sta venendo boicottata, che tutti giocano alla scopa col tutto che si accoppia le carte invece di impararsi un gioco equo, che mi ricattano per avere il brevetto arrivando addirittura ad ammazzarmi il gatto, la wxbriscola entra in stato legacy.
Continuerò ad occuparmente, ma nel tempo libero, tanto le wxsocket attualmente non permettono di limitare le connessioni e quindi un multiplayer cross platform risulta impossibile, ed è l'unica cosa che rimane da fare.
O le vostre brutali tattiche cessano, oppure io la lascio alla comunità, come fa linus torvalds col kernellinux.

Happy Hacking.


## wxBriscola
Il gioco della briscola a due giocatori scritto in c++ e wxwidgets.
Non ha il multiplayer e supporta il caricamento di mazzi regionali ed arbitrari e il caricamento delle localizzazioni.

Per compilare è necessario impostare le seguenti librerie di wxwidgets:

wxbase

wxmsw core

Il metodo predefinito di compilazione è con meson.

Funziona con gcc, mingw e [visual studio](https://github.com/numerunix/wxbriscola-for-windows), sia con le wxwidgets oldstable (3.0) stable (3.1) che development (3.2).

E' possibile inserire la propria localizzazione scaricando uno dei files .mo, sono estratti con GNU GetText, e traducendoli col blocco note o poedit. Per la localizzazione arbitraria bisogna inserire il file .mo all'interno di una cartella "LC_LOCALES" all'interno di una cartella che ha come nome il nome corto del linguaggio "it" o "it_IT" per italiano, "en_US" per inglese americano, "en_UK" per inglese regno unito o semplicemente "en" per inglese, "es_ES" per spagnolo di spagna o "es" per spagnolo e via discorrendo, tutto all'interno della cartella locale. Il programma è programmato per vedere automaticamente il nuovo file di traduzione e lo mostrerà nel menù.

Per le carte, è possibile usare 42 immagini arbitrarie, oltre a quelle preimpostate, basta creare una cartella di nome arbitrario in "Mazzi" ed inserire 40 immagini con nome da "0" a "40" e due immagini col nome "retro carte mazzo" e "retro carte pc" tutte in formato jpeg.

Il programma le vedrà in automatico e aggiornerà il menù.

Sentitevi liberi di contribuire con localizzazioni e mazzi regionali.

## L'algoritmo brevettato

Vi spiego come funziona l'algoritmo dell'ia dei livelli 2 e 3, che è brevettato all'ufficio brevetti americano.
Gli assi sono 4 e valogono 11 punti ciascuno, i 3 10 punti, i 10 4 punti i 9 3 punti 3 gli 8 2 punti, per cui:4x11+4x10+4x4+4x3+4x2=44+40+16+12+8=120
I punti totali sono 120 di cui 84 di carichi e 36 di altre carte. Per vincere bisogna giocare a prendere la carta con valore, non il carico, perchè per vincere servono 61 punti e 81-61=20 punti, questo significa che bisogna lasciar stare solo 2 carichi.
Al contrario prendendo i 36 punti delle carte di valore, servono altri 25 punti per vincere, per cui bastano 3 carichi.
In generale nei giochi di carte più carte si prendono e più possibilità c'é di far punti, per cui come algoritmo per il primo di mano si sceglie di giocare la carta più difficile da prendere, ossia un 10 ma non di briscola.

## L'attestato
Sui server di google è disponibile l'attestato che spiega che la wxbriscola prova per il gioco della briscola la teoria dei giochi.

## Installazione

## Tramite repository (consigliato)
Seguite le istruzioni all'indirizzo http://numeronesoft.ddns.net

## Tramite flatpak  (sconsigliato, non è aggiornato)
Seguite le istruzioni all'indirizzo http://numeronesoft.ddns.net:8080
Prestate attenzione: flatpak non include il mazzo napoletano, dovete scaricare il deb e spacchettarlo con fileroller e creare la directort HOME/Mazzi/Napoletano


## Tramite Snap Store (sconsigliato, non funziona twitter)

[![wxbriscola](https://snapcraft.io/wxbriscola/badge.svg)](https://snapcraft.io/wxbriscola)

[![youtube](https://i.ibb.co/k0WnTGQ/a.png)](https://www.youtube.com/watch?v=RQyRh7C0COw)

# Compilazione con Flatpak
Installate flatpak con apt, aggiungete il repository uficiale, installate flatpakbuilder con flatpak poi installateflathub org.gnome.Platform//43
flathub org.gnome.Sdk//43
con flatpak e poi date il comando

flatpak run org.flatpak.Builder --repo=./repo ./build org.altervista.numerone.wxbriscola.yml 
A questo punto il programma scaricherà e compilerà le ultime wxwidgets e l'ultima wxbriscola.

Infine dare il comando
flatpak run org.flatpak.Builder --user --install --force-clean ./build/ org.altervista.numerone.wxbriscola.yml 

# Set di mazzi arbitrario
Sono necessari 4 semi, ognuno di 10 carte.
- Bastoni è rappresentato con le immagini jpeg coi numeri da 0 a 9 (0 è 1 di bastoni, 9 è 10 di bastoni, in sequenza)

- Coppe è rappresentato con le immagini jpeg coi numeri da 10 a 19

- Denari è rappresentato con le immagini jpeg da 20 a 29

- Spade è rappresentato con le immagini jpeg da 30 a 39

Sono presenti, in oltre:
- il retro di una singola carta che rappresenta le carte del computer di nome "retro carte pc.jpg"

- il retro della carta del pc girata di 90 gradi chiamata "retro carte mazzo.jpg" che rappresenta il tallone

Queste 42 immagini vanno posizionate in una sottocartella della cartella mazzi presente nella directory di lavoro.
Il programma vedrà la nuova cartella e la aggiungerà automaticamente al menù mazzi.

# Localizzazione
Per localizzare il programma è necessario usare il programma https://poedit.net/download
Una volta installato, scaricare uno qualsiasi dei files .po presenti nella cartella "po" nella rott del repository.
Per prima cosa bisogna rinominare il file usando la dicitura a due caratteri (se prendete il file italiano e volete tradurlo in tedesco, bisogna prendere il file it.po e rinominarlo in de.po), a questo punto aprirlo ed andare in catalogo > proprietà e modificare la proprietà lingua in de.
A questo punto tradurre iogni singola riga nella colonna Traduzione.
Una volta finito bisogna andare in file > compila e compilare il file in mo.
A questo punto bisogna prendere il relativo mo di traduzioni di wxwidgets e metterlo nella stessa cartella del vostro file.

![screen-2022-05-24-18-56-09](https://user-images.githubusercontent.com/49764967/170091585-c946486a-f964-48a3-a4e1-4ebbf012c75b.png)
![screen-2022-05-24-18-55-32](https://user-images.githubusercontent.com/49764967/170091587-6895150e-815f-45c3-a99a-d7924880a406.png)

In alternativa è possibile aprire il file mo con un file di testo, modificare solo il valore delle varie stringhe msgstr e poi mandarmelo facendo il commit affinché io possa cambiare la localizzazione del file con poedit, compilarlo e metterlo ne programma ufficiale.

![Screenshot_20220525-053827](https://user-images.githubusercontent.com/49764967/170174993-e10401e0-cfc3-4bd1-a1f7-c68e442738b5.png)
![Screenshot_20220525-051036](https://user-images.githubusercontent.com/49764967/170175002-016bf07f-d0ae-490a-8267-cb7b391957f0.png)


Potete mandarmi in po di traduzione quando volete, basta fare il commit su questa piattaforma, sarò ben felice di compilarlo e inserirlo nel programma dandovi il credit.

Si ringrazia una certa Alice Victoria conosciuta dalle mie parti per la contribuzione della localizzazione spagnola.
Si ringrazia Francesca San Severino per la contribuzione alla localizzazione Francese

Richiedo esplicitamente la localizzazione in tedesco e portoghese.


## Problemi di localizzazione
Ho provveduto a localizzare la wxbriscola in italiano, spagnolo e inglese.
Su windows non tutto il programma esce localizzato. I files di localizzazione delle librerie wxwidgets sono inclusi e le chiamate alle librerie di sistema si basano sulla lingua di sistema, per cui se si prova a mettere la lingua spagnola, la schermata del font non sarà tradotta in spagnolo e per averla bisogna cambiare la lingua del sistema operativo.

Su GNU/Linux c'è bisogno del package di localizzazione di wxwidgets (wxwidgets-i18n) ma il programma risulterà tutto correttamente localizzato.

Potrebbe comparire il messaggio d'errore all'inizio "Locale xx_xx cannot be set) ed è perché il locale di sistema (tipicamente quello di gnome) non coincide con quello selezionato.

In alcune occasioni, potrebbe apparire il programma in lingua italiana, solo che al posto di avere gli accenti ha gli apostrofi, questo accade quando non trova la libreria di localizzazione richiesta e quindi mostra le stringhe senza nessuna traduzione.
Per ovviare al problema e vedere quindi correttamente gli accenti italiani, bisogna assicurarsi che il file wxBirscola.mo si trovi nella cartella LC_LOCALES sotto locale nella directory di esecuzione del programma.

## Interfaccia

![Schermata del 2024-07-19 06-32-51](https://github.com/user-attachments/assets/3be3e328-94b5-4f99-8adf-abd35982f663)
![Schermata del 2024-07-19 06-33-23](https://github.com/user-attachments/assets/4a73d769-d2fe-4b14-9b16-8cd36da75823)
![Schermata del 2024-07-19 09-15-50](https://github.com/user-attachments/assets/14deeb7f-96e4-4ed3-b7c9-74301abd1eef)
![Schermata del 2024-07-19 09-16-09](https://github.com/user-attachments/assets/8a3fd495-9f7f-4f95-9be3-1fe8c1617b41)
![Schermata del 2024-07-19 09-16-23](https://github.com/user-attachments/assets/da0e253e-0e40-4721-aca6-bab654a5511d)
![Schermata del 2024-07-19 09-16-30](https://github.com/user-attachments/assets/1e7a437a-356c-47db-974f-d04567d6eae7)


## Donazioni

http://numerone.altervista.org/donazioni.php

## Bug noti

Se si prova a cambiare il locale di default, ma all'interno della applicazione, l'interfaccia wxwidgets dependents risulta inglese, bisogna cambiare il locale dell'intero sistema.
