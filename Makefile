# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/19 16:05:34 by rsanchez          #+#    #+#              #
#    Updated: 2021/12/22 20:12:11 by rsanchez         ###   ########.fr        #
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

DIR_O = temporary

SOURCES = main.c error.c exit.c get_input.c \
	  $(INPUT)/read_input.c $(INPUT)/interpret_input.c \
	  $(INPUT)/terminal.c $(INPUT)/init_clear.c \
	  $(INPUT)/signal.c \
	  $(EVENT)/event_simple.c $(EVENT)/event_termcaps.c \
	  $(EVENT)/event_history.c $(EVENT)/utils.c \
	  $(DISP)/cursor.c $(DISP)/input_display.c \
	  $(HIST)/history.c \
	  $(LEXER)/tokenizer.c $(LEXER)/lexer_rules.c \
	  $(PARSER)/parsing.c $(PARSER)/path.c $(PARSER)/syntax.c \
	  $(EXE)/exe.c \
	  $(INOUT)/redirect_in.c $(INOUT)/redirect_out.c

SRCS = $(addprefix $(DIR_S)/,$(SOURCES))

OBJS = $(addprefix $(DIR_O)/,$(SOURCES:.c=.o))

all: $(NAME)

bonus: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIB)/libft
	$(CC) $(CFLAGS) -o $(NAME) -ltermcap $(OBJS) $(LIBFT)

$(NAMEB): $(OBJSB)
	make -C $(LIB)/libft
	$(CC) $(CFLAGS) -o $(NAMEB) $(OBJSB) $(LIBFT)

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
	$(CC) $(CFLAGS) -I $(HEADER) -o $@ -c $<

norme:
	@echo
	norminette $(LIBRARIES)/
	@echo
	norminette $(HEADER)/
	@echo
	norminette $(DIR_S)/

clean:
	rm -rf $(DIR_O)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY:		all clean fclean re bonus norme
