#pragma once
#include "sintAnalays.h"
class interpritator
{
	vector<obrPolsk> input;
	vector<obrPolsk> data;
	vector<obrPolsk> code;
	stack<obrPolsk> STACK;
	stack<int> endForLink;
	int forLink;
	int numbWrit;
	int numberOperation;
	obrPolsk newElem;
public:
	interpritator();
	interpritator( vector<obrPolsk> exit);
	int interpritation();
	int doOperation();
	int doLink();
	int doFunc();
	int doWrite();
	int MOV();
	int ADD();
	int SUB();
	int JL();
	int JG();
	int DD();
	int DB();
	int putInFile();
	void getNewElem();
};

