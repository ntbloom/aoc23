OUTDIR=$(PWD)/build

EXE=$(OUTDIR)/aoc23
TEST_EXE=$(OUTDIR)/mainTest

.PHONY:_cmake
_cmake:
	cmake -B$(OUTDIR) -DCMAKE_BUILD_TYPE=Debug -G "Unix Makefiles"

.PHONY:_build
_build:
	make -C $(OUTDIR) -j 14

.PHONY:clean
clean:
	rm -rf $(OUTDIR)

.PHONY:build
build: _cmake _build

.PHONY:test
test:
	$(OUTDIR)/mainTest

VALGRIND_FLAGS =--leak-check=full
VALGRIND_FLAGS+=--show-leak-kinds=all
VALGRIND_FLAGS+=--track-origins=yes

.PHONY:memcheck
memcheck:
	valgrind $(VALGRIND_FLAGS) $(TEST_EXE)

.DEFAULT_GOAL:= build