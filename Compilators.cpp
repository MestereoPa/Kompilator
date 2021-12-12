#include "sintAnalays.h"
#include <locale>
int main()
{
	setlocale(LC_ALL, "rus");
	Scaner A;
	A.scan();
	A.print_stream_of_lex();
	sintAnalays B(A.stream_of_token,A.table_of_identifier);
	B.analys();
	system("pause");
	return 0;
}
