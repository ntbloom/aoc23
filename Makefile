OUTDIR=$(PWD)/build

.PHONY:_cmake
_cmake:
	cmake -B$(OUTDIR) -DCMAKE_BUILD_TYPE=Debug -G "Unix Makefiles"

.PHONY:_build
_build:
	make -C $(OUTDIR) -j 8

.PHONY:clean
clean:
	rm -rf $(OUTDIR)

.PHONY:build
build: _cmake _build

.PHONY:test
test:
	$(OUTDIR)/mainTest

.DEFAULT_GOAL:= build