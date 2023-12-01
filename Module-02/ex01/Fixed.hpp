#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int value;
		static const int fractionalBits = 8;
	public:
		Fixed();
		Fixed(const int& val);
		Fixed(const float& val);
		Fixed(const Fixed &obj);
		Fixed &operator=(const Fixed &object);
		~Fixed();
		void setRawBits(int const raw);
		int getRawBits(void) const;
		float toFloat( void ) const;
		int toInt( void ) const;
};
std::ostream& operator<<(std::ostream& out, const Fixed& obj);

#endif
