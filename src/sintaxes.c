#include "Strings.h"
#include <string.h>

#define TRUE 1  
#define FALSE 0 

/*  Registers
 *  #0        -> $zero      |- allways zero
 *  #1        -> $gp        |- global pointer
 *  #2 .. #3  -> $a0 .. $a1 |- arguments to procedures
 *  #4 .. #5  -> $v0 .. $v1 |- result from procedures
 *  #6 .. #10 -> $t0 .. $t4 |- temporary values free use
 *  #11       -> $pp        |- programe pointer
 *  #12       -> $sp        |- Stack pointer
 *  #13       -> $fp        |- Frame pointer
 *  #14       -> $ra        |- return address
 *  #15       -> $sc        |- syscall
 */
int validRegisterName(String *s) {
    char *cstring = StringToCString(s);
    if      (strcmp(cstring, "$zero")) { return TRUE;  }
    else if (strcmp(cstring, "$gp"))   { return TRUE;  }
    else if (strcmp(cstring, "$pp"))   { return TRUE;  }
    else if (strcmp(cstring, "$sp"))   { return TRUE;  }
    else if (strcmp(cstring, "$fp"))   { return TRUE;  }
    else if (strcmp(cstring, "$ra"))   { return TRUE;  }
    else if (strcmp(cstring, "$sc"))   { return TRUE;  }
    else if (strcmp(cstring, "$a0"))   { return TRUE;  }
    else if (strcmp(cstring, "$a1"))   { return TRUE;  }
    else if (strcmp(cstring, "$v0"))   { return TRUE;  }
    else if (strcmp(cstring, "$v1"))   { return TRUE;  }
    else if (strcmp(cstring, "$t0"))   { return TRUE;  }
    else if (strcmp(cstring, "$t1"))   { return TRUE;  }
    else if (strcmp(cstring, "$t2"))   { return TRUE;  }
    else if (strcmp(cstring, "$t3"))   { return TRUE;  }
    else if (strcmp(cstring, "$t4"))   { return TRUE;  }
    else                                      { return FALSE; }
}

int check3Registers(ArrayString *as) {
    int r1 = validRegisterName(get(as, 1));
    if (!r1) return FALSE;

    int r2 = validRegisterName(get(as, 2));
    if (!r2) return FALSE;

    int r3 = validRegisterName(get(as, 3));
    if (!r1) return FALSE;

    return TRUE;
}

/*  Instructions
 *  nop              |- do nothing for 1 cycle 
 *  add  r1 r2 r3    |- r1 = r2 + r3 
 *  addi r1 r2 v1    |- r1 = r2 + v1 
 *  sub  r1 r2 r3    |- r1 = r2 - r3
 *  subi r1 r2 v1    |- r1 = r2 - v1
 *  mut  r1 r2 r3    |- r1 = r2 * r3 
 *  muti r1 r2 v1    |- r1 = r2 * v1
 *  div  r1 r2 r3    |- r1 = r2 / r3
 *  divi r1 r2 v1    |- r1 = r2 / v1
 *  and  r1 r2 r3    |- r1 = r2 $ r3
 *  or   r1 r2 r3    |- r1 = r2 | r3
 *  sl   r1 r2 v1    |- r1 = r2 << v1
 *  sr   r1 r2 v1    |- r1 = r2 >> v1
 *  mov  r1 r2       |- r1 = r2 
 *  jump point       |- jump to point
 *  jal  point       |- jump to point and link
 *  jr   register    |- jump to the point in the register 
 *  slt  r1 r2 r3    |- if(r2<r3) r1=1; r1=0
 *  slti r1 r2 v1    |- if(r2<v1) r1=1; r1=0
 *  beq  r1 r2 point |- if(r1=r2) jump point
 *  bne  r1 r2 point |- if(r1!=r2) jump point
 */
int validInstruction(String *s) {
    char *cstring = StringToCString(s);
    if      (strcmp(cstring, "$nop"))  { return TRUE;  }
    else if (strcmp(cstring, "$add"))  { return TRUE;  }
    else if (strcmp(cstring, "$sub"))  { return TRUE;  }
    else if (strcmp(cstring, "$div"))  { return TRUE;  }
    else if (strcmp(cstring, "$mut"))  { return TRUE;  }
    else if (strcmp(cstring, "$addi")) { return TRUE;  }
    else if (strcmp(cstring, "$subi")) { return TRUE;  }
    else if (strcmp(cstring, "$divi")) { return TRUE;  }
    else if (strcmp(cstring, "$muti")) { return TRUE;  }
    else if (strcmp(cstring, "$and"))  { return TRUE;  }
    else if (strcmp(cstring, "$or"))   { return TRUE;  }
    else if (strcmp(cstring, "$sl"))   { return TRUE;  }
    else if (strcmp(cstring, "$sr"))   { return TRUE;  }
    else if (strcmp(cstring, "$mov"))  { return TRUE;  }
    else if (strcmp(cstring, "$jump")) { return TRUE;  }
    else if (strcmp(cstring, "$jal"))  { return TRUE;  }
    else if (strcmp(cstring, "$jr"))   { return TRUE;  }
    else if (strcmp(cstring, "$slt"))  { return TRUE;  }
    else if (strcmp(cstring, "$slti")) { return TRUE;  }
    else if (strcmp(cstring, "$beq"))  { return TRUE;  }
    else if (strcmp(cstring, "$bne"))  { return TRUE;  }
    else                                      { return FALSE; }
}


// add $a1 $a2 $a3
String *sintaxeAdd(String *s) { 
    ArrayString *tokens = split(s, ' ');
    if (tokens->len != 4)
        return CStringToString("wrong number of args");
    

}
