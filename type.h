#pragma once

#include"Parser.h"

class Base_NeTerminal;
class varDefine;

class type : public Base_NeTerminal
{
	type() = delete;

public:
	type(int *now_lex, Scaner * All_table, Base_NeTerminal *parent, string name) : Base_NeTerminal{ now_lex, All_table, parent, "type" } {	};

	Base_NeTerminal *derivation(int *now_lex, Scaner *table, MyCheckVector *_MyCheck) override;
};