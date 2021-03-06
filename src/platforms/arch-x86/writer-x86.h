/**
 *    Copyright 2017 jmpews
 *
 *    Licensed under the Apache License, Version 2.0 (the "License");
 *    you may not use this file except in compliance with the License.
 *    You may obtain a copy of the License at
 *
 *        http://www.apache.org/licenses/LICENSE-2.0
 *
 *    Unless required by applicable law or agreed to in writing, software
 *    distributed under the License is distributed on an "AS IS" BASIS,
 *    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *    See the License for the specific language governing permissions and
 *    limitations under the License.
 */

#ifndef platforms_arch_x86_writer_h
#define platforms_arch_x86_writer_h

#include "zkit.h"

#include "memhelper.h"
#include "writer.h"

#include "instructions.h"
#include "regs-x86.h"
#include "writer-x86.h"

#define MAX_INSN_SIZE 256

typedef struct _X86AssemblerWriter {
  X86Instruction *insnCTXs[MAX_INSN_SIZE];
  zz_size_t insnCTXs_count;
  zz_addr_t pc;
  zz_addr_t insns_buffer;
  zz_size_t insns_size;
} X86AssemblerWriter;

X86AssemblerWriter *x86_writer_new(zz_ptr_t insns_buffer);

void x86_writer_init(X86AssemblerWriter *self, zz_addr_t insns_buffer, zz_addr_t target_ptr);

void x86_writer_reset(X86AssemblerWriter *self, zz_addr_t insns_buffer, zz_addr_t target_ptr);

void x86_writer_free(X86AssemblerWriter *self);

zz_size_t x86_writer_near_jump_range_size();

void x86_writer_put_bytes(X86AssemblerWriter *self, char *data, zz_size_t size);

void x86_writer_put_instruction(X86AssemblerWriter *self, char *insn);

#endif