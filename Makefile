# based on the article at
# http://hiltmon.com/blog/2013/07/03/a-simple-c-plus-plus-project-structure/

TARGET    := gol
TARGETDIR := bin

CC     := g++
CFLAGS := -std=c++11 -g
INC    := -I include

SRCDIR   := src
SRCEXT   := cpp
BUILDDIR := build

SOURCES := $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
OBJECTS := $(patsubst $(SRCDIR)/%, $(BUILDDIR)/%, $(SOURCES:.$(SRCEXT)=.o))


$(TARGETDIR)/$(TARGET): $(OBJECTS)
	@mkdir $(TARGETDIR)
	$(CC) $^ -o $@

$(BUILDDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	@mkdir -p $(BUILDDIR)
	$(CC) $(CFLAGS) $(INC) -c -o $@ $<

clean:
	$(RM) -r $(BUILDDIR) $(TARGETDIR)

.PHONY: clean
