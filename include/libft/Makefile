# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agrotzsc <agrotzsc@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/01 03:58:29 by agrotzsc          #+#    #+#              #
#    Updated: 2022/03/01 06:16:41 by agrotzsc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#---- Config ------------------------------------------------------------------#

NAME			=	libft.a
CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror
DEF_COLOR		=	\033[0;39m
GREEN			=	\033[0;92m
YELLOW			=	\033[0;93m
RM				=	rm -rf

#---- Directorys --------------------------------------------------------------#

SRC_DIR			=	src/
OBJ_DIR			=	./obj/

#---- Files -------------------------------------------------------------------#

SRC_FILES		=	ft_memset.c			\
					ft_bzero.c			\
					ft_memcpy.c			\
					ft_memccpy.c		\
					ft_memmove.c		\
					ft_memchr.c			\
					ft_memcmp.c			\
					ft_strlen.c			\
					ft_strlcpy.c		\
					ft_strlcat.c		\
					ft_strchr.c			\
					ft_strrchr.c		\
					ft_strnstr.c		\
					ft_strncmp.c		\
					ft_atoi.c			\
					ft_isalpha.c		\
					ft_isdigit.c		\
					ft_isalnum.c		\
					ft_isascii.c		\
					ft_isprint.c		\
					ft_toupper.c		\
					ft_tolower.c		\
					ft_calloc.c			\
					ft_strdup.c			\
					ft_substr.c			\
					ft_strjoin.c 		\
					ft_strtrim.c		\
					ft_split.c			\
					ft_itoa.c			\
					ft_strmapi.c		\
					ft_putchar_fd.c		\
					ft_putstr_fd.c		\
					ft_putendl_fd.c		\
					ft_putnbr_fd.c

SRCB_FILES		=	ft_lstnew.c			\
					ft_lstadd_front.c	\
					ft_lstsize.c		\
					ft_lstlast.c		\
					ft_lstadd_back.c	\
					ft_lstdelone.c		\
					ft_lstclear.c		\
					ft_lstiter.c		\
					ft_lstmap.c			\
					$(SRC_FILES)

#---- Prefix ------------------------------------------------------------------#

OBJ_FILES		=	${SRC_FILES:.c=.o}
OBJ				=	$(addprefix $(OBJ_DIR),$(OBJ_FILES))
OBJB_FILES		=	${SRCB_FILES:.c=.o}
OBJB			=	$(addprefix $(OBJ_DIR),$(OBJB_FILES))

$(NAME): $(OBJ)
	@printf "%b" "\r\033[2K"
	@printf "%b" "\r$(YELLOW)Compiling: $(NAME)$(DEF_COLOR)"
	@$(AR) -rcs $(NAME) $?
	@printf "%b" "\r\033[2K"
	@printf "%b" "\r$(GREEN)$(NAME) compiled.$(DEF_COLOR)\n"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@printf "%b" "\r\033[2K"
	@printf "%b" "\r$(YELLOW)Compiling: $<$(DEF_COLOR)"
	@$(CC) $(CFLAGS) -o $@ -c $<

all: ${NAME}

clean:
	@${RM} ${OBJ_DIR}
	@echo "$(GREEN)$(NAME) Clean.$(DEF_COLOR)"
fclean: clean
	@${RM} ${NAME}
	@echo "$(GREEN)$(NAME) FClean.$(DEF_COLOR)"

re: fclean all

bonus: $(OBJB)
	@$(CC) -o $(NAME) $(CFLAGS) $(OBJB)
	@echo "$(NAME) Bonus Done !"