#ifndef ASM_CPP
#define ASM_CPP
#include<map>
#include "asm.h"
#include<string>

std::map <std::string,std::string> instructionMap={
    {"inp","0000"},
    {"mov","0001"},
    {"mul","0002"},
    {"skp","0003"},
    {"bun","0004"},
    {"out","0005"},
    {"move","0006"}
};
std::map <std::string,std::string> regAddressMap={
    {"zero","00000"},
    {"$at","00001"},
    {"$v0","00010"},
    {"$v1","00011"},
    {"$a0","00100"},
    {"$a1","00101"},
    {"$a2","00110"},
    {"$a3","00111"},
    {"$t0","01000"},
    {"$t1","01001"},
    {"$t2","01010"},
    {"$t3","01011"},
    {"$t4","01100"},
    {"$t5","01101"},
    {"$t6","01110"},
    {"$t7","01111"},
    {"$s0","10000"},//16
    {"$s1","10001"},
    {"$s2","10010"},
    {"$s3","10011"},
    {"$s4","10100"},
    {"$s5","10101"},
    {"$s6","10110"},
    {"$s7","10111"},
    {"$t8","11000"},
    {"$t9","11001"},
    {"$k0","11010"},
    {"$k1","11011"},
    {"$gp","11100"},
    {"$sp","11101"},
    {"$fp","11110"},
    {"$ra","11111"}

};
void Asm::pushpush(std::string item){
    programStack.push_back(item);
};
Asm::Asm(){
    linePosition=1;
    op="";
    opcode="";
};
void Asm::interpretInstruction(std::string instruction){
    opcode= instructionMap[instruction];
};

void Asm::interpret(){
    int registerCounter=0;
        for(int i=0;i<programStack.size();i++){//modify warning
            if(programStack[i][0]=='\n'){
                linePosition++;
                continue;
            }
            for(int j=0;j<programStack[i].length();j++){
                if(programStack[i][j]==' ' && (j=0 || programStack[i][j-1]==' ')){
                    continue;
                }
                else if(programStack[i][j]>='a' && programStack[i][j]<='z'){
                    while(programStack[i][j]!=' ' || '\n'){
                        op.push_back(programStack[i][j]);
                        j++; 
                    }
                    interpretInstruction(op);
                    while(programStack[i][j]==' '){//may cause error
                        j++;
                    }
                    if(programStack[i][j]=='\n'){
                        //error
                    }
                    //if case for r-type
                    while(programStack[i][j]!='\n'){
                        if(programStack[i][j]==' '){
                            j++;
                        }
                        else if(programStack[i][j]=='$' && registerCounter==0 ){
                            rs.push_back(programStack[i][j+1]);
                            rs.push_back(programStack[i][j+2]);
                            j+=3;
                            
                        }
                        else if(programStack[i][j]=='$' && registerCounter==1 ){
                            rt.push_back(programStack[i][j+1]);
                            rt.push_back(programStack[i][j+2]);
                            j+=3;
                            
                        }
                        else if(programStack[i][j]=='$' && registerCounter==2 ){
                            rd.push_back(programStack[i][j+1]);
                            rd.push_back(programStack[i][j+2]);
                            j+=3;
                            
                        }
                        else if(programStack[i][j]==','){
                            j++;
                            registerCounter++;
                        }
                        else{
                            //error
                        }

                    }
                    registerCounter=0;
                    break;//J for loop
                    
                    
                    
                    

                    
                }
            }
    }
};








#endif