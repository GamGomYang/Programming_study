#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    char *varName = argv[1]; 
    char *varValue = argv[2]; 


    if (getenv(varName) == NULL) {
        setenv(varName, varValue, 1);
    }


    printf("%s = %s\n", varName, getenv(varName));


    unsetenv(varName);

    return 0;
}
