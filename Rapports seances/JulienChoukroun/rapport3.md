# Pendant les vacances de Noël
* J'ai réaliser un programme qui fait tourner la roue pendant x secondes.
<a href="https://www.youtube.com/watch?v=QCF7HrBWTgs&t=0s&index=6&list=LLB7UFHfT3-WoMwWvKr9C8wA"><img src="https://i.ytimg.com/vi_webp/QCF7HrBWTgs/hqdefault.webp" alt="Arduino Fruit Machine - Feature Reel" /></a>

<a href="https://www.youtube.com/watch?v=P78dixj0G8c&feature=youtu.be"><img src="
On voit que la roue possède une vitesse convenable. Nous avons donc le bon moteur.
* J'ai mis en place le détecteur IR sur la roue afin de détecter les différents symboles à l'aide d'encoches derrière la roue. 
![alt text](https://github.com/JessicaJulien/projet/blob/master/Documentation/roueAvecDetecteurIR.jpg "roue avec détecteur IR")
J'ai commencé par programmer l'initialisation de la roue. Cela va nous servir lorsqu'on va actionner le futur bras. A ce moment là, les roues vont tourner jusqu'à trouver une fente particulière, puis s'arrêter. Voici une démonstration : (mettre video). 
Ici, j'ai testé l'initalisation de la roue à vitesse lente car j'ai eu un problème. Notre roue n'est qu'un prototype réalisé à la main donc les découpes ne sont pas parfaites. Ainsi, le détecteur passe quelque fois dans des "vides" et donc arrête la roue alors qu'il y a pas de fentes. On va donc utiliser les découpeuses laser et imprimantes 3D, afin d'obtenir une roue parfaite.