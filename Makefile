# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: toshota <toshota@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/26 19:52:48 by toshota           #+#    #+#              #
#    Updated: 2023/09/14 16:57:59 by toshota          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	so_long
B_NAME			=	bonus_so_long
CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror
AR				=	ar rc
RM				=	rm -f
INCS			=	so_long.h
LIBFT_DIR		=	libft/

SRCS_DIR		=	src/
C_SRCS_DIR		=	src/common/
M_SRCS_DIR		=	src/mandantory/
B_SRCS_DIR		=	src/bonus/
C_SRCS_FILES	=	main.c utils.c init.c get.c crash.c enemy.c num_mlx.c\
					check_map.c check_map_element_num.c check_is.c \
					check_utils.c mlx.c update.c move.c move_utils.c\
					swap_player_key_code.c swap_rival_key_code.c is.c \

M_SRCS_FILES	=	check_map_components_mandantory.c
B_SRCS_FILES	=	check_map_components_bonus.c

C_SRCS			=	$(addprefix $(C_SRCS_DIR), $(C_SRCS_FILES))
M_SRCS			=	$(addprefix $(M_SRCS_DIR), $(M_SRCS_FILES))
B_SRCS			=	$(addprefix $(B_SRCS_DIR), $(B_SRCS_FILES))

C_OBJS			=	$(C_SRCS:.c=.o)
M_OBJS			=	$(M_SRCS:.c=.o)
B_OBJS			=	$(B_SRCS:.c=.o)

ifeq		($(shell uname), Linux)
			INCLUDES = -I/usr/include -Imlx
			MLX_FLAGS = -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11
else
			INCLUDES = -I/opt/X11/include -Imlx
			MLX_FLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit
endif

all:		$(NAME)

$(NAME):	$(C_OBJS) $(M_OBJS) $(INCS) Makefile
	@ make -C $(LIBFT_DIR)
	@ $(CC) $(CFLAGS) $(MLX_FLAGS) $(INCLUDES) $(LIBFT_DIR)libft.a $(C_OBJS) $(M_OBJS) -o $(NAME)
	@ echo "Compile to create an executable file: so_long"

bonus:		$(B_NAME)

$(B_NAME):	$(C_OBJS) $(B_OBJS) $(INCS) Makefile
	@ make -C $(LIBFT_DIR)
	@ $(CC) $(CFLAGS) $(MLX_FLAGS) $(INCLUDES) $(LIBFT_DIR)libft.a $(C_OBJS) $(B_OBJS) -o $(B_NAME)
	@ echo "Compile to create an executable file: bonus_so_long"

.c.o:		$(C_OBJS) $(M_OBJS) $(B_OBJS)
	@ $(CC) $(CFLAGS) -I $(INCS) -c $< -o $@

clean:
	@ make clean -C $(LIBFT_DIR)
	@ $(RM) $(C_OBJS) $(M_OBJS) $(B_OBJS)

fclean:
	@ make fclean -C $(LIBFT_DIR)
	@ $(RM) $(C_OBJS) $(M_OBJS) $(B_OBJS)
	@ $(RM) $(NAME) $(B_NAME)

re:			fclean all

.PHONY:		all bonus clean fclean re
