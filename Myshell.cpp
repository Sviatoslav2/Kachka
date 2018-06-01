//
// Created by Admin on 31.05.2018.
//

#include <fstream>
#include <iostream>
#include <thread>
#include <vector>
#include <fcntl.h>
#include <cstring>
#include <cmath>
#include <cmath>
#include <sstream>
#include <unistd.h>
#include <string>
#include <limits.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <boost/lexical_cast.hpp>
#include <boost/filesystem.hpp>
#include <stdio.h>
#include <stdlib.h>
#include <boost/algorithm/string.hpp>
#include "File.h"
#include "Value.h"


using std::cout;
using std::cerr;
using std::endl;
using std::string;
using std::vector;
using std::strlen;
using std::strcat;



namespace fs1 = boost::filesystem;
namespace fs2 = boost;

std::string get_current_directory(){
    char buf[PATH_MAX+1];
    getcwd(buf, sizeof(buf));
    return std::string(buf);
}


void helpMcd(){
    std::cout <<">Afther you writhe Mcd.\n>Please write yor Path with /mnt/c/...(linux notation).\n>If name of Path will be incorrect then No such file in directory.\n>And exit process.\n>Or you can -h/--help for help"<< std::endl;
}

void helpMpwd(){
    std::cout <<">Afther you writhe Mpwd.\n>You will see your curent directory."<< std::endl;

}

void helpMexit(){
    std::cout <<">Afther you writhe Mpwd.\n"
                ">Please write : \n"
                ">>>mexit number\n"
                ">>>mexit -h for more information.\n"
                ">>>mexit --help"<< std::endl;

}

void helpMerrno(){
    std::cout <<"Return the number of error( of the last operation)"<< std::endl;
}

int change_directory(char *dirPATH){
    int erno1 = 0;
    erno1 = chdir(dirPATH);
    return erno1;
}
int changeDirectory(std::string Directory){
    const char *cstr = Directory.c_str();
    int erno = change_directory((char *) cstr);
    return erno;
}


int ToDoFunctionInTheseDirectory(std::vector<std::string> dataFromConsol){
    int ERROR = 0;
    int args_n = dataFromConsol.size();

    char **args = static_cast<char**>(malloc( (args_n + 1) * sizeof(char*)));

    //args[0] = arg1;
    for(int i = 0; i<dataFromConsol.size();i++){
        args[i] = (char *) dataFromConsol[i].c_str(); }
    string victim_name(args[0]);


    pid_t parent = getpid();
    pid_t pid = fork();


    if (pid == -1)
    {
        std::cerr << "Failed to fork()" << std::endl;
        //exit(EXIT_FAILURE);
        ERROR = errno; }
    else if (pid > 0)
    {
        // We are parent process
        int status;
        waitpid(pid, &status, 0);
        //cout << "Parent: child stopped, exit code: " << status << endl;
        ERROR = errno;
    }
    else
    { execvpe(victim_name.c_str(), args, environ);

        //const char *cstr2 = thisDirectory.c_str();
        //change_directory((char *) cstr2);
        //cerr << "Parent: Failed to execute " << victim_name << " \n\tCode: " << errno << endl;
        //exit(EXIT_FAILURE);   // exec never returns
        if(errno == 14){
            ToDoFunctionInTheseDirectory(dataFromConsol);
        }
        else{
            cerr << "Parent: Failed to execute " << victim_name << " \n\tCode: " << errno << endl;
        }
        ERROR = errno;
    }
    return ERROR;

}


std::vector<std::string> split_cmd_line(std::istream& is) {
    std::string commandline;
    std::vector<std::string> parsed_command;
    std::getline(is, commandline);
    std::stringstream ss(commandline);
    std::string word;
    while (ss >> word) {
        parsed_command.push_back(word);
    }
    return parsed_command;
}

int HelpRice(std::vector<std::string> dataFromConsol){
    int NumberMexitMcdMerrnoMpwd = 0;
    if(dataFromConsol[0] == "Mexit"){
        NumberMexitMcdMerrnoMpwd = 1;
    }
    else if(dataFromConsol[0] == "Mcd"){
        NumberMexitMcdMerrnoMpwd = 2;
    }
    else if(dataFromConsol[0] == "Merrno"){
        NumberMexitMcdMerrnoMpwd = 3;
    }
    else if(dataFromConsol[0] == "Mpwd"){
        NumberMexitMcdMerrnoMpwd = 4;
    }
    else if(dataFromConsol[0] == "mycat"){
        NumberMexitMcdMerrnoMpwd = 5;
    }
    else if(dataFromConsol[0] == "."){
        NumberMexitMcdMerrnoMpwd = 6;
    }
    else if(dataFromConsol[0] == "mecho"){
        NumberMexitMcdMerrnoMpwd = 7;
    }
    else if(dataFromConsol[0] == "myls"){
        NumberMexitMcdMerrnoMpwd = 8;
    }
    else if(IsElem(dataFromConsol)){
        NumberMexitMcdMerrnoMpwd = 9;
    }


    if(not (NumberMexitMcdMerrnoMpwd == 0)){
        for(int i = 1; i < dataFromConsol.size(); i++){
            if(dataFromConsol[1] == "-h" || dataFromConsol[1] == "--help"){
                if(NumberMexitMcdMerrnoMpwd == 1){
                    helpMexit();
                }
                else if(NumberMexitMcdMerrnoMpwd == 2){
                    helpMcd();
                }
                else if(NumberMexitMcdMerrnoMpwd == 3){
                    helpMerrno();
                }
                else if(NumberMexitMcdMerrnoMpwd == 4){
                    helpMpwd();
                }
            }
        }
    }
    return NumberMexitMcdMerrnoMpwd;
}


int castStringToInt(std::string NumberString){
    int i = 0;
    try {

        i = boost::lexical_cast<int>( NumberString.c_str());

    }
    catch( boost::bad_lexical_cast const& ){
        std::cout<<"You used incorrect number after Mexit"<<std::endl;

    }

    return i;
}


void Mexit(std::vector<std::string> dataFromConsol){

    if(dataFromConsol.size() == 2){

        exit(castStringToInt(dataFromConsol[1]));
    }
    else if (dataFromConsol.size() == 1){
        exit(0);
    }
    else if(dataFromConsol.size() > 2){
        std::cout<<"Incorrect parameter for Mexit"<<std::endl;
    }
}

int Mcd(std::vector<std::string> dataFromConsol,int ERROR,std::map<std::string, std::string>& Map){
    bool key = false;
    int position = 0;
    for(int i = 0; i < dataFromConsol.size();++i){
        key = IsSimbolInString(dataFromConsol[i],std::string("$"));
    }
    if(dataFromConsol.size() >= 2){
        if(key){
            std::cout<<dataFromConsol[position]<<std::endl;
            dataFromConsol[position] = Map[dataFromConsol[position]];
        }
        ERROR = changeDirectory(dataFromConsol[1]);
    }
    else{
        std::cout<<"You used incorrect argument"<<std::endl;
        ERROR = 1;
    }
    return ERROR;
}

int Mpwd(std::vector<std::string> dataFromConsol,int ERROR){
    if(dataFromConsol.size() == 1){
        std::cout <<get_current_directory()<< std::endl;
    }
    else{
        std::cout<<"You used incorrect argument"<<std::endl;
        ERROR = 1;
    }
    return ERROR;
}


int Consol(bool ExitKey,std::string MainDirectory, int ERROR, std::vector<std::string>dataFromConsol,std::map<std::string, std::string>& Map){

    auto NumberMexitMcdMerrnoMpwd = HelpRice(dataFromConsol);
    if(NumberMexitMcdMerrnoMpwd == 1){//Mexit
        Mexit(dataFromConsol);
    }
    else if(NumberMexitMcdMerrnoMpwd == 2){//Mcd
        ERROR = Mcd(dataFromConsol,ERROR,Map);
    }
    else if(NumberMexitMcdMerrnoMpwd == 3){//Merno
        std::cout<<ERROR<<std::endl;
    }
    else if (NumberMexitMcdMerrnoMpwd == 4){//Mpwd
        Mpwd(dataFromConsol,ERROR);
    }
    else if(NumberMexitMcdMerrnoMpwd == 5){
        std::string directory = get_current_directory();
        changeDirectory(MainDirectory);
        dataFromConsol[0] = "./"+dataFromConsol[0] + ".exe";
        ERROR = ToDoFunctionInTheseDirectory(dataFromConsol);
        changeDirectory(directory);
    }

    else if(NumberMexitMcdMerrnoMpwd == 7){
        std::cout<<dataFromConsol[1]<<std::endl;
        std::cout<<Map[dataFromConsol[1]]<<std::endl;
}
    else if(NumberMexitMcdMerrnoMpwd == 8){
        dataFromConsol[0] = "ls";
        ERROR = ToDoFunctionInTheseDirectory(dataFromConsol);
    }
    else if(NumberMexitMcdMerrnoMpwd == 9){
        Map =  MapOfValue(dataFromConsol,Map);

    }
    else if (NumberMexitMcdMerrnoMpwd == 0){
        ERROR = ToDoFunctionInTheseDirectory(dataFromConsol);
    }
    return ERROR;
}

