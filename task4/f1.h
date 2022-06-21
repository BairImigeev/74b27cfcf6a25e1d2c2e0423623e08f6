typedef char data[20];

struct list_node 
{
   data data;
   struct list_node* previous;
   struct list_node* next;
};

typedef struct list_node node;

node *ending(node *list, int count);

int count(node* list); 

node* get_by_index(int index, node* list);

node* search_value(data word, node *list);

node* remove_first(node* list); 

node* remove_last(node* list);

node* remove_by_index(int index, node* list);

node* add_first(node* list);

node *insert_start(data word, node *list);

node *insert_end(data word, node *list);

node *add_index(data word, int index, node * list);

void add_last(data word, node* current);

void print_list(node* current);

void print_menu();

int get_variant(int count);
