#include "../inc/Utils.hpp"

const std::string	utils::color(const std::string& text, const std::string& col) {
        return (col + text + RST);
}

char** utils::split(const std::string& s, char delim) {
	char**	result;
	int		num_tokens = 1;
	int		current_token_idx = 0;
	size_t	current_token_start = 0;

	if (s.empty())
		return (nullptr);
	for (char c : s)
		if (c == delim)
			num_tokens++;
	result = new char*[num_tokens + 1];
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

void    utils::freeCharArray(char** arr) {
	size_t  size = 0;

	if (!arr)
			return ;
	while (arr[size])
			size++;
	for (size_t i = 0; i < size; i++)
			delete[] arr[i];
	delete[] arr;
}

int	utils::arraySize(char **arr) {
	int	i = -1;

	while (arr[++i])
		continue ;
	return (i);
}

