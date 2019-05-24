#include <stdio.h>
#include "Header.h"
#include "func.c"
#include <stdlib.h>	
#include <string.h>
#define A 100

int main() {
	char str[A];
	list *head = NULL, *temp, *edited_head;
	char *s;
	printf("Hello!\nEnter a sentence ending with a point:\n");
	gets(str);
	while (check_string(str) == -1) {
		printf("Enter a sentence ending with a point:\n");
		gets(str);
	}
	char sep[] = { ' ','.' };
	s = strtok(str, sep);
	head = create_head(s);
	temp = head;
	char *max = malloc(sizeof(char)*A);
	strcpy(max, head->field);
	while (s != NULL)
	{
		s = strtok(NULL, sep);
		if (s == NULL) break;
		temp = add_elem(temp, s);
	}
	sleep(1);
	printf("Entered sentence\n");
	print_list(head);
	max = search_max(head, max);
	edited_head = erase(head, max);
	if (edited_head != NULL) head = edited_head;
	printf("Same sentence without words of maximum length:\n");
	sleep(1);
	print_list(head);
	delete_elem(temp);
	delete_head(head);
	free(max);
	return 0;
}
