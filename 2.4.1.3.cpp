#include<iostream>
using namespace std;

class Parser
{
private:
	char* expr;

	void stmt()
	{
		if(*expr=='0')
		{
			if (*(expr + 1) != '1') {
				match('0');
				cout << 0;
				stmt();
				match('1');
				cout << 1;
			}
			else
			{
				match('0');
				cout << 0;
				match('1');
				cout << 1;
			}

		}


		
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
	Parser(char* newExpr):expr(newExpr){}

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
	char* des = "000111";
	Parser parser;
	parser.parse(des);

}