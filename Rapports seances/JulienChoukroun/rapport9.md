# Avant cette séance

* Avec Jessica, on a ajouté le bouton à notre programme. Pour ce faire, on a rajouté une condition : si on appuie sur le bouton, les roues tournent.
* Puis, on a ajouté le détecteur de pièce (Keyes-01). Le principe est maintenant de passer une pièce devant ce détecteur, puis de faire l'initialisation des roues, enfin d'appuier sur le bouton et faire tourner les roues. On a donc rajouté une condition : si la pièce passe devant le détecteur, on fait l'initialisation des roues. Mais on a rencontré un problème à ce niveau là. En effet, lorsqu'on insérait une pièce, l'initialisation commençait normalement mais ne s'arrêtait jamais. C'est-à-dire que les roues ne s'arrêtaient pas, alors qu'elles étaient cencées tourner au maximum un seul tour, jusqu'à s'arrêter sur les trois "7". En cherchant sur Internet et en testant plusieurs codes, on est arrivé à régler ce problème : dans notre condition qui nous posait problème, on a inséré une nouvelle variable. Ainsi, si on passe la pièce devant le détecteur, on affecte la variable à 1. Et lorsque cette variable est à 1, on peut alors lancer l'initialisation, enfin on remet cette variable à 0. Maintenant, cela fonctionne très bien.
* On a inséré un module bluetooth à notre machine. Le principe est qu'à la fin du jeu, le joueur reçoit sur son téléphone un message l'informant s'il a gagné avec combien de jetons rapportés ou s'il a perdu. Cela fonctionne bien.
* On a mis en place un système de musique grâce à un module MP3. J'ai cherché des sons et musiques en rapport avec les machines à sous. Au final, j'en ai trouvé 4. Je les ai donc téléchargés et modifiés légèrement sur le logiciel Audacity. Parmi ces 4 musiques, il va y avoir une musique d'ambiance dès qu'on appuie sur le bouton jusqu'à l'arrêt complet des roues. Les 3 autres musiques viennent après cette musique là. Parmi les 3 musiques, 2 musiques vont être pour les jackpots : une musique pour le "gros" jackpot (les trois "7") et l'autre musique pour les 2 autres jackpot. Enfin la dernière musique sera la musique si on perd.
* Notre projet est maintenant terminé. Comme nous avons pas pu filmer en salle de cours, j'ai filmé à la maison. Voici 3 démonstrations de la machine à sous.
Jackpot Ananas 5 jetons :
https://www.youtube.com/watch?v=7xNCxAcZ2dk



Remarque : lorsqu'on branche notre alimentation à différents endroits, la rotation des roues est légèrement modifiée. Ce qui fait que dans les vidéos (prises à la maison), les trois symboles ne sont pas tout à fait alignés, alors qu'en salle de cours elle le sont très bien.
