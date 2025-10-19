#include "EncryptorApp.h"
#include <iostream>

int main(){
	try{
		EncryptorApp app;
		app.run();
		return 0;
	}catch(const std::exception& e){
		std::cerr<<"error:程序发生错误"<<e.what()<<std::endl;
		return 1;
	}
}


