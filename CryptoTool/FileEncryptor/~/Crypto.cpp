#include "Crypto.h"
#include <cctype>
using namespace std;

bool Crypto::vs(int shift){
	return shift >= 1 && shift <= 25;
}

vector<unsigned char> Crypto::encrypt(const vector<unsigned char>&data,int shift){
	vector<unsigned char> result;
	result.reserve(data.size());
	for (unsigned char byte : data){
		if (isalpha(byte)){
			char base = isupper(byte)? 'A' : 'a' ;
			char encrypted= (byte-base+shift)%26+base;
			result.push_back(encrypted);
		}else{
			result.push_back(byte);
		}
	}
	return result;
}
vector<unsigned char> Crypto::decrypt(const vector<unsigned char>&data,int shift){
return encrypt(data,26-shift);
}

