#include "sintAnalays.h"
sintAnalays::sintAnalays( Table <Token> stream_of_token, vector <Ident> table_of_identifier)
{
	this->stream_of_token = stream_of_token;
	this->table_of_identifier = table_of_identifier;
	tokNumber =0;
	lineNumber = 0;
}
void sintAnalays::newToken()
{
	tokenName = stream_of_token.table.at(tokNumber).get_name();
	tokenType = stream_of_token.table.at(tokNumber).get_type();
	tokNumber++;
}
int sintAnalays::analys()
{
	newToken();
	if (tokenName != "PROGRAMM")
	{
		return ero(1);
	}
	newToken();
	if (tokenName != ";")
	{
		return ero(2);
	}
	if (programBody() == 0)
	{
		return 0;
	}
	cout << "Программа выполнена успешно" << endl;
	return 1;
}
int sintAnalays::programBody()
{
	newToken();
	do
	{
		if (tokenName == "END")
		{
			break;
		}
		if ((tokenType == KEYWORD) | (tokenType == IDENTIFIER))
		{
			if (tokenName == "FUNC")
			{
				if (funChek() == 0)
				{
					return 0;
				}
				newToken();
			}
			else if (BodyChek() == 0)
			{
				return 0;
			}
		}
		else
		{
			return 0;
		}
		if (stream_of_token.table.size() == tokNumber)
		{
			ero(9);
			return 0;
		}
	} while (tokenName != "END");
	return 1;
}
int sintAnalays::checkIdentTable(string tokenName)
{
	for (int i = 0; i < table_of_identifier.size(); i++)
	{
		if (table_of_identifier.at(i).name == tokenName)
		{
			return i;
		}
	}
	return -1;
}
int sintAnalays::forChek()
{
	if (tokenName == "for")
	{
		newToken();
		if (tokenName != "(")
		{
			ero(4);
			return 0;
		}
		else
		{
			newToken();
			if (tokenType != IDENTIFIER)
			{
				ero(5);
				return 0;
			}
			if (checkIdentTable(tokenName) > -1)
			{
				newToken();
				if (tokenName != "=")
				{
					ero(6);
					return 0;
				}
				newToken();
				if (tokenType != CONSTANT)
				{
					ero(8);
					return 0;
				}
				newToken();
				if (tokenName != ":")
				{
					ero(10);
					return 0;
				}
				newToken();
				if (tokenType != CONSTANT)
				{
					ero(8);
					return 0;
				}
				newToken();
				if (tokenName != "by")
				{
					ero(11);
					return 0;
				}
				newToken();
				if (tokenType != CONSTANT)
				{
					ero(8);
					return 0;
				}
				newToken();
				if (tokenName != ")")
				{
					ero(12);
					return 0;
				}
				newToken();
				while (tokenName != "endfor")
				{
					if (BodyChek() == 0)
					{
						return 0;
					}
				}
				newToken();
				if (tokenName != ";")
				{
					ero(2);
					return 0;
				}
			}
			else
			{
				ero(7);
				return 0;
			}
		}
		return 1;
	}
	return 0;
}
int sintAnalays::BodyChek()
{
	lineNumber++;
		if (tokenType == KEYWORD)
		{
			if (tokenName == "FUNC")
			{
				ero(15);
				return 0;
			}
			if (keywordChek() == 0)
			{
				return 0;
			}
		}
		else if (tokenType == IDENTIFIER)
		{
			if (equaChek() == 0)
			{
				return 0;
			}
		}
		else
		{
			ero(14);
			return 0;
		}
		if (stream_of_token.table.size() - 1 == tokNumber)
		{
			ero(13);
			return 0;
		}
		newToken();
		
		return 1;
}
int  sintAnalays::equaChek()
{
	
	int numbInd, numbNext;
	if (tokenType == IDENTIFIER)
	{
		numbInd = checkIdentTable(tokenName);
		if (table_of_identifier.at(numbInd).defined == 0)
		{
			ero(7);
			return 0;
		}
		if (table_of_identifier.at(numbInd).type == "string")
		{
			newToken();
			if (tokenName != "=")
			{
				ero(6);
				return 0;
			}
			newToken();
			if (tokenType == IDENTIFIER)
			{
				if (table_of_identifier.at(checkIdentTable(tokenName)).type != "string")
				{
					ero(16);
					return 0;
				}
				newToken();
				if (tokenName != ";")
				{
					ero(15);
					return 0;
				}
				return 0;
			}

			if (tokenType != DIVIDER)
			{
				ero(15);
				return 0;
			}
			newToken();
			if (tokenType != IDENTIFIER)
			{
				ero(15);
				return 0;
			}
			newToken();
			if (tokenType != DIVIDER)
			{
				ero(15);
				return 0;
			}
			newToken();
			if (tokenName != ";")
			{
				ero(15);
				return 0;
			}
		}
		else
		{
			newToken();
			if (tokenName != "=")
			{
				ero(6);
				return 0;
			}
			int flag = 0;
			do
			{
				newToken();
				if ((tokenType != CONSTANT) && (tokenType != IDENTIFIER))
				{
					if (tokenName == "(")
					{
						newToken();
						if (tokenType == DIVIDER)
						{
							ero(17);
							return 0;
						}
						flag++;
					}
					if (tokenName == "-")
					{
						newToken();
						if (tokenType == DIVIDER)
						{
							ero(17);
							return 0;
						}
					}
					else if (tokenName == ")")
					{
						newToken();
						flag--;
					}
					else
					{
						ero(15);
						return 0;
					}
				}
				if (tokenName == ";")
				{
					break;
				}
				if (tokenType == IDENTIFIER)
				{
					numbNext = checkIdentTable(tokenName);
					newToken();
					if (tokenName == "(")
					{
						newToken();
						if ((tokenType == IDENTIFIER) | (tokenType == CONSTANT))
						{
							newToken();
							if (tokenName != ")")
							{
								ero(12);
								return 0;
							}
							newToken();
						}
						else
						{
							ero(16);
							return 0;
						}
					}
					else
					{
						if (numbNext == -1)
						{
							ero(7);
							return 0;
						}
						if (table_of_identifier.at(numbInd).type != table_of_identifier.at(numbNext).type)
						{
							ero(16);
							return 0;
						}
					}
				}
				else
				{
					newToken();
				}
				if (tokenName == ";")
				{
					break;
				}
				if ((tokenName != "+") && (tokenName != "-") && (tokenName != "*") && (tokenName != "/"))
				{
					ero(3);
					return 0;
				}
			} while (tokenName != ";");
			if (flag != 0)
			{
				ero(12);
				return 0;
			}
		}
		return 1;
	}
	return 0;
}
int sintAnalays::varDecCheck()
{
	int tableNum;
	if (tokenName == "integer" | tokenName == "string" )
	{
		newToken();
		if (tokenType == IDENTIFIER)
		{
			tableNum = checkIdentTable(tokenName);
			if (tableNum == -1)
			{
				ero(19);
				return 0;
			}
			newToken();
			if (tokenName != ";" )
			{
				ero(2);
				return 0;
			}
			table_of_identifier.at(tableNum).defined = 1;
		}
		else
		{
			ero(3);
			return 0;
		}
		return 1;
	}
	return 0;
}
int sintAnalays::keywordChek()
{
	if (tokenName == "for")
	{
		if (forChek() == 0)
		{
			return 0;
		}
	}
	else if (tokenName == "write")
	{
		if (writeChek() == 0)
		{
			return 0;
		}
	}
	else if (tokenName == "FUNC")
	{
		if (funChek() == 0)
		{
			return 0;
		}
	}
	else if(tokenName == "return")
	{
		newToken();
		if (tokenType != IDENTIFIER && tokenType != CONSTANT)
		{
			ero(16);
			return 0;
		}
		newToken();
		if (tokenName != ";")
		{
			ero(2);
			return 0;
		}
	}
	else
	{
		if (varDecCheck() == 0)
		{
			return 0;
		}
	}
	
	return 1;
}
int sintAnalays::writeChek()
{
	newToken();
	if (tokenName != "(")
	{
		ero(4);
		return 0;
	}
	do
	{
		newToken();
		if (tokenName == ")")
		{
			break;
		}
		if (tokenType == DIVIDER)
		{

			newToken();
			if (tokenType != IDENTIFIER && tokenType != CONSTANT)
			{
				ero(16);
				return 0;
			}
			newToken();
			if (tokenType != DIVIDER)
			{
				ero(16);
				return 0;
			}
			if (tokenName == ")")
			{
				ero(16);
				return 0;
			}
		}
		else
		{
			if (tokenType != IDENTIFIER && tokenType != CONSTANT)
			{
				ero(16);
				return 0;
			}
		}
		if (tokenType == IDENTIFIER)
		{
			if (checkIdentTable(tokenName) == -1)
			{
				ero(7);
				return 0;
			}
		}
		newToken();
		if (tokenName != ",")
		{
			if (tokenName == ")")
			{
				break;
			}
			else
			{
				ero(12);
				return 0;
			}
		}
		newToken();
		if (stream_of_token.table.size() - 1 == tokNumber)
		{
			ero(12);
			return 0;
		}
	} while (tokenName != ")");
	newToken();
	if (tokenName != ";")
	{
		ero(2);
		return 0;
	}
	return 1;
}
int sintAnalays::funChek()
{
	if (tokenName == "FUNC")
	{
		Ident a;
		a.type = tokenName;
		newToken();
		if (tokenType != IDENTIFIER)
		{
			ero(5);
			return 0;
		}
		a.name = tokenName;
		newToken();
		if (tokenName != "(")
		{
			ero(4);
			return 0;
		}
		newToken();
		while (tokenName !=")")
		{
			if ((tokenName != "string") && (tokenName != "integer"))
			{
				ero(15);
				return 0;
			}
			newToken();
			if (tokenType != IDENTIFIER)
			{
				ero(15);
				return 0;
			}
			newToken();
			if (tokenName == ")" )
			{
				break;
			}
			if (tokenName != ",")
			{
				ero(17);
				return 0;
			}
			if (stream_of_token.table.size() - 1 == tokNumber)
			{
				ero(12);
				return 0;
			}
			newToken();
		}
		newToken();
		if (tokenName != ";")
		{
			ero(15);
			return 0;
		}
		newToken();
		while (tokenName != "ENDF")
		{
			if (BodyChek() == 0)
			{
				return 0;
			}
		}
		newToken();
		if (tokenName != ";")
		{
			ero(2);
			return 0;
		}
		return 1;
	}
	return 0;
}
int sintAnalays::ero(int er)
{
	if (er == 1)
	{
		cout << "Нет PROGRAM в начале программы" << endl;
	}
	else if (er == 2)
	{
		cout << "Нет ';'" << endl;
	}
	else if (er == 3)
	{
		cout << "Неправильное объявление переменной" << endl;
	}
	else if (er == 4)
	{
	cout << "Ожидается (" << endl;
	}
	else if (er == 5)
	{
		cout << "Ожидается идендификатор" << endl;
	}
	else if (er == 6)
	{
		cout << "Ожидается =" << endl;
	}
	else if (er == 7)
	{
		cout << "Необъявленый идндификатор" << endl;
	}
	else if (er == 8)
	{
		cout << "Ожидается константа" << endl;
	}
	else if (er == 9)
	{
		cout << "Нет END" << endl;
		
	}
	else if (er == 10)
	{
		cout << "Ожидается :" << endl;

	}
	else if (er == 11)
	{
		cout << "Ожидается by" << endl;
	}
	else if (er == 12)
	{
		cout << "Ожидается )" << endl;

	}
	else if (er == 13)
	{
		cout << "нет }" << endl;

	}
	else if (er == 14)
	{
		cout << "втретилась константа" << endl;

	}
	else if (er == 15)
	{
		cout << "Неверное выражение" << endl;

	}
	else if (er == 16)
	{
		cout << "Не совпадение типов" << endl;
	}
	else if (er == 17)
	{
		cout << "Не верное построение" << endl;
	}
	else if (er == 18)
	{
		cout << "Ожидается ','" << endl;
	}
	else if (er == 19)
	{
		cout << "Идентификатор уже обЪявлен" << endl;
	}
	cout << "В строке " << lineNumber << endl;
	return er;
}