#include "push_swap.h"

void	ft_swap(t_node **stack)
{
	t_node	*temp1;
	t_node	*temp2;

	if (*stack)
	{
		temp1 = (*stack)->next;
		temp2 = (*stack)->next->next;
		temp1->next = *stack;
		(*stack)->next = temp2;
		*stack = temp1;
	}
}

void	ft_push(t_node **src, t_node **dest)
{
	t_node	*temp;

	if (*src)
	{
		temp = *src;
		*src = (*src)->next;
		temp->next = *dest;
		*dest = temp;
	}
}

void	ft_rotate(t_node **stack)
{
	t_node	*temp1;
	t_node	*temp2;

	if ((*stack)->next)
	{
		temp1 = (*stack)->next;
		temp2 = *stack;
		while (temp2->next)
			temp2 = temp2->next;
		temp2->next = *stack;
		*stack = temp2;
	}
}

void	ft_reverse_rotate(t_node **stack)
{
	t_node	*temp1;
	t_node	*temp2;

	temp1 = *stack;
	while (temp1->next->next)
		temp1 = temp1->next;
	temp2 = temp1->next;
	temp1->next = NULL;
	temp2->next = *stack;
	*stack = temp2;
}
