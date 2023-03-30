.PHONY: build

CC = gcc
PLT = gnuplot

build: dist_box.png

pts.txt: main.c
	$(CC) $<
	./a.out

dist_box.png: boxplot.gp pts.txt
	$(PLT) $<

clean:
	rm -rf *.txt *.png
