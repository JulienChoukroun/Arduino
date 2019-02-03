# Pendant les vacances de ski

* Pour éviter les frottements du capteur avec la roue, j'ai testé un nouveau capteur : le Keyes IR-01. C'est le capteur utilisé en cours pour la voiture qui suit une ligne noire.
Et ce capteur fonctionne très bien. Il n'y a plus aucun frottements. On va donc utilisé ce capteur. 
* J'ai donc adapté nos programmes déjà fait pour ce capteur.
Le nouveau programme pour l'initialisation est celui-ci : https://github.com/JessicaJulien/projet/blob/master/Codes/initialisationRoueNouveau.ino
Voici une démonstration : 
<a href="https://www.youtube.com/watch?v=4ydrxAV1xTY"><img src="https://i.ytimg.com/vi/4ydrxAV1xTY/hqdefault.jpg?sqp=-oaymwEZCNACELwBSFXyq4qpAwsIARUAAIhCGAFwAQ==&rs=AOn4CLC9CE8JMA-LUZUt-Czr3-Y03VeviQ" alt="Initialisation de la roue avec le nouveau capteur et la lumière" /></a>
Le nouveau programme qui contrôle la roue aléaroirement est celui-ci : https://github.com/JessicaJulien/projet/blob/master/Codes/controleRoueNouveau.ino
Voici une démonstration :
<a href="https://www.youtube.com/watch?v=9nWWDmIgQyY"><img src="https://i.ytimg.com/vi/9nWWDmIgQyY/hqdefault.jpg?sqp=-oaymwEZCNACELwBSFXyq4qpAwsIARUAAIhCGAFwAQ==&rs=AOn4CLD37lPgDMVptl--zK_stG-Oz6aO0Q" alt="Roue qui tourne de façon aléatoire avec le nouveau capteur et la lumière" /></a>
* Pour la lumière, on va utilisé une bande de led. J'ai donc programmé cette bande. Le programme est : https://github.com/JessicaJulien/projet/blob/master/Codes/lumiereBlanche.ino
Cela donne : 
![alt text](https://github.com/JessicaJulien/projet/blob/master/Documentation/RoueEclair%C3%A9e.jpg "Roue éclairée")
