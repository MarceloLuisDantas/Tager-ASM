#include <stdio.h>
#include <stdint.h>
#include "Strings.h"
#include "LinkedList.h"
#include "Files.h"

#define TRUE  1
#define FALSE 0

int validFileName(String *s) {
    ArrayString *as = split(s, '.');
    if (as->len != 2)
        return FALSE;

    if (!StringCmp(as->array[1], CStringToString("kn")))
        return FALSE;

    return TRUE;
}

int main(int argc, char const *argv[]) {
    if (argc != 2) {
        printf("Wrong number of args\n");
        return 0;
    }

    String *source_name = CStringToString((char *)(argv[1]));
    if (!validFileName(source_name)) {
        printf("%s is not a valid file", source_name->array);
        return 0;
    }
    
    File *source = loadFile(StringToCString(source_name));
    


    saveIntoFile(source, "out.kn");
    return 0;
}
