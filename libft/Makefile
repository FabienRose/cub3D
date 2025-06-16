

#--------------------------------------------------
#                  ENVIRONMENT
#--------------------------------------------------

#----- C language compiler -----
CPL=cc
CPL_FLAGS=-Wall -Wextra -Werror

#----- Library make command -----
LIB_CMD=ar
LIB_CMD_FLAGS=-rcs

#----- Program informations -----
PNAME=libft.a

#----- RM Command -----
RM_FLAGS=-f
SMK_RM_FLAGS=-fr


#--------------------------------------------------
#              SOURCES AND OBJECTS
#--------------------------------------------------

#----- Sources -----
SRCS=	./array/ft_arraypush.c \
		./array/ft_arraylen.c \
		./array/ft_arraypop.c \
		./array/ft_arrayfree.c \
		./files/ft_gnl.c \
		./files/ft_gnl_utils.c \
		./convertions/ft_atoi.c \
		./convertions/ft_itoa.c \
		./memory/ft_memset.c \
		./memory/ft_memmove.c \
		./memory/ft_realloc.c \
		./memory/ft_memcpy.c \
		./memory/ft_bzero.c \
		./memory/ft_memcmp.c \
		./memory/ft_memchr.c \
		./memory/ft_calloc.c \
		./strings/ft_strinsert.c \
		./strings/ft_strpush.c \
		./strings/ft_strmapi.c \
		./strings/ft_strncmp.c \
		./strings/ft_strmerge.c \
		./strings/ft_strnstr.c \
		./strings/ft_strchr.c \
		./strings/ft_striteri.c \
		./strings/ft_strlcat.c \
		./strings/ft_strlcpy.c \
		./strings/ft_strlen.c \
		./strings/ft_strrchr.c \
		./strings/ft_tolower.c \
		./strings/ft_strtrim.c \
		./strings/ft_split.c \
		./strings/ft_strpop.c \
		./strings/ft_strdup.c \
		./strings/ft_strjoin.c \
		./strings/ft_strcpy.c \
		./strings/ft_strchecks.c \
		./strings/ft_substr.c \
		./strings/ft_toupper.c \
		./checkers/ft_isascii.c \
		./checkers/ft_isdigit.c \
		./checkers/ft_isspace.c \
		./checkers/ft_isalpha.c \
		./checkers/ft_isalnum.c \
		./checkers/ft_isprint.c \
		./lists/ft_lstiter.c \
		./lists/ft_lstadd_back.c \
		./lists/ft_lstadd_front.c \
		./lists/ft_lstmap.c \
		./lists/ft_lstnew.c \
		./lists/ft_lstsize.c \
		./lists/ft_lstclear.c \
		./lists/ft_lstlast.c \
		./lists/ft_lstdelone.c \
		./io/ft_putchar_fd.c \
		./io/ft_putendl_fd.c \
		./io/ft_putstr_fd.c \
		./io/ft_putnbr_fd.c

#----- Objects -----
OBJS=$(SRCS:.c=.o)

#----- Objects (SMK) -----
SMK_OBJS_DIR=objs
SMK_OBJS=$(addprefix ./$(SMK_OBJS_DIR)/, $(notdir $(OBJS)))
VPATH = $(sort $(dir $(SRCS)))



#--------------------------------------------------
#              DEPENDENCIES (LIBS)
#--------------------------------------------------

#----- Common -----
DEPS_LIST=
DEPS_CALLS=


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
all: $(PNAME)

$(PNAME): $(SMK_OBJS_DIR)/ $(SMK_OBJS)
	$(eval NB_BARPOS := $(AMK_NB_FILES))
	$(call init_bar)
	$(call next_bar)
	@$(LIB_CMD) $(LIB_CMD_FLAGS) $@ $(SMK_OBJS)
	$(call final_bar)
	@printf "\n\033[s"

$(SMK_OBJS_DIR)/%.o: %.c
	$(call init_bar)
	$(call next_bar)
	@$(CPL) $(CPL_FLAGS) -I./ -c $< -o $@
	@sleep 0.000000

#----- Libs Rules -----


#--------------------------------------------------
#                CLEANING RULES
#--------------------------------------------------
clean:
	@printf "%-101s\033[s[\033[1m\033[33mWORKING\033[0m]" "$$(printf "[\033[1m\033[34mMAKEFILE\033[0m - \033[1m\033[36mClean\033[0m]: Cleaning object files")"
	@rm $(RM_FLAGS) $(SMK_OBJS)
	@printf "\033[u[\033[1m\033[34mOK\033[0m]        \n\033[s"

fclean: clean
	@printf "%-101s\033[s[\033[1m\033[33mWORKING\033[0m]" "$$(printf "[\033[1m\033[34mMAKEFILE\033[0m - \033[1m\033[36mFclean\033[0m]: Removing all generated files")"
	@rm $(RM_FLAGS) $(PNAME)
	@printf "\033[u[\033[1m\033[34mOK\033[0m]        \n\033[s"
	@printf "%-101s\033[s[\033[1m\033[33mWORKING\033[0m]" "$$(printf "[\033[1m\033[34mMAKEFILE\033[0m - \033[1m\033[36mFclean\033[0m]: Removing object folder")"
	@rm $(SMK_RM_FLAGS) $(SMK_OBJS_DIR)/
	@printf "\033[u[\033[1m\033[34mOK\033[0m]        \n\033[s"


#--------------------------------------------------
#                EXTRA RULES
#--------------------------------------------------
$(SMK_OBJS_DIR)/:
	@printf "%-101s\033[s[\033[1m\033[33mWORKING\033[0m]" "$$(printf "[\033[1m\033[34mMAKEFILE\033[0m - \033[1m\033[36mExtra\033[0m]: Creating object folder")"
	@mkdir $(SMK_OBJS_DIR)/
	@printf "\033[u[\033[1m\033[34mOK\033[0m]        \n\033[s"

re: fclean all

.phony: all clean fclean re
