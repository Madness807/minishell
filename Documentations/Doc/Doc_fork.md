# FORK

La fonction `fork()` est une fonction système de l'API POSIX, largement implémentée dans les systèmes d'exploitation de type Unix, dont Linux. Elle est utilisée pour créer un nouveau processus, appelé processus enfant, qui est une copie exacte du processus appelant, appelé processus parent.

Voici comment fonctionne `fork()`:

1. **Création du processus enfant**: Lorsque `fork()` est appelé, le système d'exploitation crée une copie du processus parent. Cette copie est le processus enfant. Cela signifie que le processus enfant hérite de la plupart des attributs du processus parent, tels que les valeurs des variables, les descripteurs de fichiers ouverts, l'environnement utilisateur et le contexte d'exécution.

2. **Différenciation parent/enfant**: Après avoir créé le processus enfant, `fork()` renvoie deux fois : une fois dans le processus parent, et une fois dans le processus enfant. Dans le processus parent, `fork()` renvoie l'ID du processus (PID) du processus enfant nouvellement créé. Dans le processus enfant, `fork()` renvoie 0. C'est ainsi que les deux processus peuvent savoir lequel est le parent et lequel est l'enfant.

3. **Exécution indépendante**: Une fois créés, les processus parent et enfant s'exécutent indépendamment l'un de l'autre. Ils ont chacun leur propre espace d'adressage et leur propre ensemble d'exécutions. Cependant, ils partagent des ressources du système d'exploitation, comme des fichiers ouverts et des signaux.

4. **Modification de l'espace d'adressage**: Si le processus enfant ou le processus parent modifie une variable ou ferme un descripteur de fichier, ces modifications ne sont pas visibles par l'autre processus. Cela est dû au fait que les deux processus ont leur propre espace d'adressage, et donc, ne partagent pas la même mémoire physique.

5. **Fermeture des processus**: Lorsqu'un processus enfant se termine avant le processus parent, il devient un "zombie" jusqu'à ce que le processus parent lise son statut de sortie. De même, si le processus parent se termine avant que le processus enfant ait fini, le processus enfant est "adopté" par le processus init (PID 1), qui lit son statut de sortie lorsque le processus enfant se termine.
