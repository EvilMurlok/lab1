//
//  laba1.h
//  number2
//
//  Created by Panin_Ilia on 26.02.2020.
//  Copyright © 2020 Panin_Ilia. All rights reserved.
//

#ifndef laba1_h
#define laba1_h
#define MAX_SIZE 256

    #include <ctype.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    char** CreateStrings(int amount_strings){
        char **string_arr = NULL;
        string_arr = (char **)malloc(amount_strings * sizeof(char *));
        getchar();
        for (int i = 0; i < amount_strings; ++i){
            char str[MAX_SIZE];
            gets(str);
            string_arr[i] = (char *)malloc(strlen(str) * sizeof(char));
            memcpy(string_arr[i], str, strlen(str));
        }
        return string_arr;
    }
void OutputStrings(int amount_strings, char **str){
    for (int i = 0; i < amount_strings; ++i)
    {
        printf("%s",str[i]);
        printf("\n");
    }
}
void concatenation(unsigned int first, unsigned int second, char **str){
    char *work_array = (char *)malloc(sizeof(char) * (strlen(str[first - 1]) + strlen(str[second - 1])));
    strcat(work_array, str[first - 1]);
    strcat(work_array, str[second - 1]);
    printf("%s", work_array);
    printf("\n");
    free(work_array);
}
void expected_freedom(int amount_strings, char **str){
    for (int i = 0; i < amount_strings; ++i)  
      free(str[i]);
    free(str);
}
void print_LeftIndex_RightIndex(unsigned int NumOfStr, unsigned int LeftIndex, unsigned int RightIndex, char **str){
    printf("искомая подстрока:\n");
    for (int i = LeftIndex - 1; i < RightIndex; ++i)
        printf("%c", str[NumOfStr - 1][i]);
    printf("\n");
}
void RecodingOfString(unsigned int NumOfStr, int Code, char **str){
    for (int i = 0; i < strlen(str[NumOfStr - 1]); ++i){
        if (isalpha(str[NumOfStr - 1][i]) && isupper(str[NumOfStr - 1][i])){
            printf("%c",tolower(str[NumOfStr - 1][i]));
        }
        else if (isalpha(str[NumOfStr - 1][i]) && islower(str[NumOfStr - 1][i])){
            printf("%c",toupper(str[NumOfStr - 1][i]));
            continue;
        }
        else if (isdigit(str[NumOfStr - 1][i])){
            printf("%c", str[NumOfStr - 1][i]);
            continue;
        }
        else {
            if (((int)str[NumOfStr - 1][i] + Code) <= 126) printf("%c", (char)((int)str[NumOfStr - 1][i] + Code));
            else
                printf("%c", str[NumOfStr - 1][i]);
        }
    }
    
}
#endif /* laba1_h */





