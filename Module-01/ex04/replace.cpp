#include "replace.hpp"

Replace::Replace(const std::string& filename, const std::string& s1, const std::string& s2)
	: filename(filename), s1(s1), s2(s2) {}

Replace::~Replace() {}

void Replace::replaceAndWriteToFile()
{
	std::string content;
	std::ifstream file(filename.c_str());
	std::stringstream buffer;
	size_t pos;

	buffer << file.rdbuf();
	content = buffer.str();
	pos = content.find(s1);
	while (pos != std::string::npos)
	{
	    content = content.substr(0, pos) + s2 + content.substr(pos + s1.length());
	    pos = content.find(s1, pos + s2.length());
	}
	std::ofstream outFile(filename + ".replace");
	outFile << content;
}
