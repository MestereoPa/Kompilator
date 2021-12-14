#include "interpritator.h"
#include <locale>
int main()
{
	setlocale(LC_ALL, "rus");
	Scaner A;
	A.scan();
	A.print_stream_of_lex();
	sintAnalays B(A.stream_of_token,A.table_of_identifier);
	 
	B.analys();
	B.getExit();
	interpritator C(B.exit);
	C.interpritation();
	C.putInFile();
	system("pause");
	return 0;
}
