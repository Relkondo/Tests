/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaurent <dlaurent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 16:26:42 by dlaurent          #+#    #+#             */
/*   Updated: 2018/10/14 16:30:33 by dlaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

char		sh_history_option_c(t_shell *sh, t_env *env)
{
	command_delete_all(sh);
	remove(env_search(env, "HISTFILE"));
	return (0);
}
