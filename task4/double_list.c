#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char data[10];

struct list_node 
{
   data data;
   struct list_node* previous;
   struct list_node* next;
};

data word;

typedef struct list_node node;
node *start, *end, *tmp;



node *ending(node *list, int count)
{
	while(list)
	{
		count++;
		if (list->next==NULL) 
		{
			end = list;
		}
		list = list->next;
	}
	return end;
}

int count(node* list) 
{
	int count = 0;
  	while(list)
	{
		count++;
		list = list->next;		
	}	
	return count;
}


node* get_by_index(int index, node* list)
{
	int counter = count(list);
	int i = 0;
	if (index < 0 || index > counter) 
	{
		return NULL;
	}
	if (index >= counter/2) 
	{
		printf("!здесь!\n");
		list = end;
		i = counter;
		while(i != index)
		{
			printf("i = %d",i);
			if (list->previous = NULL){
				return list;
			}
			list=list->previous;
			i--;
		}      
	}
	if (index<counter/2) 
	{
		printf("!здесь2!\n");
		for (i = 0; i <= index; i++) 
		{
			if (i == index) 
			{
				return list;
			}
		list = list->next;
		}
    }
	return list;
}

int search(data word, node *list)
{	
	int i = 0;
  	while(list)
	{
		i++;
		if (strcmp(word, list->data) == 0)
		{
			tmp =  get_by_index(i, list);
			printf("%d : %p : %p", i, tmp, tmp->data);
		}
		list = list->next;		
	}	
	printf(" Нет такого значения ");
	return 0;
}

node* remove_first(node* list) 
{
	list = list->next;
	free(list->previous);
	list->previous = NULL;
	return list;
}

// int remove_last(node* list) 
// {
// 	while(list) {
// 		if (list->next->next == NULL) {
// 			free(list->next);
// 			list->next = NULL;
// 			return 0;
// 		}
// 		list = list->next;
// 	}
// 	return -1;
// }

node* remove_by_index(int index, node* list) 
{
	node* current;
	if (index == 0) {
		return remove_first(list);
	} else if ( index < 0) {
		return list;
	}
	current = get_by_index(index, list);
	if (current == NULL) {
		return list;
	}  
	current->previous->next = current->next;
	if (current->next != NULL) {
		current->next->previous = current->previous;
	}
	free(current);
	return list;
}

node* add_first(node* list) 
{
	node* new_node;
	new_node = (node*)malloc(sizeof(node));

	strcpy(new_node->data, "hello");
    new_node->next = list;

	if (list != NULL) 
	{
		list->previous = new_node;
	}
    list = new_node;
	return list;
}

node *insert_start(data word, node *list)
{   
	tmp = list;
	node* new_node;	
	new_node = (node*)malloc(sizeof(node));
	
	strcpy(new_node->data, word);
    list->previous = new_node;
	new_node->previous = NULL;
	new_node->next = list;
	list = new_node;
	return list;
}

node *insert_end(data word, node *list)
{
	node *new_node;
	tmp = ending(list, count(list));

	new_node = (node*)malloc(sizeof(node));
	
	strcpy(new_node->data, word);
 	tmp->next = new_node;
	new_node->previous = tmp;
	new_node->next = NULL;
	return list;
}


node *add_index(data word, int index, node * list) 
{	
	node *new_node;
	new_node = (node*)malloc(sizeof(node));

	tmp = get_by_index(index, list);

    strcpy(new_node->data, word);
   
	new_node->next = tmp; 
    new_node->previous = tmp->previous;                      
	tmp->previous->next = new_node;
	tmp->previous=new_node;
	
	return list; 
}    
 

void add_last(data word, node* current) 
{
	node* new_node;
	new_node = (node*)malloc(sizeof(node));
	while(current) 
	{
		if (current->next == NULL) 
		{
			current->next = new_node;
			strcpy(new_node->data, word);
			new_node->previous = current;
			return;
		}
		current = current->next;
	}
}

void print_list(node* current) {
	printf("\n");
	int i = 0;
	while(current) {
		printf("%d : пред: %p адрес: %p знач: %s след: %p\n", i, current->previous, current, current->data, current->next);
		printf("\n");
		current = current->next ;
		i++;
	}
	printf("\n\n\n");
}



int main() 
{  
    printf("1. Создание базы\n");
	printf("2. Чтение элемента по индексу\n");
	printf("2. Удаление элемента по индексу\n");
	printf("3. Поиск элемента по значению\n");
	printf("4. Поиск элемента по индексу\n");
	// printf("5. Сохранение в файл\n");
	// printf("6. Загрузка из файла\n");
	printf("Ваш выбор : ");
	int input, input1;
	scanf("%d", &input);    
		switch (input)
      {
        case 1:
            // printf(" 1. Генерация случайных записей\n");
            printf(" 2. Добавление элементов\n ");
            scanf("%d", &input1);
            if (input1 == 1) {
              printf("!!!");
            }
            if (input1 == 2) 
			{
               node* list = NULL;
	
	    	   list = add_first(list);
		    	int answer = 1;
				while (answer == 1)
				{
					printf ("введите значение : \n");
					scanf("%s", word);
					add_last(word, list);
					printf("продолжим ? \n");
					scanf("%d", &answer);
				}
			    printf("ok\n");  

	            /* printing the original list. */
				printf(" List:\n");
				print_list(list);
				printf("\n");
      
            }
            break;

        case 2:    
            break;

        case 3:
            break;  

        default:
            printf("Wrong");
            abort();
      }
      getchar();
      return 0;
}        
