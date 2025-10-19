#include "FileHandler.h"
#include<fstream>
#include<iostream>
#include<system_error>
using namespace std;
vector<unsigned char> FileHandler::readFile(const string&filename){
	ifstream file(filename,ios::binary | ios::ate);
	if (!file.is_open()) {
		throw runtime_error("无法打开文件: " + filename);
	}
	streamsize size = file.tellg();
	file.seekg(0,ios::beg);
	vector<unsigned char> buffer(size);
	if (!file.read(reinterpret_cast<char*>(buffer.data()), size)) {
		throw runtime_error("读取文件失败: " + filename);
	}
	return buffer;
}
bool FileHandler::writeFile(const string& filename,const vector<unsigned char>& data){
	ofstream file(filename,ios::binary);
	if(!file.is_open()){
		cerr<<"error:无法创建文件"<<filename<<endl;
		return false;
	}
	if(!file.write(reinterpret_cast<const char*>(data.data()),data.size())){
		cerr<<"error：无法写入文件"<<filename<<endl;
		return false;
	}

	return true;
}
bool FileHandler::fileExists(const string& filename){
	ifstream file(filename);
	return file.good();
}
size_t FileHandler::getFileSize(const string& filename) {
	ifstream file(filename, ios::binary | ios::ate);
	if(file.is_open()){
		return static_cast<size_t>(file.tellg());
	}else{
		return 0;
	}
}
