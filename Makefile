# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agrotzsc <agrotzsc@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/01 03:58:29 by agrotzsc          #+#    #+#              #
#    Updated: 2022/03/03 16:22:03 by agrotzsc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#---- Config ------------------------------------------------------------------#

NAME			=	so_long
CC				=	gcc
CFLAGS			=	-g -Wall -Wextra -Werror
DEF_COLOR		=	\033[0;39m
GREEN			=	\033[0;92m
YELLOW			=	\033[0;93m
RM				=	rm -rf

#---- Directorys --------------------------------------------------------------#

SRC_DIR			=	src/
UTILS_DIR		=	utils/
MAP_DIR			=	map/
MOVE_DIR		=	movement/
OBJ_DIR			=	obj/

#---- Files -------------------------------------------------------------------#

SRC_FILES		=	main.c \
					init.c

UTILS_FILES 	= 	memory.c \
					misc.c \
					print.c 

MAP_FILES		=	check.c \
					check2.c \
					ident.c \
					init.c

MOVE_FILES		=	player.c \
					enemy.c

#---- Prefix ------------------------------------------------------------------#

UTILS			=	$(addprefix $(UTILS_DIR),$(UTILS_FILES))
MAP				=	$(addprefix $(MAP_DIR),$(MAP_FILES))
MOVE			=	$(addprefix $(MOVE_DIR),$(MOVE_FILES))

COMP_FILES		=	$(SRC_FILES) \
					$(UTILS) \
					$(MAP) \
					$(MOVE)

OBJ_FILES		=	${COMP_FILES:.c=.o}
OBJS			=	$(addprefix $(OBJ_DIR),$(OBJ_FILES))

#---- Libaries ----------------------------------------------------------------#

LIBFT_DIR		=	./include/libft/
LIBFT_FILES		=	libft.a
LIBFT			=	$(addprefix $(LIBFT_DIR),$(LIBFT_FILES))

MLX_DIR			=	./include/mlx/
MLX_FILES		=	libmlx_Linux.a
MLX				=	$(addprefix $(MLX_DIR),$(MLX_FILES))

$(NAME): mlx_all $(OBJS)
	@printf "%b" "\r\033[2K"
	@make -C ${LIBFT_DIR}
	@printf "%b" "\r\033[2K"
	@printf "%b" "\r$(YELLOW)Compiling: $(NAME)$(DEF_COLOR)"
	@$(CC) -o so_long $(CFLAGS) $(OBJS) $(MLX) $(LIBFT) -L/usr/include/X11/extensions -lX11 -lXext
	@printf "%b" "\r\033[2K"
	@printf "%b" "\r$(GREEN)$(NAME) compiled.$(DEF_COLOR)\n"

debug: mlx_all $(OBJS)
	@$(CFLAGS) += -ggdb
	@printf "%b" "\r\033[2K"
	@make -C ${LIBFT_DIR}
	@printf "%b" "\r\033[2K"
	@printf "%b" "\r$(YELLOW)Compiling: $(NAME)$(DEF_COLOR)"
	@$(CC) -o so_long $(CFLAGS) $(OBJS) $(MLX) $(LIBFT) -L/usr/include/X11/extensions -lX11 -lXext
	@printf "%b" "\r\033[2K"
	@printf "%b" "\r$(GREEN)$(NAME) compiled.$(DEF_COLOR)\n"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@printf "%b" "\r\033[2K"
	@printf "%b" "\r$(YELLOW)Compiling: $<$(DEF_COLOR)"
	@$(CC) $(CFLAGS) $(INC) -o $@ -c $<

$(OBJ_DIR)$(UTILS_DIR)%.o: $(SRC_DIR)$(UTILS_DIR)%.c
	@mkdir -p $(OBJ_DIR)$(UTILS_DIR)
	@printf "%b" "\r\033[2K"
	@printf "%b" "\r$(YELLOW)Compiling: $<$(DEF_COLOR)"
	@$(CC) $(CFLAGS) $(INC) -o $@ -c $<

$(OBJ_DIR)$(MAP_DIR)%.o: $(SRC_DIR)$(MAP_DIR)%.c
	@mkdir -p $(OBJ_DIR)$(MAP_DIR)
	@printf "%b" "\r\033[2K"
	@printf "%b" "\r$(YELLOW)Compiling: $<$(DEF_COLOR)"
	@$(CC) $(CFLAGS) $(INC) -o $@ -c $<

$(OBJ_DIR)$(MOVE_DIR)%.o: $(SRC_DIR)$(MOVE_DIR)%.c
	@mkdir -p $(OBJ_DIR)$(MOVE_DIR)
	@printf "%b" "\r\033[2K"
	@printf "%b" "\r$(YELLOW)Compiling: $<$(DEF_COLOR)"
	@$(CC) $(CFLAGS) $(INC) -o $@ -c $<

all: mlx_all ${NAME}

clean:
	@${RM} ${OBJ_DIR}
	@make -C ${LIBFT_DIR} clean
	@make -C ${MLX_DIR} clean
	@echo "$(GREEN)Clean.$(DEF_COLOR)"
fclean: clean
	@${RM} ${NAME}
	@make -C ${LIBFT_DIR} fclean
	@make -C ${MLX_DIR} clean
	@echo "$(GREEN)FClean.$(DEF_COLOR)"

re: fclean all

mlx_all:
	cd $(MLX_DIR) && ./configure