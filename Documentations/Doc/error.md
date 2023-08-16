# liste des erreurs de sortie

Exit code [127] -> Command not found – La commande n'existe pas ou n'est pas dans le $PATH.

Exit code [126] -> Permission denied – Vous essayez d'exécuter un fichier sans permissions d'exécution.

Exit code [127] -> No such file or directory – Le fichier ou le répertoire spécifié n'existe pas.

Exit code [1]   -> Syntax error near unexpected token – Erreur de syntaxe dans le script.

Exit code [1]   -> Ambiguous redirect – Vous avez donné une redirection qui n'est pas claire (par exemple, essayant de rediriger vers plus   d'un fichier sans utiliser des caractères appropriés).

Exit code [126] -> Cannot execute [file]: Permission denied – Vous essayez d'exécuter un fichier sans les permissions appropriées.

Exit code [127] -> [command]: command not found – Erreur courante lorsque la commande spécifiée n'est pas installée.

Exit code [128 + 13 || 141] -> Broken pipe – Se produit généralement lorsque vous utilisez un pipe (|) et la première commande se termine avant que la deuxième ne démarre.

Exit code [128 + 11 || 139] -> Segmentation fault – Lorsqu'un programme tente d'accéder à une mémoire qu'il n'est pas censé accéder.

Exit code [128 + 8 || 136] -> Arithmetic error – Erreur lors de l'évaluation d'une expression arithmétique.

Exit code [1] -> Directory stack not that deep – Lors de l'utilisation de la commande dirs avec un nombre trop élevé.

Exit code [2] -> Too many arguments – Lorsqu'une commande ou un script est appelé avec plus d'arguments que prévu.


# Exit status code bash

## Francais
- 0 : Succès
- 1 : Échec générique / Erreur inconnue
- 2 : Mauvaise utilisation d'une commande intégrée (builtin)
- 126 : La commande invoquée ne peut pas être exécutée (permissions insuffisantes ou autre)
- 127 : "command not found" (commande non trouvée)
- 128 : Code de sortie invalide d'une commande
- 128 + N : Erreur fatale de signal N
    Par exemple:
    - 130: Script terminé avec Ctrl+C (SIGINT)
    - 137: Script terminé avec kill -9 (SIGKILL)
    - 139: Erreur de segmentation (SIGSEGV)
- 255 : Code de sortie hors de portée

## Anglais
- 0 : Success
- 1 : Generic failure / Unknown error
- 2 : Misuse of shell builtins
- 126 : Command invoked cannot execute (insufficient permissions or other)
- 127 : "command not found"
- 128 : Invalid exit argument
- 128 + N : Fatal error signal N
    For example:
    - 130: Script terminated with Ctrl+C (SIGINT)
    - 137: Script killed with kill -9 (SIGKILL)
    - 139: Segmentation fault (SIGSEGV)
- 255 : Exit status out of range