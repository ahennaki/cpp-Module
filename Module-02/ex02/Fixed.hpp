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
		~Fixed();

		void setRawBits(int const raw);
		int getRawBits(void) const;

		float toFloat( void ) const;
		int toInt( void ) const;

		Fixed &operator=(const Fixed &object);
		Fixed operator+(const Fixed &obj) const;
		Fixed operator-(const Fixed &obj) const;
		Fixed operator*(const Fixed &obj) const;
		Fixed operator/(const Fixed &obj) const;

		bool operator>(const Fixed &obj) const;
		bool operator<(const Fixed &obj) const;
		bool operator>=(const Fixed &obj) const;
		bool operator<=(const Fixed &obj) const;
		bool operator==(const Fixed &obj) const;
		bool operator!=(const Fixed &obj) const;

		Fixed operator++(int);
		Fixed operator--(int);
		Fixed &operator++(void);
		Fixed &operator--(void);

		static const Fixed &min(const Fixed &x, const Fixed &y);
		static const Fixed &max(const Fixed &x, const Fixed &y);
		static Fixed &min(Fixed &x, Fixed &y);
		static Fixed &max(Fixed &x, Fixed &y);
};
std::ostream& operator<<(std::ostream& out, const Fixed& obj);

#endif
