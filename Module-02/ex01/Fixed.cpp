#include "Fixed.hpp"

Fixed::Fixed() : value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int& val) : value(val << fractionalBits)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const float& val) : value((int) roundf(val * (1 << fractionalBits)))
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& obj)
{
	this->value = obj.value;
	std::cout << "Copy constructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed& obj)
{
	if (this != &obj)
		this->value = obj.value;
	std::cout << "Copy assignment operator called" << std::endl;
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->value = raw;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->value);
}

float Fixed::toFloat(void) const
{
	return (value / 256.0f);
}

int Fixed::toInt(void) const
{
	return (value / 256);
}

std::ostream& operator<<(std::ostream& out, const Fixed& obj)
{
	out << obj.toFloat();
	return out;
}

