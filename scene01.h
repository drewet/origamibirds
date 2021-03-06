#ifndef SCENE01_H
#define SCENE01_H

#include "core/scene.h"

class Scene01 : public Scene
{
    public:
        Scene01() {}

        void init(const Window& window);
        void update(float delta);

        virtual ~Scene01() {}
};

#endif // SCENE01_H
