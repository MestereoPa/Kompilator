#pragma once
#include "Scaner.h"
class sintAnalays
{
	Table <Token> stream_of_token;
	vector <Ident> table_of_identifier;
	int tokNumber;
	int constNumber;
	int indNumber;
	string tokenName;
	int tokenType;
	int lineNumber;
public:
	int forChek();
	void newToken();
	int BodyChek();
	int keywordChek();
	int writeChek();
	int equaChek();
	int varDecCheck();
	int ero(int er);
	int analys();
	int programBody();
	int checkIdentTable(string tokenName);
	int funChek();
	sintAnalays(Table <Token> stream_of_token, vector <Ident> table_of_identifier);
};
