
#include <iostream>
#include <mutex>


// CRTP 라는 기술(C++ IDioms)
// => Curiously Recurring Template Pattern
// => 기반 클래스에서 미래에 만들어질 파생 클래스 이름을 사용할수
//    있게 하는 기술

// => C++에서 아주 널리 사용.
// => C++20 부터는 표준 라이브러리(STL 의 Range)가 이기술로 작성됨


template<typename T>
class Singleton
{
protected:
	Singleton() {}

	Singleton(const Singleton&) = delete;
	Singleton& operator=(const Singleton&) = delete;

	static std::mutex mtx;
	static T* instance;
public:
	static T& get_instance()
	{
		std::lock_guard<std::mutex> g(mtx);

		if (instance == nullptr)
			instance = new T;

		return *instance;
	}
};
template<typename T> T* Singleton<T>::instance = nullptr;
template<typename T> std::mutex Singleton<T>::mtx;

// Mouse 클래스도 위와 같은 싱글톤으로 만들고 싶다.
class Mouse : public Singleton< Mouse >
{
public:
};


int main()
{
	Mouse& c1 = Mouse::get_instance();
}

// github.com/aosp-mirror    "android open source project"

// platform system core  repository

// libutils/include/utils/Singleton.h 열어 보세요




