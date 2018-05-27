#include <stdio.h>
#include "myscanner.h"

extern int yylex();
extern int yylineno;
extern char* yytext;

char *names[] = {
	NULL,
	"ELSE_KEYWORD",
	"IF_KEYWORD",
	"INT_KEYWORD",
	"RETURN_KEYWORD",
	"VOID_KEYWORD",
	"WHILE_KEYWORD",
	"PLUS",
	"MINUS",
	"MULT",
	"DIV",
	"LCHEVRON_EQ",
	"LCHEVRON",
	"RCHEVRON_EQ",
	"RCHEVRON",
	"DBL_EQ",
	"NEQ",
	"EQ",
	"SCOLON",
	"COMMA",
	"LBRACE",
	"RBRACE",
	"LPAREN",
	"RPAREN",
	"LBRACK",
	"RBRACK",
	"ID",
	"NUM",
	"COM_START",
	"COM_END"
 };

int main(void) {
	int ntoken;

	ntoken = yylex();

	while(ntoken) {
		// printf("%d\n", ntoken);

		if((ntoken == 26) || (ntoken == 27)) {
			printf("%s(%s)\n", names[ntoken], yytext);
		} else {
			printf("%s\n", names[ntoken]);
		}

		ntoken = yylex();
	}
}
