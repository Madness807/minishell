# Compilation

- [X]	Utilisez "make -n" to pour vous assurer que le projet
		compile avec "-Wall -Wextra -Werror". Si ce n'est
		pas le cas, cochez le flag "invalid compilation".

- [X]	Le minishell compile sans aucune erreur. Si ce n'est
		pas le cas, cochez le flag

- [X]	Le Makefile ne doit pas re-link. Si ce n'est pas le
		cas, cochez le flag

# Commande simple et variables globales

- [X]	Exécutez une commande simple avec un PATH
		absolu tel que /bin/Is ou n'importe quelle autre
		commande sans option.

- [X]	Combien de variables globales y a-il 2 Pourquoi
		Demandez a la personne évaluée de vous donner
		un exemple concret pour démontrer que leur usage
		est obligatoire et cohérent.

- [X]	Testez une commande vide.

- [ ]	Test ez seulement des espaces et des tabs.//FIXME - 

# Arguments

- [X]	Exécutez une commande simple avec un PATH
		absolu tel que /bin/Is ou n'importe quelle autre
		commande, avec option mais sans" (single quotes)
		ni" (double quotes).

- [X]	Répétez ce test plusieurs fois avec différentes
		commandes et différents arguments.

# echo

- [ ]	Lancez la commande echo avec et sans argument//FIXME - 
		‘ou options, ou avec l'option -n.

- [X]	Répétez ce test plusieurs fois avec différents
		arguments.

# exit

- [ ]	Lancez la commande exit avec et sans arguments.//FIXME - 

- [ ]	Répétez ce test plusieurs fois avec différents//FIXME - 
		arguments.

# Valeur de retour d'un processus

- [ ]	Exécutez des commandes simple avec un chemin//TODO - 
		absolu tel que /bin/Is ou n'importe quelle autre
		commande avec des arguments mais sans " (single
		quotes) ni" (double quotes), puis lancez "echo $?"
		Vérifiez la valeur affichée. Vous pouvez le refaire
		dans bash et comparer.

- [ ]	Répétez ce test plusieurs fois avec différentes//TODO - 
		commandes et différents arguments.

- [ ]	Utilisez des commandes qui ne fonctionnent pas//TODO - 
		telles que '/bin/Is fichiernul’.

- [ ]	Essayez des expressions telles que $? + $?//TODO - 

# Signaux//TODO - 

- [ ]	ctrl-C dans un prompt vide devrait afficher une
		nouvelle ligne avec un nouveau prompt.

- [ ]	ctrl-\ dans un prompt vide ne devrait rien faire.

- [ ]	ctrl-D dans un prompt vide devrait quitter minishell.
		Ensuite, relancez-le.

- [ ]	ctrl-C dans un prompt aprés avoir écrit des choses
		devrait afficher une nouvelle ligne avec un nouveau
		prompt.

- [ ]	Egalement, le buffer devrait étre vide. Appuyez sur
		"Entrée" afin de vous assurer que la ligne
		précédente a été exécutée.

- [ ]	ctrl-D dans un prompt aprés avoir écrit des choses
		ne devrait rien faire.

- [ ]	ctrl-\ dans un prompt aprés avoir écrit des choses
		ne devrait rien faire.

- [ ]	Essayez ctrl-C aprés avoir lancé une commande
		bloquante, comme cat ou grep sans argument.

- [ ]	Essayez ctrl-\ aprés avoir lancé une commande
		bloquante, comme cat ou grep sans argument.

- [ ]	Essayez ctrl-D aprés avoir lancé une commande
		bloquante, comme cat ou grep sans argument.

- [ ]	Répétez plusieurs fois en utilisant des commandes
		différentes.

# Double Quotes

- [X]	Exécutez une commande simple avec des
		arguments, mais cette fois utilisez des guillemets
		(rajoutez des '; et des espaces entre les guillemets)

- [X]	Essayez une commande comme : echo “cat lol.c |
		cat > lol.c"

# Single Quotes

- [X]	Exécutez des commandes avec des single quotes
		dans les arguments.

- [X]	Essayez des arguments vides.

- [X]	Faites des tests avec des variables d'environnement,
		des espaces, des pipes, des redirections entre les
		guillemets.

- [X]	echo '$USER' doit afficher "$USER"

- [X]	Rien ne devrait étre interprété.

# env

- [X]	Vérifiez qu'env vous affiche bien les variables
		d'environnement.

# export

- [X]	Exportez des variables d'environnement, dont
		certaines pour remplacer les anciennes.
- [X]	Vérifiez le résultat avec env.

# unset

- [X]	Exportez des variables d'environnement, dont
		certaines pour remplacer les anciennes.

- [X]	Ufilisez unset pour en retirer.

- [X]	Vérifiez le résultat avec env.

# cd

- [ ]	Utilisez la commande cd pour vous déplacer dans//FIXME - 
		Varborescence et utilisez /bin/Is pour vérifier que
		vous étes dans le bon répertoire.

- [ ]	Répétez ce test plusieurs fois avec des cd qui//FIXME - 
		fonctionnent et qui ne fonctionnent pas.

- [ ]	Essayez aussi '.’ et ".." en arguments.//FIXME - 

# pwd

- [X]	Utilisez la commande pwd, avec et sans argument.

- [X]	Répétez ce test plusieurs fois dans différents
		répertoires.

- [X]	Essayez '.' et '..' en arguments.

# Chemin relatif

- [ ]	Exécutez des commandes en utilisant un chemin//FIXME - 
		relatif.

- [ ]	Répétez ce test plusieurs fois dans d'autres dossier//FIXME - 
		avec un chemin relatif complexe (beaucoup de ..).

# PATH d'environnement

- [ ]	Exécutez des commandes mais sans PATH (Is, wc,
		awk, etc...).

- [ ]	Retirez le $PATH et vérifiez si les commandes ne
		fonctionnent plus.

- [ ]	Mettez plusieurs répertoires & PATH
		(directory 1 :directory2) et vérifiez qu'ils sont bien
		évalués de gauche droite.

# Redirection

- [ ]	Exécutez des commandes avec les redirections <//FIXME - 
		et / ou >

- [X]	Répétez ce test plusieurs fois avec différentes
		commandes et différents arguments et, quelques
		fois, utilisez >> au lieu de >.

- [ ]	Vérifiez si plusieurs instances de la méme redirection
		échovent.

- [ ]	Testez les redirections avec << (cela ne doit pas//FIXME -
		forcément mettre & jour I'historique).

# Pipes

- [ ]	Exécutez des commandes avec des pipes telles que
		‘cat file | grep bla | more!

- [ ]	Répétez plusieurs fois avec différentes commandes
		et différents arguments.

- [ ]	Essayez des commandes qui échovent telles que ‘ls.
		fichiernul | grep bla | more’

- [ ]	Mixez les pipes et les redirections.

# Soyons fous ! Et I'historique

- [ ]	Entrez une commande, puis ctrl-C, et appuyez sur
		"Entrée". Le buffer devrait étre vide et il ne devrait
		plus rien avoir & exécuter.

- [ ]	Peut-on naviguer dans I'historique avec Haut et Bas
		(profitez-en pour relancer des commandes) @

- [ ]	Exécutez des commandes qui ne fonctionnent pas
		telles que 'dskdskdksd' et vérifiez que tout
		fonctionne comme préwu.

- [ ]	‘cat | cat | Is' doit fonctionner.

- [ ]	Essayez des commandes vraiment, vraiment
		longues avec des tonnes d'arguments.

- [ ]	Amusez-vous avec ce superbe minishell et profitez-

# Variables d'environnement

- [ ]	Exécutez echo avec des variables d'environnement
		($variable) en argument.

- [ ]	Assurez-vous que § est interprété correctement.

- [ ]	Vérifiez que les guillemets autour des $variables
		fonctionnent correctement (comme dans bash).

- [ ]	Si USER n'existe pas, définissez-la.

- [ ]	Ainsi, echo "$USER" devrait afficher la valeur de
		SUSER.

