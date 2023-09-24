# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: toshota <toshota@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/26 19:52:48 by toshota           #+#    #+#              #
#    Updated: 2023/09/24 14:58:11 by toshota          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a
CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror
AR		=	ar rc
RM		=	rm -f
PRINTF	=   ft_printf/
INCS	=	libft.h
M_SRCS	=	ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c \
			ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c \
			ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c \
			ft_memcmp.c ft_strnstr.c ft_atoi.c \
			ft_calloc.c ft_strdup.c get_next_line.c\
			ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c \
			ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c
B_SRCS	=	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
			ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c
OBJS	=	$(M_SRCS:.c=.o)

ifdef		WITH_BONUS
			OBJS	+= $(B_SRCS:.c=.o)
endif



$(NAME):	$(OBJS)
	@ make -C $(PRINTF)
	@ cp $(PRINTF)libftprintf.a $@
	@ $(AR) $@ $^

all:		$(NAME)

bonus:
	@ make WITH_BONUS=1

.c.o:		$(OBJS)
	@ $(CC) $(CFLAGS) -I $(INCS) -c $< -o $@

clean:
	@ make clean -C $(PRINTF)
	@ $(RM) $(OBJS) $(B_SRCS:.c=.o)

fclean:		clean
	@ make fclean -C $(PRINTF)
	@ $(RM) $(NAME)

re:			fclean all

.PHONY:		all bonus clean fclean re
