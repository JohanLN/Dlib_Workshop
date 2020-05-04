 _____       ___   _____   _       ___   _       _____    _____   _____   _____   __   _  
|  ___|     /   | /  ___| | |     /   | | |     |  _  \  | ____| /  ___| /  _  \ |  \ | | 
| |__      / /| | | |     | |    / /| | | |     | |_| |  | |__   | |     | | | | |   \| | 
|  __|    / / | | | |     | |   / / | | | |     |  _  /  |  __|  | |     | | | | | |\   | 
| |      / /  | | | |___  | |  / /  | | | |___  | | \ \  | |___  | |___  | |_| | | | \  | 
|_|     /_/   |_| \_____| |_| /_/   |_| |_____| |_|  \_\ |_____| \_____| \_____/ |_|  \_|

FacialRecon est un petit projet personnel qui j'ai réalisé pour tester les capacités de la reconnaissance facial via la webcam d'un ordinateur.

Vous trouverez la librairie que j'utilise dans ce projet la Dlib version 19.19.

Un dossier de test d'images...

Et enfin le projet lui même dans le dossier FacialRecon.

   À l'intérieur de ce dernier vous trouver un script shell compile.sh qui suffira d'exécuter via la commande : " ./compile.sh ",
   et le projet se compilera de lui même. Afin de lancer le programme vous devrez rentrer la commande suivant : " ./FacialRecon ", le programme effectuera une reconnaissance faciale via la webcam de l'ordinateur et comparera le visage sauvegardé à ceux qui seront présent à la caméra.
   Pour sauvegarder une image, utilisez le flag " --save ". ex : " ./FacialRecon --save <chemin vers une photo> "

Vous pouvez tester ce programme sur vous-même en y insérant une image de vous dans le dossier "faces". Sauvegardez le via le flag --save et lancer le programme FacialRecon.
