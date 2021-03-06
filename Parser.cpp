#include "Parser.h"

Parser::Parser()
{
	_All_table = new Scaner();
	_All_table->to_scan();//�������� ��� ������� � �������
	_now_lex = new int;
	*_now_lex = 0;//������������� � ������ �������
	_root = nullptr;
	_MyCheck = new MyCheckVector();
	_MyVectorOp = new VectorOfOP();
}

Parser::~Parser()
{
	delete _All_table;
	delete _now_lex;
	delete _root;
	delete _MyCheck;
	delete _MyVectorOp;
}
int Parser::toCompile()
{
	system("cls");
	finde_syntaxTree();//������ ������ ��������������� �������, � ��� ���������, �������� ����� � �������� ��������

	//�������������� ������� � �������� �������� ������ � ��� ����������
	system("pause");
	return 0;
}
Base_NeTerminal * Parser::finde_syntaxTree()
{

	//������ ��� ���������� �������� �������� ������
	_root = new program(_now_lex, _All_table, nullptr, "program");
	//_All_table->print_stream_of_lex();

	_root->derivation( _now_lex, _All_table, _MyCheck, _MyVectorOp);//������ ������ ��������������� �������, � ��� ���������, ��������
	
	ofstream parse("parse_tree.dot");
	if (!parse)
		cout << "�� ������� ������� ����" << endl;
	parse << "digraph A" << endl;
	parse << "{" << endl;
	_root->PrintTree(parse);
	parse << "}" << endl;
	parse.close();
	system("graphviz-2.38\\bin\\dot -Tpng parse_tree.dot -o parse_tree.png");
	
	return _root;
	//return nullptr;
}


