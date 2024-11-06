# Project name and output directory
OUT_DIR = dist
OUT = $(OUT_DIR)/fc-templates
APP_BUNDLE = $(OUT_DIR)/fc-templates.app
CONTENTS_DIR = $(APP_BUNDLE)/Contents
MACOS_DIR = $(CONTENTS_DIR)/MacOS
RESOURCES_DIR = $(CONTENTS_DIR)/Resources

# Compiler and linker options
CXX = g++
CXXFLAGS = -std=c++20 -Iinclude

# Default build mode (debug or release)
BUILD = debug

# Platform-specific configuration
UNAME_S := $(shell uname -s)

ifeq ($(UNAME_S), Darwin)          # macOS
    CXXFLAGS += -I/opt/homebrew/include
    LDFLAGS = -L/opt/homebrew/lib -lraylib -framework OpenGL -framework Cocoa -framework IOKit
endif

# Source and output
SRC = src/main.cpp
LOGO = logo.png

# Build commands
all: $(OUT_DIR) $(BUILD)

# Create output directory
$(OUT_DIR):
	mkdir -p $(OUT_DIR)

# Create macOS app bundle for release builds
release: $(OUT_DIR)
	# Create the necessary directories
	mkdir -p $(MACOS_DIR)
	mkdir -p $(RESOURCES_DIR)

	# Compile the application
	$(CXX) $(CXXFLAGS) -O3 $(SRC) $(LDFLAGS) -o $(MACOS_DIR)/fc-templates

	# Copy logo.png to the Resources folder
	cp $(LOGO) $(RESOURCES_DIR)/logo.png

	# Create Info.plist and link the icon
	echo "<?xml version=\"1.0\" encoding=\"UTF-8\"?>" > $(CONTENTS_DIR)/Info.plist
	echo "<plist version=\"1.0\">" >> $(CONTENTS_DIR)/Info.plist
	echo "<dict>" >> $(CONTENTS_DIR)/Info.plist
	echo "  <key>CFBundleExecutable</key>" >> $(CONTENTS_DIR)/Info.plist
	echo "  <string>fc-templates</string>" >> $(CONTENTS_DIR)/Info.plist
	echo "  <key>CFBundleIdentifier</key>" >> $(CONTENTS_DIR)/Info.plist
	echo "  <string>com.example.fc-templates</string>" >> $(CONTENTS_DIR)/Info.plist
	echo "  <key>CFBundleName</key>" >> $(CONTENTS_DIR)/Info.plist
	echo "  <string>fc-templates</string>" >> $(CONTENTS_DIR)/Info.plist
	echo "  <key>CFBundleIconFile</key>" >> $(CONTENTS_DIR)/Info.plist
	echo "  <string>logo.png</string>" >> $(CONTENTS_DIR)/Info.plist
	echo "</dict>" >> $(CONTENTS_DIR)/Info.plist
	echo "</plist>" >> $(CONTENTS_DIR)/Info.plist

# Debug target (standard executable)
debug: $(OUT_DIR)
	$(CXX) $(CXXFLAGS) -g $(SRC) $(LDFLAGS) -o $(OUT)

# Clean command
clean:
	rm -rf $(OUT_DIR)
