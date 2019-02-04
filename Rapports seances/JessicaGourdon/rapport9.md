# Séance du 4 Février 2019
Initialement, nous voulions mettre un bras sur notre machine à sous, mais au vue des versions actuelles dans les casinos nous avons
pensé qu'il serait plus moderne de réaliser un système de bouton. Pour actionner les roues, il sera nécessaire d'insérer 
un jeton puis d'appuyer sur le bouton. Aujourd'hui, j'ai donc réaliser les tests d'un gros bouton poussoir avec une LED dans un premier temps.
Le code est celui-ci: https://github.com/JessicaJulien/projet/blob/master/Codes/bouton_projet.ino  <br/>
Une fois ce travail effectué je me suis occupée de la décoration des roues. J'ai donc collé chaque autocollant au bon emplacement sur celles-ci.
Les centres de chaque autocollant sont espacés un à un de 6,5 cm.
![alt text](https://github.com/JessicaJulien/projet/blob/master/Documentation/roue.autocollant.jpg)
Nous avons eu également une idée concernant la rotation des roues. Après avoir fait tourner les roues 10 fois, au lieu de prendre un nombre aléatoire
décidant de la position finale de la roue, nous souhaitons créer une liste de nombres correspondant à la position du centre de chaque autocollant.
On tirera alors aléatoirement un nombre parmi cette liste pour décider de la position finale de chaque roue. Cela permettra d'éviter que la position finale se situe entre deux autocollants.
Je m'occuperai prochainement de créer cette liste de nombres.
