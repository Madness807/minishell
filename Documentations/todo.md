# Todo list

## Lexer
[X] toknisation des fonctions
[X] creation de la liste chainee pour le stockage 
[X] single quote
[X] double quote
[X] <
[X] >
[X] <<
[X] >>
[X] |
[X] word
[X] cmd
[X] cmd args


## Parsing
[X] gestion des commandes
[X] gestion des builtins
[X] gestion des commandes simple sans pipe
[X] gestion des commandes complexe avec pipe
[] gestion du cas /bin/(une commande)
[X] gestion des quotes simple
[X] gestion des quotes double
[X] gestion du dollars $$$

## Execution 
[X] Comprendre les bases
[X] Implémenter l'exécution simple:
    Commence par implémenter l'exécution d'une commande simple sans pipe ni redirection. Utilise fork et exec pour créer un nouveau processus et exécuter la commande.
[] Gérer les redirections:
    Une fois que tu peux exécuter une commande simple, tu peux commencer à ajouter le support des redirections. Tu devras manipuler les descripteurs de fichier en utilisant des appels système comme open, close, dup2, etc.
[X] Ajouter le support des pipes:
    Les pipes seront probablement la partie la plus complexe. Tu devras utiliser pipe pour créer un tube entre les commandes et dup2 pour rediriger l'entrée et la sortie standard. Cela implique probablement de gérer plusieurs processus et de les synchroniser correctement.
[] Gérer les erreurs et les cas limites:
    Assure-toi de bien gérer les erreurs et les cas limites. Cela inclut la gestion des erreurs d'appels système, le nettoyage des ressources (comme fermer les descripteurs de fichier), et s'assurer que ton code fonctionne correctement dans tous les scénarios possibles.

# Builtins
[X] cd
[1/2] echo (-n) []impossible de revenir en arriere
[X] pwd
[1/2] export //TODO - reste a gerer le cas ou il n ya pas d option pour export 
[X] unset
[X] env
[X] exit 


## Gestion des signaux
[X] ctrl-C affiche un nouveau prompt sur une nouvelle ligne.
[X] ctrl-D quitte le shell.
[X] ctrl-\ ne fait rien.

## Autre truc remarquer
- l-historique ne se comporte pas comme dans bash


# apres correction 00
commande que des espaces, segfault
appelle builtins sans argument, ne pas creer le tableau
building exit, si arguments, il faut changer la valeur numérique représentant le code de sortie du shell
gestion dollard, ajouter le $?
les signaux
.., verbose (ou autre dossier) concidere comme commande (peut etre la fonction stat peut aider)
dans l init, nous faisons une copie du path dans la struc, il faudrai changer ca et faire en sorte que a chaque fois qu on en a besoin, on va le chercher