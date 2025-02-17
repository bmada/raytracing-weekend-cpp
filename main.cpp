#include <iostream>
#include <ranges>


void update_progress_bar(float progress, int bar_width = 30) {
    // ANSI escape codes for colors
    const char* green = "\033[32m";
    const char* blue = "\033[34m";
    const char* reset = "\033[0m";
    
    // Unicode block characters for smoother bar
    const char* full_block = "█";
    const char* light_shade = "▓";
    const char* medium_shade = "▒";
    
    int pos = bar_width * progress;
    
    // Current time processing info (simulating pip's style)
    std::clog << "\r" << blue << "Processing " << reset;
    std::clog << "|" << green;
    
    for (int i = 0; i < bar_width; ++i) {
        if (i < pos) std::clog << full_block;
        else if (i == pos) std::clog << medium_shade;
        else std::clog << " ";
    }
    
    std::clog << reset << "| " << int(progress * 100.0) << "% ";
    
    // Clear the rest of the line
    std::clog << "\033[K" << std::flush;
}


int main() {
    // image
    int image_width = 256;
    int image_height = 256;

    // render
    std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

    for (int j : std::ranges::iota_view(0, image_width)) {
        update_progress_bar(float(j) / (image_width - 1));
        for (int i : std::ranges::iota_view(0, image_height)) {
            auto r = double(i) / (image_width - 1);
            auto g = double(j) / (image_height - 1);
            auto b = 0.0;

            int ir = int(255.999 * r);
            int ig = int(255.999 * g);
            int ib = int(255.999 * b);

            std::cout << ir << ' ' << ig << ' ' << ib << '\n';
        }
    }
}


