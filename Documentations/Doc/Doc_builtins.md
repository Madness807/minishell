## BUILTINS

Les commandes "builtins" ou "internes" sont des commandes qui sont directement intégrées dans le shell lui-même. Elles sont appelées "builtins" (intégrées) parce qu'elles ne sont pas des programmes externes qui sont chargés à partir du disque, mais font plutôt partie intégrante du code du shell.

Cela signifie que lorsque vous tapez une commande builtin dans le shell, le shell sait immédiatement comment l'exécuter et n'a pas besoin de chercher un programme externe correspondant dans le système de fichiers. Cela peut rendre les commandes builtin plus rapides à exécuter que les commandes externes, surtout si elles sont utilisées fréquemment.

- `cd` : change le répertoire de travail courant.
- `pwd` : affiche le chemin du répertoire de travail courant.
- `echo` : affiche une chaîne de caractères ou une variable à l'écran.
- `export` : déclare une variable d'environnement.
- `unset` : supprime une variable ou une fonction.
- `env` : affiche les variables d'environnement ou exécute une commande dans un environnement modifié.
- `exit` : termine la session du shell.
