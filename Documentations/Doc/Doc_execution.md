# EXECUTION

Les fonctions `exec` sont un ensemble de fonctions système dans l'API POSIX, largement implémentées dans les systèmes d'exploitation de type Unix, dont Linux. Elles sont utilisées pour remplacer le programme actuellement en cours d'exécution par un nouveau programme.

Voici comment fonctionnent les fonctions `exec` :

1. **Remplacement du programme actuel** : Lorsqu'une fonction `exec` est appelée, le programme actuellement en cours d'exécution est complètement remplacé par le nouveau programme. C'est comme si le processus actuel cessait d'exister, sauf que son ID de processus (PID) et ses fichiers ouverts restent les mêmes. Le nouveau programme commence son exécution à son point d'entrée principal (par exemple, la fonction `main()` pour un programme C).

2. **Chargement du nouveau programme** : Le système d'exploitation est responsable du chargement du nouveau programme en mémoire. Cela implique de lire le fichier exécutable du nouveau programme à partir du système de fichiers, de configurer un nouvel espace d'adressage pour lui, et de le préparer pour l'exécution.

3. **Passage des arguments** : Les fonctions `exec` prennent une liste d'arguments qui sont passés au nouveau programme. Le premier argument est généralement le nom du nouveau programme lui-même, et le dernier argument doit être un pointeur null. Ces arguments sont accessibles dans le nouveau programme via les paramètres argc et argv de sa fonction principale.

4. **Modification de l'environnement** : Certaines variantes de la fonction `exec` permettent également de modifier l'environnement du nouveau programme, c'est-à-dire l'ensemble de paires clé-valeur qui stockent des informations comme le répertoire de travail courant, le chemin d'accès au système de fichiers, et ainsi de suite.

5. **Non retour** : Si l'appel à `exec` réussit, il ne revient jamais. Le nouveau programme remplace complètement l'ancien et continue son exécution indépendamment. Si l'appel à `exec` échoue (par exemple, parce que le fichier exécutable du nouveau programme ne peut pas être trouvé), alors il retourne une valeur d'erreur au programme original qui peut alors gérer cette erreur.

En résumé, les fonctions `exec` sont un moyen puissant de lancer de nouveaux programmes et de faire des transitions entre différents programmes dans un système d'exploitation Unix ou Linux. Elles sont à la base de nombreux concepts dans la programmation multitâche et multiprocessus.


D'accord, reprenons les étapes pour faire fonctionner la commande `ls -la | grep .md > toto`.

Pour réaliser cela, vous devez :

1. Créer un pipeline entre `ls -la` et `grep .md` pour permettre à la sortie de `ls -la` d'être l'entrée de `grep .md`.
2. Rediriger la sortie de `grep .md` vers le fichier `toto`.

Voici une approche étape par étape :

### 1. Création du pipe:

Lorsque vous créez un pipe avec la fonction `pipe()`, elle retourne deux descripteurs de fichiers:

- `fd[0]` : C'est l'extrémité en lecture.
- `fd[1]` : C'est l'extrémité en écriture.

Si `ls -la` écrit dans `fd[1]`, `grep .md` doit lire depuis `fd[0]`.

### 2. Redirection de la sortie standard:

Avant d'exécuter `ls -la`, redirigez sa sortie standard vers `fd[1]` avec `dup2()`:

```c
dup2(fd[1], STDOUT_FILENO);
```

### 3. Exécution de la première commande:

Exécutez `ls -la`.

### 4. Fermeture des descripteurs de fichiers appropriés:

Fermez `fd[1]` après avoir exécuté `ls -la` et avant d'exécuter `grep .md` pour vous assurer qu'il n'y a pas de descripteurs de fichiers inutilisés ouverts.

### 5. Redirection de l'entrée standard:

Avant d'exécuter `grep .md`, redirigez son entrée standard pour lire depuis `fd[0]` avec `dup2()`:

```c
dup2(fd[0], STDIN_FILENO);
```

### 6. Redirection de la sortie standard vers le fichier:

Ouvrez le fichier `toto` et obtenez son descripteur de fichier. Redirigez la sortie standard de `grep` vers ce fichier:

```c
int file_fd = open("toto", O_WRONLY | O_CREAT | O_TRUNC, 0644);
dup2(file_fd, STDOUT_FILENO);
```

### 7. Exécution de la deuxième commande:

Exécutez `grep .md`.

### 8. Fermeture de tous les descripteurs de fichiers:

Fermez `fd[0]`, `fd[1]` et `file_fd` après avoir terminé pour libérer les ressources.

---

Si vous suivez ces étapes, la sortie de `ls -la` devrait être passée à `grep .md` et la sortie de `grep .md` devrait être écrite dans le fichier `toto`.

Assurez-vous également de gérer les erreurs pour chaque appel système, comme `pipe()`, `dup2()`, `open()`, etc.