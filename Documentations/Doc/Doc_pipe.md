# PIPE

Un pipe, dans le contexte des systèmes d'exploitation Unix et Linux, est un moyen de rediriger l'entrée et la sortie entre deux processus. Il s'agit essentiellement d'une zone de mémoire tampon dans le noyau du système d'exploitation, qui peut être lue par un processus et écrite par un autre. Les données transmises par un pipe sont organisées en mode FIFO (First In, First Out) : les données écrites en premier sont également lues en premier.

Voici comment fonctionne `pipe()`:

1. **Création du pipe**: Lorsqu'un pipe est créé, il est associé à deux descripteurs de fichier : un pour l'extrémité d'entrée du pipe, et un pour l'extrémité de sortie. Ces descripteurs de fichier sont généralement stockés dans un tableau de deux éléments.

2. **Écriture dans le pipe**: Un processus peut écrire dans le pipe en utilisant le descripteur de fichier associé à l'extrémité de sortie du pipe. Les données écrites dans le pipe sont stockées dans une zone de mémoire tampon du noyau jusqu'à ce qu'elles soient lues.

3. **Lecture du pipe**: Un autre processus peut lire à partir du pipe en utilisant le descripteur de fichier associé à l'extrémité d'entrée du pipe. Les données sont lues dans l'ordre où elles ont été écrites (FIFO). Une fois lues, les données sont supprimées du pipe.

4. **Blocage et synchronisation**: Si un processus tente de lire à partir d'un pipe vide, il est bloqué (c'est-à-dire mis en sommeil) jusqu'à ce que des données soient disponibles. De même, si un processus tente d'écrire dans un pipe qui est plein (la capacité de la mémoire tampon est limitée), il est bloqué jusqu'à ce que de l'espace soit disponible.

5. **Fermeture du pipe**: Lorsqu'un processus a terminé d'utiliser un pipe, il doit fermer les descripteurs de fichier appropriés pour libérer les ressources associées. Si un processus tente de lire à partir d'un pipe dont l'extrémité de sortie a été fermée, il reçoit une fin de fichier (EOF). Si un processus tente d'écrire dans un pipe dont l'extrémité d'entrée a été fermée, il reçoit un signal SIGPIPE et, par défaut, est terminé.

En résumé, `pipe()` est un mécanisme essentiel pour la communication interprocessus et la redirection de l'entrée et de la sortie dans les systèmes d'exploitation Unix et Linux. Il est à la base de nombreux concepts de la programmation multitâche et multiprocessus.
