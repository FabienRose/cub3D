#--------------------------------------------------
#                  ENVIRONMENT
#--------------------------------------------------

#----- C language compiler -----
CPL=cc
CPL_FLAGS=-Wall -Wextra -Werror

#----- Program informations -----
PNAME=cub3D

#----- RM Command -----
RM_FLAGS=-f

#----- Sanitize flags -----
SAN_FLAGS=-fsanitize=address -fsanitize=leak

#----- Minilibx directory and library -----
MLX_DIR=minilibx-linux
MLX=$(MLX_DIR)/libmlx.a
MLX_FLAGS=-L$(MLX_DIR) -lmlx -L/usr/include/../lib -lXext -lX11 -lm -lbsd

#--------------------------------------------------
#              SOURCES AND OBJECTS
#--------------------------------------------------

#----- Sources -----
SRCS=	main.c \
		map/map.c \
		hooks/hooks.c \
		render/render.c \
		player/player.c \
		player/player_rays.c \
		game/game.c \
		game/game_movement.c

#----- Objects -----
OBJDIR = obj
OBJS=$(addprefix $(OBJDIR)/, $(SRCS:.c=.o))

#--------------------------------------------------
#              DEPENDENCIES (LIBS)
#--------------------------------------------------

#----- Lib: libft -----
LIBFT_NAME=libft.a
LIBFT_PATH=./libft/
LIBFT_LPATH=-L$(LIBFT_PATH)
LIBFT_LCALL=-lft
LIBFT_CALL=$(LIBFT_LPATH) $(LIBFT_LCALL)

#----- Common -----
DEPS_LIST=$(LIBFT_PATH)$(LIBFT_NAME) $(MLX)
DEPS_CALLS=$(LIBFT_CALL) $(MLX_FLAGS)

#--------------------------------------------------
#      LOADING BAR - ADVANCED MAKEFILE (AMK)
#--------------------------------------------------

#----- Counts -----
AMK_NB_FILES=$(words $(SRCS))
AMK_NB_ACTIONS=$(shell echo $$(( $(AMK_NB_FILES))))

#----- Vars -----
AMK_BARPOS=-1
AMK_WIDTH=50 
AMK_IS_INIT=0

#----- Functions -----

#Function 'init_bar': Setup the cursor position of the laoding bar
define init_bar
	@if [ $(AMK_IS_INIT) -eq 0 ]; then printf "\033[s"; fi
	$(eval AMK_IS_INIT := 1)
endef

#Function 'next_bar': Increment bar display to the next file
define next_bar
	$(eval AMK_BARPOS := $(shell echo $$(( $(AMK_BARPOS) + 1))))
	@printf "\033[u%-101s[\033[1m\033[33mWORKING\033[0m]" "$$(printf "[\033[1m\033[34mMAKEFILE\033[0m - \033[1m\033[36mCompiling\033[0m]: $$( printf "%.46s" "$@")")"
	@printf "\n["; \
	for i in `seq 1 $$(( (($(AMK_BARPOS) * 100) / $(AMK_NB_ACTIONS)) * $(AMK_WIDTH) / 100 ))`; \
	do \
	printf "\033[1m\033[34m#\033[0m"; \
	done; \
	printf "\033[u\n\033[$$(( $(AMK_WIDTH) + 1 ))C] \033[34m\033[1m$$(( (($(AMK_BARPOS) * 100) / $(AMK_NB_ACTIONS)) ))%%\033[0m (\033[34m\033[1m$(AMK_BARPOS)\033[0m/\033[34m\033[1m$(AMK_NB_FILES)\033[0m)\033[u"
endef

#Function 'final_bar': call when all done to set as finalresult
define final_bar
	$(eval AMK_BARPOS := $(shell echo $$(( $(AMK_BARPOS) + 1))))
	@printf "\033[u%-101s[\033[1m\033[34mOK\033[0m]        " "$$(printf "[\033[1m\033[34mMAKEFILE\033[0m - \033[1m\033[36mCompiling\033[0m]: $(PNAME)")"
	@printf "\033[s\n"; \
	for i in `seq 1 $$(( $(AMK_WIDTH) * 2 ))`; \
	do \
	printf " "; \
	done; \
	printf "\033[u\033s"
endef

#--------------------------------------------------
#                COMPILING RULES
#--------------------------------------------------

#----- Main Rules -----
all: $(MLX) $(PNAME)

$(MLX):
	@printf "\n%-123s\033[s[\033[1m\033[33mWORKING\033[0m]" "$$(printf "[\033[1m\033[34mMAKEFILE\033[0m - \033[1m\033[36mCompiling\033[0m]: '\033[1m\033[4m\033[36mminilibx\033[24m\033[0m' compiling started")"
	@printf "\033[u[\033[1m\033[34mOK\033[0m]        \n\033[s"
	@$(MAKE) -C $(MLX_DIR)
	@printf "%-123s\033[s[\033[1m\033[33mWORKING\033[0m]" "$$(printf "[\033[1m\033[34mMAKEFILE\033[0m - \033[1m\033[36mCompiling\033[0m]: '\033[1m\033[4m\033[36mminilibx\033[24m\033[0m' compiling ended")"
	@printf "\033[u[\033[1m\033[34mOK\033[0m]        \n\033[s\n"

$(PNAME): $(DEPS_LIST) $(OBJS)
	$(eval NB_BARPOS := $(AMK_NB_FILES))
	$(call init_bar)
	$(call next_bar)
	@$(CPL) $(CPL_FLAGS) $(if $(SAN_ACTIVE), $(SAN_FLAGS)) $(DEPS_LIST) $(OBJS) $(DEPS_CALLS) -o $@
	$(call final_bar)
	@printf "\n\033[s"

sanitize: fclean
	@printf "%-101s\033[s[\033[1m\033[33mWORKING\033[0m]" "$$(printf "[\033[1m\033[34mMAKEFILE\033[0m - \033[1m\033[36mCompiling\033[0m]: Compiling with Sanitize")"
	@printf "\033[u[\033[1m\033[34mOK\033[0m]        \n\033[s"
	@$(MAKE) --no-print-directory SAN_ACTIVE=true

$(OBJDIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(call init_bar)
	$(call next_bar)
	@$(CPL) $(CPL_FLAGS) -I./ -c $< -o $@
	@sleep 0.000000

#----- Libs Rules -----
$(LIBFT_PATH)$(LIBFT_NAME):
	@printf "\n%-123s\033[s[\033[1m\033[33mWORKING\033[0m]" "$$(printf "[\033[1m\033[34mMAKEFILE\033[0m - \033[1m\033[36mCompiling\033[0m]: '\033[1m\033[4m\033[36mlibft.a\033[24m\033[0m' compiling started")"
	@printf "\033[u[\033[1m\033[34mOK\033[0m]        \n\033[s"
	@$(MAKE) --no-print-directory -C $(LIBFT_PATH)
	@printf "%-123s\033[s[\033[1m\033[33mWORKING\033[0m]" "$$(printf "[\033[1m\033[34mMAKEFILE\033[0m - \033[1m\033[36mCompiling\033[0m]: '\033[1m\033[4m\033[36mlibft.a\033[24m\033[0m' compiling ended")"
	@printf "\033[u[\033[1m\033[34mOK\033[0m]        \n\033[s\n"

#--------------------------------------------------
#                CLEANING RULES
#--------------------------------------------------
clean:
	@printf "%-101s\033[s[\033[1m\033[33mWORKING\033[0m]" "$$(printf "[\033[1m\033[34mMAKEFILE\033[0m - \033[1m\033[36mClean\033[0m]: Cleaning object files")"
	@$(MAKE) -C $(MLX_DIR) clean
	@rm $(RM_FLAGS) $(OBJS)
	@printf "\033[u[\033[1m\033[34mOK\033[0m]        \n\033[s"
	@printf "\n%-123s\033[s[\033[1m\033[33mWORKING\033[0m]" "$$(printf "[\033[1m\033[34mMAKEFILE\033[0m - \033[1m\033[36mClean\033[0m]: '\033[1m\033[4m\033[36mlibft.a\033[24m\033[0m' cleaning started")"
	@printf "\033[u[\033[1m\033[34mOK\033[0m]        \n\033[s"
	@$(MAKE) --no-print-directory -C $(LIBFT_PATH) clean
	@printf "%-123s\033[s[\033[1m\033[33mWORKING\033[0m]" "$$(printf "[\033[1m\033[34mMAKEFILE\033[0m - \033[1m\033[36mClean\033[0m]: '\033[1m\033[4m\033[36mlibft.a\033[24m\033[0m' cleaning ended")"
	@printf "\033[u[\033[1m\033[34mOK\033[0m]        \n\033[s\n"

fclean: clean
	@printf "%-101s\033[s[\033[1m\033[33mWORKING\033[0m]" "$$(printf "[\033[1m\033[34mMAKEFILE\033[0m - \033[1m\033[36mFclean\033[0m]: Removing all generated files")"
	@$(MAKE) -C $(MLX_DIR) clean
	@rm $(RM_FLAGS) $(PNAME)
	@printf "\033[u[\033[1m\033[34mOK\033[0m]        \n\033[s"
	@printf "\n%-123s\033[s[\033[1m\033[33mWORKING\033[0m]" "$$(printf "[\033[1m\033[34mMAKEFILE\033[0m - \033[1m\033[36mFclean\033[0m]: '\033[1m\033[4m\033[36mlibft.a\033[24m\033[0m' full cleaning started")"
	@printf "\033[u[\033[1m\033[34mOK\033[0m]        \n\033[s"
	@$(MAKE) --no-print-directory -C $(LIBFT_PATH) fclean
	@printf "%-123s\033[s[\033[1m\033[33mWORKING\033[0m]" "$$(printf "[\033[1m\033[34mMAKEFILE\033[0m - \033[1m\033[36mFclean\033[0m]: '\033[1m\033[4m\033[36mlibft.a\033[24m\033[0m' full cleaning ended")"
	@printf "\033[u[\033[1m\033[34mOK\033[0m]        \n\033[s\n"

#--------------------------------------------------
#                EXTRA RULES
#--------------------------------------------------
re: fclean all

.phony: all clean fclean re
