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

#puzzle=0
.PHONY:answer
ifdef puzzle
answer:
	@$(EXE) -d $(day) -p $(puzzle) || echo "usage: make day=X puzzle=Y"
else
answer:
	@$(EXE) -d $(day) -p 1
	@$(EXE) -d $(day) -p 2
endif

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