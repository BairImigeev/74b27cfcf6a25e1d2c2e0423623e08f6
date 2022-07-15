
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "f1.c"

int main() 
{
    int index;
    node* main_list;
    int variant, input; 
    FILE *file;
	do 
    {
        print_menu(); 
        variant = get_variant(8); 
        switch (variant) 
        {
            case 1:
                node* list = NULL;
                main_list = create_list_hands(list);
                printf("List:\n");
                print_list(main_list);
                printf("\n");
                break;

            case 2:
                printf("введите индекс для поиска: ");
                scanf("%d", &index);
                search_index(index, main_list);
                break;

            case 3:
                printf("введите индекс для удаления: ");
                scanf("%d", &index);
                main_list = remove_by_index(index, main_list);
                // print_list(main_list);
                break;

            case 4:
                printf("введите значение для поиска : ");
                scanf("%s", word);
                search_value(word, main_list);
                break;

            case 5:
                printf("введите индекс : ");
                scanf("%d", &index);
                printf("введите значение ");
                scanf("%s", word);
                main_list = add_index(word, index, main_list);
                break;

            case 6:
                printf("список : ");
                print_list(main_list);
                break;

            case 7:
                save_file(main_list);
                break;

            case 8:
                main_list = NULL;
                file = fopen("words", "r");
                main_list = open_file(file, main_list);
                break;
                
            case 9:
                main_list = generation(main_list);
                break;
        }
    } while (variant != 10);
return 0;
}

