C = clang

NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror -O2

LIBFT = libft

DIR_S = srcs

DIR_O = obj

HEADER = includes

SOURCES = ft_parse.c ft_processor.c ft_type_parse.c \
ft_precision_parse.c ft_type_char.c ft_type_string.c \
ft_flags_parse.c ft_printf.c ft_type_decimal.c ft_width_parse.c \
ft_type_unsigned.c ft_unsiged_itoa.c ft_type_percent.c \
ft_itoa_base.c ft_type_x.c ft_type_x_upper.c ft_type_pointer.c

SRCS = $(addprefix $(DIR_S)/,$(SOURCES))

OBJS = $(addprefix $(DIR_O)/,$(SOURCES:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIBFT)
	cp libft/libft.a ./$(NAME)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

$(DIR_O)/%.o: $(DIR_S)/%.c $(HEADER)/ft_printf.h
	@mkdir -p obj
	@$(CC) $(FLAGS) -I $(HEADER) -o $@ -c $<

norme:
	norminette ./libft/
	@echo
	norminette ./$(HEADER)/
	@echo
	norminette ./$(DIR_S)/

clean:
	@rm -f $(OBJS)
	@rm -rf $(DIR_O)
	@make clean -C $(LIBFT)

fclean: clean
	@rm -f $(NAME) libft.a
	@make fclean -C $(LIBFT)

re: fclean all

.PHONY: fclean re norme all clean