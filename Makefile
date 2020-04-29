SRC = ft_ssl.c \
	  ft_md5.c \
	  cli.c \
	  msg_prep.c \
	  ft_sha256.c \
	  sample_text.c \
	  router.c \
	  output.c
 
INC = includes/cli.h \
	  includes/ft_md5.h \
	  includes/ft_ssl.h \
	  includes/msg_prep.h \
	  includes/ft_sha256.h \
	  includes/router.h \
	  includes/ft_ssl_data_types.h \
	  includes/output.h

SRC_DIR = ./src/
OBJ_DIR = ./obj/
OBJ = $(addprefix $(OBJ_DIR),$(SRC:.c=.o))
NAME = ft_ssl
CFLAG = -Werror -Wextra -Wall
LIB = -L./libft/ -lft
CC = gcc
REMAKE = rmk

#colours
NONE = \033[0m
RED = \033[31m
GREEN = \033[32m
YELLOW = \033[33m
#BLUE = \033[34m
#MAGENTA = \033[35m
#CYAN = \033[36m
#colours

$(OBJ_DIR)%.o: %.c $(INC)
		@echo "\033[0;32mCreating object files\$(NONE) \033[31m$@\$(NONE)"
		@$(CC) $(CFLAG) -c $< -o $@

all: LIBFT $(NAME)

LIBFT:
		@make -C ./libft/;
		@echo "\n$(GREEN)Libft: $(YELLOW)READY$(NONE)";

$(NAME): $(OBJ)
		@echo "\033[0;32mCompile solution ...$(NONE)"
		@$(CC) $(CFLAG) -o $(NAME) $(OBJ) $(LIB)
		@echo "\033[0;32mProgram compiled : $(NONE)\033[31m$(NAME)$(NONE)"

$(OBJ): $(OBJ_DIR)

$(OBJ_DIR):
		@mkdir $(OBJ_DIR)

clean:
		@echo "\033[0;32mCleaning object files ...$(NONE)"
		@rm -rf $(OBJ_DIR)

fclean: clean
		@rm -f $(NAME)
		@echo "\033[31m$(NAME)$(NONE)\033[0;32m was completely removed$(NONE)"

re: $(REMAKE) fclean all
$(REMAKE):
		@echo "\033[0;32mRemaking project $(NONE)\033[31m$(NAME)$(NONE)"

vpath %.c $(SRC_DIR)
