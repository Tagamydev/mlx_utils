COMMIT_D := $(shell date)
COMMIT_U := ${USER}

all:
	cp .TODO .TODO.tmp
	sed -i '1s/^/$(COMMIT_D) by $(COMMIT_U)\n/' .TODO.tmp
