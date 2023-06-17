Bien sûr, voici un résumé de chaque builtin que vous avez mentionné :

1. `echo` : Cette commande imprime ses arguments à l'écran. Elle prend également en charge quelques options, comme `-n` qui supprime le saut de ligne final.

2. `cd` : Change le répertoire courant. Sans argument, il se déplace vers le répertoire spécifié dans la variable d'environnement `HOME`. Avec un argument, il tente de se déplacer vers le répertoire spécifié.

3. `pwd` : Affiche le répertoire de travail actuel. 

4. `export` : Utilisée pour définir ou modifier les variables d'environnement. Avec aucun argument, elle liste toutes les variables d'environnement.

5. `unset` : Supprime une variable d'environnement. 

6. `env` : Sans arguments, il affiche toutes les variables d'environnement. Avec des arguments, il peut être utilisé pour exécuter une commande dans un environnement modifié.

7. `exit` : Termine le shell. Elle accepte un argument optionnel qui spécifie le code de sortie.

Chacune de ces commandes a ses propres détails et comportements spécifiques en fonction des arguments et des options, donc vous pouvez avoir besoin de faire plus de recherches ou de tests pour comprendre comment elles fonctionnent en détail. Pour une description plus détaillée de chaque commande, vous pouvez utiliser la commande `man` suivie du nom de la commande dans un terminal Unix pour afficher le manuel de cette commande. Par exemple, `man echo` affichera le manuel pour la commande `echo`.