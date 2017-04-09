CC = g++
CFLAGS  = -g -Wall
TARGET = caesar
DEST = /usr/local/bin
all: $(TARGET)
$(TARGET): $(TARGET).cpp
	# Creating binary...
		$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).cpp

install:
	# Copying $(TARGET) to $(DEST)...
	cp $(TARGET) $(DEST)

clean:
	# Removing $(TARGET)
	$(RM) $(TARGET)
