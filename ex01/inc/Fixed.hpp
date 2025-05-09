#include <iostream>
#include <cmath>

class Fixed {

private:
	int					_result;
	static const int	_fract = 8;
public:
	Fixed();
	Fixed(const Fixed& other);
	Fixed& operator=(const Fixed& other);
	Fixed(const int num);
	Fixed(const float num);
	~Fixed();

	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	float	toFloat(void);
	int		toInt(void);

};
