#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("SCF", 145, 137) , target("SCFT") {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("SCF", 145, 137) , target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& scf) : AForm(scf) , target(scf.target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& scf)
{
    if (this != &scf)
        target = scf.target;
    return (*this);
}

void ShrubberyCreationForm::actionForm() const
{
    std::ofstream outFile(target + "_shrubbery");

	outFile << "                                            .\n"
			<< "                                    .         ;\n"
			<< "       .              .              ;%     ;;\n"
			<< "         ,           ,                :;%  %;\n"
			<< "          :         ;                   :;%;'     .,\n"
			<< " ,.        %;     %;            ;        %;'    ,;\n"
			<< "   ;       ;%;  %%;        ,     %;    ;%;    ,%'\n"
			<< "    %;       %;%;      ,  ;       %;  ;%;   ,%;'\n"
			<< "     ;%;      %;        ;%;        % ;%;  ,%;'\n"
			<< "      `%;.     ;%;     %;'         `;%%;.%;'\n"
			<< "       `:;%.    ;%%. %@;        %; ;@%;%'\n"
			<< "          `:%;.  :;bd%;          %;@%;'\n"
			<< "            `@%:.  :;%.         ;@@%;'\n"
			<< "              `@%.  `;@%.      ;@@%;\n"
			<< "                `@%%. `@%%    ;@@%;\n"
			<< "                  ;@%. :@%%  %@@%;\n"
			<< "                    %@bd%%%bd%%:;\n"
			<< "                      #@%%%%%:;;\n"
			<< "                      %@@%%%::;\n"
			<< "                      %@@@%(o);  . '\n"
			<< "                      %@@@o%;:(.,'\n"
			<< "                  `.. %@@@o%::;\n"
			<< "                     `)@@@o%::;\n"
			<< "                      %@@(o)::;\n"
			<< "                     .%@@@@%::;\n"
			<< "                     ;%@@@@%::;.\n"
			<< "                    ;%@@@@%%:;;;.\n"
			<< "                ...;%@@@@@%%:;;;;,..\n"
			<< " ##############################################################" << std::endl;

	outFile.close();

	std::cout << target << "_shrubbery has been created." << std::endl;
}
