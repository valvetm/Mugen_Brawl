﻿#pragma once
#include "cCharacterEventHandler.h"

class cCharacter : public cComponent, Serializer, cCharacterEventHandler
{
public:
    void Init() override;
    void Update() override;
    void Render() override;
    void Release() override;
    void OnCollision(cObject* _other) override;
    void OnAlarm(std::string _key) override;

    void OnHurt(cCharacter* _by, cHurtBox* _myHurtBox, cHitBox* _enemyHitBox, RECT _overlappedRect) override;
    void OnHit(cCharacter* _to, cHurtBox* _enemyHurtBox, cHitBox* _myHitBox, RECT _overlappedRect) override;
    void OnThrew(cCharacter* _by, cBodyBox* _myBodyBox, cThrowBox* _enemyThrowBox, RECT _overlappedRect) override;
    void OnThrow(cCharacter* _to, cThrowBox* _myThrowBox, cBodyBox* _enemyBodyBox, RECT _overlappedRect) override;
    void OnCollisionWithCharacter(cCharacter* _with, RECT _overlappedRect) override;
    void OnCollisionWithMap(cCharacter* _with, RECT _overlappedRect) override;

    void HandleAnimationEvent(std::string _eventKey) override;
    void HandleSpriteEvent(std::string _eventKey) override;
    void HandleHurtBoxEvent(std::string _eventKey) override;
    void HandleHitBoxEvent(std::string _eventKey) override;
    void HandleThrowBoxEvent(std::string _eventKey) override;
    void HandleBodyBoxEvent(std::string _eventKey) override;

    void Serialize(char* _buffer, UINT& _pointer) const override;
    void Deserialize(char* _buffer, UINT& _pointer) override;
    size_t GetSize() const override;

private:
    cCharacterData* m_Data;
    int m_Flag;
    Vec2 m_Velocity;
    Vec2 m_Friction;
};
