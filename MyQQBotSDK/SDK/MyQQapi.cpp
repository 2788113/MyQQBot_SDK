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

		MessageBoxA (GetForegroundWindow (), "δ�ҵ���̬���ӿ�MyQQApi.DLL", "��ʾ", 0);
		throw "δ�ҵ���̬���ӿ�MyQQApi.DLL";
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

	OutputDebugString ((string ("������QQ:") + BotQQ + "���뷢����Ϣ��" + QQ + "��Ϣ����:" + msg).c_str ());
	
#else

	if (Api_SendMsgEx == NULL) {
		MessageBoxA (GetForegroundWindow (), "��̬���ӿ�ָ������\" Api_SendMsgEx\"������", "��ʾ", 0);
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

	OutputDebugString ((string ("�����־:") + msg+"\n").c_str ());
	return OutPut ();
#else
	if (Api_OutPut == NULL) {
		MessageBoxA (GetForegroundWindow (), "��̬���ӿ�ָ������\"Api_OutPut\"������", "��ʾ", 0);
		throw "��̬���ӿ�ָ������\"Api_OutPut\"������";
		//return OutPut ();
	}
	else
	{
		Api_OutPut (msg);
		return OutPut ();
	}

#endif // !_DEBUG


	

}

