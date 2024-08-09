.SUFFIXES : .o .c .cpp

AUTOREPLYPRINT_DIR ?= ../autoreplyprint
ifeq ($(AUTOREPLYPRINT_ARCH),)
	ifeq ($(shell uname), Darwin)
		AUTOREPLYPRINT_ARCH=mac
	else
		ifeq ($(shell uname -m), x86_64)
			AUTOREPLYPRINT_ARCH=linux-x64
		else
			AUTOREPLYPRINT_ARCH=linux-x86
		endif
	endif
endif
ifeq ($(AUTOREPLYPRINT_LINKTYPE),)
	AUTOREPLYPRINT_LINKTYPE=staticlib
endif
AUTOREPLYPRINT_LINK_DIR=$(AUTOREPLYPRINT_DIR)/$(AUTOREPLYPRINT_LINKTYPE)/$(AUTOREPLYPRINT_ARCH)

CXX ?= g++
CXXFLAGS = -I$(AUTOREPLYPRINT_LINK_DIR)
LDFLAGS	= -L$(AUTOREPLYPRINT_LINK_DIR) -lautoreplyprint -lstdc++ -lm -pthread

SRCS	= main.cpp cmdtestfunction.cpp cmdtestutils.cpp cmdtestunit.cpp

TARGET	= samplelabel_withoutautoreply

all: clean
	$(CXX) -o $(TARGET) $(CXXFLAGS) $(SRCS) $(LDFLAGS) 

clean:
	rm -f *.o 
	rm -f $(TARGET)

