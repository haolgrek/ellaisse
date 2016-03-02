# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tandrieu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/02 18:31:57 by tandrieu          #+#    #+#              #
#    Updated: 2016/03/02 18:08:30 by rluder           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OBJET_NAME = $(SRC_NAME:.c=.o)
	CC = gcc
	EXE = ft_ls 
	LIBRARY = libfillit.a
	MAKELIB = make -C ./libft
	CLEANLIB = make clean -C ./libft
	FCLEANLIB = make fclean -C ./libft
	MAIN = main.o
	CFLAGS = -Werror -Wextra -Werror 
	SRC_NAME = clean.c\
			   datalist.c\
			   errors.c\
			   free.c\
			   ft_ls.c\
			   print.c\
			   print2.c\
			   sort.c

all : $(EXE)

$(EXE) : $(LIBRARY) $(MAIN)
		$(MAKELIB)
		$(CC) -o $(EXE) $(CFLAGS) $(MAIN) $(LIBRARY) ./libft/libft.a

$(LIBRARY) : $(OBJET_NAME)
		ar -r $(LIBRARY) $(OBJET_NAME)

$(MAIN) : main.c
		$(CC) $(CFLAGS) -c $<

%.o : %.c
		$(CC) -c $(CFLAGS) $<

clean :
		rm -rf $(SRC_NAME:.c=.o) main.o
		$(CLEANLIB)

fclean : clean
		rm -rf $(EXE) $(LIBRARY)
		$(FCLEANLIB)

re : fclean all
