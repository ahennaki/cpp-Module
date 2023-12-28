#include "ScalarConverter.hpp"

// class ScalarConverter {
// public:
//     // Static method to convert a string to various scalar types
//     static void convert(const std::string& input) {
//         // Attempt to convert to char
//         try {
//             char charResult = std::stoi(input);
//             if (isprint(charResult)) {
//                 std::cout << "char: '" << charResult << "'" << std::endl;
//             } else {
//                 std::cout << "char: Non-displayable" << std::endl;
//             }
//         } catch (const std::out_of_range&) {
//             std::cerr << "char: Out of range" << std::endl;
//         } catch (const std::invalid_argument&) {
//             std::cerr << "char: Invalid argument" << std::endl;
//         }

//         // Convert to int
//         try {
//             int intResult = std::stoi(input);
//             std::cout << "int: " << intResult << std::endl;
//         } catch (const std::out_of_range&) {
//             std::cerr << "int: Out of range" << std::endl;
//         } catch (const std::invalid_argument&) {
//             std::cerr << "int: Invalid argument" << std::endl;
//         }

//         // Convert to float
//         try {
//             float floatResult = std::stof(input);
//             std::cout << "float: " << floatResult << "f" << std::endl;
//         } catch (const std::out_of_range&) {
//             std::cerr << "float: Out of range" << std::endl;
//         } catch (const std::invalid_argument&) {
//             std::cerr << "float: Invalid argument" << std::endl;
//         }

//         // Convert to double
//         try {
//             double doubleResult = std::stod(input);
//             std::cout << "double: " << doubleResult << std::endl;
//         } catch (const std::out_of_range&) {
//             std::cerr << "double: Out of range" << std::endl;
//         } catch (const std::invalid_argument&) {
//             std::cerr << "double: Invalid argument" << std::endl;
//         }
//     }
// };

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cout << "Error" << std::endl;
        return 0;
    }
    ScalarConverter::convert(av[1]);

    return 0;
}
