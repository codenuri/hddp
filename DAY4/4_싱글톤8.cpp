
#include <iostream>
#include <mutex>


// CRTP ��� ���(C++ IDioms)
// => Curiously Recurring Template Pattern
// => ��� Ŭ�������� �̷��� ������� �Ļ� Ŭ���� �̸��� ����Ҽ�
//    �ְ� �ϴ� ���

// => C++���� ���� �θ� ���.
// => C++20 ���ʹ� ǥ�� ���̺귯��(STL �� Range)�� �̱���� �ۼ���


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

// Mouse Ŭ������ ���� ���� �̱������� ����� �ʹ�.
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

// libutils/include/utils/Singleton.h ���� ������




