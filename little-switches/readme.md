# 6 pistoni
Il programma little-switches controlla 6 pistoni, su 3 installazioni differenti. Ogni pistone è collegato ad un elettrovalvola, collegata ad un relay comandato da arduino

## prima di cominciare
 - installare arduino IDE da qui: arduino.cc
 - collegare il cavo usb al pc
 - impostare come scheda ARDUINO/GENUINO UNO
 - scegliere la giusta porta USB tra quelle in elenco
 - dal menu "Sketch" andare su #include libreria e poi cliccare su "Gestione Librerie..."
 - verificare di avere installate o installare la seguente libreria:
 	- PS2Keyboard
 - scaricare i file descritti di seguito, caricarli e provarli uno ad uno

## lista dei test preliminare da effettuare
 1- **Setup Keyboard**: scaricalo o copialo da [qui](https://github.com/paolocavagnolo/plastik-art_democracy/little-swithces/1_setup-key/1_setup-key.ino). Dopo averlo caricato, aprire il monitor seriale e verificare il valore prodotto da alcuni tasti della tastiera: dal 1 allo 0 e della lettera q, dovrebbero essere:
|tasto   |valore   |
|:-:|:-:|
|1   | 49  |
|2   | 50  |
|3   | 51  |
|4   | 52  |
|5   | 53  |
|6   | 54  |
|7   | 55  |
|8   | 56  |
|9   | 57  |
|0   | 58  |
|q   | 59  |



 2- **Setup Relay**: scaricalo o copialo da [qui](https://github.com/paolocavagnolo/plastik-art_democracy/little-swithces/2_setup-rel/2_setup-rel.ino). 

