//
// Created by Admin on 31.05.2018.
//

#ifndef MYSELL_MYSHELL_H
#define MYSELL_MYSHELL_H

#include <string>
#include <vector>
#include <map>

std::string get_current_directory();
void helpMcd();
void helpMpwd();
void helpMexit();
void helpMerrno();
int change_directory(char *dirPATH);
int changeDirectory(std::string Directory);
int ToDoFunctionInTheseDirectory(std::vector<std::string> dataFromConsol);
std::vector<std::string> split_cmd_line(std::istream& is);
int HelpRice(std::vector<std::string> dataFromConsol);
int castStringToInt(std::string NumberString);
void Mexit(std::vector<std::string> dataFromConsol);
int Mcd(std::vector<std::string> dataFromConsol,int ERROR);
int Mpwd(std::vector<std::string> dataFromConsol,int ERROR);
int Consol(bool ExitKey,std::string MainDirectory, int ERROR, std::vector<std::string>dataFromConsol,std::map<std::string, std::string>& Map);
#endif //MYSELL_MYSHELL_H
