#include <iostream>
using namespace std;
#include <string>
// ָ������ *&  
// �����ǣ�ָ�뱾��ĵ�ַҲ��ͬ &ptr == &p 
/*
void getChar(char *& ptr,int bytes)
{
	ptr = new char[bytes];
	cout << "ptr�ĵ�ַ��" << &ptr << endl;
}
void open()
{
	char *p = NULL;
	getChar(p,5);
	cout << (void *)p;
	cout << "p�ĵ�ַ��" << &p << endl;
}

int main() {
	open();
	return 0;
}

*/

// �� 
/*
class Hero
{
	// ����Ȩ�� public private protected
	public:
		// ����
		int m_id;
		int m_hp;
	void addHp(int hp)
	{
		m_hp += hp;
	}
	void subHp(int hp)
	{
		m_hp -= hp;
	}
};

int main()
{
	// ͨ�������ɶ���Ĺ��� ����ʵ����
	Hero h;
	h.m_id = 5;
	h.m_hp = 100;
	h.addHp(100);
	cout << "Ӣ��Ѫ����" << h.m_hp << endl;

	return 0;
}
*/



/*
����Ȩ��
����Ȩ�� public    ���ڿ��Է��ʣ� ������Է���
����Ȩ�� protected ���ڿ��Է��ʣ������޷�����  ������Է���
˽��Ȩ�� private   ���ڿ��Է��ʣ������޷�����  ���಻���Է���
*/

/*
class Hero
{
public:
	void setName(string set_name)
	{
		name = set_name;
	}
	string getName()
	{
		return name;
	}
	// ----- 
	int getSkillCount()
	{
		return SkillCount;
	}
	// -----
	void getSpeed(int change_speed)
	{
		Speed = change_speed;
	}

	// ˽��Ȩ��private  
private:
	string name;		// �ɶ���д 
	int SkillCount = 4; // �ɶ� 
	int Speed = 0; 	// ��д 
};


int main()
{
	Hero h;
	h.setName("˧��");
	h.getSpeed(20);
	cout << "���Ӣ�۵�������" << h.getName() << endl;
	cout << "������" << h.getSkillCount() << endl;

	return 0;
}
*/


/*
��������
1.������������һ�£���������ǰ��~���˺�
2.��������ֵ����Ҫд
3.�����в���
*/

/*
class Hero
{
public:
	// ���캯��
	Hero()
	{
		cout << "Hero Ĭ�Ϲ��캯����ϣ�" << endl;
	}
	// ��������
	~Hero()
	{
		if(a)
		{
			delete a;
			a = NULL;
		}
		cout << "Hero ����������ϣ�" << endl;
	}
	int a;

};
int main()
{
	Hero h;
	int a;
	// ������û�н���ʱ ���������������
	cin >> a; 
	return 0;
}
*/

/*
�в�������Ĭ������
����ʱ���ݵĲ���һ�� �Ż����
*/
/*
class Hero
{
public:
	Hero()
	{
		m_Hp = 100;
		cout << "Hero Ĭ�Ϲ��캯��������ϣ�" << endl;
	}
	Hero(int hp)
	{
		m_Hp = hp;
		cout << "Hero �вι��캯��������ϣ�" << endl;
	}
private:
	int m_Hp;
};

int main()
{
	Hero h;
	return 0;
}
*/


//��̬��Ա�����ص㣺
// ���ж�����ͬһ������
// ����׶η����ڴ�
// ��Ҫ�����н�����������������г�ʼ�� 
/*
class Hero
{
	public:
		Hero()
		{
			m_Hp = 100;
			m_Name = "ɵ��";
		}
		~Hero()
		{

		}
	// ��̬��Ա����
	static int m_Content;

	// ��̬��Ա���� ֻ��ʹ�þ�̬��Ա����
	static change_Content()
	{
		// m_Hp++;����
		return m_Content;
	}
	private:
		int m_Hp;
		string m_Name;
	static change_Content11()
	{
		// m_Hp++;����
		return m_Hp;
	}
};
// ȫ������ʹ�þ�̬��Ա����Ҫ ������
int Hero::m_Content = 200;

int main() {
	Hero h;
	cout<< h.m_Content << endl;
	h.m_Content = 500;
	cout <<Hero::m_Content << endl;
	cout << h.change_Content() << endl;
	// �޷���private�µ��þ�̬��Ա����
	// cout << h.change_Content11() << endl; ����
	return 0;
}

*/


/*
thisָ��
1.�����Ŀ��ͻ
2.*this�Ϳ��Ի�ȡ���������
*/
/*
class Hero
{
	public:
		Hero(int hp)
		{
			// hp = hp;������ͻ�޷���ֵ
			this->hp = hp;
			// thisʵ���Ͼ���Heroʵ��������ĵ�ַ
			cout << this << endl;
			// �����ò������Ի�ȡHero���µ�hp��Ա����
			cout << (*this).hp << endl;
		}
		int hp;
};


int main()
{
	Hero h(100);
	cout << &h << endl;
	cout << h.hp << endl;
	return 0;
}
*/

/*
mutable�ؼ���
class Hero
{
	public:
		Hero() : m_Hp(0) , m_Name("˧��")
		{

		}
		// const ���γ�Ա����
		// �����εĺ����޷��޸ĳ�Ա����
		int getHp() const
		{
			// m_Hp = 2; ����
			m_Name = "��˧��"; // ��mutable����
			return m_Hp;
		}
		int setHp(int hp)
		{
			m_Hp = hp;
		}
	private:
		int m_Hp;
		// ʹ��mutable�ؼ��� ��ʹ��Ա������const ����
		// Ҳ���޸ı�mutable���εı���
		mutable string m_Name;
};



int main()
{
	// ��const ����ʵ��������ʱ
	// �޷��޸�ʵ��������ĳ�Ա����
	const Hero h;
	cout << h.getHp() << endl;
	// h.setHp(20);����

	return 0;
}
*/

/*
��Ԫ��Ŀ��
��һ������ߺ���
�ܹ�������һ�����˽�г�Ա

��Ԫ�Ĺؼ��� �� friend 

������Ԫ
1.ȫ�ֺ�����Ϊ��Ԫ
2.����Ϊ��Ԫ
3.��Ա������Ϊ��Ԫ
*/


/*
��Ԫ����˳������

��������������
��д��Ԫ
������д��������
���д��Ԫ�ĺ���

*/

/*
class People;

// ����Ϊ��Ԫ
class PeopleFriend
{

	public:
		PeopleFriend()
		{

		}
	// ���������ɺ�������
	void FriendVisit(People * p);
	void visitAll(People * p);
};
// ��ĳ�Ա���������Ԫ
class PeopleVisit
{
	public:
		PeopleVisit()
		{

		}
	void visitAll(People * p);
	void visitCar(People * p);
};

class People
{
	// ������Ԫ
	friend class PeopleFriend;
	// ȫ�ֱ�������Ԫ
	friend void visit(People * p);
	// ���г�Ա��������Ԫ
	friend void PeopleVisit::visitAll(People * p);
	public:
		People()
		{
			m_House = "����";
			m_Car = "�ܳ�";
		}
	public:
		string m_House;
	private:
		string m_Car;
};

//ȫ�ֺ�����Ϊ��Ԫ
void visit(People * p)
{

	cout << "��������ס���" << p->m_House << endl;
	cout << "�������������" << p->m_Car << endl;
}

//����Ϊ��Ԫ
void PeopleFriend::FriendVisit(People * p)
{
		cout << "��������ס���" << p->m_House << endl;
		cout << "�������������" << p->m_Car << endl;
}

//��ĳ�Ա������Ϊ��Ԫ
void PeopleVisit::visitAll(People * p)
{
	cout << "��������ס���" << p->m_House << endl;
	cout << "�������������" << p->m_Car << endl;
}
void PeopleVisit::visitCar(People * p)
{
	cout << "�������������" << p->m_House << endl;
}

int main()
{
	People p;
	//visit(&p);
	//PeopleFriend pf;
	//pf.FriendVisit(&p);
	//PeopleVisit pv;
	pv.visitAll(&p);
	pv.visitCar(&p);
	return 0;
}yu
*/

/*
+ - << ++ ���������
*/
/*
class Complex
{
	friend Complex operator+(Complex& a, Complex& b);
	friend Complex operator-(Complex& a, Complex& b);
	friend ostream& operator<<(ostream& cout, const Complex& a);
public:
	Complex() : real(0), image(0)
	{

	}
	Complex(int real, int image)
	{
		this->real = real;
		this->image = image;
	}
	// ���������
	
	//Complex operator+(Complex& other)
	//{
	//	Complex ret;
	//	ret.real = this->real + other.real;
	//	ret.image = this->image + other.image;
	//	return ret;
	//}
	
	// ǰ��++��������� 
	Complex& operator++()
	{
		this->real += 1;
		return *this;// ��������
	}
	// ����++��������� 
	Complex operator++(int)
	{
		Complex c = *this;
		this->real += 1;
		return c;// ��������
	}
	void print()
	{
		cout << this->real << '+' << this->image << 'i' << endl;
	}
private:
	int real;
	int image;
};
// ȫ�ֺ��� 
Complex operator+(Complex& a, Complex& b)
{
	Complex ret;
	ret.real = a.real + b.real;
	ret.image = a.image + b.image;
	return ret;
}
Complex operator-(Complex& a, Complex& b)
{
	Complex ret;
	ret.real = a.real - b.real;
	ret.image = a.image - b.image;
	return ret;
}

// ������������� 
ostream& operator<<(ostream& cout, const Complex& a)
{
	cout << a.real << "+" << a.image << "i" << endl;
	return cout;
}
int main()
{
	Complex a(10, 20);
	Complex b(6, 8);
	//Complex c = a.add(b);
	Complex c = a + b;
	Complex d = a - b;
 	c.print();
	d.print();
	// ������������غ� ����ֱ��������� 
	cout << c;
	// ǰ��++��������� 
	Complex A(10, 20);
	cout << ++A;
	return 0;
}
*/

/*
class Hero
{
public:
	Hero() : m_Data(NULL)
	{

	}
	Hero(int data)
	{
		m_Data = new int;
		*m_Data = data;
	}
	// ����ַ��ͬʱ ����� double free
	// ��Ϊ��ֵ������ָ���ַ��ͬ ����ֻ��ɾ��һ��
	~Hero()
	{
		if (m_Data)
		{
			delete m_Data;
			m_Data = NULL;
		}
	}

	// ���ظ�ֵ�����
	Hero& operator=(Hero& h)
	{
		// ��ɾ��ָ�� �������ڴ� ȷ������ͬһ����ַ
		if (m_Data)
		{
			delete m_Data;
			m_Data = NULL;
		}
		m_Data = new int;
		*m_Data = *h.m_Data;
		return *this;
	}
	int* m_Data;
};

int main()
{
	Hero h1(1);
	Hero h2(2);
	Hero h3(3);
	cout << h1.m_Data << endl;
	cout << h2.m_Data << endl;

	h1 = h2;
	// ��ֵ���ַ��ͬ
	cout << h1.m_Data << endl;
	cout << h2.m_Data << endl;

	// h1��ֵh2 ���ҷ���ֵ��Her& ������ʽ����
	h3 = (h2 = h1);

	return 0;
}
*/





// ���غ���
/*
class ChangeFunction
{

	public:
		ChangeFunction()
		{
			m_acc = 0;
		}
		int operator() (int a, int b)
		{
			m_acc++;
			return a + b + m_acc;
		}
	private :
		int m_acc;
};

int main() {
	ChangeFunction add;
	// α���� ÿ�ε��ÿ��Դ洢��ֵ
	cout << add(5,6) << endl;
	cout << add(5,6) << endl;
	cout << add(5,6) << endl;
	return 0;
}
*/

/*
// �̳е��﷨
// class ���� �� �̳з�ʽ ����{}

// ���� - ����
class Animal
{
	public:
		void eat()
		{
			cout << "��" << endl;
		}
};

// ���� - ������
class Dog : public Animal
{
	public:
		void say()
		{
			cout << "��" << endl;
		}
};

class Cat : public Animal
{
	public:

		void say()
		{
			cout << "˧��" << endl;
		}
};

int main()
{
	Dog d;
	Cat c;
	c.eat();
	d.eat();
	c.say();
	d.say();
	return 0;
}
*/

/*
�̳з�ʽ��
���� public
���� protacted
˽�� private

public ���ڿ��Է��ʣ�����Ҳ���Է���
protected ���ڿ��Է��ʣ����ⲻ���Է��ʣ���������Է���
private ���ڿ��Է��� ���ⲻ���Է��ʣ������಻�ɷ���
*/

/*
class Animal
{
	public:
		int m_Hp;
	protected:
		int m_Name;
	private:
		int m_String;
};

class Dog : public Animal
{
	public:
	Dog()
	{
		m_Hp = 1;
		m_Name = 2;
		// m_Sting = 3; �޷�����
	}
};
class Cat : protected Dog
{
	public:
	Cat()
	{
		m_Hp = 1;
		m_Name = 2;
		// m_Sting = 3; �޷�����
	}
};
void BigCat()
{
	Cat c;
	c.m_Hp = 1;
}
//void SamllCat()
//{
//    Cat c;
//    c.m_Hp = 2;
//    //c.m_Name = 3; ����
//}

class bird : private Animal
{
	public:
		bird()
		{
			m_Hp = 1;
			m_Name = 2;
		}
};

//class Smallbird : private bird
//{
//    public:
//        Smallbird()
//        {
//            m_Hp = 1;
//            m_Name = 2;
//        }
//};
int main()
{
	return 0;
}
*/


/*
�̳�ʱ ���ù��캯������������˳��
�ȵ��ø��๹��  �ٵ���������
�ȵ�����������     �ٵ��ø�������
�Ƚ���� ԭ��
*/

/*
class Animal
{
	public:
	Animal()
	{
		m_Hp = 123;
		cout << "����Animal ����" << endl;
	}
	void eat ()
	{
		cout << "��ʳ��" << endl;
	}
	~Animal()
	{
		cout << "����Animal ����" << endl;
	}
	int m_Hp;
};
class Cat : public Animal
{
	public:
	Cat()
	{
		m_Hp = 456;
		cout << "����Cat ����" << endl;
	}
	void eat ()
	{
		cout << "����" << endl;
	}
	~Cat()
	{
		cout << "����Cat ����" << endl;
	}
	int m_Hp;
};
class SamllCat : public Cat
{
	public:
	SamllCat()
	{
		cout << "����SamllCat ����" << endl;
	}
	~SamllCat()
	{
		cout << "����SamllCat ����" << endl;
	}
};
void Open()
{
	//Animal a;
	//Cat c;
	//SamllCat s;
	Cat c;
	cout << c.m_Hp << endl;
	cout << c.Animal::m_Hp << endl;

	// ����Ա��������ͬʱ �̳в��Ḳ�Ǹ���ĳ�Ա������ֵ
	// ������ַ����ͬ
	cout << &(c.m_Hp) << endl;
	cout << &(c.Animal::m_Hp) << endl;
	
	cout << endl << endl;

	// ����������ͬʱ �̳в��Ḳ�Ǹ���ĺ���
	cout << endl << endl;

	c.eat();
	c.Animal::eat();
	
	cout << endl << endl;
}
int main()
{
	Open();
	return 0;
}
*/

/*
��̳�
����ʵ����.����::��Ա����
*/
/*
class BaseA
{
	public:
		int m_A;
		int base;
	BaseA()
	{
		m_A = 1;
		base = 5;
	}
};

class BaseB
{
	public:
		int m_B;
		int base;
	BaseB()
	{
		m_B = 2;
		base = 6;
	}
};

class BaseC
{
	public:
		int m_C;
	BaseC()
	{
		m_C = 3;
	}
};

class Base : public BaseA,public BaseB,public BaseC
{

};

int main()
{
	Base b;
	cout << b.m_A << endl;
	cout << b.m_B << endl;
	cout << b.m_C << endl;
	cout << b.BaseA::base << endl;
	cout << b.BaseB::base << endl;
	return 0;
}
*/



/*
�麯��
���������Ǹ����� ���Ǵ��벻ͬ�Ķ��� �������ͬ����Ϊ ����ͽж�̬
*/
/*
class Animal
{
	public:
		void eat()
		{
			cout << "�����ڳԶ���" << endl;
		}
		// �麯��
		// ���������麯��ʱ ���Զ�����һ���麯��ָ������
		// ��ָ���������ʽ���� �麯���ĵ�ַ
		// ���������ͬ������ʱ ��ɾ����Ӧ�����麯���ĵ�ַ ���Ҹ���Ϊ���ຯ����ַ
		virtual void hover()
		{
			cout << "������ж�" << endl;
		}
};
class Cat : public Animal
{
	public:
		void eat()
		{
			cout << "è�ڳԶ���" << endl;
		}
		void hover()
		{
			cout << "è����" << endl;
		}
};
// ʵ����������Cat ���Ǻ���������Animal
// ���Ե��õ���Animal ��eat()
void Doing(Animal & other)
{
	other.eat();
	// ������ͬ������ʹ���麯��virtual�� 
	// �������д������麯��
	other.hover();
}
void test()
{
	Cat c;
	Doing(c);
}

int main()
{
	test();
	// ���� Animal �ǰ˸��ֽ� ����Ϊ�麯����һ��ָ�����
	cout << "Animal��size " << sizeof(Animal) << endl;
	return 0;
}
*/

/*
// �������д��麯��ʱ ����ǳ�����
class Animal
{
	public:
		// ���麯��
		virtual void eat() = 0 ;
};

class Cat : public Animal
{
	public:
		// �������̳�ʱû����д���麯��
		// ������Ҳ�ǳ�����
		virtual void eat()
		{
			cout << "è�ڳԶ���" << endl;
		}
};

int main()
{
	// Animal a;���麯���޷�ʵ����
	Cat c;
	c.eat();
	return 0;
}
*/


class BaseA
{
public:
	BaseA()
	{

	}
	// ����������
	// �������virtual �Ͳ��������������� 
	// virtual ~BaseA()
	// {
	//    cout << "BaseA ������" << endl;
	// }

	// ���鹹���� 
	virtual ~BaseA() = 0;
};
// ���鹹������Ҫ�ⲿ����
BaseA::~BaseA()
{
	cout << "BaseA ������" << endl;
}

class Son : public BaseA
{
public:
	Son() : m_Value(NULL)
	{
		m_Value = new int(0);
	}
	~Son()
	{
		cout << "Son ������" << endl;
		delete m_Value;
	}
	int* m_Value;
};

int main()
{
	// ������Son���͵Ŀռ䲢��ֵ��a 
	BaseA* a = new Son;
	// ɾ��a ������BaseA���������� 
	delete a;
	// ��BaseA �ǳ�����ʱ
	// BaseA a; �������޷����� 
	return 0;
}
