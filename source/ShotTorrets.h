#pragma once
#include "Object.h"
#include "Vector2.h"

class ShotTorrets : public Object {
private:
    float _actualRotation = 0.0f;
    float _lastPosX = 0.0f;
    float _distance = 0.0f;
    float _lateral = 40.0f; 
    bool _isActivate = false;

public:
    ShotTorrets() : _lastPosX(0), _distance(0), _isActivate(false) {}

    void SetActiva(bool estado) { _isActivate = estado; }

    // Se llama desde el Update de la nave (Ship)
    void UpdateLogic(Vector2 playerPos) {
        if (!_isActivate) return;

        float deltaX = playerPos.x - _lastPosX;
        _distance += std::abs(deltaX);

        if (_distance >= 100.0f) {
            if (deltaX > 0) _actualRotation -= 45.0f;
            else if (deltaX < 0) _actualRotation += 45.0f;

            _distance -= 100.0f;
        }
        _lastPosX = playerPos.x;

        // Torreta 1 (Izquierda): playerPos.x - _lateral
        // Torreta 2 (Derecha): playerPos.x + _lateral
    }

    void Disparar() {
        if (!_isActivate) return;
        // Lógica para instanciar balas con _rotacionActual
    }
};