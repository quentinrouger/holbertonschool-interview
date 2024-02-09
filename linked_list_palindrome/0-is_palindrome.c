#include "lists.h"
#include <stddef.h>

/**
 * is_palindrome - checks if a singly linked list is a palindrome
 * @head: pointer to the head of the linked list
 * Return: 1 if the linked list is a palindrome, 0 otherwise
 */
int is_palindrome(listint_t **head)
{
    listint_t *slow = *head, *fast = *head;
    int values[1000];  /* Assume linked list has at most 1000 elements */
    int i = 0, j;

    if (*head == NULL || (*head)->next == NULL)
        return (1); /* An empty list or a single node list is a palindrome */

    while (fast != NULL && fast->next != NULL)
    {
        values[i++] = slow->n;
        slow = slow->next;
        fast = fast->next->next;
    }

    /* If the number of nodes is odd, move slow pointer one step forward */
    if (fast != NULL)
        slow = slow->next;

    /* Compare the second half of the linked list with the stored values */
    for (j = i - 1; j >= 0; j--)
    {
        if (slow->n != values[j])
            return (0); /* Not a palindrome */
        slow = slow->next;
    }

    return (1); /* Palindrome */
}
