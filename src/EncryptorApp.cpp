#include "EncryptorApp.h"
#include "Crypto.h"
#include "FileHandler.h"
#include<iostream>
#include<limits>
using namespace std;

void EncryptorApp::run(){
	int choice;
	cout<<"======文件加密工具ξ( ✿＞◡❛)======"<<endl;
	do{
		showMenu();
		cout<<"撒，做出命运的抉择吧:";
		cin>>choice;
		
		switch(choice){
			case 1:
				processEncrypt();
				break;
			case 2:
				processDecrypt();
				break;
			case 3:
				cout<<"谢谢惠顾，欢↗迎→下↘次↓光↘临↗"<< endl;
				break;
			default:
				cout<<"前面的区域以后再来探索吧！"<<endl;
		}
		cout<<endl;
	}while(choice!=3);
}
void EncryptorApp::showMenu(){
	cout<<"加密文件 or 解密文件"<<endl;
	cout<<"加密文件请按1"<<endl;
	cout<<"解密文件请按2"<<endl;
	cout<<"选择or请按3"<<endl;
}
void EncryptorApp::processEncrypt(){
	cout<<"===文件加密==="<<endl;
	processFile(true);
}
void EncryptorApp::processDecrypt(){
	cout<<"===文件解密==="<<endl;
	processFile(false);
}
int EncryptorApp::getShiftFromUser(){
	int shift;
	while(true){
		cout<<"请输入密钥:";
		cin>>shift;
		
		if(Crypto::vs(shift)){
			return shift;
		}else{
			cout<<"error发生，请更换密钥"<<endl;
		}
	}
}
string EncryptorApp::getInputFilename(){
	string filename;
	cout<<"请输入初始文件名";
	getline(cin,filename);
	return filename;
}
string EncryptorApp::getOutputFilename(){
        string filename;
        cout<<"请输入密码文件名";
        getline(cin,filename);
        return filename;
}
void EncryptorApp::processFile(bool encrypt){
	try{
		string inputFile = getInputFilename();
		string outputFile = getOutputFilename();
		int shift = getShiftFromUser();

		if(!FileHandler::fileExists(inputFile)){
			cout<<"error:文件不存在"<<endl;
			return;
		}

		auto fileData =FileHandler::readFile(inputFile);
		cout<<"文件大小为："<<fileData.size()<<"字节"<<endl;
		vector<unsigned char> result;
		if(encrypt){
			result = Crypto::encrypt(fileData,shift);
			cout<<"文件加密成功，好评喵"<<endl;
		}else{
			result = Crypto::decrypt(fileData,shift);
			cout<<"文件解密成功，好评吱"<<endl;
		}

		if(FileHandler::writeFile(outputFile,result)){
			cout<<"保存至 "<<outputFile<<endl;
			cout<<"大小为"<<result.size()<<"字节"<<endl;
		}else{
			cout<<"error：输出失败"<<endl;
		}
	}catch(const exception& e){
		cout<<"error:操作失败"<<e.what()<<endl;
	}
}









