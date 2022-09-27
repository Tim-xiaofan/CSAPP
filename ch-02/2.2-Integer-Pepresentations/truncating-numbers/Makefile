# binary name
APP = truncate

# all source are stored in SRCS-y
SRCS-y := main.cpp


# Add flag 
CPPFLAGS += -g -Wall -std=c++11

$(APP): $(SRCS-y) Makefile 
	$(CXX) $(CPPFLAGS) $(SRCS-y) -o $@


.PHONY: clean
clean:
	rm -f *.o
	rm -f *.exe
	rm -f $(APP)
