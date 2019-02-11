CC=gcc
CFLAGS=-g3 -I includes -I srcs/libft/includes
INCS= -I ../includes/snake.h
NAME=snk
SRCS=	srcs/main.c \
		srcs/draw/draw_tools_p1.c \
		srcs/draw/draw_tools_p2.c \
		srcs/draw/draw_update.c \
		srcs/graphic/vec2_cmp.c \
		srcs/graphic/vec2_convert.c \
		srcs/graphic/vec2_directional.c \
		srcs/graphic/vec2_op.c \
		srcs/init/init_gamedata.c \
		srcs/init/init_snk.c \
		srcs/mechanics/exit_snk.c \
		srcs/mechanics/food.c \
		srcs/mechanics/update_snk.c \
		srcs/tc/sig.c \
		srcs/tc/tc_engine.c \
		srcs/update/input_update.c

OBJS= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS) -L srcs/libft -lft -ltermcap 

clean:
	rm -f $(OBJS)
	rm -f *.dsym

fclean: clean
	rm -f $(NAME)