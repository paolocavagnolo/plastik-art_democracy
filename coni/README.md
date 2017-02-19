# The big cones machine

## TODO
 - pulsante sulla scatola di controllo
 - servono i connettori
 

## scatola di controllo
 - **INPUT**:
 	- 4 potenziometri (test) + 1 pulsante (start)
 	- 1 x CONNETTORE DMX 3 POLI PER BUS RS485
 
 - **OUTPUT**:
 	- segnale RS485 per controllo di due arduino sullo stesso BUS

 - **PROCESS**:
 	- ARDUINO legge pulsante e potenziometri
 	- ARDUINO manda a RS485 comandi in seriale
 	- RS485 manda a bus comandi in seriale

 - **COMPONENTI**:
 	- 1 x ARDUINO
 	- 1 x RS485 (3,3V)
 	- 1 x ALIMENTATORE
 	- 1 x CONNETTORE DMX 3 POLI PER RS485

## scatola BIG CONE
 - **INPUT**:
 	- segnale RS485 su bus seriale
 
 - **OUTPUT**:
 	- 3 x controlli motore stepper

 - **PROCESS**:
 	- RS485 legge segnale e manda ad ARDUINO 
 	- ARDUINO legge segnale e manda il segnale ai 3 motori

 -**COMPONENTI**:
 	- 1 x RS485 
 	- 1 X ARDUINO
 	- 1 x ALIMENTATORE
 	- 1 x CONNETTORE DMX 3 POLI PER BUS RS485

## scatola SMALL CONE
 - **INPUT**:
 	- segnale RS485 su bus seriale
 
 - **OUTPUT**:
 	- 2 x controlli motore stepper

 - **PROCESS**:
 	- RS485 legge segnale e manda ad ARDUINO 
 	- ARDUINO legge segnale e manda il segnale ai 2 motori

 -**COMPONENTI**:
 	- 1 x RS485 
 	- 1 X ARDUINO
 	- 1 x ALIMENTATORE
 	- 1 x CONNETTORE DMX 3 POLI PER BUS RS485

