//primary
#pragma once

#include"Parser.h"

class Base_NeTerminal;

class primary : public Base_NeTerminal
{
	primary() = delete;

public:
	primary(int *now_lex, Scaner * All_table, Base_NeTerminal *parent, string name) : Base_NeTerminal{ now_lex, All_table, parent, "primary" } {	};

	Base_NeTerminal *derivation(int *now_lex, Scaner *table, MyCheckVector *_MyCheck, VectorOfOP * _MyVectorOp) override;
};