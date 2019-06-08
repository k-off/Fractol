#******************************************************************************#
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: pacovali <marvin@codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2019/01/01 00:42:00 by pacovali      #+#    #+#                  #
#    Updated: 2019/01/01 00:42:01 by pacovali      ########   odam.nl          #
#                                                                              #
#******************************************************************************#

NAME = fractol
SRCS = main.c set_fractal.c barnsley.c julia.c mandelbrot.c sierpinski.c \
key_mouse.c
OBJS = main.o set_fractal.o barnsley.o julia.o mandelbrot.o sierpinski.o \
key_mouse.o
MKOBJ = @gcc -Wall -Wextra -Werror -c
LFTHDR = -I libft
LFT = -L libft/ -lft
MKLFT = @make -C libft/ fclean && make -C libft/ && make -C libft/ clean
MLXHDR = -I lmlx
MLX = -L lmlx/ -lmlx -framework OpenGL -framework AppKit 
MKMLX = @make -C lmlx/ clean && make -C lmlx/
MKEXE = @gcc -o


all: $(NAME)
$(NAME):
	$(MKLFT)
	$(MKMLX)
	$(MKOBJ) $(SRCS) $(LFTHDR) $(MLXHDR)
	$(MKEXE) $(NAME) $(OBJS) $(HDRS) $(LFT) $(MLX)

clean:
	@rm -f $(OBJS)

fclean: cleanlib clean
	@rm -f $(NAME)

cleanlib:
	@make -C libft/ fclean
	@make -C lmlx/ clean

re: fclean all