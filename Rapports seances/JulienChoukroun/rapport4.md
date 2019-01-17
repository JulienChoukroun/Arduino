# Avant cette séance

* Nous nous sommes rendu au FabLab de Sophia. Puis, de mon côté, j'ai assemblé la nouvelle roue. 
Vue de face :
![alt text](https://github.com/JessicaJulien/projet/blob/master/Documentation/roueAssembl%C3%A9eFace.jpg "Roue assemblée vue de face")
Vue de l'intérieur :
![alt text](https://github.com/JessicaJulien/projet/blob/master/Documentation/roueAssembl%C3%A9eInt%C3%A9rieur.jpg "Roue assemblée vue de l'intérieur")
J'ai amélioré la rotation et l'initialisation de la roue car avec l'ancienne roue, on avait des frottements. Par exemple, entre le détecteur IR et le cercle ouvert situé derrière la roue. Voici une démonstration de l'initialisation avec la nouvelle roue : 
<a href="https://www.youtube.com/watch?v=ye7orix8uuc"><img src="https://i9.ytimg.com/vi_webp/ye7orix8uuc/hqdefault.webp?v=5c3f8e25&sqp=COyc_uEF&rs=AOn4CLBfYhsc0XKkfF-w8Xdc74TVMDyFYg" alt="Initialisation avec la nouvelle roue" /></a>
* J'ai commencé à réaliser le programme qui nous permettra de choisir la position de la roue. C'est-à-dire, après l'initialisation de la roue, on pourra la faire tourner de x secondes afin d'atteindre un certain symbole. Par exemple, pour atteindre le symbole "7", la roue doit faire pile un tour complet. Pour cela, j'ai calculé le temps que mettait la roue à faire un tour complet avec notre vitesse. Le code est le suivant : https://github.com/JessicaJulien/projet/blob/master/Codes/tourComplet.ino

# Séance du 17 Janvier 2019

* Avec Jessica, on a terminé le programme qui permet de choisir la position de la roue. On a rajouté la fonction random() qui permet de faire tourner la roue aléatoirement. Le programme est le suivant :
https://github.com/JessicaJulien/projet/blob/master/Codes/controleRoue.ino
Cependant, on avait un problème. A chaque éxécution de notre programme, on avait toujours la même série de nombre aléatoire qui sortait. Puis, on a trouvé sur internet comment résoudre ce problème : grâce à la fonction randomSeed(). Maintenant le problème est résolu.
On a aussi eu un autre problème. Pour faire un seul tour complet, notre roue met 390 ms. Mais lorsqu'on veut la faire tourner 10 fois, par exemple, on est obligé d'augmenter le temps de rotation à 460 ms. En effet, notre roue subit des frottements avec notre détecteur pendant les 10 rotations. Notre détecteur n'étant pas très stable, il est difficile de ne pas avoir de frottements même en limant la paroi.
Voici une démonstration du programme avec notre roue :
<a href="https://youtu.be/nJUigsxkim4"><img src="https://i.ytimg.com/vi/nJUigsxkim4/hqdefault.jpg?sqp=-oaymwEZCNACELwBSFXyq4qpAwsIARUAAIhCGAFwAQ==&rs=AOn4CLAlhKNWUaXY5nWeAloN1L3EWfA4bg" alt="Roue qui tourne de façon aléatoire" /></a>
* A partir de maintenant on pourra assembler nos programmes, c'est-à-dire, les programmes de la roue et du monnayeur.
