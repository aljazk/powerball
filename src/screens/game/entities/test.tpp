#include <iostream> // std::cout
#include <memory>   // std::unique_ptr
#include <vector>   // std::vector
#include <utility>  // std::move

struct Shape {
	virtual void hello() = 0;
};

struct Triangle : public Shape {
	int ID;
	Triangle(int ID) : ID(ID) {}
	void hello() { std::cout << "Hello from Triangle " << ID << std::endl; }
};

struct Circle : public Shape {
	std::string ID;
	Circle(const std::string& ID) : ID(ID) {}
	void hello() { std::cout << "Hello from Circle " << ID << std::endl; }
};

struct LinearStorage {
	std::vector<std::unique_ptr<Shape>> storage;
	
	void add(std::unique_ptr<Shape> shape) {
		storage.push_back(std::move(shape));
	}
	
	template <class T, class... Args>
	T& emplace(Args&&... args) {
		T* obj = new T(args...);
		storage.push_back(std::move(std::unique_ptr<T>(obj)));
		return *obj;
	}
	
	template <class T, class... Args>
	const T& emplace(Args&&... args) const {
		T* obj = new T(args...);
		storage.push_back(std::move(std::unique_ptr<T>(obj)));
		return *obj;
	}
	
	void helloAll() {
		for (std::unique_ptr<Shape>& obj : storage) {
			obj->hello();
		}
	} 
};

int main() {
	
	LinearStorage storage;
	
	storage.add(std::unique_ptr<Triangle>(new Triangle(5)));
	storage.add(std::unique_ptr<Circle>(new Circle("top")));
	Triangle& A = storage.emplace<Triangle>(8);
	Circle&   B = storage.emplace<Circle>("kek");
	
	storage.helloAll();
	A.hello();
	B.hello();
	
	return 0;
}