#include "header.hpp"

void saveToFile(const std::string& filename, const std::vector<Book>& data) {
    std::ofstream out(filename);
    if (out.is_open())
    {
        for (auto book : data)
            out << book.Author<< "\n" << book.Title << "\n" << book.Year << "\n";
    }
    out.close();
}

void loadFromFile(const std::string& filename, std::vector<Book>& outData) {
    std::ifstream in(filename);
    std::string line;
    Book book;
    if (in.is_open()) {
        while (std::getline(in, book.Author))
        {
            std::getline(in, book.Title);
            std::getline(in, line);
            book.Year = std::stoi(line);
            outData.push_back(book);
        }
    }
    in.close();
}