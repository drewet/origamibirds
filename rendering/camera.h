/**
Todo: http://hamelot.co.uk/visualization/moderngl-camera/
**/

#ifndef CAMERA_H
#define CAMERA_H

#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtx/quaternion.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "../core/input.h"

class Camera {

    public:

        Camera(float fov, float aspect, float zNear, float zFar);

        inline glm::vec3& getPosiiton() { return m_position; }
        inline glm::vec3& getDirection() { return m_direction; }
        inline glm::vec3& getUp() { return m_up; }

        inline glm::mat4 getView() { return glm::lookAt(m_position, m_position + m_direction, m_up); }
        inline glm::mat4 getProjection() { return m_perspective; }

        inline void setPositon(const glm::vec3& position) { m_position = position; }
        inline void setDirection(const glm::vec3& direction) { m_direction = direction; }
        inline void setUp(const glm::vec3& up) { m_up = up; }


        inline glm::mat4 getViewProjection() const {
            return m_perspective * glm::lookAt(m_position, m_position + m_direction, m_up);
        }

        void moveForward();
        void moveBackward();
        void lookLeft();
        void lookRight();
        void moveDown();
        void moveUp();

        void update();

        virtual ~Camera() {}

    protected:

    private:
        glm::mat4 m_perspective;
        glm::vec3 m_position;
        glm::vec3 m_direction;
        glm::vec3 m_up;

        float MOVEMENT_SPEED;
};

#endif // CAMERA_H
