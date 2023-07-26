typedef enum
{
	TOKEN_WORD				= 0,	// Ce token est un mot
	TOKEN_PIPE				= 1,	// Ce token est un pipe
	TOKEN_CMD				= 2,	// Ce token est une commande
	TOKEN_CMD_FLAG			= 3,	// Ce token est un flag de commande
	TOKEN_EOF				= 4,	// Ce token definit la fin du fichier
	TOKEN_BUILTINS			= 5,	// Ce token definit les builtins
	TOKEN_SPACE				= 6,	// Ce token definit les espaces
	TOKEN_REDIC_SD			= 7,	// Ce token definit >
	TOKEN_REDIC_SG			= 8,	// Ce token definit <
	TOKEN_REDIC_DD			= 9,	// Ce token definit >>
	TOKEN_REDIC_DG			= 10,	// Ce token definit <<
	TOKEN_QUOTE				= 11,	// Ce token definit les quotes simple
	TOKEN_DQUOTE			= 12,	// Ce token definit les quotes doubles
	TOKEN_DOLLARS			= 13,	// Ce token definit les dollars
	TOKEN_ECHO				= 14,	// Ce token definit echo
	TOKEN_CD				= 15,	// Ce token definit builtin cd
	TOKEN_PWD				= 16,	// Ce token definit builtin pwd
	TOKEN_EXPORT			= 17,	// Ce token definit builtin export
	TOKEN_UNSET				= 18,	// Ce token definit builtin unset
	TOKEN_ENV				= 19,	// Ce token definit builtin env
	TOKEN_EXIT				= 20,	// Ce token definit builtin exit

}Token_Type;

typedef enum
{
	ERR_SUCCESS				= 0,	// Pas d'erreur
	ERR_CMD_NOT_FOUND 		= 1,	// Commande non trouvée
	ERR_SYNTAX				= 2,	// Erreur de syntaxe
	ERR_ARG_REQUIRED		= 3,	// Argument requis pour une commande
	ERR_TOO_MANY_ARGS		= 4,	// Trop d'arguments pour une commande
	ERR_PERMISSION_DENIED	= 5,	// Permission refusée pour une opération
	ERR_FILE_NOT_FOUND		= 6,	// Fichier non trouvé
	
}Error_Type;
