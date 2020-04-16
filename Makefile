SRC = ft_ssl.c ft_md5.c cli.c msg_prep.c ft_sha256.c sample_text.c router.c output.c
 
INC = includes/cli.h includes/ft_md5.h includes/ft_ssl.h includes/msg_prep.h\
	  includes/ft_sha256.h includes/router.h includes/ft_ssl_data_types.h \
	  includes/output.h

SRC_DIR = ./src/
OBJ_DIR = ./obj/
OBJ = $(addprefix $(OBJ_DIR),$(SRC:.c=.o))
NAME = ft_ssl
CFLAG = -Werror -Wextra -Wall
LIB = -L./libft/ -lft
CC = gcc
REMAKE = rmk

$(OBJ_DIR)%.o: %.c $(INC)
		@echo "\033[0;32mCreating object files\033[0m \033[31m$@\033[0m"
		@$(CC) $(CFLAG) -c $< -o $@

all: $(NAME)
$(NAME): $(OBJ)
		@echo "\033[0;32mCompile solution ...\033[0m"
		@$(CC) $(CFLAG) -o $(NAME) $(OBJ) $(LIB)
		@echo "\033[0;32mProgram compiled : \033[0m\033[31m$(NAME)\033[0m"

$(OBJ): $(OBJ_DIR)

$(OBJ_DIR):
		@mkdir $(OBJ_DIR)

clean:
		@echo "\033[0;32mCleaning object files ...\033[0m"
		@rm -rf $(OBJ_DIR)

fclean: clean
		@rm -f $(NAME)
		@echo "\033[31m$(NAME)\033[0m\033[0;32m was completely removed\033[0m"

re: $(REMAKE) fclean all
$(REMAKE):
		@echo "\033[0;32mRemaking project \033[0m\033[31m$(NAME)\033[0m"

vpath %.c $(SRC_DIR)
