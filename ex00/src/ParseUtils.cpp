#include "../inc/ParseUtils.hpp"

char** Parse::split(const std::string& s, char delim) {
	if (s.empty()) {
		char** result = new char*[1];
		result[0] = nullptr;
		return result;
	}
	int num_tokens = 1;
	for (char c : s) {
		if (c == delim) {
			num_tokens++;
		}
	}
	char** result = new char*[num_tokens + 1];
	int current_token_idx = 0;
	size_t current_token_start = 0;
	for (size_t i = 0; i <= s.length(); ++i) {
		if (i == s.length() || s[i] == delim) {
			size_t token_len = i - current_token_start;
			result[current_token_idx] = new char[token_len + 1];
			std::memcpy(result[current_token_idx], s.c_str() + current_token_start, token_len);
			result[current_token_idx][token_len] = '\0';
			current_token_idx++;
			current_token_start = i + 1;
		}
	}
	result[num_tokens] = nullptr;
	return (result);
}

void	Parse::freeCharArray(char** arr) {
	size_t	size = 0;

	if (!arr)
		return ;
	while (arr[size])
		size++;
	for (size_t i = 0; i < size; i++)
		delete[] arr[i];
	delete[] arr;
}
