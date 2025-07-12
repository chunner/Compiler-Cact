#ifndef RISCV_H
#define RISCV_H
#include <IRGenerator.h>



class RISCV {
public:
    std::vector<std::string> riscv_text;
    std::vector<std::string> riscv_data;

    void generate_riscv(LLVMModule &LLVM_IR);
private:
    void gen_riscv_function(const LLVMFunction &LLVM_Func);

};





#endif