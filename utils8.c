/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils8.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abkhefif <abkhefif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 20:33:03 by tcaccava          #+#    #+#             */
/*   Updated: 2025/04/27 18:24:56 by abkhefif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	handle_redirection(char *input, int *i, t_token **head, t_token **current)
{
	if (input[*i] == 60)
		return (handle_less_operator(input, i, head, current));
	else if (input[*i] == 62)
		return (handle_greater_operator(input, i, head, current));
	return (0);
}

void	cleanup_resources(char *line, t_token *tokens, t_tree_node *root,
		t_command *cmds)
{
	(void)cmds;
	if (line)
		free(line);
	if (tokens)
		free_tokens(tokens);
	if (root)
		free_tree(root);
}
