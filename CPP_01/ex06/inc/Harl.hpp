#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>

enum Level {
	DEBUG,
	INFO,
	WARNING,
	ERROR
};

class Harl {

public:
	Harl();
	void	complain(Level lvl);

private:
	void	debug(void);
	void	info(void);
	void	warning(void);
	void	error(void);
};

#endif
