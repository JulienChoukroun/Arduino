# Pendant les vacances de Noël

* J'ai réaliser un programme qui fait tourner la roue pendant x secondes. Le code utilisé est le suivant :
https://github.com/JessicaJulien/projet/blob/master/Codes/actionneEtArreteRoue.ino
Voici une démonstration :
<a href="https://www.youtube.com/watch?v=P78dixj0G8c&feature=youtu.be"><img src="https://i9.ytimg.com/vi_webp/P78dixj0G8c/hqdefault.webp?sqp=CLzT2OEF&rs=AOn4CLB07hcUmO9a3qzS6QvR912UUbnyCg" alt="Roue qui tourne et s'arrête" /></a>
On voit que la roue possède une vitesse convenable. Nous avons donc le bon moteur.
* J'ai mis en place le détecteur IR sur la roue afin de détecter les différents symboles à l'aide d'encoches derrière la roue. 
![alt text](https://github.com/JessicaJulien/projet/blob/master/Documentation/roueAvecDetecteurIR.jpg "roue avec détecteur IR")
J'ai commencé par programmer l'initialisation de la roue. Cela va nous servir lorsqu'on va actionner le futur bras. A ce moment là, les roues vont tourner jusqu'à trouver une fente particulière, puis s'arrêter. Le code utilisé est le suivant :
https://github.com/JessicaJulien/projet/blob/master/Codes/initialisationRoue.ino
Voici une démonstration : 
<a href="https://www.youtube.com/watch?v=aghbIHAVvek&feature=youtu.be"><img src="https://i9.ytimg.com/vi_webp/aghbIHAVvek/hqdefault.webp?sqp=CLzT2OEF&rs=AOn4CLBZgoCJJr0aYKvDATmtY2B-olJolQ" alt="Initialisation de la roue à vitesse lente" /></a>
Ici, j'ai testé l'initalisation de la roue à vitesse lente car j'ai eu un problème. Notre roue n'est qu'un prototype réalisé à la main donc les découpes ne sont pas parfaites. Ainsi, le détecteur passe quelque fois dans des "vides" et donc arrête la roue alors qu'il y a pas de fentes. On va donc utiliser les découpeuses laser et imprimantes 3D, afin d'obtenir une roue parfaite.

# Séance du 10 Janvier 2019
