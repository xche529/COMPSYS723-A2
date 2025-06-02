# Makefile

# 1. Name of your Esterel source (without extension):
EST_SRC = cruiseControl.strl

# 2. Name of the generated C file (compiler will do this):
EST_C   = cruiseControl.c

# 3. Name of the final XES executable:
EST_XES = cruiseControl.xes

# 4. The C file you must link (given by assignment):
CRUISE_C = cruiseregulation.c

# 5. Compiler flags for C (adjust include/lib paths if your installation is elsewhere):
CC      = gcc
CFLAGS  = -I/usr/local/esterel/include   # adjust to your actual Esterel‐install path
LDFLAGS = -L/usr/local/esterel/lib        # ditto

# 6. Esterel compiler command (eslc or whatever your environment uses):
ESLC    = eslc   # in many Auckland labs, "eslc" is the command

# ========== Targets ==========

all: $(EST_XES)

# 1) Generate .c from .strl, then compile/link with cruiseregulation.c
$(EST_XES): $(EST_SRC) $(CRUISE_C)
	@echo "=== Compiling Esterel ($<) into C …"
	$(ESLC) -c -o $(EST_C) $(EST_SRC)
	@echo "=== Linking with C code ($(CRUISE_C)) to produce $@ …"
	$(CC) $(CFLAGS) -o $(EST_XES) $(EST_C) $(CRUISE_C) $(LDFLAGS) -lesterel

# 2) Clean up intermediate files
clean:
	rm -f $(EST_C) $(EST_XES)

# 3) Run the simulator (XES)
simulate: $(EST_XES)
	@echo "=== Running simulator: ./${EST_XES} ==="
	./$(EST_XES)

.PHONY: all clean simulate
