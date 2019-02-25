# Séance du 25 Février 2019
Durant les vacances, avec Julien, nous avons réalisé toutes les mesures et créés tous les schémas nécessaires pour l'impression de notre boite. 
Celle-ci fut prête aujourd'hui. Nous l'avons donc monté pour avoir le résultat suivant:
![alt text](https://github.com/JessicaJulien/projet/blob/master/Documentation/BoiteMachine.jpg)
Durant les vacances, j'ai également travaillé sur un système de "tobogan" pour que les jetons du monnayeur soient bien guidés vers la sortie. Cela sera prêt d'ici peu.
<br/>
Pendant ce cours, nous avons également tenté de faire fonctionner correctement l'ensemble roue + monnayeur. Le programme utilisé est le suivant:
https://github.com/JessicaJulien/projet/blob/master/Codes/rouesMonnayeur.ino
<br/>
Cependant quelques problèmes ont été rencontrés.<br/>
Dans un premier temps, lorsqu'on connectait les 4 servomoteurs sur la carte, nos roues tournaient beaucoup trop longtemps. 
Pour remédier à ce problème nous avons mis un condensateur.<br/>
Puis, les valeurs utilisées pour le fonctionnement du monnayeur (les positions de 3 valeurs identiques) sont obsolètes puisqu'elles ont été mesurées avant certaines 
modifications des roues. Mais le véritable problème est que l'on ne parvient pas encore à contrôler de manière précise les positions des roues. 
Nous avons aujourd'hui réalisé des tests avec certaines valeurs mais il y avait certaines incohérences (une valeur qui renvoie deux positions différentes etc).
