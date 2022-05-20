# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: samajat <samajat@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/16 00:58:43 by samajat           #+#    #+#              #
#    Updated: 2022/05/20 19:57:43 by samajat          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philosopher

HEADER = philosopher.h t_list.h

CC = gcc

CFLAGS = -Wall -Wextra -Werror -I includes/

M_SRC =  philosopher ft_start_simulation\

U_SRC = ft_strcmp ft_strlen ft_atoi ft_isdigit ft_all_allocated ft_philos_data\


TIME_SRC = get_passed_time get_time_in_millis\

PACT_SRC = Ph_actions\

LST_SRC = ft_lstadd_front ft_lstadd_back ft_lstclear\
			ft_lstdelete_last ft_lstdelete_top ft_lstdelone\
			ft_lstiter ft_lstlast ft_lstnew ft_lstprint ft_lstsize\
			ft_lst_contain\
			

ERR_SRC = print_error chstatus check_syntax check_redirection check_user_input\

INIT_SRC = initialize\

## fill_list  
FILES = $(addprefix srcs/main/, $(M_SRC)) \
	  $(addprefix srcs/t_list/, $(LST_SRC)) \
	  $(addprefix srcs/ft_init/, $(INIT_SRC)) \
	  $(addprefix srcs/ft_time/, $(TIME_SRC)) \
	  $(addprefix srcs/Philosopher_actions/, $(PACT_SRC)) \
	  $(addprefix srcs/utils/, $(U_SRC)) \
	#   $(addprefix srcs/error_handler/, $(ERR_SRC)) \

OBJ = $(FILES:=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@echo "\n"
	@echo "\033[0;32mCompiling minishell..."
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(READ) -g
	@echo "\n\033[0mDone !"

%.o: %.c
	@printf "\033[0;33mGenerating minishell objects... %-33.33s\r" $@
	@${CC} ${CFLAGS} -c $< $(RL_INCLUDE) -o $@ -g

clean:
	@echo "\nRemoving files..."
	@rm -f $(OBJ)
	@echo "\033[0m"

fclean:
	@echo "\033[0;31mDeleting objects..."
	@rm -f $(OBJ)
	@echo "\nDeleting executable..."
	@rm -f $(NAME)
	@echo "\033[0m"

re: fclean all