# ===== NAMES ================================================== #

NAME = minitalk

# ===== COMPILES =============================================== #

CC = 			gcc
C_FLAGS = 		-Wall -Wextra -Werror
RM = 			rm -f
MKDIR = 		mkdir -p

# ===== DIRECTORIES ============================================ #

SRC = src/
SRC_UTILS =		$(SRC)utils.c
SRC_CLIENT = 	$(SRC)client.c
SRC_SERVER =	$(SRC)server.c
LIBFT_DIR =		lib/libft/
BIN_DIR = 		bin/
OBJ_DIR = 		obj/

# ===== LIBRARIES ================================================ #

LIBFT_LIB = $(LIBFT_DIR)libft.a

# ===== OBJECTS ================================================ #

OBJ_CLIENT = $(OBJ_DIR)client.o
OBJ_SERVER = $(OBJ_DIR)server.o
OBJ_UTILS = $(OBJ_DIR)utils.o

# ===== TARGETS ================================================ #

TARGET_CLIENT = $(BIN_DIR)client
TARGET_SERVER = $(BIN_DIR)server


# ===== all ==================================================== #

all: $(TARGET_CLIENT) $(TARGET_SERVER)

$(OBJ_DIR)client.o: $(SRC_CLIENT)
	$(MKDIR) $(OBJ_DIR)
	@$(CC) $(C_FLAGS) -c $< -o $@

$(OBJ_DIR)server.o: $(SRC_SERVER)
	$(MKDIR) $(OBJ_DIR)
	@$(CC) $(C_FLAGS) -c $< -o $@

$(OBJ_DIR)utils.o: $(SRC_UTILS)
	@$(MKDIR) $(OBJ_DIR)
	@$(CC) $(C_FLAGS) -c $< -o $@

$(TARGET_CLIENT): $(OBJ_CLIENT) $(OBJ_UTILS) $(LIBFT_LIB)
	$(MKDIR) $(BIN_DIR)
	@$(CC) $(C_FLAGS) $(OBJ_CLIENT) $(OBJ_UTILS) -L$(LIBFT_DIR) -lft -o $(TARGET_CLIENT)

$(TARGET_SERVER): $(OBJ_SERVER) $(OBJ_UTILS) $(LIBFT_LIB)
	$(MKDIR) $(BIN_DIR)
	@$(CC) $(C_FLAGS) $(OBJ_SERVER) $(OBJ_UTILS) -L$(LIBFT_DIR) -lft -o $(TARGET_SERVER)

$(LIBFT_LIB):
	@$(MAKE) bonus -C $(LIBFT_DIR)

clean:
	$(RM) -r $(OBJ_DIR)

fclean: clean
	$(RM) $(TARGET_CLIENT) $(TARGET_SERVER)

re: clean all

.PHONY: all clean fclean re
