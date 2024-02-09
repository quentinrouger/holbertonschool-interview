#include "lists.h"
#include <stddef.h>


/**
 * reverse_list - reverses a linked list
 * @head: pointer to the head of the linked list
 * Return: pointer to the head of the reversed linked list
 */
listint_t *reverse_list(listint_t **head)
{
    listint_t *prev = NULL, *current = *head, *next;

    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    *head = prev;
    return (*head);
}

/**
 * is_palindrome - checks if a singly linked list is a palindrome
 * @head: pointer to the head of the linked list
 * Return: 1 if the linked list is a palindrome, 0 otherwise
 */
int is_palindrome(listint_t **head)
{
    listint_t *slow = *head, *fast = *head;
    listint_t *second_half, *prev_slow = *head;
    int result = 1; /* Assume linked list is a palindrome */

    if (*head == NULL || (*head)->next == NULL)
        return (result); /* An empty list or single-node list is a palindrome */

    /* Find the middle of the linked list */
    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        prev_slow = slow;
        slow = slow->next;
    }

    /* If the number of nodes is odd, move slow pointer one step forward */
    if (fast != NULL)
        slow = slow->next;

    /* Reverse the second half of the linked list */
    second_half = reverse_list(&slow);

    /* Compare the first half with the reversed second half */
    while (second_half != NULL)
    {
        if ((*head)->n != second_half->n)
        {
            result = 0; /* Not a palindrome */
            break;
        }
        *head = (*head)->next;
        second_half = second_half->next;
    }

    /* Restore the original list */
    reverse_list(&slow);
    prev_slow->next = slow;

    return (result);
}
