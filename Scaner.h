#ifndef _MY_SCANER_H_
#define _MY_SCANER_H_
#include "Struct.h"
#include <iomanip>
using namespace std;
class Scaner
{
	ifstream in_main;//���� � ������� �����
	KeyWords table_of_keyWords;
	Dividers table_of_dividers;
	
	char keeper_last_char;
public:
	Table <Token> stream_of_token;
	vector <Ident> table_of_identifier;
	Table <Constant> table_of_constant;
	Scaner();
	~Scaner();
	string get_lex();
	bool delete_coment(char c1, char c2);
	void scan();
	void print_stream_of_lex();
	void print_another_table();
	int checkIdentTab(string tokenName);
};
#endif //!_MY_SCANER_H_ 
