//
// Created by Admin on 31.05.2018.
//

#ifndef MYSELL_VALUE_H
#define MYSELL_VALUE_H

#include <map>
#include <vector>

std::map<std::string, std::string> MapOfValue(std::vector<std::string>& Data,std::map<std::string, std::string>& Map);
std::vector<std::string>DataVector(std::vector<std::string>Data, std::map<std::string, std::string>& Map);
bool IsElem(std::vector<std::string>Data);
#endif //MYSELL_VALUE_H
