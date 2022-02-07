# ECE-ElectroMain



## Liste des composants

* Arduino Nano
* Module Bluetooth HC-05
* Servo moteur SG90 x2
* Batterie externe 
  * (ou ensemble accumulateur, coupleur et circuit de charge)

## Branchements circuit

![Branchements des composants](https://github.com/ElectroMain/ECE-ElectroMain/blob/main/branchements.png?raw=true)

## Programmation du module Bluetooth

Le parametrage des modules Bluetooth se fait avec le code [program_ble.ino](https://github.com/ElectroMain/ECE-ElectroMain/blob/main/program_ble.ino). Il suffit simplement d'upload ce code sur l'arduino, s'assurer que les pins RX et TX du module soient branchés respectivement sur les pins 4 et 3 de l'arduino et que le pin EN/KEY du module bluetooth soit alimenté en 5V (ou sur le pin 8 de l'arduino).

### Sur notre module

Pour changer le baud rate du module : `AT+UART=38400,0,0`

Pour récuperer l'addresse du module : `AT+ADDR?`

Pour changer le mot de passe du module : `AT+PSWD=PASSWORD`, remplacer PASSWORD avec un mot de passe robuste

### Sur le module commande (ex: celui de commande au souffle)

Pour changer le baud rate du module : `AT+UART=38400,0,0`

Pour changer le mot de passe du module : `AT+PSWD=PASSWORD`, remplacer PASSWORD avec le même mot de passe pour que sur l'autre module

Pour se connecter a notre module : `AT+BIND=ADRESSE`, remplacer ADRESSE avec l'adresse obtenu avec `AT+ADDR?`

Pour changer le role du module : `AT+ROLE=1`

Pour changer le mode du module : `AT+CMODE=0`

Si vous souhaitez modifier d'autre parametres, vous pouvez trouver la liste des commandes disponibles [ici](https://s3-sa-east-1.amazonaws.com/robocore-lojavirtual/709/HC-05_ATCommandSet.pdf)

## Modification en fonction du prototype choisi

En fonction du prototype choisi (Lego ou 3D), les amplitudes de mouvement ne sont pas les mêmes et il faut donc modifier les ratio présent au debut du code. 

Dans le cas du proto Lego il faut utiliser les ratios présent lignes  17 et 18. 

Dans le cas du proto 3D il faut utiliser les ratios présent lignes 21 et 22.
