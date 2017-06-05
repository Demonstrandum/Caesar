CC = g++
CFLAGS  = -g -Wall -O3
TARGET = caesar
DEST = /usr/local/bin
all: $(TARGET)
$(TARGET): $(TARGET).cpp
	@echo "Compiling $(TARGET).cpp..."
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).cpp

install:
	@echo "Copying $(TARGET) to $(DEST)..."
	cp $(TARGET) $(DEST)

clean:
	@echo "Removing '$(TARGET)' binary from current directory"
	rm -f $(TARGET)

uninstall:
	@echo "Removing binary from $(DEST)"
	rm -f $(DEST)/$(TARGET)
