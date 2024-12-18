# 🟣 Rapport projet TicTacToe ✖️

Ce projet de jeu TicTacToe, réalisé par Océane Drapeau, a été effectué dans le cadre du cours Prog & Algo 1 en IMAC1, encadré par Enguerrand DE SMET.

## 🚨Indications

Le code a été testé uniquement sur Windows. Il se joue dans le terminal après compilation.

## 📝 L'implémentation

J'ai opté pour une structure de fichiers simple : tous les fichiers sont regroupés dans le dossier `src`, à l'exception de `CMakeLists.txt` et `README.md` qui sont  à la racine du projet.

🟦 [main.cpp](./src/main.cpp)

Ce fichier regroupe les initialisations liées au jeu (symboles, joueurs, plateau de jeu) et gère sa logique globale, en répétant les tours jusqu'à la victoire d'un joueur ou un match nul.

🟦 [player.cpp](./src/player.cpp) & [player.hpp](./src/player.hpp) 🟪

Il s'agit des fichiers permettant la création des différents joueurs (humain, IA) et qui définissent la structure `Player`

J'ai choisi d'ajouter à la struct une variable booléenne `isAI`. Cette variable permet alors d'avoir un comportement différencié lors du jeu.

De plus, j'ai séparé les fonctions permettant d'obtenir le nom et le symbole du joueur. Cela m'a permis de réutiliser la même fonction pour le nom du deuxième joueur.

Par ailleurs, que le second joueur soit un humain ou une IA, il ne peut pas choisir son symbole, puisque dans notre cas seuls deux étaient possibles 'X' et 'O' et celui-ci dépend du symbole du premier joueur. Si je voulais initialiser un second joueur avec le choix d'autres symboles j'aurais appelé deux fois la même fonction et vérifier à la sortie si les symboles sont identiques.

🟦 [game_board.cpp](./src/game_board.cpp) & [game_board.hpp](./src/game_board.hpp) 🟪

Ceux-ci permettent la création et l'affichage du plateau de jeu

Le plateau est un tableau de 9 éléments, il est initialisé grace à la fonction `create_game_board` avec des caractères vides (des espaces). 

Pour l'afficher, c'est avec la fonction `draw_game_board` qui peut prendre comme paramètre une variable booléenne nommée "help". Celle-ci était à la base pour des phases de tests, cependant, j'ai décidé de la laisser. Je n'ai pas eu le temps de l'exploiter pleinement, mais dans l'idéal, cela aurait été dans le but de créer un second menu qui proposerait les règles du jeu et si le joueur veut jouer avec ou sans numéro dans les cases.

🟦 [game_play.cpp](./src/game_play.cpp) & [game_play.hpp](./src/game_play.hpp) 🟪

Ces fichiers contiennent le coeur du jeu (jouer 1 tour, gérer les mouvements des joueurs, conditions de victoire)

Pour les conditions de victoire, j'ai choisi de partir de la dernière position du joueur et de regarder dans toutes les directions voir si trois symboles sont alignés.

Objectivement, il existe des manières plus simples pour arriver au même résultat, vu qu'il n'existe que 8 combinaisons gagnantes. Cependant, dans le cas d'un plateau de jeu plus grand, mon hypothèse est que cela aurait permis de réduire le nombre de combinaisons testées.

🟦 [verification.cpp](./src/verification.cpp) & [verification.hpp](./src/verfication.hpp) 🟪

Ils permettent d'effectuer des vérifications sur les entrées utilisateurs en fonction de la demande. Il y a deux types de fonctions : la première vérifie simplement si l'entrée est valide (et peut être réutilisée pour d'autres usages), tandis que l'autre demande à l'utilisateur d'entrer une valeur.

🟦 [menu.cpp](./src/menu.cpp) & [menu.hpp](./src/menu.hpp) 🟪

Ces fichiers contiennent le menu de démarrage, permettent son affichage et récupèrent une valeur valide correspondant à l'une des options.

## 📊 Bilan

🆘 Problème : création `checkDirection`

Lors de la création de cette fonction, j'ai eu du mal avec le fait que le tableau soit en une seule dimension et les limites invisibles du plateau de jeu.

Par exemple, alors que l'on peut théoriquement aller à la gauche lorsqu'on est sur la deuxième ou la troisième ligne, ce n'est pas le comportement voulu. Pareil pour aller à droite ou les diagonales.

🚁 Solution
Pour résoudre ce problème j'ai ajouté des conditions plus strictes dans la fonction.

```cpp
!((move == static_cast<int>(Move::Left) && index % nbOfColumns == 0) || 
(move == static_cast<int>(Move::Right) && index % nbOfColumns == nbOfColumns - 1) ||

(move == static_cast<int>(Move::RightToLeftDown) && index % nbOfColumns == 0) ||
(move == static_cast<int>(Move::LeftToRightUp) && index % nbOfColumns == nbOfColumns - 1))
```

🆘 Problème : Trop de changements de direction

Lorsque la fonction `checkDirection` trouve un symbole identique dans une direction et qu'elle ne peut pas continuer, elle change de direction et continue le même compte.

Or, si le plateau est le suivant et que X vient de placer une croix dans la deuxième case, la fonction `main` renvoie "X a gagné". 

```cpp
std::array<char, 9> gameBoard
{
    'O', 'X', 'O',
    'X', 'O', 'X',
    ' ', ' ', 'X',
};
```
Alors que ce n'est pas le cas !

En fait ce qu'il se passe c'est qu'une fois les premières directions passées (haut, bas, gauche, droite), il restait les quatres directions suivantes :

```cpp
Move::LeftToRightDown, //vaut +4
Move::RightToLeftUp, // vaut -4

Move::RightToLeftDown, // vaut +2
Move::LeftToRightUp; // vaut -2
```

C'est à dire les diagonales ↘↖ et ↙↗.

Dans notre cas, il y a bien un symbole identique en index 5. Donc, le compte continue après avoir descendu la diagonale ↘.Puis s'arrête par ce que c'est un bord du tableau. Ensuite ça teste ↖, qui n'est pas possible.

Mais au lieu de renvoyer un compte vide, cela continuait sur les directions suivantes soit (↙↗). Et en index 3, il y a aussi un symbole identique, donc la fonction win renvoyait true, et c'était la fin du jeu.

🚁 Solution
Pour régler ce problème, j'ai ajouté un compteur `change` qui ajoute 1 dès que le compte de répétitions est réutilisé pour une autre direction.

J'ai également ajouté une condition qui fait que si on a changé plus de deux fois de directions en gardant le même compteur (c'est à dire qu'on a trouvé un symbole identique dans trois directions), c'est qu'il y a eu une erreur quelque part.

🚨 Sécurité `checkDirection`

En l'état la fonction est opérationnelle. Cependant, par manque de temps, j'ai fait l'impasse sur la sécurité de la fonction et sur son utilisation.

En effet, si l'on venait à modifier le tableau `directions` en ajoutant, en supprimant ou en échangeant deux directions, les variables `skip` et `newDirection` n'auront pas le bon comportement. De même, l'ordre des directions permet de tester un sens puis le sens inverse directement, ce qui aurait été bien ce serait de le définir qu'une seule fois et de faire dans un cas + le mouvement et dans l'autre - le mouvement.

🆘Problème : `playAI`

Au début je pensais qu'il fallait faire jouer l'IA sur la première case vide du plateau de jeu, j'ai du modifier pour que ce soit aléatoire dans`getRandomPosition`.

Cependant, j'avais gardé la même logique que pour le for prévu initialement (dès qu'une case est vide, je retourne la position) dans le while. (`while (gameBoard[i] == empty )`)

🚁 Solution

J'ai mis du temps à comprendre, puisque aucune erreur était renvoyée lors de la compilation. C'est finalement en changeant la condition à `while (gameBoard[i] != empty )` que ça s'est résolu.