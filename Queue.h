#include <stdlib.h>

typedef struct Node{
	char* item;
	struct Node* link;
} Node;

typedef struct Queue{
	Node* head;
	Node* tail;
} Queue;

void initNode(Node* n, char* item) {
	n->item = item;
	n->link = NULL;
}

void initQueue(Queue* q) {
	q->head = NULL;
	q->tail = NULL;
}

Node* dequeue(Queue* q) {
	if (q->head == NULL) {
		printf("Queue is empty; can't dequeue");
		return NULL;
	}
	Node* head = q->head;
	q->head = (Node*) head->link;
	if (q->head == NULL) q->tail = NULL;
	head->link = NULL;
	return head;
}

void enqueue(Queue* q, Node* n) {
	if (q->tail == NULL) {
		q->head = n;
		q->tail = n;
	} else {
		q->tail->link = (struct Node*) n;
		q->tail = n;
	}
} 