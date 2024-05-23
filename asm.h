#ifndef ASM_H
#define ASM_H

#include<iostream>
#include<vector>
#include<string>
/*enum INS_TYPE{
    INP,MOV,MUL,SKP,BUN
};*/
/*enum REGS{
    ZERO,AT,V0,V1,A0,A1,A2,A3,T0,T1,T2,T3,T4,T5,T6,T7,S0,S1,S2,S3,S4,S5,S6,S7,T8,T9,K0,K1,GP,SP,FP,RA
};*/
class Asm{
    private:
        int linePosition;
        std::string op;
        
       
        std::string rd_binary;
        std::string rs;
        std::string rs_binary;
        std::string rt;
        std::string rt_binary;



    public:
      Asm();
      void pushpush(std::string);
      void interpret();
      void interpretRegister();
      void interpretInstruction(std::string instruction);
      std::vector<std::string> programStack;
       std::string rd;
       std::string opcode;
        

};






#endif