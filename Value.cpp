//
// Created by Admin on 31.05.2018.
//

#include <boost/algorithm/string.hpp>
#include <map>
#include "File.h"

std::map<std::string, std::string> MapOfValue(std::vector<std::string>& Data,std::map<std::string, std::string>& Map){
    for(int i = 0; i < Data.size(); ++i){
        if((Data[i] == std::string("=")) && i > 0 && i < Data.size()){
            Map[std::string("$")+Data[i-1]] = Data[i+1];
        }
    }
    return Map;
};

bool IsElem(std::vector<std::string>Data){
    bool key = false;
    for(int i = 0; i < Data.size(); ++i){
        if(Data[i] == std::string("=")){
            key = true;
        }
    }
    return key;
}

std::vector<std::string>DataVector(std::vector<std::string>Data, std::map<std::string, std::string>& Map){
    for(int i = 0; i < Data.size(); ++i){
        if(IsSimbolInString(Data[i],std::string("$"))){
            Data[i] = Map[Data[i]];
        }
    }
    return Data;
}

