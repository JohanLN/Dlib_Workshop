Vous voici à la racine de mon projet hub :

 _____       ___   _____   _       ___   _       _____    _____   _____   _____   __   _  
|  ___|     /   | /  ___| | |     /   | | |     |  _  \  | ____| /  ___| /  _  \ |  \ | | 
| |__      / /| | | |     | |    / /| | | |     | |_| |  | |__   | |     | | | | |   \| | 
|  __|    / / | | | |     | |   / / | | | |     |  _  /  |  __|  | |     | | | | | |\   | 
| |      / /  | | | |___  | |  / /  | | | |___  | | \ \  | |___  | |___  | |_| | | | \  | 
|_|     /_/   |_| \_____| |_| /_/   |_| |_____| |_|  \_\ |_____| \_____| \_____/ |_|  \_|

Vous trouverez la librairie que j'utilise dans ce projet la Dlib version 19.19.

Un dossier de test d'images...

Et enfin le projet lui même dans le dossier FacialRecon.

   À l'intérieur de ce dernier vous trouver un script shell compile.sh qui suffira d'exécuter via la commande : " ./compile.sh ",
   et le projet se compilera de lui même. Afin de lancer le programme vous devrez rentrer la commande suivant : " ./FacialRecon --save ../faces/<une image du répertoire> ",
      	 	   	     	    	       	  	    	      	   	  	     	      	      	  -> pour pouvoir sauvegarder un visage.
      	      	      		     	    									  "./FacialRecon --detect ../faces/<une image du répertoire> "
														  -> pour pouvoir comparer un ou plusieurs visages à celui sauvegardé.
