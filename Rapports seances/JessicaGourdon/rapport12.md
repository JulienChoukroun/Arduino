# Week-end du 3 Mars
Durant ce week-end je me suis occupé de monter la boite. J'ai collé les bords et j'ai peint en noir l'exterieur. Je me suis également occupé de la porte  l'arrière. Pour cela,
j'ai mis des charnières, un bouton pour l'ouverture ainsi que des crochets pour éviter que la porte ne vienne endommager le matériel à l'intérieur de la boite.
Je me suis également charger de mettre des poignées pour faciliter le transport. 
![alt text](https://github.com/JessicaJulien/projet/blob/master/Documentation/PorteBoite.jpg)
J'ai ensuite travaillé sur le dispositif de sortie des jetons. J'ai donc abandonné mon idée de "tobogan" à jeton. A présent il y a 
un petit tiroir dans lequel le monnayeur fait tomber les jetons à la sortie. On peut le voir ici :
![alt text](https://github.com/JessicaJulien/projet/blob/master/Documentation/tiroir.jpg)
Je me suis ensuite occupé de l'insertion des jetons. J'ai donc créé une boite possédant une encoche à travers laquel ceux-ci seront insérés.
![alt text](https://github.com/JessicaJulien/projet/blob/master/Documentation/InterieurBoite.jpg)

# Séance du 04 Mars 2019
Durant cette séance, avec Julien nous avons dans un premier temps travaillé uniquement sur les roues. Nous avons donc fait des réglages 
par rapport au delay() puisque les troies roues ne se lancent pas en même temps. Grâce à cela, nous avons permis aux trois roues de pouvoir
commencer à tourner en même temps. On a donc réussi à obtenir trois symboles identiques.<br/>
Nous avons ensuite réalisé les mesures du temps nécessaire pour obtenir chaque symbole. Ces mesures nous seront utiles pour créer notre liste à
partir de laquelle on tirera notre nombre aléatoire qui décidera de la position de chaque roue. Nous avons donc adapté le code du monnayeur 
avec ces nouvelles données. Le code est celui-ci: https://github.com/JessicaJulien/projet/blob/master/Codes/rouesMonnayeurTriche.ino
<br/>
Puis, nous avons decidé de connecter les roues et le monnayeur ensemble. Nous avons alors eu un problème. Le monnayeur, qui a toujours très bien fonctionné
jusque là, ne fonctionnait plus. On a donc changé de moteur. Cependant, il ne fonctionnait toujours pas après cela. Nous avons donc découvert que le problème 
provenait de câbles abimés. A présent, le monnayeur fonctionne à nouveau.
<br/>
Néanmoins, un problème subsiste. Selon l'endroit où l'alimentation est branchée le temps de rotation des roues est modifié. Les valeurs de temps que l'on mesure sont donc 
elles aussi modifiées. Il en résulte que l'alignement des symbôles en fin de rotation est compromis.<br/>
Voici une photo de la boite finale:
![alt text](https://github.com/JessicaJulien/projet/blob/master/Documentation/BoiteMontee.jpg)



 


