# Derleyici seçimi
CC = gcc

# Derleyici flagleri
CFLAGS = -Wall -Wextra -Werror

# Çıktı dosyası adı
NAME = libftprintf.a

# Kütüphane dosyaları
LIBFT = Libft
LIBFT_INC = $(LIBFT)/libft.h
LIBFT_SRC = $(wildcard $(LIBFT)/*.c)
LIBFT_OBJ = $(patsubst $(LIBFT)/%.c,$(LIBFT)/%.o,$(LIBFT_SRC))

# Proje dosyaları
PRINTF_SRC = ft_printf.c ft_print_ptr.c ft_print_hex.c
PRINTF_HEADER = ft_printf.h
PRINTF_OBJ = $(PRINTF_SRC:.c=.o)

# Tüm hedef dosyalar
OBJECTS = $(LIBFT_OBJ) $(PRINTF_OBJ)

# Derleme kuralı
all: $(NAME)

$(NAME): $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)

# Libft derlemesi
$(LIBFT)/%.o: $(LIBFT)/%.c $(LIBFT_INC)
	$(CC) $(CFLAGS) -c $< -o $@ -I $(LIBFT)

# ft_printf derlemesi
%.o: %.c $(PRINTF_HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

