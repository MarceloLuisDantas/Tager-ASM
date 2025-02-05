#include <stdlib.h>
#include <stdint.h>
#include "Strings.h"
#include "LinkedList.h"
#include "Files.h"


int start(char *ss) {
    String *s = CStringToString(ss);
    File *f = loadFile("Teste.txt");
    addLine(f, StringToCString(s));
    saveIntoFile(f, "saved.txt");
    return 0;
}
