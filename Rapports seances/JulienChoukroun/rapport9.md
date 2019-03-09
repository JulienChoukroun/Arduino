# Avant cette séance

* 


Pendant que Julien continuait de travailler sur les roues, je me suis occupée de l'insertion des jetons. J'ai donc fixé un détecteur FC-03 sur la paroi du bac récupérateur de jetons. Nous avons ensuite écrit le code de façon à déclencher l'initialisation des roues lorsque l'on insère un jeton. Nous avons alors eu un problème. Les roues qui, pendant l'initialisation, étaient censés réaliser seulement un tour avant de s'arrêter sur les trois 7, ne s'arretaient plus du tout.

#Travail du 7 Mars Aujourd'hui nous avons réglé le problème de l'initialisation. En effet, au lieu de simplement mettre un "if" qui verifiait la condition "Etat du detecteur de jeton à 1" avant de lancer l'initialisation, nous avons créé une nouvelle variable. Si l'état du détecteur de jetons est à 1, la variable prend la valeur 1. Et si cette variable est à 1, alors on lance l'initialisation des roues. A la fin de celle-ci, on remet notre variable à 0. Grâce cela notre initialisation marche très bien. Ensuite, nous avons mis en place le module Bluetooth. L'objectif est que l'on puisse avoir sur notre smartphone un message nous informant si l'on a gagné et combien de jetons on a gagné dans ce cas. Nous avons réussi à réaliser cela.

#Travail du 8 Mars Aujourd'hui nous avons mis en place le système de musique avec un module MP3. A l'aide du logiciel Audacity nous avons modifié un son. En effet, nous souhaitions mettre une musique d'ambiance pendant que les roues tournaient. Nous avons donc rallongé un son trouvé sur internet pour qu'il dure 10 secondes (durée pendant laquelle les roues tournent vite). Nous avons ensuite mis une musique lorsque l'on gagne le grand Jackpot (les trois 7). Puis nous avons mis une autre musique lorsque l'on obtient trois figures identiques (autre que les trois sept). Enfin, nous avons mis un son en cas de défaite. Tout marche très bien à présent.
