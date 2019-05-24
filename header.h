#pragma once
typedef struct list {
	char *field;
	struct list *next;
	struct list *prev;
}list;

int check_string(char *str);
list *create_head(char *field);
list * add_elem(list *lst, char *s);
void print_list(list *head);
char *search_max(list *head, char *max);
list *delete_elem(list *lst);
list *erase(list *head, char *max);
