
#include"MyQQapi.h"

text _stdcall MQ_Info () {
	json* j = new json;
	j->Add ("name", "墨墨商城");
	j->Add ("author", "小墨");
	j->Add ("description", "插件说明");
	j->Add ("version", "1.0.2");
	j->Add ("skey", "SDG5D4Ys89h7DJ849d");
	j->Add ("sdk", "S1");
	string str = j->ToString ();
	

	//api->OutPut () << "测试1" << "测试" << 12334324 << "日志";
	//api.OutPut ("aaa");
	
	delete  j;
	return str.c_str();
	
	
	//return "{ \"name\":\"墨墨商城\", \"author\" : \"墨\", \"description\" : \"插件说明\", \"version\" : \"1.0.0\", \"skey\" : \"SDG5D4Ys89h7DJ849d\", \"sdk\" : \"S1\"}";//用这个返回速度更快
}


