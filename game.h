
#ifndef GAME_H
#define GAME_H

#include <bits/stdc++.h>
#include <SDL.h>
#include <SDL_image.h>
#include <vector>
using namespace std;

void ClassicMode(SDL_Renderer* renderer, SDL_Texture* texture1, SDL_Rect SourceRect1, SDL_Rect desRect1, SDL_Texture* texture3, SDL_Rect SourceRect3, SDL_Rect desRect3);

void BoxMode(SDL_Renderer* renderer, SDL_Texture* texture1, SDL_Rect SourceRect1, SDL_Rect desRect1, SDL_Texture* texture3, SDL_Rect SourceRect3, SDL_Rect desRect3);

void MenurunningOrGamemode(SDL_Renderer* renderer, SDL_Texture* texture2, SDL_Rect SourceRect2, SDL_Rect desRect2);

#endif // GAME_H
