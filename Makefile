SRCDIR = ./src
INCDIR = ./include
OBJDIR = ./bin

SRCEXT = cpp
INCEXT = h
OBJEXT = o

VARS = SRC INC

$(foreach VAR,$(VARS),\
	$(eval $(VAR) := $(shell\
		find $($(VAR)DIR) -name "*.$($(VAR)EXT)")))

OBJ = $(patsubst $(SRCDIR)/%.$(SRCEXT),$(OBJDIR)/%.$(OBJEXT),$(SRC))

CXX = g++
CXXFLAGS = -std=c++17 -Wall -I $(INCDIR)

all: clear $(OBJ)
	@echo "MAKING..."
	./bin/main.o

$(OBJDIR)/%.$(OBJEXT): $(SRCDIR)/%.$(SRCEXT) $(INC)
	@echo "COMPILING... "
	$(CXX) $(CXXFLAGS) $< -o $@

clear:
	clear

clean:
	rm bin/*
