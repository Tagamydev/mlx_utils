COMMIT_M := $(shell date)

all:
	echo $(COMMIT_M)
	git commit -F .TODO
