#include <riscv.h>

void RISCV::generate_riscv(LLVMModule &LLVM_IR) {
    riscv_text.push_back(".text");
    riscv_data.push_back(".data");
    for (const auto &entry : LLVM_IR.entries) {
        if (std::holds_alternative<LLVMFunction>(entry)) {
            const LLVMFunction &func = std::get<LLVMFunction>(entry);
            gen_riscv_function(func);

                

        } else if (std::holds_alternative<LLVMGlobalVar>(entry)) {
            const LLVMGlobalVar &global_var = std::get<LLVMGlobalVar>(entry);

        }
    }
}


void RISCV::gen_riscv_function(const LLVMFunction &func) {
    riscv_text.push_back(func.name + ":");
    riscv_text.push_back("  # Function prologue");
    riscv_text.push_back("  addi sp, sp, -16"); // Adjust stack pointer
    riscv_text.push_back("  sw ra, 12(sp)"); // Save return address
    riscv_text.push_back("  sw s0, 8(sp)"); // Save frame pointer
    riscv_text.push_back("  addi s0, sp, 16"); // Set frame pointer

    for (const auto &block : func.basicblocks) {
        riscv_text.push_back(block->label + ":");
        for (const auto &inst : block->instructions) {
            
        }
    }

    riscv_text.push_back("  # Function epilogue");
    riscv_text.push_back("  lw ra, 12(sp)"); // Restore return address
    riscv_text.push_back("  lw s0, 8(sp)"); // Restore frame pointer
    riscv_text.push_back("  addi sp, sp, 16"); // Restore stack pointer
    riscv_text.push_back("  ret"); // Return from function
}