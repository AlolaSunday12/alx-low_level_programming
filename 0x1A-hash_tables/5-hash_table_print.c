#include "hash_tables.h"
#include <stdio.h>

/**
* hash_table_print - Prints a hash table
* @ht: The hash table to print
*/
void hash_table_print(const hash_table_t *ht)
{
hash_node_t *node;
unsigned long int i;
int first_element = 1;

if (ht == NULL)
return;

printf("{");
for (i = 0; i < ht->size; i++)
{
node = ht->array[i];
while (node != NULL)
{
if (first_element == 0)
printf(", ");
printf("'%s': '%s'", node->key, node->value);
first_element = 0;
node = node->next;
}
}
printf("}\n");
}
