NAME =	my_hunter

SRC =	src/main.c \
	src/events.c \
	src/sprites.c \
	src/change_sprites.c \
	src/reset_sprite_pos.c \
	src/sound.c \
	src/intro.c \
	src/draw_bg.c \
	src/modify_duck_speed.c \
	src/change_menus.c \
	src/game_over.c \
	src/save_score.c \
	src/duck_death.c \
	src/score.c \
	src/bonus.c \
	src/modify_mouse_pos.c \
	src/show_ammos.c \
	src/my_hunter.c \
	src/menu.c

OBJ =	$(SRC:.c=.o)

INC =	-Iinclude \
	-Ilib/my/includes

LIB =	./lib/my/libmy.a

LDFLAGS = -Llib/my -lmy -lc_graph_prog

CFLAGS= $(INC) \
	-W \
	-Wall \
	-Wextra \

CC =	gcc

all:    $(NAME)

$(LIB):
	$(MAKE) -C lib/my

$(NAME):$(OBJ) $(LIB)
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
	$(MAKE) -C lib/my clean
	$(RM) $(OBJ)

fclean:	clean
	$(MAKE) -C lib/my fclean
	$(RM) $(NAME)
	$(RM) score.dat

re:	fclean all

dbg:	CFLAGS += -g -O0
dbg:	re
