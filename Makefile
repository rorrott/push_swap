NAME = push_swap

C_FILE = $(addprefix src/, push_swap.c \
						push.c \
						quick_sort.c \
						rev_rotate.c \
						rotate.c \
						utils.c \
						swap.c \
						sort.c \
						)

CC			=	cc

FLAG		=	-Wall -Wextra -Werror -g3

LIBFT_PATH	=	.libft

LIBFT_FILE	=	libft.a

LIBFT_LIB	=	$(LIBFT_PATH)/$(LIBFT_FILE)

OBJS		=	$(C_FILE:.c=.o)

.c.o:
	@printf "\r\033[K[push_swap] \033[0;32mBuilding : $<\033[0m"
	@$(CC) $(FLAG) -c $< -o $@

all:	$(NAME)

$(LIBFT_LIB):
	@make -C $(LIBFT_PATH)

$(NAME): $(LIBFT_LIB) $(OBJS)
	@printf "\r\033[K[push_swap] \033[0;32mLinking...\033[0m"
	@$(CC) $(OBJS) $(LIBFT_LIB) -o $(NAME) -lm 
	@printf "\r\033[K[push_swap] \033[0;32mDone!\033[0m\n"

clean:
	@make clean -sC $(LIBFT_PATH)
	@rm -f $(OBJS)
	@printf "[push_swap] \033[1;31mCleaned .o!\033[0m\n"

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT_PATH)
	@printf "[push_swap] \033[1;31mCleaned all!\033[0m\n"
	@printf "[checker] \033[1;31mCleaned all!\033[0m\n"

re: fclean all

.PHONY: all clean fclean re