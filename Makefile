##
## Makefile for lib-arduino in /home/caudou_j/Documents/projets/arduino/lib-arduino
## 
## Made by caudou_j
## Login   <caudou_j@epitech.net>
## 
## Started on  Wed May 14 16:46:50 2014 caudou_j
## Last update Wed May 21 15:33:53 2014 caudou_j
##

AR		= 	ar -rc

RM		=	rm -f

CC		=	gcc

RANLIB		=	ranlib

NAME		=	lib-arduino.a

SRC		=	arduino_init.c			\
			arduino_read.c			\
			arduino_close.c			\
			arduino_write.c			\
			arduino_set_digital_mode.c	\
			arduino_set_digital_state.c	\
			arduino_get_digital_state.c	\
			arduino_get_analog_value.c

VPATH		+=	src/

BUILD		=	build

OBJ		=	$(patsubst %.c, $(BUILD)/%.o, $(SRC))

CFLAGS		+=	-Iinc/ -I../../includes
CFLAGS		+=	-Wall -Wextra -Werror

all		:	$(BUILD) $(NAME)

$(BUILD)	:
			mkdir -p $(BUILD)

$(NAME)		:	$(OBJ)
			$(AR) $(NAME) $(OBJ)
			$(RANLIB) $(NAME)

$(BUILD)/%.o	:	%.c
			$(CC) $(CFLAGS) -c -o $@ $<

clean		:
			$(RM) $(BUILD)/*.o
			@if [ -d "$(BUILD)" ]; \
			then \
				rmdir $(BUILD); \
			fi \

fclean		:	clean
			$(RM) $(NAME)

re		:	fclean all

.PHONY		:	all clean fclean re
