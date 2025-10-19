#ifndef FILEHANDLER_H
#define FILEHANDLER_H
#include <string>
#include <vector>

class FileHandler {
	public:
		static std::vector<unsigned char> readFile(const std::string& filename);
		static bool writeFile(const std::string& filename,const std::vector<unsigned char>& data);
		static bool fileExists(const std::string& filename);
		static size_t getFileSize(const std::string& filename);
};
#endif

