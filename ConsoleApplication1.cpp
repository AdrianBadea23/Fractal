#include <numeric>
#include <complex>
#include <SDL.h>

int isInSet(std::complex<double> c) {

    std::complex<double> z(0, 0);

    for (int i = 0; i < 100; i++) {

        z = std::pow(z, 4) + c;
        if (std::norm(z) > 16) {
            return i;
        }

    }

    return 0;

}

void fractal1() {

    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;
    SDL_CreateWindowAndRenderer(1000, 1000, 0, &window, &renderer);

    for (double i = 0.0; i < 1.0; i += 0.001) {
        for (double j = 0.0; j < 1.0; j += 0.001) {

            double point_x = std::lerp(-2.0, 2.0, i);
            double point_y = std::lerp(-2.0, 2.0, j);
            int iterations = isInSet(std::complex<double>(point_x, point_y));
            if (iterations == 0) {
                SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
                SDL_RenderDrawPointF(renderer, i * 1000, j * 1000);
            }
            else {
                SDL_SetRenderDrawColor(renderer, 10 * iterations % 255, 13 * iterations % 255, 15 * iterations % 255, 255);
                SDL_RenderDrawPointF(renderer, i * 1000, j * 1000);
            }

        }
        SDL_RenderPresent(renderer);
    }

    SDL_RenderPresent(renderer);
    SDL_Delay(10000);

}


int isInSet2(std::complex<double> c, int threshold) {

    std::complex<double> z(0, 0);

    for (int i = 0; i < threshold; i++) {

        z = std::pow(z, 4) + c;
        if (std::norm(z) > 16) {
            return i;
        }

    }

    return 0;

}

void fractal2(int frame, SDL_Window* window, SDL_Renderer* renderer) {

    int threshold = floor(std::pow(1.15, (1 + frame)));

    for (double i = 0.0; i < 1.0; i += 0.001) {
        for (double j = 0.0; j < 1.0; j += 0.001) {

            double point_x = std::lerp(-2.0, 2.0, i);
            double point_y = std::lerp(-2.0, 2.0, j);
            int iterations = isInSet2(std::complex<double>(point_x, point_y), threshold);
            if (iterations == 0) {
                SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
                SDL_RenderDrawPointF(renderer, i * 1000, j * 1000);
            }
            else {
                SDL_SetRenderDrawColor(renderer, 10 * iterations % 255, 13 * iterations % 255, 15 * iterations % 255, 255);
                SDL_RenderDrawPointF(renderer, i * 1000, j * 1000);
            }

        }
    }

    SDL_RenderPresent(renderer);

}

int main(int argc, char* args[]) {

    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;
    SDL_CreateWindowAndRenderer(1000, 1000, 0, &window, &renderer);

    //fractal1();

    for (int i = 1; i < 23; i++) {

        fractal2(i, window, renderer);

    }

    SDL_Delay(10000);

    return 0;
}