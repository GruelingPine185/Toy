# Optimisation Options
# export CFLAGS+=-O2 -mtune=native -march=native

export TOY_OUTDIR = out

all: $(TOY_OUTDIR) repl

#repl builds
repl: $(TOY_OUTDIR) library
	$(MAKE) -C repl

repl-static: $(TOY_OUTDIR) static
	$(MAKE) -C repl

repl-release: clean $(TOY_OUTDIR) library-release
	$(MAKE) -C repl release

repl-static-release: clean $(TOY_OUTDIR) static-release
	$(MAKE) -C repl release

#lib builds
library: $(TOY_OUTDIR)
	$(MAKE) -j8 -C source library

static: $(TOY_OUTDIR)
	$(MAKE) -j8 -C source static

library-release: $(TOY_OUTDIR)
	$(MAKE) -j8 -C source library-release

static-release: $(TOY_OUTDIR)
	$(MAKE) -j8 -C source static-release

#utils
test: clean $(TOY_OUTDIR)
	$(MAKE) -C test

$(TOY_OUTDIR):
	mkdir $(TOY_OUTDIR)

#utils
install-tools:
	cp -rf tools/toylang.vscode-highlighting ~/.vscode/extensions

.PHONY: clean

clean:
ifeq ($(findstring CYGWIN, $(shell uname)),CYGWIN)
	find . -type f -name '*.o' -exec rm -f -r -v {} \;
	find . -type f -name '*.a' -exec rm -f -r -v {} \;
	find . -type f -name '*.exe' -exec rm -f -r -v {} \;
	find . -type f -name '*.dll' -exec rm -f -r -v {} \;
	find . -type f -name '*.lib' -exec rm -f -r -v {} \;
	find . -type f -name '*.so' -exec rm -f -r -v {} \;
	find . -empty -type d -delete
else ifeq ($(shell uname),Linux)
	find . -type f -name '*.o' -exec rm -f -r -v {} \;
	find . -type f -name '*.a' -exec rm -f -r -v {} \;
	find . -type f -name '*.exe' -exec rm -f -r -v {} \;
	find . -type f -name '*.dll' -exec rm -f -r -v {} \;
	find . -type f -name '*.lib' -exec rm -f -r -v {} \;
	find . -type f -name '*.so' -exec rm -f -r -v {} \;
	rm -rf out
	find . -empty -type d -delete
else ifeq ($(OS),Windows_NT)
	$(RM) *.o *.a *.exe 
else ifeq ($(shell uname),Darwin)
	find . -type f -name '*.o' -exec rm -f -r -v {} \;
	find . -type f -name '*.a' -exec rm -f -r -v {} \;
	find . -type f -name '*.exe' -exec rm -f -r -v {} \;
	find . -type f -name '*.dll' -exec rm -f -r -v {} \;
	find . -type f -name '*.lib' -exec rm -f -r -v {} \;
	find . -type f -name '*.dylib' -exec rm -f -r -v {} \;
	find . -type f -name '*.so' -exec rm -f -r -v {} \;
	rm -rf out
	find . -empty -type d -delete
else
	@echo "Deletion failed - what platform is this?"
endif

rebuild: clean all
