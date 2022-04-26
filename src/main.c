#include <stdio.h>
#include <string.h>

struct Arguments {
    char *files[100]; // A list of source files, given by arguments
    int fileAmount; // Amount of files
    char *arguments[100]; // Arguments
    int argumentAmount; // Amount of arguments
};


struct Arguments parseArgs(int argc, char ** argv);

int main(int argc, char ** argv) {
    
    struct Arguments a = parseArgs(argc, argv);
    
    for (int i = 0; i < a.argumentAmount; i++) {
        if (strcmp(a.arguments[i], "-h") == 0) {
            printf("Blade v1.0.0\n");
            printf("Usage: blade [options] file...\n");
            printf("Options:\n");
            printf("  -h         Print this message and exit.\n");
            printf("  -v         Print blade's version and exit.\n");
            printf("  ");
            return 0;
        } else if (strcmp(a.arguments[i], "-v") == 0) {
            printf("Blade compiler version 1.0.0\n");
            printf("(C) Samuel 2022\n");
            return 0;
        }
    }

    printf("Blade v1.0.0 compiler loaded...\n");
    printf("Need to compile %d file(s)...\n", a.fileAmount-1);
    
    // Check files
    for (int i = 1; i < a.fileAmount; i++) {
        FILE *file;
        if (!(file = fopen(a.files[i], "r"))) {
            printf("Error: File not found: %s\n", a.files[i]);
            return -1;
        }
        fclose(file);
    }
    
    
}

// Argument parser
struct Arguments parseArgs(int argc, char ** argv) {
    struct Arguments parsedArgs;
    parsedArgs.fileAmount = 0; // Make it easier for us, so we don't have to write tons of code to not cause a fault.
    parsedArgs.argumentAmount = 0;
    for (int i = 0; i < argc; i++) {
        if (argv[i][0] == '-') {
            parsedArgs.arguments[parsedArgs.argumentAmount] = argv[i];
            parsedArgs.argumentAmount++;
        } else {
            parsedArgs.files[parsedArgs.fileAmount] = argv[i];
            parsedArgs.fileAmount++;
        }
    }
    
    return parsedArgs;
}



