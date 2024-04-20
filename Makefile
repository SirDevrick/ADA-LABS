##
# iSort Plot
#
# @file
# @version 0.1

all: compile usePipes

compile:
	gcc InsertionSort.c -o Isort && gcc GenData.c -o genData

usePipes:
	./genData ${NUM} | ./Isort

# end
