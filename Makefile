OUTDIR=$(PWD)/build

.PHONY:_cmake
_cmake:
	cmake -B$(OUTDIR) -DCMAKE_BUILD_TYPE=Debug -G "Unix Makefiles"

.PHONY:_build
_build:
	make -C $(OUTDIR)

.PHONY:clean
clean:
	rm -rf $(OUTDIR)

build: _cmake _build

.DEFAULT_GOAL:= build