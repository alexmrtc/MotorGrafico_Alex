#include "precompiledHeader.h"
#include "AlexModule.h"

extern Mesh cube;
extern Mesh Sphere;

void AlexModule::start()
{

	cam = new Camera();

	glm::vec2 viewport = Engine::get().getRender().getViewport();

	cam->setProjectionParams((float)glm::radians(45.0f),
		viewport.x / viewport.y,
		0.1f,
		500.0f);
	window = Engine::get().getRender().getCtxWindow()->getWindowGL();
	Engine::get().SetCamera(cam);
	cam->getTransform().setPosition(0, 0, 8);
	cam->lookAt(glm::vec3(0, 0, 8), glm::vec3(0, 0, 0));

	pos = cam->getPosition();
	front = glm::vec3(0, 0, 1);
	initCameras();
}

void AlexModule::stop()
{

	for (int i = 0; i < cameras.size(); i++)
		delete cameras[i];
}

void AlexModule::update(float elapsed)
{

	glm::vec3 euler = quad3.getEulerAngles();
	quad1.setPosition(5.0f, 1.0f, 2.0f);


	quad2.setPosition(glm::vec3(0, 1, -3));
	float num = euler.y + glfwGetTime() * 2.0f;
	quad2.setEulerAngles(euler.x, glm::radians(num), euler.z);

	quad3.setPosition(glm::vec3(0, -0.5, -1));
	quad3.setScale(2.5f);
	quad3.setEulerAngles(glm::radians(euler.x + glfwGetTime()), euler.y * 3, euler.z);

	quad4.setPosition(glm::vec3(1200, 1050, 1000));
	quad4.setScale(4.f);
	quad4.setEulerAngles(glm::radians(euler.x + glfwGetTime()), euler.y, euler.z);

	quad5.setPosition(glm::vec3(1200, 1000, 1000));
	quad5.setScale(3.f);
	quad5.setEulerAngles(glm::radians(euler.x), euler.y + glfwGetTime() * 3, euler.z + glfwGetTime());

	cubetransform1.setPosition(glm::vec3(0, 0, 5));
	cubetransform1.setEulerAngles(glm::radians(euler.x + glfwGetTime()), euler.y, euler.z + glfwGetTime()*2);
	cubetransform1.setScale(25.0f);

	cubetransform2.setPosition(glm::vec3(0, 1, 2));
	cubetransform2.setEulerAngles(glm::radians(euler.x + glfwGetTime()), euler.y, euler.z);
	cubetransform2.setScale(1.0f);

	cubetransform3.setPosition(glm::vec3(100, 0, 0));
	cubetransform3.setEulerAngles(glm::radians(euler.x + glfwGetTime()), euler.y, euler.z);
	cubetransform3.setScale(2.0f);

	cubetransform4.setPosition(glm::vec3(0, 0, 10));
	cubetransform4.setEulerAngles(glm::radians(euler.x + glfwGetTime() * 2), euler.y + glfwGetTime()* 5, euler.z);
	cubetransform4.setScale(0.5f);

	cubetransform5.setPosition(glm::vec3(100, 20, 5));
	cubetransform5.setEulerAngles(glm::radians(euler.x + glfwGetTime()), euler.y + glfwGetTime() * 4, euler.z + glfwGetTime());
	cubetransform5.setScale(25.0f);

	cameraController();

	//glm::vec3 front = cam->getFront();
	cam->lookAt(pos, target);
}

void AlexModule::initCameras()
{
	cameras.push_back(new Camera());
	cameras.push_back(new Camera());
	cameras.push_back(new Camera());
	cameras.push_back(new Camera());
	cameras.push_back(new Camera());
	cameras.push_back(new Camera());
	cameras.push_back(new Camera());
	cameras.push_back(new Camera());

	cameras.push_back(cam);
	glm::vec2 viewport = Engine::get().getRender().getViewport();

	cameras[0]->setProjectionParams((float)glm::radians(15.0f),
		viewport.x / viewport.y,
		0.1f,
		500.0f);
	cameras[0]->lookAt(glm::vec3(14.5f, 10, 20.f), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0));

	cameras[1]->setProjectionParams((float)glm::radians(95.0f),
		viewport.x / viewport.y,
		0.1f,
		500.0f);
	cameras[1]->lookAt(glm::vec3(10, 14.5f, 20.f), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0));

	cameras[2]->setProjectionParams((float)glm::radians(95.0f),
		viewport.x / viewport.y,
		0.1f,
		500.0f);
	cameras[2]->lookAt(glm::vec3(0, 70, 175), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0));

	cameras[3]->setProjectionParams((float)glm::radians(75.0f),
		viewport.x / viewport.y,
		0.1f,
		500.0f);
	cameras[3]->lookAt(glm::vec3(80, 0, -175), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0));

	cameras[4]->setProjectionParams((float)glm::radians(45.0f),
		viewport.x / viewport.y,
		0.1f,
		500.0f);
	cameras[4]->lookAt(glm::vec3(-220, 30, -175), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0));

	cameras[5]->setProjectionParams((float)glm::radians(20.f),
		viewport.x / viewport.y,
		0.1f,
		500.0f);
	cameras[5]->lookAt(glm::vec3(900, -1000, -1000), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0));

	cameras[6]->setProjectionParams((float)glm::radians(30.f),
		viewport.x / viewport.y,
		0.1f,
		500.0f);
	cameras[6]->lookAt(glm::vec3(1200, 1000, 1000), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0));

	cameras[7]->setProjectionParams((float)glm::radians(120.f),
		viewport.x / viewport.y,
		0.1f,
		500.0f);
	cameras[7]->lookAt(glm::vec3(1500, 1000, 1000), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0));

	Engine::get().SetCamera(cameras[0]);
}

void AlexModule::cameraController()
{
	front = glm::vec3(0, 0, 1);
	glm::vec3 euler = cam->getTransform().getEulerAngles();



	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
	{
		newAngle += glm::radians(5.0f);
	}
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
	{
		newAngle -= glm::radians(5.0f);
	}
	//cam->getTransform().yawPitchToVector(front ,newAngle, 0.0f);

	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
	{
		pos -= 0.1f * cam->getFront();//cam->getFront();
	}
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
	{
		pos += 0.1f * cam->getFront();
	}

	if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS)
	{
		newPitch += glm::radians(5.0f);
	}
	if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS)
	{
		newPitch += glm::radians(-5.0f);
	}
	if (canPress && glfwGetKey(window, GLFW_KEY_1) == GLFW_PRESS)
	{
		actualCamera++;
		actualCamera %= cameras.size();
		Engine::get().SetCamera(cameras[actualCamera]);
		canPress = false;
	}
	else if (glfwGetKey(window, GLFW_KEY_1) == GLFW_RELEASE)
	{
		canPress = true;
	}



	target = pos + glm::vec3(sinf(newAngle) * cosf(newPitch),
		sinf(newPitch), cosf(newAngle) * cosf(newPitch));
	glm::vec3 front = cam->getFront();

	cam->getTransform().setPosition(pos);

	std::cout << cameras[0]->getTransform().getPosition().x << " " <<
		cameras[0]->getTransform().getPosition().y << " "
		<< cameras[0]->getTransform().getPosition().z << std::endl;
}

void AlexModule::renderDebug()
{

	Engine::get().setModelObjectConstants(quad1.asMatrix(), glm::vec4(0.2f, 0.0f, 1.0f, 1.0f));
	quad.activateAndRender();


	Engine::get().setModelObjectConstants(quad2.asMatrix(), glm::vec4(1, 0, 0, 1));
	quad.render();


	Engine::get().setModelObjectConstants(quad3.asMatrix(), glm::vec4(0, 1, 0, 1));
	quad.render();

	Engine::get().setModelObjectConstants(quad4.asMatrix(), glm::vec4(0, 0, 0, 1));
	quad.render();

	Engine::get().setModelObjectConstants(quad5.asMatrix(), glm::vec4(1, 1, 1, 1));
	quad.render();

	Engine::get().setModelObjectConstants(cubetransform1.asMatrix(), glm::vec4(0.5, 0.5, 0.5, 1.0f));
	cube.activateAndRender();
	cubetransform1.setScale(1.0f);

	Engine::get().setModelObjectConstants(cubetransform2.asMatrix(), glm::vec4(0.75f, 1, 1, 1.0f));
	cube.render();
	cubetransform2.setScale(2.0f);

	Engine::get().setModelObjectConstants(cubetransform3.asMatrix(), glm::vec4(0.4, 0.5, 0, 1.0f));
	cube.activateAndRender();
	cubetransform3.setScale(1.0f);

	Engine::get().setModelObjectConstants(cubetransform4.asMatrix(), glm::vec4(1, 1, 0, 1.0f));
	cube.render();
	cubetransform4.setScale(2.0f);

	Engine::get().setModelObjectConstants(cubetransform5.asMatrix(), glm::vec4(1, 1, 0, 1.0f));
	cube.render();
	cubetransform5.setScale(1.0f);
}

AlexModule::AlexModule()
{
}


AlexModule::~AlexModule()
{
}