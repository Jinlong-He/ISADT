TARGET=libtest.a

# subdirs
SUBDIRS=$(foreach dir,$(shell find . -mindepth 1 -type d),$(shell echo $(dir) ' '))


# objs
ALL_OBJS = $(subst .cpp,.o,$(foreach dir,$(SUBDIRS),$(wildcard $(dir)/*.cpp)))


all: subdirs $(TARGET)
	mv $(TARGET) $(DISTDIR)

subdirs:
	@for i in $(SUBDIRS); do \
		echo "===> $$i"; \
		(cd $$i && $(MAKE) -f $(MAKEFILE)) || exit 1; \
		echo "<=== $$i"; \
	done

$(TARGET):$(ALL_OBJS)
	ar -r $@ $^

.PHONY:clean
clean:
	@for i in $(SUBDIRS); do \
		echo "===> $$i"; \
		(cd $$i && $(MAKE) clean -f $(MAKEFILE)) || exit 1; \
		echo "<=== $$i"; \
	done
	rm -f $(DISTDIR)/$(TARGET)
