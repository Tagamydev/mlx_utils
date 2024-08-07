COMMIT_M := $(shell date)
COMMIT_D := $(shell cat .TODO)

all:
	echo $(COMMIT_M)
	git commit -m "$(COMMIT_M)" -m 
