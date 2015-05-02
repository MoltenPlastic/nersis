#include <vector>
#include "base/list.hpp"
#include "base/time.hpp"
#include "base/vector.hpp"

namespace physics {
	typedef physNum int64_t;
	typedef void (*)(object,object) collisionCallback;

	class collisionHandle {
		collisionCallback callback;
		physNum softness;
	}
	
	class object {
		collisionHandle collision;
		group* parent;
		physNum mass;
		std::vector<vec> poly;
		Vec pos;
		void split
	};
	
	class group {
		state* parent;
		std::vector<object> objects;
		Vec vel;
	};

	class state {
		std::vector<group> groups;
		physNum velDampening;
		physNum angDampening;
	};
}