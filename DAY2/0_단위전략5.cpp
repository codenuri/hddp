
// ���� : STL �� list �� ���� ����ó�� ����ȭ�� �Ǵ°��� �ƴմϴ�.
//      STL �����̳ʴ� ����ȭ ���� ���մϴ�
//      ��, �ٸ� �뵵�� ���������� ����մϴ�


// STL �� ����
template<typename T, typename Alloc = std::allocator<T>>
class vector
{
	T* buff;
	Alloc ax;	// �޸� �Ҵ��
				// ������ ��� ����Լ������� ax �� �����ؼ�
				// �޸� �Ҵ�/������ �ؾ� �մϴ�.
public:
	void resize(int n)
	{
		// ���� ũ�Ⱑ �����ؼ� �ٽ� �Ҵ��Ϸ��� �մϴ�.
		// ��� �Ҵ��ұ�� ?
		// C++������ �޸𸮸� �Ҵ��ϴ� ����� ���� ���� �ֽ��ϴ�.
		// new / malloc / system call / windows api/ Ǯ�� 
//		buff = new T[n]; // �̷��� �ڵ带 �ۼ��ߴٸ�
						// �޸� �Ҵ� ����� ��ü �Ҽ� �����ϴ�

		buff = ax.allocate(n);

		ax.deallocate(buff, n); // ������.. ���������� ����
	}
};
// std::allocator<T>  : C++ ǥ�� �Ҵ��, new/delete ���
