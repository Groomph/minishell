# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/15 14:25:42 by rsanchez          #+#    #+#              #
#    Updated: 2021/12/19 17:43:35 by rsanchez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a

CC	= clang

CFLAGS	= -Wall -Wextra -Werror #--analyze

RM	= rm -f

HEADER	= includes

NB_STR	= string_to_number

DISPLAY	= display

FD	= file_descriptor

IS_FCT	= is?_functions

STRING	= string

ARRAY	= array

ARRSTR	= $(ARRAY)/array_string

PARSER	= parser

BYTE	= bytewise

VECTOR	= vector

VECSTR	= vector_string

GC	= garbage_collector

LIST	= linked_list

LIST2	= linked_list2

DIR_S	= sources

DIR_O	= temporary

SOURCES	= valeur_absolue.c optimized_msleep.c \
	  $(BYTE)/init_zero.c $(BYTE)/mem_set.c $(BYTE)/mem_copy.c \
	  $(BYTE)/ft_calloc.c \
	  ${IS_FCT}/is_double_signed.c ${IS_FCT}/is_infinite.c \
	  ${IS_FCT}/is_not_number.c $(IS_FCT)/is_whitespace.c \
	  ${IS_FCT}/is_only_numeric.c \
	  ${STRING}/shift_left_erase.c ${STRING}/shift_right_add.c \
	  ${STRING}/str_n_comp.c ${STRING}/str_nstr_comp.c \
	  ${STRING}/string_len.c ${STRING}/string_split.c \
	  ${STRING}/strjoin.c ${STRING}/substr.c \
	  ${STRING}/string_duplicate.c ${STRING}/string_chr.c \
	  ${ARRAY}/array_clear.c \
	  ${ARRSTR}/arrstr_duplicate.c ${ARRSTR}/arrstr_malloc.c \
	  ${NB_STR}/utoa_len.c ${NB_STR}/utoa_base.c \
	  $(NB_STR)/itoa_base.c $(NB_STR)/atoi.c \
	  $(NB_STR)/atoli.c ${NB_STR}/atodoub_windex.c \
	  $(LIST)/lst_addback.c $(LIST)/lst_addfront.c \
	  $(LIST)/lst_clear.c $(LIST)/ft_lstlast.c \
	  $(LIST)/ft_lstsecondlast.c $(LIST)/lst_duplicate.c \
	  $(LIST)/lst_new.c \
	  $(LIST2)/lst2_addback.c $(LIST2)/lst2_addfront.c \
	  $(LIST2)/lst2_clear.c $(LIST2)/lst2_getlast.c \
	  $(LIST2)/lst2_getsecondlast.c $(LIST2)/lst2_duplicate.c \
	  $(VECTOR)/vector_new.c $(VECTOR)/vector_init.c \
	  $(VECTOR)/vector_add.c $(VECTOR)/vector_extend.c \
	  $(VECTOR)/vector_purge.c $(VECTOR)/vector_clean.c \
	  $(VECTOR)/vector_delone.c $(VECTOR)/vector_shift_down.c \
	  $(VECTOR)/vector_extract.c $(VECTOR)/vector_get.c \
	  $(VECTOR)/vector_arrstr_clean.c \
	  $(VECSTR)/vecstr_new.c $(VECSTR)/vecstr_init.c \
	  $(VECSTR)/vecstr_add.c $(VECSTR)/vecstr_extend.c \
	  $(VECSTR)/vecstr_purge.c $(VECSTR)/vecstr_clean.c \
	  $(VECSTR)/vecstr_delone.c $(VECSTR)/vecstr_insert.c \
	  $(VECSTR)/vecstr_concat.c \
	  $(GC)/gc_new.c $(GC)/gc_init.c \
	  $(GC)/gc_add.c \
	  $(GC)/gc_purge.c $(GC)/gc_clean.c \
	  ${FD}/get_next_line.c ${FD}/read_input.c \
	  $(PARSER)/parser_atoui.c \
	  $(DISPLAY)/buffer.c $(DISPLAY)/buffer_conversion.c

SRCS	= $(addprefix $(DIR_S)/,$(SOURCES))

OBJS	= $(addprefix $(DIR_O)/,$(SOURCES:.c=.o))

#OBJS	= ${SRCS:.c=.o}
#BOBJS	= ${BSRCS:.c=.o}

$(NAME):	${OBJS}
			ar rc ${NAME} ${OBJS}

$(DIR_O)/%.o: $(DIR_S)/%.c
	@mkdir -p $(DIR_O)
	@mkdir -p $(DIR_O)/$(NB_STR)
	@mkdir -p $(DIR_O)/$(DISPLAY)
	@mkdir -p $(DIR_O)/$(FD)
	@mkdir -p $(DIR_O)/$(IS_FCT)
	@mkdir -p $(DIR_O)/$(STRING)
	@mkdir -p $(DIR_O)/$(ARRAY)
	@mkdir -p $(DIR_O)/$(ARRSTR)
	@mkdir -p $(DIR_O)/$(PARSER)
	@mkdir -p $(DIR_O)/$(BYTE)
	@mkdir -p $(DIR_O)/$(LIST)
	@mkdir -p $(DIR_O)/$(LIST2)
	@mkdir -p $(DIR_O)/$(VECTOR)
	@mkdir -p $(DIR_O)/$(VECSTR)
	@mkdir -p $(DIR_O)/$(GC)
	$(CC) $(CFLAGS) -I $(HEADER) -o $@ -c $<

all:		${NAME}

clean:
		${RM} ${OBJS}
		${RM}r $(DIR_O)

fclean:		clean
		${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
