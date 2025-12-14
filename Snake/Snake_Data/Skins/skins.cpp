#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <iostream>


// Function to load and manage skins
class SkinsManager {
private:
    std::vector<sf::Texture> skins;
    int currentSkinIndex;

public:
    SkinsManager() : currentSkinIndex(0) {}

    // Load a skin from a file
    bool loadSkin(const std::string& filePath) {
        sf::Texture texture;
        if (!texture.loadFromFile(filePath)) {
            std::cerr << "Error: Could not load skin from " << filePath << std::endl;
            return false;
        }
        skins.push_back(texture);
        return true;
    }

    // Get the current skin
    const sf::Texture& getCurrentSkin() const {
        return skins[currentSkinIndex];
    }

    // Switch to the next skin
    void nextSkin() {
        if (!skins.empty()) {
            currentSkinIndex = (currentSkinIndex + 1) % skins.size();
        }
    }

    // Switch to the previous skin
    void previousSkin() {
        if (!skins.empty()) {
            currentSkinIndex = (currentSkinIndex - 1 + skins.size()) % skins.size();
        }
    }

    // Check if skins are loaded
    bool hasSkins() const {
        return !skins.empty();
    }
};

int main() {
    SkinsManager skinsManager;

    // Load skins
    skinsManager.loadSkin("skins/skin1.png");
    skinsManager.loadSkin("skins/skin2.png");
    skinsManager.loadSkin("skins/skin3.png");

    if (!skinsManager.hasSkins()) {
        std::cerr << "No skins loaded. Exiting..." << std::endl;
        return 1;
    }

    std::cout << "Use LEFT and RIGHT arrow keys to choose a skin. Press ENTER to confirm." << std::endl;

    bool choosing = true;
    while (choosing) {
        // Display the current skin index
        std::cout << "Current Skin: " << (skinsManager.getCurrentSkinIndex() + 1) << "/" << skinsManager.getSkinsCount() << std::endl;

        // Wait for user input
        char input = _getch(); // Get a single character input
        switch (input) {
            case 75: // LEFT arrow key
                skinsManager.previousSkin();
                break;
            case 77: // RIGHT arrow key
                skinsManager.nextSkin();
                break;
            case 13: // ENTER key
                choosing = false; // Confirm selection
                break;
            default:
                std::cout << "Invalid input. Use LEFT/RIGHT to navigate, ENTER to confirm." << std::endl;
        }
    }

    std::cout << "Skin selected! Starting the game..." << std::endl;

    // Use the selected skin in the game
    // For example, apply the texture to the snake or other game elements

    return 0;
}
