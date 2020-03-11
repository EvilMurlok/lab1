//
//  laba1.c
//  number2
//
//  Created by Panin_Ilia on 26.02.2020.
//  Copyright © 2020 Panin_Ilia. All rights reserved.
//
#define _CRT_SECURE_NO_WARNINGS
#include "laba1.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


int main32(){
    int YourChoice;
    int YourFirstChoice;
    /*printf("введите 1, если хотите начать работу\n");
    printf("вам будут предложены различные варианты действий с ними\n");
    scanf("%d", &YourChoice);
    if (YourChoice != 1){
        printf("До свидания\n");
        return 0;
    }*/
    do{
        printf("введите 1, если хотите обрабатывать строки\n");
        //printf("введите 2, если хотите пройти тестирование\n");
        printf("остальные значения завершат работу\n");
        scanf("%d", &YourFirstChoice);
        if (YourFirstChoice == 1){
            int amount_strings;
            printf("Введите количество строк, с которыми вы будете работать\n");
            scanf("%d", &amount_strings);
            if(amount_strings <=0){
                printf("если не хотите работать, то завершите программу\n");
                continue;
            }
            char **str = CreateStrings(amount_strings);
            printf("исходные данные\n");
            OutputStrings(amount_strings, str);
            do{
                printf("введите что вы хотели бы сделать: \n");
                printf("1 - конкатенация  строк\n");
                printf("2 - выделение подстроки с символа i по символ j\n");
                printf("3 - перекодировка символов в зависимости от символа и введенного знаечения для перекодирования\n");
                printf("4 - ввести новые строки, т.е. новые данные и произвести операции с ними\n");
                printf("Остальные номера не приведут ни к чему хорошему, ибо Вам придется вводить новые данные. Вы предупреждены!\n");
                scanf("%d", &YourChoice);
                switch (YourChoice) {
                    case 1:
                    {
                        unsigned int first, second;
                        do {
                            printf("введите два номер 1й строки, к которой надо присоединить вторую строку");
                            scanf("%u", &first);
                            printf("введите два номер 1й строки, к которой надо присоединить вторую строку");
                            scanf("%u", &second);
                        }while (first <= 1 || first > amount_strings || second <= 1 || second > amount_strings);
                        concatenation(first, second, str);
                        break;
                    }
                    case 2:{
                        unsigned int LeftIndex, RightIndex, NumberOfString;;
                        do {
                            
                            for(;;){
                                printf("из какой строки Вы хотите извлечь подстроку?");
                                scanf("%d", &NumberOfString);
                                if (NumberOfString <= amount_strings && NumberOfString > 0) break;
                            }
                            printf("введите начало вхождения подстроки\n");
                            printf("напомню, что номер первого вхождения не должен превышать %lu\n", strlen(str[NumberOfString - 1]));
                            scanf("%d", &LeftIndex);
                            printf("введите правую границу подстроки, которую надо выделить/n");
                            printf("напомню, что номер второго вхождения не должен превышать %lu и не может быть меньше %u\n", strlen(str[NumberOfString - 1]), LeftIndex);
                            scanf("%u", &RightIndex);
                            
                        }while(LeftIndex > RightIndex || LeftIndex < 0 || RightIndex < 0 || LeftIndex > strlen(str[NumberOfString - 1]) || RightIndex > strlen(str[NumberOfString - 1]));
                        print_LeftIndex_RightIndex(NumberOfString, LeftIndex, RightIndex, str);
                        break;
                    }
                    case 3:{
                        unsigned int NumberOfString;
                        printf("в случае буквы, регистр будет изменен на противоположный, если встретится число, ничего не произойдет, а символ будет перекодироваться в зависимости от введенного Вами значения\nВведите его\n");
                        int ChangeCode;
                        scanf("%d", &ChangeCode);
                        for(;;){
                            printf("введите номер строки, которую вы хотите перекодировать\n");
                            scanf("%u", &NumberOfString);
                            if (NumberOfString > 0 && NumberOfString <= amount_strings) break;
                        }
                        RecodingOfString(NumberOfString, ChangeCode, str);
                        break;
                    }
                    default:
                        printf("придется вводить данные заново!\n");
                        break;
                }
            }
            while(YourChoice == 1 || YourChoice == 2 || YourChoice == 3);
            expected_freedom(amount_strings, str);
        }
        else if (YourFirstChoice == 2){
            //here will be tests
        }
        else{
            printf("До свидания\n");
        }
    }while(YourFirstChoice == 1 || YourFirstChoice == 2);
    return 0;
}
