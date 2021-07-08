## Operators

Goal of this new part of the DB is to create a VM for all operations that we may need. This means that part of the DB will be responsible for generating VM programs, while another will be responsible for running those programs.

Hence we now have a `Program` object, which is a sequence of instructions or operations. The full list of possible operations are each respresented by an op code:


* BRT   - Branch if `true`
* BRF   - Branch if `false`
        - 
* ADD X Y
* SUB X Y
* MUL X Y
* DIV X Y
* MOD X Y

* TPL - Load tuple
* TPS - Store tuple



- STP - Stop the program
- 


// TC = Table Cursor

* TCN X - New cursor for table_oid=X
        - NOTE: X must be a `table_oid_t`
        - Places a `cursor_id` at the top of the stack.
        - 
* TCH X - Does the cursor with cursor_id=X have a tuple?
* TCX   - Load the next tuple.

// IC = Index Cursor



///////////// Cursor related op-codes

///////////// Aggregation related op-codes

///////////// Sorting related op-codes

///////////// Logic/Arithmetic related op-codes

///////////// Control-flow op-coces

* Branch
* Return
???

## Readings on VMs

### I need to find a good set of example opcodes to start building my own set


https://github.com/cmu-db/noisepage/blob/master/src/include/execution/vm/bytecodes.h#L48

```

  /* Branching */                                                                                                     \
  F(Jump, OperandType::JumpOffset)                                                                                    \
  F(JumpIfTrue, OperandType::Local, OperandType::JumpOffset)                                                          \
  F(JumpIfFalse, OperandType::Local, OperandType::JumpOffset)                                                         \
                                                                                                                      \
  /* Memory/pointer operations */                                                                                     \
  F(IsNullPtr, OperandType::Local, OperandType::Local)                                                                \
  F(IsNotNullPtr, OperandType::Local, OperandType::Local)                                                             \
  F(Deref1, OperandType::Local, OperandType::Local)                                                                   \
  F(Deref2, OperandType::Local, OperandType::Local)                                                                   \
  F(Deref4, OperandType::Local, OperandType::Local)                                                                   \
  F(Deref8, OperandType::Local, OperandType::Local)                                                                   \
  F(DerefN, OperandType::Local, OperandType::Local, OperandType::UImm4)                                               \
  F(Assign1, OperandType::Local, OperandType::Local)                                                                  \
  F(Assign2, OperandType::Local, OperandType::Local)                                                                  \
  F(Assign4, OperandType::Local, OperandType::Local)                                                                  \
  F(Assign8, OperandType::Local, OperandType::Local)                                                                  \
  F(AssignImm1, OperandType::Local, OperandType::Imm1)                                                                \
  F(AssignImm2, OperandType::Local, OperandType::Imm2)                                                                \
  F(AssignImm4, OperandType::Local, OperandType::Imm4)                                                                \
  F(AssignImm8, OperandType::Local, OperandType::Imm8)                                                                \
  F(AssignImm4F, OperandType::Local, OperandType::Imm4F)                                                              \
  F(AssignImm8F, OperandType::Local, OperandType::Imm8F)                                                              \
  F(Lea, OperandType::Local, OperandType::Local, OperandType::Imm4)                                                   \
  F(LeaScaled, OperandType::Local, OperandType::Local, OperandType::Local, OperandType::Imm4, OperandType::Imm4)      \
                                                                                                                      \
  /* Function calls */                                                                                                \
  F(Call, OperandType::FunctionId, OperandType::LocalCount)                                                           \
  F(Return)                                                                                                           \
                                                                                                                      \
  /* Execution Context */                                                                                             \
  F(ExecutionContextAddRowsAffected, OperandType::Local, OperandType::Local)                                          \
  F(ExecutionContextGetMemoryPool, OperandType::Local, OperandType::Local)                                            \
  F(ExecutionContextGetTLS, OperandType::Local, OperandType::Local)                                                   \
  F(ExecutionContextStartResourceTracker, OperandType::Local, OperandType::Local)                                     \
  F(ExecutionContextEndResourceTracker, OperandType::Local, OperandType::Local)                                       \
  F(ExecutionContextStartPipelineTracker, OperandType::Local, OperandType::Local)                                     \
  F(ExecutionContextEndPipelineTracker, OperandType::Local, OperandType::Local, OperandType::Local,                   \
    OperandType::Local)                                                                                               \
  F(ExecutionContextInitHooks, OperandType::Local, OperandType::Local)                                                \
  F(ExecutionContextRegisterHook, OperandType::Local, OperandType::Local, OperandType::FunctionId)                    \
  F(ExecutionContextClearHooks, OperandType::Local)                                                                   \
  F(ExecOUFeatureVectorRecordFeature, OperandType::Local, OperandType::Local, OperandType::Local, OperandType::Local, \
    OperandType::Local, OperandType::Local)                                                                           \
  F(ExecOUFeatureVectorInitialize, OperandType::Local, OperandType::Local, OperandType::Local, OperandType::Local)    \
  F(ExecOUFeatureVectorFilter, OperandType::Local, OperandType::Local)                                                \
  F(ExecOUFeatureVectorReset, OperandType::Local)                                                                     \

....
  /* Thread State Container */                                                                                        \
  F(ThreadStateContainerIterate, OperandType::Local, OperandType::Local, OperandType::FunctionId)                     \
  F(ThreadStateContainerAccessCurrentThreadState, OperandType::Local, OperandType::Local)                             \
  F(ThreadStateContainerReset, OperandType::Local, OperandType::Local, OperandType::FunctionId,                       \
    OperandType::FunctionId, OperandType::Local)                                                                      \
  F(ThreadStateContainerClear, OperandType::Local)                                                                                                                          


  /* Table Vector Iterator */                                                                                         \
  F(TableVectorIteratorInit, OperandType::Local, OperandType::Local, OperandType::Local, OperandType::Local,          \
    OperandType::UImm4)                                                                                               \
  F(TableVectorIteratorPerformInit, OperandType::Local)                                                               \
  F(TableVectorIteratorNext, OperandType::Local, OperandType::Local)                                                  \
  F(TableVectorIteratorFree, OperandType::Local)                                                                      \
  F(TableVectorIteratorGetVPINumTuples, OperandType::Local, OperandType::Local)                                       \
  F(TableVectorIteratorGetVPI, OperandType::Local, OperandType::Local)                                                \
  F(ParallelScanTable, OperandType::Local, OperandType::Local, OperandType::UImm4, OperandType::Local,                \
    OperandType::Local, OperandType::FunctionId)            
    
    
    
    
MANY MORE AFTER THIS!...
```


https://justinmeiners.github.io/lc3-vm/

```
enum
{
    OP_BR = 0, /* branch */
    OP_ADD,    /* add  */
    OP_LD,     /* load */
    OP_ST,     /* store */
    OP_JSR,    /* jump register */
    OP_AND,    /* bitwise and */
    OP_LDR,    /* load register */
    OP_STR,    /* store register */
    OP_RTI,    /* unused */
    OP_NOT,    /* bitwise not */
    OP_LDI,    /* load indirect */
    OP_STI,    /* store indirect */
    OP_JMP,    /* jump */
    OP_RES,    /* reserved (unused) */
    OP_LEA,    /* load effective address */
    OP_TRAP    /* execute trap */
};
```

https://en.wikibooks.org/wiki/Creating_a_Virtual_Machine/Register_VM_in_C

```
/* instruction fields */
int instrNum = 0;
int reg1     = 0;
int reg2     = 0;
int reg3     = 0;
int imm      = 0;

/* decode a word */
void decode( int instr )
{
  instrNum = (instr & 0xF000) >> 12;
  reg1     = (instr & 0xF00 ) >>  8;
  reg2     = (instr & 0xF0  ) >>  4;
  reg3     = (instr & 0xF   );
  imm      = (instr & 0xFF  );
}

/* the VM runs until this flag becomes 0 */
int running = 1;

/* evaluate the last decoded instruction */
void eval()
{
  switch( instrNum )
  {
    case 0:
      /* halt */
      printf( "halt\n" );
      running = 0;
      break;
    case 1:
      /* loadi */
      printf( "loadi r%d #%d\n", reg1, imm );
      regs[ reg1 ] = imm;
      break;
    case 2:
      /* add */
      printf( "add r%d r%d r%d\n", reg1, reg2, reg3 );
      regs[ reg1 ] = regs[ reg2 ] + regs[ reg3 ];
      break;
  }
}
```

https://bartoszsypytkowski.com/simple-virtual-machine/

```
        switch (opcode) {   // decode
        case HALT: return;  // stop the program
        case CONST_I32: ...
        case ADD_I32: ...
        case SUB_I32: ...
        case MUL_I32: ...
        case LT_I32: ...
        case EQ_I32: ...
        case JMP: ...
        case JMPT: ...
        case JMPF: ...
        case LOAD:  ...
        case GLOAD: ...
        case GSTORE: ...
        case CALL: ...
        case RET: ...
        case POP:
            --vm->sp;      // throw away value at top of the stack
            break;
        case PRINT:
            v = POP(vm);        // pop value from top of the stack ...
            printf("%d\n", v);  // ... and print it
            break;
        default:
            break;
        }
```


https://github.com/mnjrupp/simple-vm-cpp/blob/master/src/simple-vm.h

```
		static const unsigned short IADD = 1;    //int add
		static const unsigned short ISUB = 2;
		static const unsigned short IMUL = 3;
		static const unsigned short ILT = 4;	//int less than
		static const unsigned short IEQ = 5;	//int equal
		static const unsigned short BR = 6;		//branch
		static const unsigned short BRT = 7;	// branch if true
		static const unsigned short BRF = 8;	// branch if false
		static const unsigned short ICONST = 9;	// push const int
		static const unsigned short LOAD = 10;
		static const unsigned short GLOAD = 11;
		static const unsigned short STORE = 12;
		static const unsigned short GSTORE = 13;
		static const unsigned short PRINT = 14;
		static const unsigned short POP = 15;
		static const unsigned short HALT = 16;
		static const unsigned short CALL = 17;
		static const unsigned short RET = 18;
		static const unsigned short INIT = 19;
```
