SRCDIR = ./src
INCDIR = ./include
OBJDIR = ./build
BINDIR = ./bin

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

main: $(OBJ)
	@echo "MAKING..."
	$(CXX) $(CXXFLAGS) -o $@ $^
	$(BINDIR)/$@

$(OBJDIR)/%.$(OBJEXT): $(SRCDIR)/%.$(SRCEXT) $(INCDIR)/%.$(INCEXT)
	@echo "COMPILING... "
	$(CXX) $(CXXFLAGS) $< -o $@

test: $(wildcard bin/*)
	@echo "Done"

clear:
	clear

clean:
	rm bin/*
