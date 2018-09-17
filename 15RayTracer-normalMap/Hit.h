#ifndef _HIT_H
#define _HIT_H

#include <memory>
#include <cfloat>
#include "Vector.h"
#include "Color.h"


class Scene;

class Hit {

public:
	bool hitObject;		// Did the ray hit an object?
	double t;
	float u;
	float v;
	Color color;
	Vector3f normal;
	Vector3f tangent;
	Vector3f bitangent;
	Vector3f hitPoint;
	Matrix4f modelView;

	std::shared_ptr<Scene> m_scene;
	
	Hit();
	Hit(Scene *a_scene);
	~Hit();
};



#endif