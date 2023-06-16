# Librairie
--------------------------------------------------------------------
- readline.h : Bibliothèque pour la lecture et l'édition de lignes de texte.
- stdio.h : Bibliothèque standard d'entrée/sortie pour les opérations de lecture et d'écriture.
- stdlib.h : Bibliothèque standard pour les opérations générales telles que l'allocation mémoire et la gestion des variables d'environnement.
- unistd.h : Bibliothèque pour les appels système Unix, tels que la lecture, l'écriture, l'ouverture et la fermeture de fichiers, ainsi que la gestion - des processus.
- fcntl.h : Bibliothèque pour le contrôle des fichiers, y compris l'ouverture et la modification des attributs de fichiers.
- sys/wait.h : Bibliothèque pour la gestion et la synchronisation des processus fils.
- signal.h : Bibliothèque pour la gestion des signaux entre les processus.
- sys/stat.h : Bibliothèque pour les opérations sur les attributs de fichiers et les informations de fichiers.
- dirent.h : Bibliothèque pour la gestion des répertoires et la lecture des entrées de répertoire.
- string.h : Bibliothèque pour la manipulation des chaînes de caractères et la gestion des erreurs.
- sys/ioctl.h : Bibliothèque pour le contrôle des opérations d'entrée/sortie sur les fichiers et les périphériques.
- termios.h : Bibliothèque pour la gestion et la configuration des terminaux.
- term.h : Bibliothèque pour les opérations sur la base de données terminfo et les capacités des terminaux.

# Fonctions autorisées
--------------------------------------------------------------------
## Bibliothèque Standard C (stdlib.h, stdio.h, string.h)
### Gestion de la mémoire
- Allouer de la mémoire dynamiquement
    void *malloc(size_t size);

- Libérer la mémoire allouée
    void free(void *ptr);

### Gestion des erreurs
- Renvoyer un message d'erreur pour un code d'erreur
    char *strerror(int errnum);

- Afficher un message d'erreur pour un appel système
    void perror(const char *s);

### Autres
- Terminer un processus
    void exit(int status);

- Afficher un texte formaté
    int printf(const char *format, ...);

- Obtenir la valeur d'une variable d'environnement
    char *getenv(const char *name);

## Bibliothèque de gestion des processus (unistd.h, sys/wait.h)
- Créer un nouveau processus
    pid_t fork(void);

- Attendre la fin d'un processus fils
    pid_t wait(int *status);

- Attendre un processus fils spécifique
    pid_t waitpid(pid_t pid, int *status, int options);

- Attendre un processus fils (obsolète)
    pid_t wait3(int *status, int options, struct rusage *rusage);

- Attendre un processus fils avec usage de ressources
    pid_t wait4(pid_t pid, int *status, int options, struct rusage *rusage);

- Envoyer un signal à un processus
    int kill(pid_t pid, int sig);

- Exécuter un nouveau programme
    int execve(const char *filename, char *const argv[], char *const envp[]);


## Bibliothèque de gestion des signaux (signal.h)
- Modifier le comportement lors d'un signal
    void (*signal(int signum, void (*handler)(int)))(int);

- Examine ou modifie l'action associée à un signal
    int sigaction(int signum, const struct sigaction *act, struct sigaction *oldact);

- Initialise un ensemble de signaux vide
    int sigemptyset(sigset_t *set);

- Ajouter un signal à un ensemble de signaux
    int sigaddset(sigset_t *set, int signum);

## Bibliothèque readline (readline/readline.h, readline/history.h)
- Lire une ligne de texte à partir d'une entrée
    char *readline(const char *prompt);

- Effacer l'historique des commandes de readline
    void rl_clear_history(void);

- Indiquer une nouvelle ligne
    void rl_on_new_line(void);

- Remplacer le contenu de la ligne
    int rl_replace_line(const char *text, int clear_undo);

- Réafficher la ligne actuelle
    void rl_redisplay(void);

- Ajouter une ligne à l'historique
    void add_history(const char *line);


## Bibliothèque de gestion des fichiers et répertoires (fcntl.h, unistd.h, sys/stat.h, dirent.h)
- Ouvrir un fichier
    int open(const char *pathname, int flags, ...);

- Écrire des données dans un descripteur de fichier
    ssize_t write(int fd, const void *buf, size_t count);

- Vérifier les permissions d'accès d'un fichier
    int access(const char *pathname, int mode);

- Lire des données à partir d'un descripteur de fichier
    ssize_t read(int fd, void *buf, size_t count);

- Fermer un descripteur de fichier
    int close(int fd);

- Obtenir le répertoire de travail actuel
    char *getcwd(char *buf, size_t size);

- Changer le répertoire de travail actuel
    int chdir(const char *path);

- Obtenir les informations d'un fichier
    int stat(const char *pathname, struct stat *statbuf);

- Obtenir les informations d'un lien symbolique
    int lstat(const char *pathname, struct stat *statbuf);

- Obtenir les informations d'un descripteur de fichier
    int fstat(int fd, struct stat *statbuf);

- Supprimer un fichier ou un lien
    int unlink(const char *pathname);

- Dupliquer un descripteur de fichier
    int dup(int oldfd);

- Dupliquer un descripteur de fichier avec un numéro spécifique
    int dup2(int oldfd, int newfd);

- Créer un pipe (tube) entre deux processus
    int pipe(int pipefd[2]);

- Ouvrir un répertoire
    DIR *opendir(const char *name);

- Lire une entrée de répertoire
    struct dirent *readdir(DIR *dirp);

- Fermer un répertoire
    int closedir(DIR *dirp);


## Bibliothèque de gestion des terminaux (termios.h, unistd.h, libgen.h)
- Tester si un descripteur de fichier est un terminal
    int isatty(int fd);

- Obtenir le nom du terminal associé à un descripteur de fichier
    char *ttyname(int fd);

- Obtenir l'indice du terminal d'un utilisateur
    int ttyslot(void);

- Contrôler les opérations d'E/S
    int ioctl(int fd, unsigned long request, ...);

- Modifier les attributs d'un terminal
    int tcsetattr(int fd, int optional_actions, const struct termios *termios_p);

- Obtenir les attributs d'un terminal
    int tcgetattr(int fd, struct termios *termios_p);

- Charger la base de données terminfo
    int tgetent(char *bp, const char *name);

- Obtenir une valeur booléenne de terminfo
    int tgetflag(const char *id);

- Obtenir une valeur numérique de terminfo
    int tgetnum(const char *id);

- Obtenir une valeur de chaîne de terminfo
    char *tgetstr(const char *id, char **area);

- Générer un code de déplacement du curseur
    char *tgoto(const char *cap, int col, int row);

- Écrire une chaîne de terminfo avec délai
    int tputs(const char *str, int affcnt, int (*putc)(int));
