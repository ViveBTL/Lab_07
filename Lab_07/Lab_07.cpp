#include <iostream>
#include "header.hpp"

int main()
{

    std::cout << "Task 1.\n";

    std::vector<std::string> data = {
        "pam2pam", "privet", "poka poka"
    };
    saveToFile("privet.txt", data);

    std::vector<std::string> newData;
    loadFromFile("privet2.txt", newData);
    for (auto str : newData)
        std::cout << str << "\n";


    std::cout << "\nTask 2.\n\n";
    std::vector<Book> books = {
       {"George Orwell", "1984", 1949},
       {"Aldous Huxley", "Brave New World", 1932},
       {"Ray Bradbury", "Fahrenheit 451", 1953},
       {"Yevgeny Zamyatin", "We", 1921},
       {"Margaret Atwood", "The Handmaid's Tale", 1985}
    };
    saveToFile("books.txt", books);

    std::vector<Book> books2;
    loadFromFile("books.txt", books2);
    for (auto book : books2)
        std::cout << book.Author << "\n" << book.Title << "\n" << book.Year << "\n\n";






    Groups groups = {
        {
            "GroupA",
            {
                { "Ivan Petrov", 1,  { {"Informatics", Excellent}, {"Mathematics", Good} }},
                {"Sergey Ivanov", 1, { {"Informatics", Good}, {"Mathematics", Satisfactorily}}},
                {"Anna Smirnova", 2, { {"Informatics", Excellent}, {"Mathematics", Excellent} }}
            }
        },
        {
            "GroupB",
            {
                { "Pavel Kozlov", 2, { {"Informatics", Good}, {"Mathematics", Good} }},
                {"Olga Fedorova", 3, { {"Informatics", Satisfactorily}, {"Mathematics", Good} }},
                {"Nikita Morozov", 3, { {"Informatics", Excellent}, {"Mathematics", Satisfactorily} }},
                {"Maria Volkova", 1, { {"Informatics", Good}, {"Mathematics", Excellent} }}
            }
        }
    };

    saveToFile("groups.txt", groups);

    Groups newgroups;
    loadFromFile("groups.txt", newgroups);
    for ( auto g : newgroups) {
        std::cout << "\n===== GROUP: " << g.first << " =====\n";

        for (auto st : g.second) {
            std::string scoreStr;
            std::cout << "  Student: " << st.Name << "\n";
            std::cout << "    Year: " << st.Year << "\n";
            std::cout << "    Subjects:\n";

            for (const auto& rec : st.RecordBook) {
                std::string scoreStr;
                switch (rec.second) {
                case Unsatisfactorily: scoreStr = "Unsatisfactorily"; break;
                case Satisfactorily: scoreStr = "Satisfactorily"; break;
                case Good: scoreStr = "Good"; break;
                case Excellent: scoreStr = "Excellent"; break;
                }
                std::cout << "      - " << rec.first << " : " << scoreStr << "\n";
            }
        }
    }
}



