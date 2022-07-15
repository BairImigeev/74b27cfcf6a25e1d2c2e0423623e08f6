#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "f1.h"

node *start, *end, *tmp, *new_list;
data word;
int i, ending;


node* get_by_index(int index, node* list)
{
	count(list);
	if (index >= ending/2) 
	{
		list = end;
	    for (i=ending; i>=index; i--)
		{
			if (i == index) {
				return list;
			}			
            list = list->previous;
		}
	}	  	      
	if (index<ending/2) 
	{
		for (i = 0; i <= index; i++) {
			if (i == index)
			{
				return list;
			}
		list = list->next;
		}
	}
	return list;
}

node* search_value(data word, node *list)
{
	tmp=NULL;
	i = 0;
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
	count(list);
	return list;
}

node* remove_last(node* list) 
{
	end->previous->next = NULL;
    free(end);
	count(list);
	return list;
}

node* remove_by_index(int index, node* list) 
{
	node* current;

	if (index < 0 || index > ending) {
		printf("индекс отсутствует\n");
		return list;
	}
	if (index == 0) {
		return remove_first(list);
	}
	if (index == ending) {
		return remove_last(list);
	}
	
	current = get_by_index(index, list);
	current->previous->next = current->next;
	current->next->previous = current->previous;
	free(current);
	count(list);
	return list;
}

node* add_first(node* list) 
{
	node* new_node;
	new_node = (node*)malloc(sizeof(node));
	strcpy(new_node->data, "hello");
	list = new_node;
	list->next = NULL;
	list->previous = NULL;
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
	count(list);
	return list;
}

node *add_end(data word, node *list)
{
	node *new_node;
	tmp = end;

	new_node = (node*)malloc(sizeof(node));
	
	strcpy(new_node->data, word);
 	tmp->next = new_node;
	new_node->previous = tmp;
	new_node->next = NULL;
	count(list);
	return list;
}

node *add_index(data word, int index, node * list) 
{	
	count(list);
	node *new_node;
	new_node = (node*)malloc(sizeof(node));
    if (index == 0 || index == -1) 
	{
		list = add_start(word, list);
		printf("Добавление в начало списка :\n");
	}
	else if (index > ending)
	{
		list = add_end(word, list);
		printf("Добавление в конец списка :\n");
	}
	else 
	{
		tmp = get_by_index(index, list);
		strcpy(new_node->data, word);
		new_node->next = tmp; 
		new_node->previous = tmp->previous;                      
		tmp->previous->next = new_node;
		tmp->previous=new_node;
	}
	count(list);
	return list; 
}     

void add_last(data word, node* list)
{
	node* new_node;
	new_node = (node*)malloc(sizeof(node));
	while(list) 
	{
		if (list->next == NULL)
		{
			list->next = new_node;
			strcpy(new_node->data, word);
			new_node->previous = list;
			new_node->next = NULL;
			return;
		}
		list = list->next;
	}
}

void print_list(node* current) {
	printf("текущий указатель : %p\n", current);
	i = 0;
	if (current == NULL) {
		printf("Остуствует список\n");
		return;
	} 
	while(current) {
		printf("%d : пред: %p адрес: %p знач: %s след: %p\n", i, current->previous, current, current->data, current->next);
		printf("\n");
		current = current->next ;
		i++;
	}
	printf("\n");
}

void print_menu() {
	printf("1. Создание списка с вводом значений\n ");
	printf("2. Поиск элемента по индексу\n");
	printf("3. Удаление элемента по индексу\n");
	printf("4. Поиск элемента по значению\n");
	printf("5. Добавление элемента в список\n");
	printf("6. Вывод списка\n");
	printf("7. Сохранение в файл\n");
	printf("8. Считывание из файла\n");
	printf("9. Генерация случайных записей\n");            
	printf("Ваш выбор : \n");
}


int count(node* list) {
	i = 0;
	start = list;
	while(list) {
		i++;
		if (list->next == NULL) {
			end = list;
		}
		list = list->next;
	}
	ending = i-1;
	return ending;
}

int get_variant(int var) {
    int variant;
    char s[10]; 
    scanf("%s", s);

    while (sscanf(s, "%d", &variant) != 1 || variant < 1 || variant > var) {
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
	return list;
}

void save_file(node *current) {
	FILE *file = fopen("data_list", "w");
    i = 0;
	while(current) {
		fputs(current->data, file);
		fputs("\n", file);
		current = current->next ;
		i++;
	}
	fclose(file);
}

node *open_file(FILE *file, node * list) {
	if (file==NULL) 
	{
		printf("Ошибка открытия файла.\n\n");
	}
	{ 
		tmp = add_first(list);
		while(!feof (file)) 
		{
			fgets(word, 20, file);
			add_last(word, tmp);
		}
		list = tmp;
		fclose(file);
	}
	return list;
}

void search_index(int index, node* list) {
	count(list);
	if (index < 0 || index > ending)  {
		printf("Такой индекс отсутствует\n");
		return;
	}
	printf("Индекс %d : %s \n",index, (get_by_index(index, list))->data);
}

node *generation(node *list) {
    
	count(list);
	new_list=NULL;
	new_list = add_first(new_list);
	printf("длина списка : %d\n", ending);

    int ran, j; 
	for (j=0; j <= 500000000; j++) 
	{
        ran = rand()%ending;
		printf("счёт : %d\n", j);
		printf("случаное число : %d\n", ran);
		add_last(get_by_index(ran, list)->data, new_list);
	}
	return new_list;
}
