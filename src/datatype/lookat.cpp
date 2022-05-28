#include "../include/datatype/lookat.h"

Lookat::Lookat(){}

Lookat::Lookat(Vector3 look_from, Vector3 look_at, Vector3 vup) {
    this->look_from = look_from;
    this->look_at = look_at;
    this->vup = vup;
}

Lookat::~Lookat() {}

