#include<iostream>
using namespace std;

//�ǳ�һ��Ľ�����������ĵط���Ϊ�˷��������߼�����ʵ�ֽ�Ϊβ�ݹ�
class Parser
{
private:
	char* expr;

	void stmt()
	{
		switch (*expr)
		{
		case '+': match('+'); cout << '+'; stmt(); stmt();
			break;
		case '-':match('-'); cout << '-'; stmt(); stmt();
			break;
		case 'a':match('a'); cout << 'a';
			break;
		default:	throw exception("synax error");


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
	char* des = "+-aaa";
	Parser parser;
	parser.parse(des);

}