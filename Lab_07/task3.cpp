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
    if (s == "Unsatisfactorily") return Unsatisfactorily;
    if (s == "Satisfactorily")   return Satisfactorily;
    if (s == "Good")             return Good;
    if (s == "Excellent")        return Excellent;
}

void loadFromFile(const std::string& filename, Groups& outGroups) {
    std::ifstream in(filename);
    std::string group, subject, score, line;
    
    
    
    if (in.is_open()) {
        while (std::getline(in, group)) // группа
        {
            std::vector<Student> students; // перезапись группы

            while (std::getline(in, line) && line != "@END_GROUP") {

                Student student; // перезапись студента

                student.Name = line; // имя

                std::getline(in, line);
                student.Year = std::stoi(line); // год

                while (std::getline(in, subject) &&
                            std::getline(in, score) && subject != "@END_SUBJECTS")
                {   
                    student.RecordBook[subject] = scoreFromString(score); // зачетка

                }

                students.push_back(student);

            }

            outGroups[group] = students;
            
        }
    }

    in.close();
}