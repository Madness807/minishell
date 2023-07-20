# PATH=

1. /usr/local/sbin
Ce répertoire est prévu pour les binaires exécutables du système qui sont généralement utilisés par l'administrateur du système (le "super-utilisateur" ou "root"). Le "sbin" signifie "system binaries". Les programmes qui résident dans ce répertoire sont généralement utilisés pour la maintenance du système, le démarrage, l'arrêt, et ainsi de suite.

2. /usr/local/bin
Ce répertoire est destiné aux programmes qui ont été installés localement et qui sont destinés à être utilisés par tous les utilisateurs du système. Lorsqu'un logiciel est installé à partir des sources, c'est généralement là qu'il est installé.

3. /usr/sbin
Ce répertoire est similaire à /usr/local/sbin, mais il contient des binaires exécutables du système qui sont fournis par l'éditeur du système d'exploitation lui-même, plutôt que des logiciels tiers ou locaux.

4. /usr/bin
Ce répertoire contient des binaires exécutables pour tous les utilisateurs. La plupart des commandes standard qui ne sont pas nécessaires au démarrage, à la restauration, à la réparation ou d'autres tâches de maintenance du système sont ici.

5. /sbin
Ce répertoire est similaire à /usr/local/sbin et /usr/sbin, mais il est réservé pour les binaires exécutables du système qui sont nécessaires avant que /usr ne soit monté. Il contient des binaires exécutables tels que init, route, ifconfig, etc.

6. /bin
Ce répertoire est similaire à /usr/bin, mais il est réservé pour les commandes qui sont nécessaires avant que /usr ne soit monté. Il contient des commandes essentielles que tous les utilisateurs doivent pouvoir utiliser, même en mode mono-utilisateur ou en mode de récupération. Les exemples de ces commandes sont ls, echo, cat, sh, etc.