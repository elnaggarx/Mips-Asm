#include<iostream>
#include<Fstream>
#include<string>
#include "asm.h"
#include "asm.cpp"
int main(){
    std::string filepath="../file.txt";
    bool assemblyControl=false;
    std::ifstream file(filepath);
    if (!file.is_open()) {
        std::cerr << "Failed to open file: " << filepath << std::endl ;

        return 1;
    }
    std::string line;
    Asm a;
    while(getline(file,line)){
        if(line==".text"){
            assemblyControl=true;
            continue;
        }
        if(assemblyControl==true){
            a.pushpush(line);
        }

    }   
    file.close();
    a.interpret();
    std::cout << a.opcode;



    return 0;
}