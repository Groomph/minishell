# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/19 16:05:34 by rsanchez          #+#    #+#              #
#    Updated: 2022/01/25 22:55:08 by rsanchez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

CC = clang

CFLAGS = -Wall -Wextra -Werror

#CFLAGS = --analyze

FLAGSHARD = -Weverything

LIB	= libraries

LIBFT	= -L $(LIB)/libft/ -lft

HEADER = includes

DIR_S = sources

INPUT = read_input

EVENT = $(INPUT)/event

HIST = $(INPUT)/history

DISP = $(INPUT)/display

LEXER = lexer

PARSER = parsing

EXE = exe

INOUT = redirect

BUILT = builtins

DIR_O = temporary

SOURCES = main.c error.c exit.c get_input.c env.c\
	  $(INPUT)/read_input.c $(INPUT)/interpret_input.c \
	  $(INPUT)/terminal.c $(INPUT)/signal.c \
	  $(INPUT)/init.c $(INPUT)/clear.c \
	  $(EVENT)/event_simple.c $(EVENT)/event_termcaps.c \
	  $(EVENT)/event_history.c $(EVENT)/utils.c \
	  $(DISP)/cursor.c $(DISP)/input_display.c \
	  $(HIST)/history.c \
	  $(LEXER)/tokenizer.c $(LEXER)/lexer_rules.c \
	  $(PARSER)/parsing.c $(PARSER)/parsing_redirect.c \
	  $(PARSER)/parsing_word_str.c \
	  $(PARSER)/expand_variables.c $(PARSER)/heredoc.c \
	  $(EXE)/exe.c $(EXE)/utils.c $(EXE)/signal.c \
	  $(EXE)/builtin_hub.c $(EXE)/redirections.c \
	  $(BUILT)/ft_export.c $(BUILT)/ft_env.c $(BUILT)/ft_getenv.c \
	  $(BUILT)/ft_unset.c $(BUILT)/ft_echo.c \
	  $(BUILT)/ft_pwd.c $(BUILT)/ft_cd.c $(BUILT)/ft_exit.c \
	  $(INOUT)/redirect_in.c $(INOUT)/redirect_out.c

SRCS = $(addprefix $(DIR_S)/,$(SOURCES))

OBJS = $(addprefix $(DIR_O)/,$(SOURCES:.c=.o))

all: $(NAME)

bonus: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIB)/libft
	$(CC) $(CFLAGS) -o $(NAME) -ltermcap $(OBJS) $(LIBFT)

$(DIR_O)/%.o: $(DIR_S)/%.c
	@mkdir -p $(DIR_O)
	@mkdir -p $(DIR_O)/$(INPUT)
	@mkdir -p $(DIR_O)/$(EVENT)
	@mkdir -p $(DIR_O)/$(DISP)
	@mkdir -p $(DIR_O)/$(HIST)
	@mkdir -p $(DIR_O)/$(LEXER)
	@mkdir -p $(DIR_O)/$(PARSER)
	@mkdir -p $(DIR_O)/$(EXE)
	@mkdir -p $(DIR_O)/$(INOUT)
	@mkdir -p $(DIR_O)/$(BUILT)
	$(CC) $(CFLAGS) -I $(HEADER) -o $@ -c $<

norme:
	norminette $(LIBRARIES)/
	norminette $(HEADER)/
	norminette $(DIR_S)/

clean:
	rm -rf $(DIR_O)
	make -C $(LIB)/libft fclean

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY:		all clean fclean re bonus norme
