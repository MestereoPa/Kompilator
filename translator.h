#pragma once
#include "sintAnalays.h"
class translator
{
	vector<obrPolsk> input;// ����������� ��  �����
	vector<obrPolsk> data;// �������� ������ ����� ������ 
	vector<obrPolsk> code;// �������� ������ ����� ����
	stack<obrPolsk> STACK;// ���� ��� ��������� �����������
	stack<int> endForLink;// ���� ��� ���������� ������ ������ ��� �����
	int forLink;// ����� ����
	int numbWrit;
	int numberOperation;// ����� �������� �� �����������
	obrPolsk newElem;// ����� �������
public:
	translator();// ����������� ��-�
	translator( vector<obrPolsk> exit); // ����������� � ����������  ��������������
	int translation(); // �������� �-� ��-�
	int doOperation();// ������� ��������
	int doLink();// ���������� ������
	int doFunc(); // ������ � ��������
	int doWrite(); // ���������� ������ �� �������
	int MOV(); // ����� ���
	int ADD(); // ���������� ��
	int SUB(); // ���������� ���������
	int JL(); // ���������� <3
	int JG(); // postroenie >
	int DD(); // postroenie opisaniya peremennoy
	int DB();// postroenie opisaniya peremennoy tip string
	int putInFile(); // pomestit` rez v fail
	void getNewElem();// vz9t` new elem obrpolsk
};

