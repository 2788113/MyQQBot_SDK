
#include"MyQQapi.h"

text _stdcall MQ_Info () {
	json* j = new json;
	j->Add ("name", "īī�̳�");
	j->Add ("author", "Сī");
	j->Add ("description", "���˵��");
	j->Add ("version", "1.0.2");
	j->Add ("skey", "SDG5D4Ys89h7DJ849d");
	j->Add ("sdk", "S1");
	string str = j->ToString ();
	

	//api->OutPut () << "����1" << "����" << 12334324 << "��־";
	//api.OutPut ("aaa");
	
	delete  j;
	return str.c_str();
	
	
	//return "{ \"name\":\"īī�̳�\", \"author\" : \"ī\", \"description\" : \"���˵��\", \"version\" : \"1.0.0\", \"skey\" : \"SDG5D4Ys89h7DJ849d\", \"sdk\" : \"S1\"}";//����������ٶȸ���
}


