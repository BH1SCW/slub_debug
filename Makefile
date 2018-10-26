
BASEINCLUDE ?= /usr/local/linux-4.0
slub-objs := slub_test.o mem_layout.o
obj-m := slub.o

all :
	$(MAKE) -C $(BASEINCLUDE) SUBDIRS=$(PWD) modules;

clean:
	$(MAKE) -C $(BASEINCLUDE) SUBDIRS=$(PWD) modules;
	rm -f *.ko;
