#include <stdio.h>
#include "Header.h"
#include <stdlib.h>	
#include <string.h>
#include <unistd.h>
#define A 100


int check_string(char *str) {
	for (int i = 0; i < strlen(str) - 1; i++) {
		if (!((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z') || str[i] == ' ' || str[i] == '\n'))
		{
			printf("No pasaran!\nOne more try:\n");
			sleep(2);
			return -1;
		}
	}
	if (str[strlen(str) - 1] != '.')
	{
		printf("No pasaran! End the string correctly, please.\n");
		sleep(2);
		return -1;
	}
	return 0;
} // Unleash unspecified sh@t

list *create_head(char *field) {
	list *head;
	head = (struct list*)malloc(sizeof(struct list));
	head->field = field;
	head->next = NULL;
	head->prev = NULL; // doubly linked for some reason o_O
	return head;
} // Starting node

list * add_elem(list *lst, char *s)
{
	list *temp, *p;
	temp = (struct list*)malloc(sizeof(list));
	p = lst->next;
	lst->next = temp;
	temp->field = s;
	temp->next = p;
	temp->prev = lst;
	if (p != NULL) p->prev = temp;
	return temp;
} // New node (to create)

void print_list(list *head) {
	list *p;
	p = head;
	do {
		printf("%s\n", p->field);
		p = p->next;
	} while (p != NULL);
}   // Output

char *search_max(list *head, char *max) {
	list *p;
	p = head;
	do {
		if (strcmp(max, p->field) > 0) strcpy(max, p->field);
		p = p->next;
	} while (p != NULL);
	return max;
}   // Running through the highest length

list *delete_elem(list *lst) {
	list *prev, *next;
	prev = lst->prev;
	next = lst->next;
	if (prev != NULL)
		prev->next = lst->next;
	if (next != NULL)
		next->prev = lst->prev;
	free(lst);
	return(prev);
}   // Burning bridges

list *delete_head(list *head) {
	struct list *temp;
	temp = head->next;	
	if (head->next == NULL) {
		printf("DELETE 'EM ALL!\n");
		sleep(2);
		exit(0);
	}
	temp->prev = NULL;
	free(head);
	return(temp);
} // Tool in Erase

list *erase(list *head, char *max) {
	list *p, *edited_head = NULL;
	p = head;
	do {
		if (p == NULL) break;
		if (strlen(max) == strlen(p->field)) {
			if (p->prev == NULL) {
				p = delete_head(p);
				edited_head = p;
			}
			else 
				p = delete_elem(p);
		}
		else 
			p = p->next;
	} while (p != NULL);
	return edited_head;
}   // key feature
