#pragma once
#ifndef BASEOBJECT_H_INCLUDED
#define BASEOBJECT_H_INCLUDED

#include <memory>
class Application;
class RenderEngine;

class StateBase {
public:
    StateBase(Application& application) : application(application) {}
    virtual void init() = 0;
    virtual void handleInput() = 0;
    virtual void update(float dt) = 0;
    virtual void render(RenderEngine& render_engine) = 0;
    virtual ~StateBase() = default;
protected:
    Application& application;
};

#endif