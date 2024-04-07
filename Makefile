## build Histogram
## jbs - paragonsoft
## 06 Apr 2024 15:55

all: histo

histo: histogram.c
	cc -o histo histogram.c -lm
clean:
	rm histo
