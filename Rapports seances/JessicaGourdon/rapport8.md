# Séance du 17 Janvier 2019
Aujourd'hui avec Julien nous avions comme objectif de finaliser le système de rotation de la roue. 
Julien avait commencé à créer un programme pour cela. Il y a d'abord l'initialisation durant laquelle la roue tourne jusqu'au moment où le capteur atteigne la fente.
Notre objectif était de faire tourner la roue pendant un certain nombre de secondes avant qu'elle se fige à une certaine position.
On déterminerait celle-ci grâce à un calcul prenant en compte le temps que la roue met pour faire un tour complet.
Julien avait donc mesuré ce temps. </br>
Aujourd'hui nous avons eu une idée qui simplifierait les choses. Il s'agit de faire tourner 1 fois la roue dans un premier temps. 
Grâce à la mesure du temps de Julien, il nous restait alors plus qu'à créer une boucle. Dans un deuxième temps, on tirait un nombre aléatoire 
qui déciderait de la position finale de la roue (position adoptée pendant le onzième et dernier tour de roue). </br>
Nous avons rencontré plusieurs problèmes.
Cependant, on avait un problème. Tout d'abord, lors de chaque éxécution du programme la même série de nombres "aléatoires" étaient tirés.
Nous avons alors trouvé sur internet qu'utiliser la fonction randomSeed() résoudrait notre problème. Puis, nous avions un problème de vitesse.
En effet, pour réaliser un tour complet, notre roue met 390 ms. Mais pour lui faire réaliser 10 tours complets celle-ci mettra 460 ms par tour.
Nous pensons que cela est dû aux frottements exercés par le détecteur sur la roue.  </br>
Nous avons néanmoins réussi à finaliser ce système de rotation.
Le code est le suivant:  https://github.com/JessicaJulien/projet/blob/master/Codes/controleRoue.ino
