CXX = g++
CXXFLAGS = -I./GanedenEngine/src -I./GanedenEngine/vendor/spdlog/include -DGE_BUILD_DLL -std=c++11
LDFLAGS = 
SRC_DIR = Sandbox/src
ENGINE_DIR = GanedenEngine/src
VENDOR_DIR = GanedenEngine/vendor
BUILD_DIR = build

SOURCES = $(SRC_DIR)/SandBoxApp.cpp $(ENGINE_DIR)/Ganeden/Application.cpp $(ENGINE_DIR)/Ganeden/Log.cpp
OBJECTS = $(SOURCES:%.cpp=$(BUILD_DIR)/%.o)
EXECUTABLE = sandboxapp


all: 
	@$(MAKE) loud -s

loud: $(BUILD_DIR) $(EXECUTABLE)
	-./$(EXECUTABLE)
	$(MAKE) clean

compile: $(BUILD_DIR) $(EXECUTABLE)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)/$(SRC_DIR)
	mkdir -p $(BUILD_DIR)/$(ENGINE_DIR)/Ganeden

$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $@ $(LDFLAGS)

$(BUILD_DIR)/%.o: %.cpp
	mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR) $(EXECUTABLE)

.PHONY: all clean compile loud
