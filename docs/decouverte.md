il y a deux type de commande 
les commandes builtin qui seront executer sans cree de nouveau processus
et les commandes externes qui elle utilise execve (ex: ls, cat etc)

la premiere etape de la tokenisation aussi appeler lexer consiste a 

decouper nos arguments d entree dans quelque chose d exploitable par le parsing

EX: ls - l | grep e
donne -->               [ls] [-l] [|] [grep] [e]
de sorte a ce que si l on tombe sur ls il va chercher les flags reconnait -l et en
fait une string complete utilisable 

PS j ai surment oublier des trucs ou pas tout compris mais je suis sur a 90% de ce 
que je dit  

bisous