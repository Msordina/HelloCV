#ifndef CRYPTO_H
#define CRYPTO_H
#include <string>
#include <vector>

class Crypto {
	public:
		static std::vector<unsigned char> encrypt(const std::vector<unsigned char>& data, int shift);
		static std::vector<unsigned char> decrypt(const std::vector<unsigned char>& data, int shift);
		static bool vs(int shift);
	};
#endif


