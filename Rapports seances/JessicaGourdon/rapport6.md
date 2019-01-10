# Séance du 10 Janvier
Aujourd'hui, nous avons trouvé une petite planche en bois fine de 3mm que l'on a fixé au servomoteur. Nous avons ensuite réalisé quelques tests pour observer la rotation de ce dispositif.
Nous avons donc modifier le code du monnayeur. Le nouveau est le suivant: https://github.com/JessicaJulien/projet/blob/master/Codes/monnayeur1.ino
Par la suite nous avons réflechi aux dimensions à prendre pour réaliser les jetons ainsi que l'écart à laisser entre le socle et le cylindre.
Nous avons donc décidé de prendre une épaisseur de 4 mm pour les jetons. Ainsi, nous laissons un écart de 5 mm entre le socle et le cylindre( 1 mm en plus pour éviter tout frottement).
Le schéma du monnayeur est donc le suivant:
![alt text](https://github.com/JessicaJulien/projet/blob/master/Documentation/NouveauMonnayeur.jpg)
<strong> Problème de la roue </strong> <br/>
Nous rencontrons un problème par rapport à la détection de la position initiale de la roue.
Dans un premier temps, nous avons pensé à mettre une petite fente au niveau de chaque autocollant sur la roue et une grande fente à l'endroit où l'on souhaitera que la roue commence à tourner ( la position initiale).
La première fois, la roue tournera lentement pour détecter la position initiale. Une fois la grande fente détectée, la roue s'arrête au niveau de cette position initiale. Ensuite, on fait tourner la roue à sa vitesse normale pendant un certain nombre de secondes tout en comptant le nombre de fentes rencontrées pour pouvoir se repérer.
Puis nous nous sommes rendus compte qu'il serait plus simple de ne réaliser qu'une seule fente, située à la position initiale. Par la suite, grâce à la précision de la vitesse du moteur et à l'aide d'un calcul, nous serons en mesure de connaître la position finale du détecteur. 
