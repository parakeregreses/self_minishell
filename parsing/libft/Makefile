SRCS = ft_isascii.c\
ft_memmove.c\
ft_memcmp.c\
ft_split.c\
ft_strmapi.c\
ft_toupper.c\
ft_isdigit.c\
ft_memcpy.c\
ft_strchr.c\
ft_strncmp.c\
ft_atoi.c\
ft_isprint.c\
ft_memset.c\
ft_strdup.c\
ft_strnstr.c\
ft_bzero.c\
ft_itoa.c\
ft_putchar_fd.c\
ft_striteri.c\
ft_strrchr.c\
ft_calloc.c\
ft_putendl_fd.c\
ft_strjoin.c\
ft_strtrim.c\
ft_isalnum.c\
ft_putnbr_fd.c\
ft_strlcpy.c\
ft_strlcat.c\
ft_substr.c\
ft_isalpha.c\
ft_memchr.c\
ft_putstr_fd.c\
ft_strlen.c\
ft_tolower.c\
ft_lstdelone.c\
ft_lstiter.c\
ft_lstlast.c\
ft_lstadd_back.c\
ft_lstnew.c\
ft_lstadd_front.c\
ft_lstsize.c\
ft_lstclear.c\
ft_lstmap.c\
ft_strcmp.c\
ft_filetostr.c\
free_tab.c\
ft_insert_last_line.c\
ft_print_tab_char.c\
ft_strjoinfree.c\
ft_charinstr.c\
ft_parsing_printf.c\
ft_print_int.c\
ft_print_ptr.c\
ft_print_udec.c\
ft_printf.c\
ft_chose_printf.c\
ft_print_char.c\
ft_print_lowhex.c\
ft_print_str.c\
ft_print_uphex.c\
ft_firstword.c\
get_next_line.c\
get_next_line_utils.c\
ft_abs.c\
tab_size.c\
append_tabs_and_free.c\
cut_tab_head.c\
cut_tab_tail.c\
delete_line_in_tab.c\
find_segment.c\
is_x_char_in_str.c\
ft_iswhitespace.c\
does_char_end_line.c\

OBJS = $(SRCS:.c=.o)

INCLUDE = libft.h\
get_next_line.h

COMP = cc -Wall -Wextra -Werror

NAME = libft.a

all : $(NAME)

.c.o: 
	$(COMP) -c $< -o $(<:.c=.o)

$(NAME) : $(OBJS) 
	ar rcs $(NAME) $(OBJS)

clean : 
	rm -rf $(OBJS)

fclean : clean
	rm -rf libft.a

re : fclean all

.PHONY: all clean fclean re
