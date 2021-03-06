targets	:= maze_maker
objs	:= maze_maker.o room.o

CC	:= g++
CFLAGS	:= -Wall -Wextra -Werror
CFLAGS	+= -g

ifneq ($(V),1)
Q = @
endif

all: $(targets)

deps := $(patsubst %.o,%.d,$(objs))
-include $(deps)
DEPFLAGS = -MMD -MF $(@:.o=.d)

maze_maker: $(objs)
	@echo "CC   $@"
	$(Q)$(CC) $(CFLAGS) -o $@ $^

%.o: %.cpp
	@echo "CC   $@"
	$(Q)$(CC) $(CFLAGS) -c -o $@ $< $(DEPFLAGS)

clean:
	@echo "CLEAN"
	$(Q)rm -f $(targets) $(objs) $(deps)
