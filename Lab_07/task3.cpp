#include "header.hpp"

void saveToFile(const std::string& filename, const Groups& groups) {
    std::ofstream out(filename);
    if (out.is_open())
    {
        for (auto group : groups) {
            out << group.first << "\n";
            for (auto student : group.second) {
                out << student.Name << "\n" << student.Year << "\n";
                for (auto subject : student.RecordBook) {
                    out << subject.first << "\n";
                    out << subject.second << "\n";
                }
                out << "@END_SUBJECTS\n";
            }
            out << "@END_GROUP\n";
        }
    }
    out.close();
}

Score scoreFromString(const std::string& s)
{
    if (s == "2") return Unsatisfactorily;
    if (s == "3")   return Satisfactorily;
    if (s == "4")             return Good;
    if (s == "5")        return Excellent;
}

void loadFromFile(const std::string& filename, Groups& outGroups) {
    std::string group, subject, line;
    std::ifstream in(filename);
    
    if (in.is_open()) {

        std::string currentGroup;

        while (std::getline(in, line)) {
            if (line.empty()) continue;
                                    
                currentGroup = line;
                outGroups[currentGroup] = std::vector<Student>();
            
            
                while (std::getline(in, line) && line != "@END_GROUP") {
                    

                    Student student;
                    student.Name = line;

                    // Год обучения
                    std::getline(in, line);
                    student.Year = std::stoi(line);


                    // Читаем предметы и оценки
                    while (std::getline(in, line) && line != "@END_SUBJECTS") {
                        std::string subject = line;

                        std::getline(in, line);
                        student.RecordBook[subject] = scoreFromString(line);
                    }
                    outGroups[currentGroup].push_back(student);
                }               
        }
    }
    in.close();
}    


