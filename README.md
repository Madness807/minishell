# MINISHELL

# Table des matières

1. [BUT](#But-1)
2. [Notions](#Notions)
3. [Fonctions autorisées](#Function-autorisée-pour-ce-projet-1)

# BUT
- Afficher un prompt en l’attente d’une nouvelle commande.
- Posséder un historique fonctionnel.
- Chercher et lancer le bon exécutable (en se basant sur la variable d’environnement
PATH, ou sur un chemin relatif ou absolu).
- Ne pas utiliser plus d’une variable globale. Réfléchissez-y car vous devrez justifier son utilisation.
- Ne pas interpréter de quotes (guillemets) non fermés ou de caractères spéciaux non
  demandés dans le sujet, tels que \ (le backslash) ou ; (le point-virgule).
- Gérer ’ (single quote) qui doit empêcher le shell d’interpréter les méta-caractères
  présents dans la séquence entre guillemets.
- Gérer " (double quote) qui doit empêcher le shell d’interpréter les méta-caractères
  présents dans la séquence entre guillemets sauf le $ (signe dollar).
- Implémenter les redirections :
  -  [ < ] doit rediriger l’entrée.
  -  [ > ] doit rediriger la sortie.
  -  [ << ] doit recevoir un délimiteur et lire l’input donné jusqu’à rencontrer une ligne
       contenant le délimiteur. Cependant, l’historique n’a pas à être mis à jour !
  -  [ >> ] doit rediriger la sortie en mode append.
- Implémenter les pipes (caractère |). La sortie de chaque commande de la pipeline
  est connectée à l’entrée de la commande suivante grâce à un pipe.
- Gérer les variables d’environnement (un $ suivi d’une séquence de caractères)
  qui doivent être substituées par leur contenu.
- Gérer $? qui doit être substitué par le statut de sortie de la dernière pipeline
  exécutée au premier plan.
- Gérer ctrl-C, ctrl-D et ctrl-\ qui doivent fonctionner comme dans bash.
- En mode interactif :
  - ctrl-C affiche un nouveau prompt sur une nouvelle ligne.
  - ctrl-D quitte le shell.
  - ctrl-\ ne fait rien.
- Votre shell doit implémenter les builtins suivantes :
  - echo et l’option -n
  - cd uniquement avec un chemin relatif ou absolu
  - pwd sans aucune option
  - export sans aucune option
  - unset sans aucune option
  - env sans aucune option ni argument
  - exit sans aucune option
  
  # Les builtins en détails.
  1. `echo` : Cette commande imprime ses arguments à l'écran. Elle prend également en charge quelques options, comme `-n` qui supprime le saut de ligne final.

  2. `cd` : Change le répertoire courant. Sans argument, il se déplace vers le répertoire spécifié dans la variable d'environnement `HOME`. Avec un argument, il tente de se déplacer vers le répertoire spécifié.

  3. `pwd` : Affiche le répertoire de travail actuel. 

  4. `export` : Utilisée pour définir ou modifier les variables d'environnement. Avec aucun argument, elle liste toutes les variables d'environnement.

  5. `unset` : Supprime une variable d'environnement. 

  6. `env` : Sans arguments, il affiche toutes les variables d'environnement. Avec des arguments, il peut être utilisé pour exécuter une commande dans un environnement modifié.

  7. `exit` : Termine le shell. Elle accepte un argument optionnel qui spécifie le code de sortie.

La fonction readline() peut causer des fuites de mémoire. Vous n’avez pas à les
gérer. Attention, cela ne veut pas pour autant dire que votre code, oui celui que
vous avez écrit, peut avoir des fuites de mémoire.

# Fonctions autorisées 
|Fonction           |Utilité                                                            |Prototype                                                                             |Bibliothèque|
|:----------------- |:------------------------------------------------------------------|:-------------------------------------------------------------------------------------|--------------|
|readline 	        |Lire une ligne de texte à partir d'une entrée	                    |char *readline(const char *prompt);	                                               |readline.h|
|rl_clear_history 	|Effacer l'historique des commandes de readline	                    |void rl_clear_history(void);	                                                       |readline.h|
|rl_on_new_line	    |Indiquer une nouvelle ligne	                                    |void rl_on_new_line(void);	                                                           |readline.h|
|rl_replace_line	|Remplacer le contenu de la ligne	                                |int rl_replace_line(const char *text, int clear_undo);	                               |readline.h|
|rl_redisplay		|Réafficher la ligne actuelle	                                    |void rl_redisplay(void);	                                                           |readline.h|
|add_history      	|Ajouter une ligne à l'historique	                                |void add_history(const char *line);	                                               |readline.h|
|printf	            |Afficher un texte formaté	                                        |int printf(const char *format, ...);	                                               |stdio.h|
|malloc	            |Allouer de la mémoire dynamiquement	                            |void *malloc(size_t size);	                                                           |stdlib.h|
|free	            |Libérer la mémoire allouée	                                        |void free(void *ptr);	                                                               |stdlib.h|
|write	            |Écrire des données dans un descripteur de fichier	                |ssize_t write(int fd, const void *buf, size_t count);	                               |unistd.h|
|access	            |Vérifier les permissions d'accès d'un fichier	                    |int access(const char *pathname, int mode);	                                       |unistd.h|
|open	            |Ouvrir un fichier	                                                |int open(const char *pathname, int flags, ...);	                                   |fcntl.h|
|read	            |Lire des données à partir d'un descripteur de fichier	            |ssize_t read(int fd, void *buf, size_t count);	                                       |unistd.h|
|close	            |Fermer un descripteur de fichier	                                |int close(int fd);	                                                                   |unistd.h|
|fork             	|Créer un nouveau processus	                                        |pid_t fork(void);	                                                                   |unistd.h|
|wait	            |Attendre la fin d'un processus fils	                            |pid_t wait(int *status);	                                                           |sys/wait.h|
|waitpid          	|Attendre un processus fils spécifique	                            |pid_t waitpid(pid_t pid, int *status, int options);	                               |sys/wait.h|
|wait3            	|Attendre un processus fils (obsolète)	                            |pid_t wait3(int *status, int options, struct rusage *rusage);	                       |sys/wait.h|
|wait4            	|Attendre un processus fils avec usage de ressources	            |pid_t wait4(pid_t pid, int *status, int options, struct rusage *rusage);	           |sys/wait.h|
|signal           	|Modifier le comportement lors d'un signal	                        |void (*signal(int signum, void (*handler)(int)))(int);	                               |signal.h|
|sigaction        	|Examine ou modifie l'action associée à un signal	                |int sigaction(int signum, const struct sigaction *act, struct sigaction *oldact);	   |signal.h|
|sigemptyset      	|Initialise un ensemble de signaux vide	                            |int sigemptyset(sigset_t *set);	                                                   |signal.h|
|sigaddset        	|Ajouter un signal à un ensemble de signaux	                        |int sigaddset(sigset_t *set, int signum);	                                           |signal.h|
|kill             	|Envoyer un signal à un processus	                                |int kill(pid_t pid, int sig);	                                                       |signal.h|
|exit             	|Terminer un processus	                                            |void exit(int status);	                                                               |stdlib.h|
|getcwd           	|Obtenir le répertoire de travail actuel	                        |char *getcwd(char *buf, size_t size);	                                               |unistd.h|
|chdir            	|Changer le répertoire de travail actuel	                        |int chdir(const char *path);	                                                       |unistd.h|
|stat             	|Obtenir les informations d'un fichier	                            |int stat(const char *pathname, struct stat *statbuf);	                               |sys/stat.h|
|lstat            	|Obtenir les informations d'un lien symbolique	                    |int lstat(const char *pathname, struct stat *statbuf);	                               |sys/stat.h|
|fstat            	|Obtenir les informations d'un descripteur de fichier	            |int fstat(int fd, struct stat *statbuf);	                                           |sys/stat.h|
|unlink           	|Supprimer un fichier ou un lien	                                |int unlink(const char *pathname);	                                                   |unistd.h|
|execve           	|Exécuter un nouveau programme	                                    |int execve(const char *filename, char *const argv[], char *const envp[]);	           |unistd.h|
|dup              	|Dupliquer un descripteur de fichier	                            |int dup(int oldfd);	                                                               |unistd.h|
|dup2              	|Dupliquer un descripteur de fichier avec un numéro spécifique	    |int dup2(int oldfd, int newfd);	                                                   |unistd.h|
|pipe             	|Créer un pipe (tube) entre deux processus	                        |int pipe(int pipefd[2]);	                                                           |unistd.h|
|opendir           	|Ouvrir un répertoire	                                            |DIR *opendir(const char *name);	                                                   |dirent.h|
|readdir          	|Lire une entrée de répertoire	                                    |struct dirent *readdir(DIR *dirp);	                                                   |dirent.h|
|closedir         	|Fermer un répertoire	                                            |int closedir(DIR *dirp);	                                                           |dirent.h|
|strerror         	|Renvoyer un message d'erreur pour un code d'erreur	                |char *strerror(int errnum);	                                                       |string.h|
|perror           	|Afficher un message d'erreur pour un appel système	                |void perror(const char *s);	                                                       |stdio.h|
|isatty           	|Tester si un descripteur de fichier est un terminal	            |int isatty(int fd);	                                                               |unistd.h|
|ttyname          	|Obtenir le nom du terminal associé à un descripteur de fichier	    |char *ttyname(int fd);	                                                               |unistd.h|
|ttyslot          	|Obtenir l'indice du terminal d'un utilisateur	                    |int ttyslot(void);	                                                                   |unistd.h|
|ioctl            	|Contrôler les opérations d'E/S	                                    |vint ioctl(int fd, unsigned long request, ...);	                                   |sys/ioctl.h|
|getenv           	|Obtenir la valeur d'une variable d'environnement	                |char *getenv(const char *name);	                                                   |stdlib.h|
|tcsetattr        	|Modifier les attributs d'un terminal	                            |int tcsetattr(int fd, int optional_actions, const struct termios *termios_p);	       |termios.h|
|tcgetattr        	|Obtenir les attributs d'un terminal	                            |int tcgetattr(int fd, struct termios *termios_p);	                                   |termios.h|
|tgetent          	|Charger la base de données terminfo	                            |int tgetent(char *bp, const char *name);                                              |term.h|
|tgetflag         	|Obtenir une valeur booléenne de terminfo	                        |int tgetflag(const char *id);	                                                       |term.h|
|tgetnum          	|Obtenir une valeur numérique de terminfo	                        |int tgetnum(const char *id);	                                                       |term.h|
|tgetstr          	|Obtenir une valeur de chaîne de terminfo	                        |char *tgetstr(const char *id, char **area);	                                       |term.h|
|tgoto            	|Générer un code de déplacement du curseur	                        |char *tgoto(const char *cap, int col, int row);	                                   |term.h|
|tputs            	|Écrire une chaîne de terminfo avec délai	                        |int tputs(const char *str, int affcnt, int (*putc)(int));	                           |term.h|
