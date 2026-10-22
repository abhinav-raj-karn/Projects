CC      := gcc
CFLAGS  := -std=c11 -O2 -Wall -Wextra
LDLIBS  := -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

TARGET  := graphics
RAYLIB  := vendor/raylib/src/libraylib.a
CPPFLAGS := -Ivendor/raylib/src

all: $(TARGET)

$(TARGET): main.c $(RAYLIB)
	$(CC) $(CFLAGS) $(CPPFLAGS) main.c -o $@ -Lvendor/raylib/src $(LDLIBS)

$(RAYLIB):
	@mkdir -p vendor
	git clone --depth 1 --branch 5.5 https://github.com/raysan5/raylib.git vendor/raylib
	$(MAKE) -C vendor/raylib/src PLATFORM=PLATFORM_DESKTOP

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)

distclean: clean
	rm -rf vendor/raylib

.PHONY: all run clean distclean
