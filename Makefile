# ===== NAMES ================================================== #

NAME = minitalk

# ===== COMPILES =============================================== #

CC = 			gcc
C_FLAGS = 		-Wall -Wextra -Werror
RM = 			rm -f
MKDIR = 		mkdir -p

# ===== DIRECTORIES ============================================ #

SRC = src/
SRC_CLIENT = 	$(SRC)client.c
SRC_SERVER =	$(SRC)server.c
LIBFT_DIR =		lib/libft/
BIN_DIR = 		bin/
OBJ_DIR = 		obj/

# ===== LIBRARIES ================================================ #

LIBFT_LIB = $(LIBFT_DIR)libft.a

# ===== OBJECTS ================================================ #

OBJ1 = $(OBJ_DIR)client.o

OBJ2 = $(OBJ_DIR)server.o

# ===== TARGETS ================================================ #

TARGET_CLIENT = $(BIN_DIR)client
TARGET_SERVER = $(BIN_DIR)server


# ===== all ==================================================== #

all: $(TARGET_CLIENT) $(TARGET_SERVER)

$(OBJ_DIR)client.o: $(SRC_CLIENT)
	@$(MKDIR) $(OBJ_DIR)
	$(CC) $(C_FLAGS) -c $< -o $@

$(OBJ_DIR)server.o: $(SRC_SERVER)
	@$(MKDIR) $(OBJ_DIR)
	$(CC) $(C_FLAGS) -c $< -o $@

$(TARGET_CLIENT): $(OBJ1) $(LIBFT_LIB)
	@$(MKDIR) $(BIN_DIR)
	$(CC) $(C_FLAGS) $(OBJ1) -L$(LIBFT_DIR) -lft -o $(TARGET_CLIENT)

$(TARGET_SERVER): $(OBJ2) $(LIBFT_LIB)
	@$(MKDIR) $(BIN_DIR)
	@$(CC) $(C_FLAGS) $(OBJ2) -L$(LIBFT_DIR) -lft -o $(TARGET_SERVER)

$(LIBFT_DIR)$(LIBFT_LIB):
	@$(MAKE) bonus -C $(LIBFT_DIR)

clean:
	$(RM) -r $(OBJ_DIR)

fclean: clean
	$(RM) $(TARGET_CLIENT) $(TARGET_SERVER)

re: clean all

.PHONY: all clean fclean re
