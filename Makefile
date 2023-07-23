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
LIBFT_OBJ = $(LIBFT_SRC:.c=.o)

# Proje dosyaları
PRINTF_SRC = ft_printf.c
PRINTF_HEADER = ft_printf.h
PRINTF_OBJ = $(PRINTF_SRC:.c=.o)

# Tüm hedef dosyalar
OBJECTS = $(LIBFT_OBJ) $(PRINTF_OBJ)

# Derleme kuralı
all: $(NAME)

$(NAME): $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)

# Libft derlemesi
$(LIBFT_OBJ): $(LIBFT_SRC) $(LIBFT_INC)
	$(CC) $(CFLAGS) -c $< -o $@ -I $(LIBFT)

# ft_printf derlemesi
$(PRINTF_OBJ): $(PRINTF_SRC) $(PRINTF_HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

