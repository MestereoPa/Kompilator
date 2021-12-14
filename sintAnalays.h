#pragma once
#include "Scaner.h"
#include <stack>
class sintAnalays
{
	Table <Token> stream_of_token;
	vector <Ident> table_of_identifier;
	stack<obrPolsk> polsk; 
	
	string tokenName;
	int tokNumber;
	int constNumber;
	int indNumber;
	int tokenType;
	int lineNumber;
public:
	vector<obrPolsk> exit;
	void newToken();
	void getExit();
	int priorityChek(string sign);
	int forChek();
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


