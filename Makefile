NAME =	my_hunter

SRC =	src/main.c \
	src/events.c \
	src/sprites.c \
	src/change_sprites.c \
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
	src/menu.c \
	src/combo.c

OBJ =	$(SRC:.c=.o)

INC =	-Iinclude \
	-Ilib/my/includes


CSFML = -lcsfml-system		\
	-lcsfml-window		\
	-lcsfml-graphics	\
	-lcsfml-audio		\

SFML =	-lsfml-system		\
	-lsfml-window		\
	-lsfml-graphics		\
	-lsfml-audio		\

LDFLAGS =		\
	-L lib/my	\
	-lm		\
	-lmy		\

CFLAGS= $(INC)				\
	-W				\
	-Wall				\
	-Wextra				\
	-Wno-parentheses		\
	-fdiagnostics-color=always	\

CC =	gcc

RULE =	all

LIBS =	lib/my/libmy.a	\

RES =	

all:	$(LIBS) $(NAME)

windows:RES = icon.res
windows:LDFLAGS += -mwindows
windows:icon.res all

icon.res:
	windres icon.rc -O coff -o icon.res

lib/my/libmy.a:
	$(MAKE) -C lib/my $(RULE)

$(NAME):$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS) $(CSFML) $(RES)

clean:
	$(MAKE) -C lib/my clean
	$(RM) $(OBJ)
	$(RM) icon.res

fclean:	clean
	$(RM) $(NAME) $(NAME).exe

ffclean:fclean
	$(MAKE) -C lib/my fclean

re:	fclean all

dbg:	CFLAGS += -g -O0
dbg:	RULE = dbg
dbg:	ffclean all

sfml:	CSFML += $(SFML)
sfml:	re

epi:	CSFML = -lc_graph_prog
epi:	CFLAGS += -g -O0
epi:	RULE = dbg
epi:	re
