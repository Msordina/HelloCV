#ifndef ENCRYPTOAPP_H
#define ENCRYPTOAPP_H
#include <string>
class EncryptorApp {
	public:
		void run();
	private:
		void showMenu();
		void processEncrypt();
		void processDecrypt();
		int getShiftFromUser();
		std::string getInputFilename();
		std::string getOutputFilename();
		void processFile(bool encrypt);
	};
#endif

