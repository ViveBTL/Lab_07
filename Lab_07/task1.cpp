#include "header.hpp"

void saveToFile(const std::string& filename, const std::vector<std::string>& data) {
	std::ofstream out(filename);
    if (out.is_open())
    {
        for (auto str: data)
            out << str << std::endl;
    }
    out.close();
}


void loadFromFile(const std::string& filename, std::vector<std::string>& outData) {
    std::ifstream in(filename);
    std::string line;
    if (in.is_open()) {
        while (std::getline(in, line))
        {
            outData.push_back(line);
        }
    }
    in.close();
}