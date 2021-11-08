Makefile:;

makefile_path := $(abspath $(lastword $(MAKEFILE_LIST)))
makefile_dir := $(dir $(makefile_path))


.PHONY: %

%: 
	$(MAKE) -j8 -C $(makefile_dir) -f makefile_cm4 $@
	$(MAKE) -j8 -C $(makefile_dir) -f makefile_cm7 $@
