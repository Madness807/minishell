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
[] gestion des commandes simple sans pipe
[] gestion des commandes complexe avec pipe
[] gestion du cas /bin/(une commande)
[] gestion des quotes simple
[] gestion des quotes double
[] gestion du dollars $$$


## Execution
[] re implementer pipex version minishell
[X] variables d'environement et les substituer par leur contenu


# Builtins
[X] cd
[1/2] echo (-n)
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