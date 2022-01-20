#include"MyQQapi.h"

Output operator<<(Output p, text Msg) {

	return api->OutPut (Msg);
};
Output operator<<(Output p, int Msg) {

	return api->OutPut (std::to_string (Msg).c_str ());
};

MyQQApi::MyQQApi ()
{
#ifdef _DEBUG

#else
	hdll = LoadLibrary ("MyQQApi.DLL");
	if (hdll != nullptr)
	{
		Api_SendMsgEx = (_SendMsgEx)GetProcAddress (hdll, "Api_SendMsgEx");
		Api_OutPut = (_OutPut)GetProcAddress (hdll, "Api_OutPut");
	}
	else {

		MessageBoxA (GetForegroundWindow (), "未找到动态链接库MyQQApi.DLL", "提示", 0);
		throw "未找到动态链接库MyQQApi.DLL";
	}
#endif // !_DEBUG

}


MyQQApi::~MyQQApi ()
{
	FreeLibrary (hdll);
}

void MyQQApi::SendMsgEx (text BotQQ, int namebat, int type, text group, text QQ, text msg, int id)
{

#ifdef _DEBUG

	OutputDebugString ((string ("机器人QQ:") + BotQQ + "申请发送消息到" + QQ + "消息内容:" + msg).c_str ());
	
#else

	if (Api_SendMsgEx == NULL) {
		MessageBoxA (GetForegroundWindow (), "动态链接库指定命令\" Api_SendMsgEx\"不存在", "提示", 0);
		GetModuleHandle ("");
		return;
	}
	else
	{
		Api_SendMsgEx (BotQQ, namebat, type, group, QQ, msg, id);
	}

#endif // !_DEBUG




}

Output MyQQApi::OutPut () {

	Output p;
	return p;
}
Output MyQQApi::OutPut (int TextRGB, int BackRGB, text Msg ) {



	Output p;
	return p;
}
Output MyQQApi::OutPut (text msg) {

#ifdef _DEBUG

	OutputDebugString ((string ("输出日志:") + msg+"\n").c_str ());
	return OutPut ();
#else
	if (Api_OutPut == NULL) {
		MessageBoxA (GetForegroundWindow (), "动态链接库指定命令\"Api_OutPut\"不存在", "提示", 0);
		throw "动态链接库指定命令\"Api_OutPut\"不存在";
		//return OutPut ();
	}
	else
	{
		Api_OutPut (msg);
		return OutPut ();
	}

#endif // !_DEBUG


	

}

