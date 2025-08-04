#include "../inc/ParseUtils.hpp"

char** Parse::split(const std::string& str, char delim) {
	std::vector<char*> tokens;
	size_t start = 0;
	size_t end;

	while ((end = str.find(delim, start)) != std::string::npos) {
		std::string token = str.substr(start, end - start);
		char* cstr = new char[token.length() + 1];
		std::strcpy(cstr, token.c_str());
		tokens.push_back(cstr);
		start = end + 1;
	}
	std::string token = str.substr(start);
	char* cstr = new char[token.length() + 1];
	std::strcpy(cstr, token.c_str());
	tokens.push_back(cstr);
	char** result = new char*[tokens.size() + 1];
	for (size_t i = 0; i < tokens.size(); ++i) {
		result[i] = tokens[i];
	}
	result[tokens.size()] = nullptr;
	return (result);
}

