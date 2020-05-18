##
## EPITECH PROJECT, 2020
## CPE_lemin_2019 [SSH: 192.168.159.130]
## File description:
## Makefile
##

NAME	=	lem_in

TESTS_NAME	=	unit_tests

CC	=	gcc

RM	=	rm	-f

SRCS	=	./sources/add_rooms_and_tunnels/add_room.c				\
			./sources/add_rooms_and_tunnels/add_room_or_tunnel.c	\
			./sources/add_rooms_and_tunnels/add_tunnels.c			\
			./sources/checks/check_rooms.c							\
			./sources/checks/check_tunnels.c						\
			./sources/display/display_all.c							\
			./sources/display/display.c								\
			./sources/display/display_moves.c						\
			./sources/free_all.c									\
			./sources/link_rooms.c									\
			./sources/main.c										\
			./sources/parsing/parse_line.c							\
			./sources/parsing/read_input.c							\
			./sources/path_ants/get_path.c							\
			./sources/path_ants/init_and_reset.c					\
			./sources/path_ants/move_ants.c							\
			./sources/path_ants/split_ants_in_path.c				\
			./sources/utils/is_digit.c								\
			./sources/utils/is_printable.c							\
			./sources/utils/my_atoi.c								\
			./sources/utils/my_put_nbr.c							\
			./sources/utils/my_strcat.c								\
			./sources/utils/my_strcmp.c								\
			./sources/utils/my_strcspn.c							\
			./sources/utils/my_strdup.c								\
			./sources/utils/my_strlen.c								\
			./sources/utils/my_strspn.c								\
			./sources/utils/my_strstr.c								\
			./sources/utils/my_strtok.c								\
			./sources/utils/my_strtok_r.c							\
			./sources/utils/remove_end_spaces.c

TESTS_SRCS	=	./sources/add_rooms_and_tunnels/add_room.c		\
				./sources/add_rooms_and_tunnels/add_tunnels.c	\
				./sources/checks/check_tunnels.c				\
				./sources/utils/is_digit.c						\
				./sources/utils/is_printable.c					\
				./sources/utils/my_atoi.c						\
				./sources/utils/my_strcmp.c						\
				./sources/utils/my_strcspn.c					\
				./sources/utils/my_strdup.c						\
				./sources/utils/my_strspn.c						\
				./tests/test_add_room.c							\
				./tests/test_add_tunnels.c						\
				./tests/test_check_tunnels.c					\
				./tests/test_is_digit.c							\
				./tests/test_is_printable.c						\
				./tests/test_my_atoi.c							\
				./tests/test_my_strcspn.c						\
				./tests/test_my_strdup.c						\
				./tests/test_my_strspn.c

OBJS	=	$(SRCS:.c=.o)

TESTS_OBJS	=	$(TESTS_SRCS:.c=.o)

CFLAGS	=	-I	./include/
CFLAGS	+=	-g3
CFLAGS	+=	-Wall	-Wextra

LDFLAGS	=

ifeq	($(MAKECMDGOALS),	tests_run)
CFLAGS	+=	--coverage
LDFLAGS	+=	-lcriterion
endif

all:	$(NAME)

$(NAME):	$(OBJS)
	$(CC)	$(OBJS)	-o	$(NAME)	$(LDFLAGS)

tests_run:	$(TESTS_OBJS)
	$(CC)	$(TESTS_OBJS)	-o	$(TESTS_NAME)	$(LDFLAGS)	$(CFLAGS)
	./$(TESTS_NAME)

tests_clean:
	$(RM)	$(TESTS_NAME)
	$(RM)	$(TESTS_OBJS)
	$(RM)	$(wildcard	*/*.gc*)	$(wildcard	*/*/*.gc*)

clean:	tests_clean
	$(RM)	$(OBJS)

fclean:	clean
	$(RM)	$(NAME)

re:	fclean	all

.PHONY:	all	tests_run	tests_clean	clean	fclean	re
