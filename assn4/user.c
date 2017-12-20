#include <stdio.h>
#include <stdlib.h>
#include "bintree.h"

int main() {
	/*
	Insert your test code here. Try inserting nodes then searching for them.

	When we grade, we will overwrite your main function with our own sequence of
	insertions and deletions to test your implementation. If you change the
	argument or return types of the binary tree functions, our grading code
	won't work!
	*/

    int ids[] = {3, 5, 1, 20, 33, 4, 265, -1};
    int n = 8;
    int i;

    for (i = 0; i < n; i++) {
        insert_node(ids[i], i + 1);
    }
    for (i = 0; i < n; i++) {
        printf("Node id: %d, data: %d\n",
                ids[i], find_node_data(ids[i]));
    }
    printf("Node id: %d => %d should be 0\n",
            3456, find_node_data(3456));
    remove_node(5);
    for (i = 0; i < n; i++) {
        printf("Node id: %d, data: %d\n",
                ids[i], find_node_data(ids[i]));
    }

	return 0;
}
