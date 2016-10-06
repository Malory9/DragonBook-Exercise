#include<iostream>
using namespace std;
//根据2.4.5节所述，需将原式转换为右递归
class Parser
{
private:
	char* expr;

	void rest()
	{
		if (*expr == '(')
		{
			match('('); cout << '('; stmt(); match(')'); cout << ')'; stmt(); rest();
		}
		else
		{
			//
		}
	}
	void stmt()
	{
		
		if (*expr == '(') //不做任何操作就满足为空的类型
			rest();

	}
	void match(char t)
	{
		if (*expr == t)
			++expr;
		else
			throw exception("not match");
	}
public:
	Parser():expr(nullptr){}

	 void parse(char * toParse)
	{
		 this->expr = toParse;
		 stmt();
		 if (*expr != '\0')
			 throw exception("not at the end");
	}
	

};


int main()
{
	char* des = "()";
	Parser parser;
	try {
		parser.parse(des);
	}catch(exception e)
 	{
		cout << e.what();
	}
}