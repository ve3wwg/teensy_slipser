######################################################################
#  teensy3_lib/teensy3/slipser/Makefile
#  Warren Gay ve3wwg	Mon May 19 16:58:14 2014
#
# This Makefile is intended to be used as part of the teensy3_lib
# project. No Makefile is required for Arduino IDE use.
######################################################################

include $(CURDIR)/../../Makefile.conf

CXX_FILES 	:= $(wildcard *.cpp)
OBJS 		:= $(CXX_FILES:.cpp=.o) 

all:	$(LIB_DIR)/libslipser.a

$(LIB_DIR)/libslipser.a: $(OBJS)
	@rm -f $(LIB_DIR)/libslipser.a
	$(AR) cr $(LIB_DIR)/libslipser.a $(OBJS)

clean:
	rm -f *.o

distclean: clean
	rm -f libslipser.a $(LIB_DIR)/libslipser.a *.d

# End teensy3/teensy3/slip/Makefile.teensy
