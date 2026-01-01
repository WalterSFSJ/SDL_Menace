#pragma once
#include <vector>
#include <string>
#include "TextObject.h"
#include "RenderManager.h"

class HUD {
private:
    TextObject* _score;
    TextObject* _scoreValue;
    SDL_Texture* _lifeTexture;
    int _numLives;
    Vector2 _pos;

public:
    HUD(Vector2 position) : _pos(position), _numLives(3) {
        _score = new TextObject("SCORE:", { position.x, position.y });
        _score->GetRenderer()->SetColor({ 255, 255, 255, 255 });

        _scoreValue = new TextObject("000000", { position.x + 120, position.y });

        _lifeTexture = RM->GetTexture("resources/images/ship.png");
    }

    ~HUD() {
        delete _score;
        delete _scoreValue;
    }

    void UpdateScore(int newScore) {
        // siempre hay 6 digitos en el _scoreValue
        std::string digits = std::to_string(newScore);
        _scoreValue->SetText(std::string(6 - digits.length(), '0') + digits);
    }

    void SetLives(int lives) { _numLives = lives; }

    void Update(float dt) {
        _score->Update();
        _scoreValue->Update();
    }

    void Render() {
        _score->Render();
        _scoreValue->Render();

        for (int i = 0; i < _numLives; ++i) {
            SDL_FRect dest = { _pos.x + (i * 35), _pos.y + 40, 30, 30 };
            SDL_RenderTexture(RM->GetRenderer(), _lifeTexture, nullptr, &dest);
        }
    }
};