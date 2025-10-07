# Makefile for compiling and running a single C++ file
# Usage: make filename=program.cpp        -> just build
#        make run filename=program.cpp    -> build and run

CXX = g++
CXXFLAGS = -Wall -O2

# Output directory for executables
OUTDIR = ./out

# Strip .cpp extension to get executable name, then put in OUTDIR
TARGET = $(OUTDIR)/$(basename $(filename))

all: $(TARGET)

# Rule: compile the source into the output folder
$(TARGET): $(filename)
	@mkdir -p $(OUTDIR)
	$(CXX) $(CXXFLAGS) $< -o $@

run: $(TARGET)
	$(TARGET)

clean:
	rm -f $(OUTDIR)/*
