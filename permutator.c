#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Queue.h"

/*gives all permutations of the program's arguments using a queue and a single string buffer*/

void permute(int n, int los, char* s, Queue* q) {
	Node* cur;
	if (n == 1) {
		printf("%s\n", strcat(strcat(s, " "), q->head->item));
		s[los] = '\0';
		return;
	}

	int i;
	for (i = 0; i < n; i++) {
		cur = dequeue(q);
		permute(n - 1, los + strlen(cur->item) + 1, strcat(strcat(s, " "), cur->item), q);
		s[los] = '\0';
		enqueue(q, cur);
	}
	
}

int main(int argc, char** argv) {
	
	if (argc > 1) {
		Queue* q = (Queue*) malloc(sizeof(Queue));
		initQueue(q);
		int i;
		
		//populate queue
		for (i = 1; i < argc; i++) {
			Node* n = (Node*) malloc(sizeof(Node));
			initNode(n, argv[i]);
			enqueue(q, n);
		}
		
		int totalen = 0;
		//one extra space for each argument
		for (i = 1; i < argc; i++) 
			totalen += strlen(argv[i]) + 1;
			
		//permute
		char* buffer = (char*) malloc(totalen*sizeof(char));	
		permute(argc - 1, 0, buffer, q);
	
		//clean-up
		free(buffer);
		for (i = 1; i < argc; i++) {
			Node* n = dequeue(q);
			free(n);
		}
		free(q);
		
		return 0;
	}
	
	printf("Gimmeh sumthin to permute!\n");
	return 1;
		
}