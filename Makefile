# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: graja <graja@student.42wolfsburg.de>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/09 08:54:10 by graja             #+#    #+#              #
#    Updated: 2022/05/10 12:10:17 by graja            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	ft_containers	

ONAME	=	std_containers

SRCS	=	ft.cpp

OSRCS	=	std.cpp

LOGS	=	ft.log std.log

CC	=	c++

FLAGS	=	-Wextra -Werror -Wall -std=c++98 -pedantic


all	:	$(NAME)

$(NAME)	:	$(SRCS) $(OSRCS)
	$(CC) $(FLAGS) $(SRCS) -o $(NAME) 
	$(CC) $(FLAGS) $(OSRCS) -o $(ONAME)

clean	:

fclean	:	clean
	rm -f $(NAME)
	rm -f $(ONAME)
	rm -f $(LOGS)

re		:	fclean all

grade	:	fclean all
	./$(NAME) 1953 > ft.log
	./$(ONAME) 1953 > std.log
	diff -y ft.log std.log

.PHONY: all clean fclean re
