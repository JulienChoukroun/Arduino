# Pendant les vacances de Noël

* J'ai réaliser un programme qui fait tourner la roue pendant x secondes. Le code utilisé est le suivant :
https://github.com/JessicaJulien/projet/blob/master/Codes/actionneEtArreteRoue.ino
Voici une démonstration :
<a href="https://www.youtube.com/watch?v=P78dixj0G8c&feature=youtu.be"><img src="https://i9.ytimg.com/vi_webp/P78dixj0G8c/hqdefault.webp?sqp=CITf3eEF&rs=AOn4CLCLHE27qrml0_1gy-CMptJZxHhBCg" alt="Roue qui tourne et s'arrête" /></a>
On voit que la roue possède une vitesse convenable. Nous avons donc le bon moteur.
* J'ai mis en place le détecteur IR sur la roue afin de détecter les différents symboles à l'aide d'encoches derrière la roue. 
![alt text](https://github.com/JessicaJulien/projet/blob/master/Documentation/roueAvecDetecteurIR.jpg "roue avec détecteur IR")
J'ai commencé par programmer l'initialisation de la roue. Cela va nous servir lorsqu'on va actionner le futur bras. A ce moment là, les roues vont tourner jusqu'à trouver une fente particulière, puis s'arrêter. Le code utilisé est le suivant :
https://github.com/JessicaJulien/projet/blob/master/Codes/initialisationRoue.ino 
Voici une démonstration : 
<a href="https://www.youtube.com/watch?v=aghbIHAVvek&feature=youtu.be"><img src="https://i9.ytimg.com/vi_webp/aghbIHAVvek/hqdefault.webp?sqp=CITf3eEF&rs=AOn4CLBVnJ4Bq2pxXOr6dprsz5JHd4p_7w" alt="Initialisation de la roue à vitesse lente" /></a>
Ici, j'ai testé l'initalisation de la roue à vitesse lente car j'ai eu un problème. Notre roue n'est qu'un prototype réalisé à la main donc les découpes ne sont pas parfaites. Ainsi, le détecteur passe quelque fois dans des "vides" et donc arrête la roue alors qu'il y a pas de fentes. On va donc utiliser les découpeuses laser et imprimantes 3D, afin d'obtenir une roue parfaite.

* J'ai donc commencé à modéliser les pièces pour aller au FabLab de Sophia.

# Séance du 10 Janvier 2019

* J'ai d'abord fini de modéliser les pièces avec les bonnes dimensions finales. Voici toutes les pièces qu'on va découper/imprimer : 
https://github.com/JessicaJulien/projet/tree/master/Pieces
* J'ai participé à la mise en place du monnayeur avec un servomoteur à rotation 180° (fixation du servomoteur sur une petite planche de bois). Puis, on a réaliser le code qui va nous permettre de renvoyer les pièces gagnées. Le voici :
https://github.com/JessicaJulien/projet/blob/master/Codes/monnayeur1.ino
* J'ai réalisé un code qui permet de compter le nombre de fentes pendant que la roue tourne. Voici le code :
https://github.com/JessicaJulien/projet/blob/master/Codes/compteFentes.ino 
Cependant, il n'est pas encore terminé car les tests avec le prototype sont quelques fois faussés.
* Nous avons revu le code de l'initialisation et sommes tombés sur un problème. Si on crée une fente pour chaque logo, on ne pourra plus initialiser la roue. On a donc eu l'idée d'agrandir uniquement la fente de l'initialisation, pour la différencier des autres fentes. Mais une nouvelle idée est venue. On créera une seule fente pour toute la roue, ainsi qu'un programme qui calculera la vitesse du servomoteur. On va alors obtenir le distance parcourue et donc la position de la roue.

* Juste après cette séance, on s'est rendu au FabLab de Sophia et avons découpé/imprimé les pièces modélisés. Je vais donc m'occuper du montage de la roue.
