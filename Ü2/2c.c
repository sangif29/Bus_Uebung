#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <unistd.h>

int main() {
    printf("Creating directory\n");
    if(mkdir("Erstellter_Ordner", S_IRWXU | S_IRWXG | S_IRWXO) != 0) {
        printf("Error occurred while creating directory");
        return 1;
    }

    printf("Changing directory and creating file\n");
    if (chdir("Erstellter_Ordner") != 0) {
        printf("Error occurred during directory change");
        return 1;
    }
    FILE *datei_ptr = fopen("test", "a");
    if (datei_ptr == NULL) {
        printf("Error occured\n");
        fclose(datei_ptr);
        return 1;
    } 

    printf("Writing 123 into the txt file\n");
    fprintf(datei_ptr, "123");

    printf("Finished successfully");
    fclose(datei_ptr);
    return 0;
}