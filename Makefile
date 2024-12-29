CXX = g++
CXXFLAGS = -I./GanedenEngine/src -DGE_BUILD_DLL -std=c++11
LDFLAGS = 
SRC_DIR = Sandbox/src
ENGINE_DIR = GanedenEngine/src
BUILD_DIR = build

SOURCES = $(SRC_DIR)/SandBoxApp.cpp $(ENGINE_DIR)/Ganeden/Application.cpp
OBJECTS = $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SOURCES))
EXECUTABLE = sandboxapp

all: $(BUILD_DIR) $(EXECUTABLE)
	./$(EXECUTABLE)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $@ $(LDFLAGS)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BUILD_DIR)/%.o: $(ENGINE_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR) $(EXECUTABLE)

.PHONY: all clean
