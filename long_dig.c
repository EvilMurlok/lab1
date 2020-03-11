//
//  task1.c
//  number_1
//
//  Created by Panin_Ilia on 12.02.2020.
//  Copyright © 2020 Panin_Ilia. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#define BORDER 1001
char *CreateDigit(char *str, int len);
char *Plus(char *str1, char *str2, int border, int delta);
char *Substruction(char *str1, char* str2, int border, int delta);
int digit(char ch);
void prints(char *str, int len);
int CompareDigits(char *str1, char *str2);

int main(){
    char InputStr1[BORDER];
    char InputStr2[BORDER];
    printf("введите первую строку, состоящую ТОЛЬКО из чисел!!\n");
    gets(InputStr1);
    printf("введите вторую строку, состоящую ТОЛЬКО из чисел!!\n");
    gets(InputStr2);
    int StrLen1 = strlen(InputStr1);
    int StrLen2 = strlen(InputStr2);
    int border = (StrLen1 > StrLen2) ? (StrLen1 + 1) : (1 + StrLen2);
    int delta = abs(StrLen2 - StrLen1);
    if (StrLen1 >= StrLen2 && InputStr1[0] != '-' && InputStr2[0] != '-'){
        char *StrPoint1 = CreateDigit(InputStr1, StrLen1);
        char *StrPoint2 = CreateDigit(InputStr2, StrLen2);
        printf("Исходные данные:\n");
        prints(StrPoint1, StrLen1);
        printf("  +  ");
        prints(StrPoint2, StrLen2);
        printf("  =  ");
        char *result_of_summ = Plus(StrPoint1 , StrPoint2, border, delta);
        int i = 0;
        while (*(result_of_summ + i)){
            printf("%c", *(result_of_summ + i));
            ++i;
        }
        printf("\n");
        free(result_of_summ);
        free(StrPoint1);
        free(StrPoint2);
    }
    else if (StrLen2 > StrLen1 && InputStr1[0] != '-' && InputStr2[0] !='-'){
        char *StrPoint1 = CreateDigit(InputStr1, StrLen1);
        char *StrPoint2 = CreateDigit(InputStr2, StrLen2);
        printf("Исходные данные:\n");
        prints(StrPoint1, StrLen1);
        printf("  +  ");
        prints(StrPoint2, StrLen2);
        printf("  =  ");
        char *result_of_summ = Plus(StrPoint2, StrPoint1, border, delta);
        int i = 0;
        while (*(result_of_summ + i)){
            printf("%c", *(result_of_summ + i));
            ++i;
        }
        printf("\n");
        free(result_of_summ);
        free(StrPoint1);
        free(StrPoint2);
    }
    else if(StrLen1 >= StrLen2 && InputStr1[0] == '-' && InputStr2[0] == '-'){
        char *StrPoint1 = CreateDigit(InputStr1 + 1, StrLen1 - 1);
        char *StrPoint2 = CreateDigit(InputStr2 + 1, StrLen2 - 1);
        printf("Исходные данные:\n- ");
        prints(StrPoint1, StrLen1);
        printf("  -  ");
        prints(StrPoint2, StrLen2);
        printf("  =  ");
        char *result_of_summ = Plus(StrPoint1, StrPoint2, border - 1, delta);
        int i = 0;
        printf("-");
        while (*(result_of_summ + i)){
            printf("%c", *(result_of_summ + i));
            ++i;
        }
            printf("\n");
            free(result_of_summ);
            free(StrPoint1);
            free(StrPoint2);
    }
    else if (StrLen2 > StrLen1 && InputStr1[0] == '-' && InputStr2[0] == '-'){
        char *StrPoint1 = CreateDigit(InputStr1 + 1, StrLen1 - 1);
        char *StrPoint2 = CreateDigit(InputStr2 + 1, StrLen2 - 1);
        printf("Исходные данные:\n- ");
        prints(StrPoint1, StrLen1);
        printf("  -  ");
        prints(StrPoint2, StrLen2);
        printf("  =  ");
        char *result_of_summ = Plus(StrPoint2, StrPoint1, border - 1, delta);
        int i = 0;
        printf("-");
        while (*(result_of_summ + i)){
            printf("%c", *(result_of_summ + i));
            ++i;
        }
        printf("\n");
        free(result_of_summ);
        free(StrPoint1);
        free(StrPoint2);
    }
    else if(StrLen1 - 1 > StrLen2 && InputStr1[0] == '-' && InputStr2[0] != '-'){
        char *StrPoint1 = CreateDigit(InputStr1 + 1, StrLen1 - 1);
        char *StrPoint2 = CreateDigit(InputStr2, StrLen2);
        printf("Исходные данные:\n-");
        prints(StrPoint1, StrLen1);
        printf("  +  ");
        prints(StrPoint2, StrLen2);
        printf("  =  ");
        char *result_of_substruction = Substruction(StrPoint1, StrPoint2, border - 1, delta - 1);
        int i = 0;
        printf("-");
        while (*(result_of_substruction + i) == '0' && *(result_of_substruction + 1 + i)) ++i;
        while (*(result_of_substruction + i)){
            printf("%c", *(result_of_substruction + i));
            ++i;
        }
        printf("\n");
        free(result_of_substruction);
        free(StrPoint1);
        free(StrPoint2);
    }
    else if (StrLen1  < StrLen2 -  1 && InputStr1[0] != '-' && InputStr2[0] == '-'){
        char *StrPoint1 = CreateDigit(InputStr1, StrLen1);
        char *StrPoint2 = CreateDigit(InputStr2 + 1, StrLen2 - 1);
        printf("Исходные данные:\n");
        prints(StrPoint1, StrLen1);
        printf("  -  ");
        prints(StrPoint2, StrLen2);
        printf("  =  ");
        char *result_of_substruction = Substruction(StrPoint2, StrPoint1, border - 1, delta - 1);
        int i = 0;
        printf("-");
        while (*(result_of_substruction + i) == '0' && *(result_of_substruction + 1 + i)) ++i;
        while (*(result_of_substruction + i)){
            printf("%c", *(result_of_substruction + i));
            ++i;
        }
        printf("\n");
        free(result_of_substruction);
        free(StrPoint1);
        free(StrPoint2);
    }
    else if (StrLen1 > StrLen2 - 1 && InputStr1[0] != '-' && InputStr2[0] == '-'){
        char *StrPoint1 = CreateDigit(InputStr1, StrLen1);
        char *StrPoint2 = CreateDigit(InputStr2 + 1, StrLen2 - 1);
        printf("Исходные данные:\n");
        prints(StrPoint1, StrLen1);
        printf("  -  ");
        prints(StrPoint2, StrLen2);
        printf("  =  ");
        char *result_of_substruction = Substruction(StrPoint1, StrPoint2, border, delta + 1);
        int i = 0;
        while (*(result_of_substruction + i) == '0' && *(result_of_substruction + 1 + i)) ++i;
        while (*(result_of_substruction + i)){
            printf("%c", *(result_of_substruction + i));
            ++i;
        }
        printf("\n");
        free(result_of_substruction);
        free(StrPoint1);
        free(StrPoint2);
    }
    else if (StrLen1 - 1 < StrLen2 && InputStr1[0] == '-' && InputStr2[0] != '-'){
        char *StrPoint1 = CreateDigit(InputStr1 + 1, StrLen1 - 1);
        char *StrPoint2 = CreateDigit(InputStr2, StrLen2);
        printf("Исходные данные:\n-");
        prints(StrPoint1, StrLen1);
        printf("  +  ");
        prints(StrPoint2, StrLen2);
        printf("  =  ");
        char *result_of_substruction = Substruction(StrPoint2, StrPoint1, border, delta + 1);
        int i = 0;
        while (*(result_of_substruction + i) == '0' && *(result_of_substruction + 1 + i)) ++i;
        while (*(result_of_substruction + i)){
            printf("%c", *(result_of_substruction + i));
            ++i;
        }
        printf("\n");
        free(result_of_substruction);
        free(StrPoint1);
        free(StrPoint2);
    }
    //обработать случаи, когда количество цифр в вводимых  числах равно(2 случая)
    else if(StrLen1 - 1 == StrLen2 && InputStr1[0] == '-' && InputStr2[0] != '-'){
        char *StrPoint1 = CreateDigit(InputStr1 + 1, StrLen1 - 1);
        char *StrPoint2 = CreateDigit(InputStr2, StrLen2);
        printf("Исходные данные:\n-");
        prints(StrPoint1, StrLen1);
        printf("  +  ");
        prints(StrPoint2, StrLen2);
        printf("  =  ");
        int i = 0;
        if (CompareDigits(StrPoint1, StrPoint2) == 0){
            printf("%d\n", 0);
            return 0;
        }
        else if (CompareDigits(StrPoint1, StrPoint2) == 1){
            printf("-");
            char *result_of_substruction = Substruction(StrPoint1, StrPoint2, border - 1, delta -  1);
            while (*(result_of_substruction + i) == '0' && *(result_of_substruction + 1 + i)) ++i;
            while (*(result_of_substruction + i)){
                printf("%c", *(result_of_substruction + i));
                ++i;
            }
            printf("\n");
            free(result_of_substruction);
            free(StrPoint1);
            free(StrPoint2);
        }
        else{
            char *result_of_substruction = Substruction(StrPoint2, StrPoint1, border - 1, delta - 1);
            while (*(result_of_substruction + i) == '0' && *(result_of_substruction + 1 + i)) ++i;
            while (*(result_of_substruction + i)){
                printf("%c", *(result_of_substruction + i));
                ++i;
            }
            printf("\n");
            free(result_of_substruction);
            free(StrPoint1);
            free(StrPoint2);
        }
    }
    return 0;
}



//возвращает 1, если первое число больше второго,
//0, если числа равны
//-1, если второе число больше
int CompareDigits(char *str1, char *str2){
    while (*str1 && *str2){
        if (*str1 > *str2)
            return 1;
        else if (*str1 == *str2){
            ++str1;
            ++str2;
            continue;
        }
        else
            return -1;
    }
    return 0;
}



char* CreateDigit(char *str, int len){
    char* StrArray = (char*)malloc(sizeof(char) * (len + 1));
    //if (*str == '-')
     //   *StrArray = '-';
    for (int i = 0; i <= len; ++i){
        if (i == len)
            *(StrArray + i) = '\0';
        else
            *(StrArray + i) = *(str + i);
        
    }
    return StrArray;
}
int digit(char ch){
    switch ((int)ch) {
        case 48:
            return  0;
            break;
        case 49:
            return  1;
            break;
        case 50:
            return  2;
            break;
        case 51:
            return 3;
            break;
        case 52:
            return 4;
            break;
        case 53:
            return  5;
            break;
        case 54:
            return 6;
            break;
        case 55:
            return 7;
            break;
        case 56:
            return 8;
            break;
        case 57:
            return 9;
            break;
        default:
            printf("просил же ввести только цифры!!\n Вы сломали программу\n");
            exit(1);
            break;
    }
}

char *Plus(char *str1, char *str2, int border, int delta){
    char *answer = (char*)malloc(sizeof(char) * (1 + border));
    int addition = 0;
    *(answer + border) = '\0';
    int a = 0;
    for (int i = border - 2; i > -1; --i){
        int b = 0;
        if (i >= delta){
            a = digit(*(str1 + i));
            b = digit(*(str2 + i - delta));
            *(answer + i + 1) = (char)((a + b + addition)%10 + 48);
            if (a + b + addition >= 10)
                addition = 1;
            else
                addition = 0;
        }
        else{
            a = digit(*(str1 + i));
            *(answer + i + 1) = (char)((a + addition)%10 + 48);
            if (a + addition == 10)
                addition = 1;
            else
                addition = 0;
        }
    }
    if (addition) {
        answer[0] = (char)(addition % 10 + 48);
    }
    else
    {
        *answer = ' ';
        
    }
    return answer;
}
char *Substruction(char *str1, char* str2, int border, int delta){
    char *answer = (char*)malloc(sizeof(char) * (border));
    *(answer + border - 1) = '\0';
    int  decrease = 0, ten = 0, a = 0, b = 0;;
    char fl = 0;
    for (int i = border - 2; i > -1; --i){
        if (i >= delta){
            a = digit(*(str1 + i));
            b = digit(*(str2 + i - delta));
            //printf("%d %d\t", a, b);
            if (a + decrease - b < 0){
                 ten = 1;
                 fl = 1;
            }
            else{
                ten = 0;
                fl = 0;
            }
            *(answer + i) = (char)(10 * ten + decrease + a - b + 48);
            //printf("%c\n", *(answer + i));
            if (fl)
                decrease = -1;
            else
                decrease = 0;
        }
        else{
            a = digit(*(str1 + i));
            if (a + decrease < 0){
                ten = 1;
                fl = 1;
            }
            else{
                ten = 0;
                fl = 0;
            }
            *(answer + i) = (char)(10 * ten + decrease + a + 48);
            //printf("%c\n", *(answer + i));
            if (fl)
                decrease = -1;
            else
                decrease = 0;
        }
    }
    //printf("\n");
    return answer;
}

void prints(char *str, int len){
    for (int i = 0; i < len; ++i){
        printf("%c", *(str + i));
    }
}

