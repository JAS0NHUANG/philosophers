# **************************************************************************** #
#       COMANDS                                                                #
# **************************************************************************** #
CC			=	gcc
RM			=	rm
AR			=	ar rcs

# **************************************************************************** #
#       TITLE                                                                  #
# **************************************************************************** #
NAME		=	philo

# **************************************************************************** #
#       FLAGS                                                                  #
# **************************************************************************** #
CFLAGS		=	-Wall -Wextra -Werror
PTHREAD		=	-pthread
FSAN_THR	=	-fsanitize=thread
FSAN_ADD	=	-fsanitize=address
DEBUG		=	-g3
FNO_STACK	=	-fno-stack-protector
RF			=	-rf

# **************************************************************************** #
#       SOURCES                                                                #
# **************************************************************************** #
SRCS_DIR	=	srcs

INCS_DIR	=	incs

SRCS		=	main.c \
				ft_get_data.c \
				ft_init_mutexs.c \
				ft_run_philo.c \
				ft_actions.c \
				ft_print_action.c \
				utils/ft_atoi.c \
				utils/ft_isdigit.c \
				utils/ft_strlen.c \
				utils/ft_get_time_in_ms.c \

INCS		=	philo.h	\

# **************************************************************************** #
#       RULES                                                                  #
# **************************************************************************** #
OBJS		=	$(addprefix $(SRCS_DIR)/,$(SRCS:.c=.o))

%.o			:	%.c
				$(CC) $(CFLAGS) $(PTHREAD) -I $(INCS_DIR) -c $< -o $@

$(NAME)		:	$(OBJS)
				$(CC) -o $@ $(OBJS) -I $(INCS_DIR) $(CFLAGS) $(PTHREAD)

all			:	$(NAME)

philo_thr	:	$(OBJS)
				$(CC) -o $@ $(OBJS) -I $(INCS_DIR) $(FSAN_THR) $(PTHREAD) \
				$(FNO_STACK)

philo_add	:	$(OBJS)
				$(CC) -o $@ $(OBJS) -I $(INCS_DIR) $(FSAN_ADD) $(PTHREAD) \
				$(FNO_STACK)

clean		:
				$(RM) $(RF) $(OBJS)

fclean		:	clean
				$(RM) $(RF) $(NAME) philo_thr philo_add

re			:	fclean all

# **************************************************************************** #
#       PHONY                                                                  #
# **************************************************************************** #
.PHONY		:	NAME all clean fclean re
