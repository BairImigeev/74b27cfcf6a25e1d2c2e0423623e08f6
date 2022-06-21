#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "f1.h"

node *start, *end, *tmp;
data word;

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
		printf("индекс отсутствует");
		return NULL;
	}
	if (index >= counter/2) 
	{
		printf("!здесь!\n");
		list = end;
		i = counter-1;
		while(i != index)
		{
			printf("i = %d",i);
			if (list->previous == NULL) {
				return list;
			}
			list=list->previous;
			i--;
		}
		return list;      
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
		return list;
    }
	//return list;
}

node* search_value(data word, node *list)
{
	tmp=NULL;
	int i = 0;
  	while(list)
	{
		if (strcmp(word, list->data) == 0)
		{
			printf("найдено : индекс %d : адрес %p : значение %s\n", i, list, list->data);
			tmp = list;
			break;
		}
		i++;
		list = list->next;		
	}
	if (tmp == NULL) 
	{
		printf("ненайдено");
	}
	return tmp;
}

node* remove_first(node *list) 
{
	list = list->next;
	free(list->previous);
	list->previous = NULL;
	return list;
}

node* remove_last(node* list) 
{
	tmp = end;
	free(tmp);
	return list;
}

node* remove_by_index(int index, node* list) 
{
	node* current;
	if (index == 0) {
		return remove_first(list);
	} else if ( index < 0) {
		return list;
	}
	index = index-1;
	current = get_by_index(index, list);
	if (current == NULL) {
		printf("отсутствует индекс");
		return list;
	}  
	current->previous->next = current->next;
	if (current->next != NULL) {
		current->next->previous = current->previous;
	}
	else
	
	return remove_last(list);
	printf(" удален");
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

node *add_start(data word, node *list)
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

node *add_end(data word, node *list)
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
    if (index == 0 || index == -1) 
	{
		tmp = add_start(word, list);
		printf("Добавление в начало");
	}
	else if (index+1 > count(list))
	{
		tmp = add_end(word, list);
		printf("Добавление в конец");
	}
	else 
	{
		tmp = get_by_index(index, list);
		strcpy(new_node->data, word);
		new_node->next = tmp; 
		new_node->previous = tmp->previous;                      
		tmp->previous->next = new_node;
		tmp->previous=new_node;
		tmp = list;
	}
	return tmp; 
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
	printf("\n");
}

void print_menu() {
    printf("1. Создание базы\n");
	printf("2. Поиск элемента по индексу\n");
	printf("3. Удаление элемента по индексу\n");
	printf("4. Поиск элемента по значению\n");
	printf("5. Добавление элемента в список\n");
	printf("6. Вывод списка\n");
	printf("7. Сохранение в файл\n");
	printf("8. Считывание из файла\n");
	printf("Ваш выбор : \n");
}

int get_variant(int count) {
    int variant;
    char s[10]; 
    scanf("%s", s);

    while (sscanf(s, "%d", &variant) != 1 || variant < 1 || variant > count) {
        printf("Неккоректный ввод. Ещё раз: ");
        scanf("%s", s); 
    }
    return variant;
}

node *create_list_hands(node *list) {
	list = add_first(list);
	int answer = 1;
   // data word;
    while (answer == 1) {
		printf ("введите значение : \n");
		scanf("%s", word);
		add_last(word, list);
		printf("продолжим ? \n");
		scanf("%d", &answer);
	}
	end = ending(list, count(list));
	return list;
}

void save_file(node *current) {
	FILE *file = fopen("data_list", "w");
	int i = 0;
	while(current) {
		fputs(current->data, file);
		fputs("\n", file);
		current = current->next ;
		i++;
	}
	fclose(file);
}

void open_file(FILE *file) {
	if (file==NULL) 
	{
		printf("Ошибка открытия файла.\n\n");
		return;
	}
    while(!feof (file)) 
	{
	if (fgets(word, 20, file))
	printf("%s", word);
	}
    fclose(file);
}
