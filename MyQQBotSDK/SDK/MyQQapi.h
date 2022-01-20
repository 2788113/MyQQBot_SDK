#ifndef _MYQQAPI
#define _MYQQAPI
#include"pch.h"

struct Output {};

class MyQQApi
{
	
	
public:


	HMODULE  hdll = 0;
	MyQQApi ();
	~MyQQApi ();

	void SendMsgEx (text BotQQ, int namebat, int type, text group, text QQ, text msg, int id);
	Output OutPut ();
	Output OutPut (int TextRGB, int BackRGB, text Msg = "");
	Output OutPut (text Msg);
	
	
private:

	typedef void (*_OutPut)(text);  _OutPut Api_OutPut ;
	typedef void (*_SendMsgEx)(text, int, int, text, text, text, int); _SendMsgEx  Api_SendMsgEx ;

};

Output operator<<(Output p, text Msg);
Output operator<<(Output p, int Msg);
static MyQQApi* api = new MyQQApi;
#endif // _MYQQAPI
