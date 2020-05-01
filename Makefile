SRC 	=	  ft_ssl.c		\
			  ft_md5.c		\
			  cli.c			\
			  msg_prep.c	\
			  ft_sha256.c	\
			  sample_text.c	\
			  router.c		\
			  output.c
 
INC		=	  includes/cli.h				\
			  includes/ft_md5.h				\
			  includes/ft_ssl.h				\
			  includes/msg_prep.h			\
			  includes/ft_sha256.h			\
			  includes/router.h				\
			  includes/ft_ssl_data_types.h	\
			  includes/output.h

SRC_DIR	=	  ./src/
OBJ_DIR	=	  ./obj/
INC_DIR	=	  ./includes/
NAME	=	  ft_ssl
CFLAG	=	  -Werror -Wextra -Wall
#INCL	=	  -Iincludes
LIB		=	  -L./libft/ -lft libft/libft.a
CC		=	  gcc

SRCS	=	  $(addprefix $(SRC_DIR),$(SRC))
OBJ		=	  $(SRC:.c=.o)
OBJS	=	  $(addprefix $(OBJ_DIR),$(OBJ))

#colours
NONE	=	  \033[0m
RED		=	  \033[31m
GREEN	=	  \033[32m
YELLOW	=	  \033[33m
BLUE	=	  \033[34m
MAGENTA	=	  \033[35m
CYAN	=	  \033[36m
#colours

.PHONY: all clean fclean re Lib objectdir

all: objectdir Lib $(NAME)

Lib:
		@make -C ./libft/
		@printf "\nLibft: $(GREEN)READY$(NONE)\n\n"

objectdir:
		@mkdir $(OBJ_DIR) 2> /dev/null || true

$(NAME): $(OBJS)
		@printf "\n\nObject Files: $(GREEN)READY$(NONE)\n"
		@printf "\nFT_SSL: "
		@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -I $(INC_DIR) $(LIB)
		@printf "$(GREEN)READY$(NONE)\n\n"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
		@$(CC) $(CFLAGS) -c $< -o $@ -I $(INC_DIR)
		@printf "."

clean:
		@rm -rf obj

fclean: clean
		@rm -rf $(NAME)

re: fclean all
