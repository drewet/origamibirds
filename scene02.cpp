#include "scene02.h"

#include "scenegraph/meshrenderer.h"
#include "scenegraph/physicsenginecomponent.h"
#include "scenegraph/physicsobjectcomponent.h"
#include "scenegraph/cameracomponent.h"
#include "physics/boundingsphere.h"

void Scene02::init(const Window& window)
{
    Camera camera(50.0f, window.getAspectRatio(), 0.1f, 100.0f);
    CameraComponent* cameraComponent = new CameraComponent(camera);

    PhysicsEngine physicsEngine;
    PhysicsObject physicsObject1(new BoundingSphere(glm::vec3(-1.0, 0.5, -5.0), 0.2f), glm::vec3(0.1f, 0.1f, 0.0f), true);
    PhysicsObject physicsObject2(new BoundingSphere(glm::vec3(-2.0, 0.5, -5.0), 0.2f), glm::vec3(0.1f, 0.1f, 0.0f), true);
    PhysicsObject physicsObject3(new BoundingSphere(glm::vec3(-3.0, 0.5, -5.0), 0.2f), glm::vec3(0.1f, 0.1f, 0.0f), true);
    PhysicsObject physicsObject4(new BoundingSphere(glm::vec3(-4.0, 0.5, -5.0), 0.2f), glm::vec3(0.1f, 0.1f, 0.0f), true);
    PhysicsObject physicsObject5(new BoundingSphere(glm::vec3(-5.0, 0.5, -5.0), 0.2f), glm::vec3(0.1f, 0.1f, 0.0f), true);
    //PhysicsObject physicsObject6(new BoundingSphere(glm::vec3(-6.0, 0.5, -5.0), 0.2f), glm::vec3(0.1f, 0.1f, 0.0f), true);

    //PhysicsObject physicsObject6(new BoundingSphere(glm::vec3(3.0, 0.0, -5.0), 0.1f), glm::vec3(0.0f, 0.0f, 0.0f), false);

    physicsEngine.addObject(physicsObject1);
    physicsEngine.addObject(physicsObject2);
    physicsEngine.addObject(physicsObject3);
    physicsEngine.addObject(physicsObject4);
    physicsEngine.addObject(physicsObject5);
    //physicsEngine.addObject(physicsObject6);

    PhysicsEngineComponent* physicsEngineComponent = new PhysicsEngineComponent(physicsEngine);
    Node* physicsEngineNode = new Node;
    physicsEngineNode->addComponent(physicsEngineComponent);
    addToScene(physicsEngineNode);

    IndexedMesh floorIndexedMesh("models/plane.obj");
    floorIndexedMesh.m_texCoords.push_back( glm::vec2(1.0, 1.0) );
    floorIndexedMesh.m_texCoords.push_back( glm::vec2(1.0, 0.0) );
    floorIndexedMesh.m_texCoords.push_back( glm::vec2(0.0, 0.0) );
    floorIndexedMesh.m_texCoords.push_back( glm::vec2(0.0, 1.0) );
    Mesh floorMesh;
    floorMesh.init(floorIndexedMesh);
    Material* floor = new Material( new Texture("textures/snow.jpg") , glm::vec3(1.0, 1.0, 1.0));

    // adding interior
    Material* back = new Material( new Texture("textures/Fireplace.jpg") , glm::vec3(1.0, 1.0, 1.0));
    Node* backNode = new Node(glm::vec3(-10.0, 8.0, -10.0), glm::vec3(-90.0f, 0.0f, 0.0f), glm::vec3(20.0f, 1.0f, 10.0f));
    backNode->addComponent(new MeshRenderer(floorMesh, *back));
    addToScene(backNode);

    Material* win = new Material( new Texture("textures/s.jpg") , glm::vec3(1.0, 1.0, 1.0));
    Node* winNode = new Node(glm::vec3(9.99, 10.0, -10.0), glm::vec3(0.0f, -90.0f, -90.0f), glm::vec3(5.0f, 1.0f, 5.0f));
    winNode->addComponent(new MeshRenderer(floorMesh, *win));
    addToScene(winNode);

    Node* winNode2 = new Node(glm::vec3(10.01, 10.0, -10.0), glm::vec3(0.0f, -90.0f, -90.0f), glm::vec3(5.0f, 1.0f, 5.0f));
    winNode2->addComponent(new MeshRenderer(floorMesh, *win));
    addToScene(winNode2);

    Material* walls = new Material( new Texture("textures/carpet5.jpg") , glm::vec3(1.0, 1.0, 1.0));
    Node* roofNode = new Node(glm::vec3(-10.0, 18.0, -10.0), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(20.0f, 1.0f, 20.0f));
    roofNode->addComponent(new MeshRenderer(floorMesh, *walls));
    addToScene(roofNode);

    Node* rwallNode = new Node(glm::vec3(10.0, 8.0, -10.0), glm::vec3(0.0f, 0.0f, -90.0f), glm::vec3(13.0f, 1.0f, 20.0f));
    rwallNode->addComponent(new MeshRenderer(floorMesh, *walls));
    addToScene(rwallNode);

    Material* fwall = new Material( new Texture("textures/Door.jpg") , glm::vec3(1.0, 1.0, 1.0));
     Node* fwallNode = new Node(glm::vec3(-30.0, 8.0, -10.0), glm::vec3(0.0f, 90.0f, -90.0f), glm::vec3(13.0f, 1.0f, 20.0f));
    fwallNode->addComponent(new MeshRenderer(floorMesh, *fwall));
    addToScene(fwallNode);

    Material* flor = new Material( new Texture("textures/carpet4.jpg") , glm::vec3(1.0, 1.0, 1.0));
    Node* florNode = new Node(glm::vec3(-10.0, -0.99, -10.0), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(20.0f, 1.0f, 20.0f));
    florNode->addComponent(new MeshRenderer(floorMesh, *flor));
    addToScene(florNode);

    Material* bg1 = new Material( new Texture("textures/n.jpg") , glm::vec3(1.0, 1.0, 1.0));
    Node* bgNode = new Node(glm::vec3(0.0, 8.0, -10.0), glm::vec3(-90.0f, 0.0f, 0.0f), glm::vec3(30.0f, 1.0f, 10.0f));
    bgNode->addComponent(new MeshRenderer(floorMesh, *bg1));
    addToScene(bgNode);

    Node* bgNode2 = new Node(glm::vec3(30.0, 8.0, -10.0), glm::vec3(-90.0f, 0.0f, 0.0f), glm::vec3(30.0f, 1.0f, 10.0f));
    bgNode2->addComponent(new MeshRenderer(floorMesh, *bg1));
    addToScene(bgNode2);

       Node* bgNode3 = new Node(glm::vec3(90.0, 8.0, -10.0), glm::vec3(-90.0f, 0.0f, 0.0f), glm::vec3(30.0f, 1.0f, 10.0f));
    bgNode3->addComponent(new MeshRenderer(floorMesh, *bg1));
    addToScene(bgNode3);

    // finishing interior

    Node* floorNode = new Node(glm::vec3(0.0, -1.0, 0.0), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(50.0f, 1.0f, 10.0f));
    floorNode->addComponent(new MeshRenderer(floorMesh, *floor));
    addToScene(floorNode);

    Material* bg = new Material( new Texture("textures/bg2.jpg") , glm::vec3(1.0, 1.0, 1.0));
    Node* bgNode1 = new Node(glm::vec3(0.0, 2.5, -10.0), glm::vec3(90.0f, 0.0f, 0.0f), glm::vec3(50.0f, 1.0f, 5.0f));
    bgNode1->addComponent(new MeshRenderer(floorMesh, *bg));
    addToScene(bgNode1);

    Mesh* cubeMesh = new Mesh;
    cubeMesh->initCube();
    //Material* building = new Material( new Texture("textures/igloo.jpg") , glm::vec3(1.0, 1.0, 1.0));
    Material* gift = new Material( new Texture("textures/xmas.jpg") , glm::vec3(1.0, 1.0, 1.0));

//    Node* cubeNode1 = new Node(glm::vec3(3.0, 0.0, -5.0), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f));
//    cubeNode1->addComponent(new MeshRenderer(*cubeMesh, *building));
//    //cubeNode1->addComponent(new PhysicsObjectComponent(&physicsEngineComponent->getPhysicsEngine().getObject(5)));
//    addToScene(cubeNode1);
//
//    Node* cubeNode2 = new Node(glm::vec3(13.0, 0.0, -6.0), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f));
//    cubeNode2->addComponent(new MeshRenderer(*cubeMesh, *building));
//    addToScene(cubeNode2);

    Material* building = new Material( new Texture("textures/e.jpg") , glm::vec3(1.0, 1.0, 1.0));
    Material* outer = new Material( new Texture("textures/igloo.jpg") , glm::vec3(1.0, 1.0, 1.0));

    Node* cubeNode1 = new Node(glm::vec3(3.0, 0.0, -6.0), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f));
    cubeNode1->addComponent(new MeshRenderer(*cubeMesh, *building));
    addToScene(cubeNode1);

    Node* cubeNode2 = new Node(glm::vec3(13.0, 0.0, -6.0), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f));
    cubeNode2->addComponent(new MeshRenderer(*cubeMesh, *outer));
    addToScene(cubeNode2);

    Node* cubeNode3 = new Node(glm::vec3(23.0, 0.0, -5.0), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f));
    cubeNode3->addComponent(new MeshRenderer(*cubeMesh, *outer));
    addToScene(cubeNode3);

     Node* cubeNode4 = new Node(glm::vec3(-3.0, 0.0, -5.0), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f));
    cubeNode4->addComponent(new MeshRenderer(*cubeMesh, *building));
    addToScene(cubeNode4);

//    Node* cubeNode3 = new Node(glm::vec3(23.0, 0.0, -6.0), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f));
//    cubeNode3->addComponent(new MeshRenderer(*cubeMesh, *building));
//    addToScene(cubeNode3);

    Node* xmasNode = new Node(glm::vec3(33.0, 0.0, -6.0), glm::vec3(90.0f, 0.0f, 0.0f), glm::vec3(3.0f, 1.0f, 1.0f));
    xmasNode->addComponent(new MeshRenderer(floorMesh, *gift));
    addToScene(xmasNode);

    IndexedMesh paperPlaneIndexedMesh("models/paperbird.obj");
    Mesh paperPlaneMesh;
    paperPlaneMesh.init(paperPlaneIndexedMesh);

    Material* yellowPaper = new Material( new Texture("textures/paper.jpg") , glm::vec3(0.95, 0.95, 0.25));
    Node* birdNode1 = new Node(glm::vec3(-1.0, 0.5, -5.0), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.5f, 0.5f, 0.5f));
    birdNode1->addComponent(new MeshRenderer(paperPlaneMesh, *yellowPaper));
    birdNode1->addComponent(new PhysicsObjectComponent(&physicsEngineComponent->getPhysicsEngine().getObject(0)));
    birdNode1->addComponent(cameraComponent);
    addToScene(birdNode1);

    Material* orangePaper = new Material( new Texture("textures/paper.jpg") , glm::vec3(0.93, 0.67, 0.09));
    Node* birdNode2 = new Node(glm::vec3(-2.0, 0.5, -5.0), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.5f, 0.5f, 0.5f));
    birdNode2->addComponent(new MeshRenderer(paperPlaneMesh, *orangePaper));
    birdNode2->addComponent(new PhysicsObjectComponent(&physicsEngineComponent->getPhysicsEngine().getObject(1)));
    addToScene(birdNode2);

    Material* redPaper = new Material( new Texture("textures/paper.jpg") , glm::vec3(0.9, 0.28, 0.28));
    Node* birdNode3 = new Node(glm::vec3(-3.0, 0.5, -5.0), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.5f, 0.5f, 0.5f));
    birdNode3->addComponent(new MeshRenderer(paperPlaneMesh, *redPaper));
    birdNode3->addComponent(new PhysicsObjectComponent(&physicsEngineComponent->getPhysicsEngine().getObject(2)));
    addToScene(birdNode3);

    Material* greenPaper = new Material( new Texture("textures/paper.jpg") , glm::vec3(0.43, 0.79, 0.43));
    Node* birdNode4 = new Node(glm::vec3(-4.0, 0.5, -5.0), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.5f, 0.5f, 0.5f));
    birdNode4->addComponent(new MeshRenderer(paperPlaneMesh, *greenPaper));
    birdNode4->addComponent(new PhysicsObjectComponent(&physicsEngineComponent->getPhysicsEngine().getObject(3)));
    addToScene(birdNode4);

    Material* bluePaper = new Material( new Texture("textures/paper.jpg") , glm::vec3(0.27, 0.51, 0.78));
    Node* birdNode5 = new Node(glm::vec3(-5.0, 0.5, -5.0), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.5f, 0.5f, 0.5f));
    birdNode5->addComponent(new MeshRenderer(paperPlaneMesh, *bluePaper));
    birdNode5->addComponent(new PhysicsObjectComponent(&physicsEngineComponent->getPhysicsEngine().getObject(4)));
    addToScene(birdNode5);

//    Material* whitePaper = new Material( new Texture("textures/paper.jpg") , glm::vec3(1.0, 1.0, 1.0));
//    Node* birdNode6 = new Node(glm::vec3(-6.0, 0.5, -5.0), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.5f, 0.5f, 0.5f));
//    birdNode6->addComponent(new MeshRenderer(paperPlaneMesh, *whitePaper));
//    birdNode6->addComponent(new PhysicsObjectComponent(&physicsEngineComponent->getPhysicsEngine().getObject(5)));
//    addToScene(birdNode6);

}

void Scene02::update(float delta)
{
    this->getRootNode().update(delta);
}
