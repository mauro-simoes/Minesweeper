# Minesweeper

Français:

Le projet consiste à mettre en place un jeu de démineur (Minesweeper en anglais). Dans ce jeu, il existe une grille composée de plusieurs cases pouvant être des mines ou non. Le but du jeu est de démasquer toutes les cases qui ne sont pas des mines, attention à ne pas démasquer celles-ci ou marquer celles qui ne le sont pas, car sinon le jeu est perdu.
Lorsque l’on démasque une case, s’il y a des mines adjacentes autour, le nombre de celles-ci est affiché. S’il n’y a pas de mines adjacentes, on démasque toutes les cases qui
l’entourent jusqu’à obtenir une zone délimitée par les cases ayant des mines adjacentes.

Pour jouer au démineur, il suffit de lancer le programme puis entrer la dimensions de la grille puis le nombre de mines à placer aléatoirement sur la grille. On entre d'abord le nombre de lignes puis le nombre de colonnes et ensuite le nombre de mines. 
Exemple: 5 7 6. Cela va créer une grille de 5 lignes, 6 colonnes et va placer 6 mines sur la grille.
Ensuite pour jouer, l'utilisateur a le choix de générer un coup au hasard ou de choisir un nouveau coup lui même. Attention, le nouveau coup généré aléatoirement peut aussi provoquer la perte du jeu, elle ne fait que démasquer ou marquer les cases qui n'ont pas encore été jouées.
Voici la syntaxe d'un coup: D15 démasque la case à la position 15. M6 marque la case à la position 6.

English:

In this game called Minesweeper, there is a grid composed of several squares that can be mines or not. The goal of the game is to unmask all the squares that are not mines, be careful not to unmask the mines or mark those that are not, otherwise the game is lost. When you unmask a square, if there are mines adjacent to it, the number of mines is displayed. If there are no adjacent mines, you unmask all the squares around it until you get an area delimited by the squares with adjacent mines.

To play Minesweeper, simply launch the program and enter the size of the grid and the number of mines to be placed randomly on the grid. First you enter the number of rows, then the number of columns and then the number of mines. 
Example: 5 7 6. This will create a grid of 5 rows, 6 columns and will place 6 mines on the grid.
Then to play, the user has the choice to generate a random move or to choose a new move himself. Beware, the new randomly generated move can also make you lose the game, it only unmasks or marks the squares that have not been played yet.
Here is how to write a move: D15 unmasks the square at position 15. M6 marks the square at position 6.
