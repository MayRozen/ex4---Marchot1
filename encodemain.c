#include <stdio.h>
#include <string.h>
#include "compress.h"

int main(int argc, char* argv[]){

    if(argc != 2){
        perror("The input is not correct\n");
        return -1;
    }

    char* operation = argv[0]; //-c or -d

    if((strcmp(operation, "-c")!= 0) || (strcmp(operation, "-d")!= 0)){ //If the input is not "-c" or "-d"
        perror("Invailed input\n");
        return -1;
    }

    char* fileName = argv[1]; //the file
    char* fileType = strrchr(fileName, '.');

    if((strcmp(fileType, "txt")!= 0) || (strcmp(fileType, "bin")!= 0)){ //If the file type is incorrect
        perror("The file type is incorrect\n");
        return -1;
    }

    FILE* output_file = fopen("output_file.Bin","wb+"); //If the file is not exist -> it will be created.
    int num = 0;

    if(strcmp(fileType, "txt")== 0){ //If the type is txt
       FILE* text = fopen("filename","r+");
       if(text == NULL){
            printf("Failed to open file\n");
            return -1;
       }
       
       while(num != NULL){
            num = fgetc(text); //Get the first number (0-9)
            num = toBinary(num); //Make num to binary number
            num = change(num); //Performs the encryption

            fwrite(&num, sizeof(int), 1, output_file);
       }

       if(fcolse(text)==0){
            printf("The file was closed successfully!\n");
        }
        else{
            printf("Failed to close the file\n");
            return -1;
        }
    }
    else if(strcmp(fileType, "bin")== 0){ //If the type is Bin
        FILE* binary = fopen("filename","rb+");
        if(binary == NULL){
            printf("Failed to open file\n");
            return -1;
       }

        while(num!=NULL){
            num = fread(&num, sizeof(int), 1, binary);
            num = change(num);

            fwrite(&num, sizeof(int), 1, output_file);
        }

        if(fcolse(binary)==0){
            printf("The file was closed successfully!\n");
        }
        else{
            printf("Failed to close the file\n");
            return -1;
        }
    }

    if(fclose(output_file)!=0){
        printf("Failed to close the file\n");
        return -1;
    }
    else{
        printf("The output_file was closed successfully!\n");
    }

    return 0;
}