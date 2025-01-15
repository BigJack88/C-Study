#include <iostream>
using namespace std;
#include <string>
// 指针引用 *&  
// 作用是：指针本身的地址也相同 &ptr == &p 
/*
void getChar(char *& ptr,int bytes)
{
	ptr = new char[bytes];
	cout << "ptr的地址是" << &ptr << endl;
}
void open()
{
	char *p = NULL;
	getChar(p,5);
	cout << (void *)p;
	cout << "p的地址是" << &p << endl;
}

int main() {
	open();
	return 0;
}

*/

// 类 
/*
class Hero
{
	// 访问权限 public private protected
	public:
		// 属性
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
	// 通过类生成对象的过程 叫做实例化
	Hero h;
	h.m_id = 5;
	h.m_hp = 100;
	h.addHp(100);
	cout << "英雄血量是" << h.m_hp << endl;

	return 0;
}
*/



/*
访问权限
公共权限 public    类内可以访问， 类外可以访问
保护权限 protected 类内可以访问，类外无法访问  子类可以访问
私有权限 private   类内可以访问，类外无法访问  子类不可以访问
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

	// 私有权限private  
private:
	string name;		// 可读可写 
	int SkillCount = 4; // 可读 
	int Speed = 0; 	// 可写 
};


int main()
{
	Hero h;
	h.setName("帅哥");
	h.getSpeed(20);
	cout << "这个英雄的名字是" << h.getName() << endl;
	cout << "技能有" << h.getSkillCount() << endl;

	return 0;
}
*/


/*
析构函数
1.函数名和类名一致，并且在最前面~波浪号
2.函数返回值不需要写
3.不能有参数
*/

/*
class Hero
{
public:
	// 构造函数
	Hero()
	{
		cout << "Hero 默认构造函数完毕！" << endl;
	}
	// 析构函数
	~Hero()
	{
		if(a)
		{
			delete a;
			a = NULL;
		}
		cout << "Hero 析构函数完毕！" << endl;
	}
	int a;

};
int main()
{
	Hero h;
	int a;
	// 当程序没有结束时 析构函数不会调用
	cin >> a; 
	return 0;
}
*/

/*
有参析构和默认析构
调用时传递的参数一样 才会调用
*/
/*
class Hero
{
public:
	Hero()
	{
		m_Hp = 100;
		cout << "Hero 默认构造函数调用完毕！" << endl;
	}
	Hero(int hp)
	{
		m_Hp = hp;
		cout << "Hero 有参构造函数调用完毕！" << endl;
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


//静态成员变量特点：
// 所有对象共享同一份数据
// 编译阶段分配内存
// 需要在类中进行声明，在类外进行初始化 
/*
class Hero
{
	public:
		Hero()
		{
			m_Hp = 100;
			m_Name = "傻逼";
		}
		~Hero()
		{

		}
	// 静态成员变量
	static int m_Content;

	// 静态成员函数 只能使用静态成员变量
	static change_Content()
	{
		// m_Hp++;错误
		return m_Content;
	}
	private:
		int m_Hp;
		string m_Name;
	static change_Content11()
	{
		// m_Hp++;错误
		return m_Hp;
	}
};
// 全局声明使用静态成员变量要 先找类
int Hero::m_Content = 200;

int main() {
	Hero h;
	cout<< h.m_Content << endl;
	h.m_Content = 500;
	cout <<Hero::m_Content << endl;
	cout << h.change_Content() << endl;
	// 无法在private下调用静态成员函数
	// cout << h.change_Content11() << endl; 错误
	return 0;
}

*/


/*
this指针
1.解决类目冲突
2.*this就可以获取这个对象本身
*/
/*
class Hero
{
	public:
		Hero(int hp)
		{
			// hp = hp;命名冲突无法赋值
			this->hp = hp;
			// this实际上就是Hero实例化对象的地址
			cout << this << endl;
			// 解引用操作可以获取Hero类下的hp成员变量
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
mutable关键字
class Hero
{
	public:
		Hero() : m_Hp(0) , m_Name("帅哥")
		{

		}
		// const 修饰成员函数
		// 被修饰的函数无法修改成员变量
		int getHp() const
		{
			// m_Hp = 2; 错误
			m_Name = "大帅哥"; // 被mutable修饰
			return m_Hp;
		}
		int setHp(int hp)
		{
			m_Hp = hp;
		}
	private:
		int m_Hp;
		// 使用mutable关键字 即使成员函数被const 修饰
		// 也能修改被mutable修饰的变量
		mutable string m_Name;
};



int main()
{
	// 当const 修饰实例化对象时
	// 无法修改实例化对象的成员变量
	const Hero h;
	cout << h.getHp() << endl;
	// h.setHp(20);错误

	return 0;
}
*/

/*
友元的目的
让一个类或者函数
能够访问另一个类的私有成员

友元的关键字 ： friend 

三种友元
1.全局函数作为友元
2.类作为友元
3.成员函数作为友元
*/


/*
友元声明顺序误区

先声明被访问类
再写友元
接着再写被访问类
最后写友元的函数

*/

/*
class People;

// 类作为友元
class PeopleFriend
{

	public:
		PeopleFriend()
		{

		}
	// 函数定义变成函数声明
	void FriendVisit(People * p);
	void visitAll(People * p);
};
// 类的成员函数变成友元
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
	// 类作友元
	friend class PeopleFriend;
	// 全局变量作友元
	friend void visit(People * p);
	// 类中成员函数作友元
	friend void PeopleVisit::visitAll(People * p);
	public:
		People()
		{
			m_House = "别墅";
			m_Car = "跑车";
		}
	public:
		string m_House;
	private:
		string m_Car;
};

//全局函数作为友元
void visit(People * p)
{

	cout << "好朋友来住你的" << p->m_House << endl;
	cout << "好朋友来开你的" << p->m_Car << endl;
}

//类作为友元
void PeopleFriend::FriendVisit(People * p)
{
		cout << "好朋友来住你的" << p->m_House << endl;
		cout << "好朋友来开你的" << p->m_Car << endl;
}

//类的成员函数作为友元
void PeopleVisit::visitAll(People * p)
{
	cout << "好朋友来住你的" << p->m_House << endl;
	cout << "好朋友来开你的" << p->m_Car << endl;
}
void PeopleVisit::visitCar(People * p)
{
	cout << "好朋友来开你的" << p->m_House << endl;
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
+ - << ++ 运算符重载
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
	// 运算符重载
	
	//Complex operator+(Complex& other)
	//{
	//	Complex ret;
	//	ret.real = this->real + other.real;
	//	ret.image = this->image + other.image;
	//	return ret;
	//}
	
	// 前置++运算符重载 
	Complex& operator++()
	{
		this->real += 1;
		return *this;// 返回自身
	}
	// 后置++运算符重载 
	Complex operator++(int)
	{
		Complex c = *this;
		this->real += 1;
		return c;// 返回自身
	}
	void print()
	{
		cout << this->real << '+' << this->image << 'i' << endl;
	}
private:
	int real;
	int image;
};
// 全局函数 
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

// 左移运算符重载 
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
	// 左移运算符重载后 可以直接输出对象 
	cout << c;
	// 前置++运算符重载 
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
	// 当地址相同时 会出现 double free
	// 因为赋值后两个指针地址相同 所以只会删除一个
	~Hero()
	{
		if (m_Data)
		{
			delete m_Data;
			m_Data = NULL;
		}
	}

	// 重载赋值运算符
	Hero& operator=(Hero& h)
	{
		// 先删除指针 再申请内存 确保不是同一个地址
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
	// 赋值后地址相同
	cout << h1.m_Data << endl;
	cout << h2.m_Data << endl;

	// h1赋值h2 并且返回值是Her& 才能链式调用
	h3 = (h2 = h1);

	return 0;
}
*/





// 重载函数
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
	// 伪函数 每次调用可以存储数值
	cout << add(5,6) << endl;
	cout << add(5,6) << endl;
	cout << add(5,6) << endl;
	return 0;
}
*/

/*
// 继承的语法
// class 子类 ： 继承方式 父亲{}

// 父类 - 基类
class Animal
{
	public:
		void eat()
		{
			cout << "吃" << endl;
		}
};

// 子类 - 派生类
class Dog : public Animal
{
	public:
		void say()
		{
			cout << "丑" << endl;
		}
};

class Cat : public Animal
{
	public:

		void say()
		{
			cout << "帅哥" << endl;
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
继承方式：
公共 public
保护 protacted
私有 private

public 类内可以访问，类外也可以访问
protected 类内可以访问，类外不可以访问，但子类可以访问
private 类内可以访问 类外不可以访问，且子类不可访问
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
		// m_Sting = 3; 无法访问
	}
};
class Cat : protected Dog
{
	public:
	Cat()
	{
		m_Hp = 1;
		m_Name = 2;
		// m_Sting = 3; 无法访问
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
//    //c.m_Name = 3; 错误
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
继承时 调用构造函数和析构函数顺序
先调用父类构造  再调用自身构造
先调用自身析构     再调用父类析构
先进后出 原则
*/

/*
class Animal
{
	public:
	Animal()
	{
		m_Hp = 123;
		cout << "调用Animal 构造" << endl;
	}
	void eat ()
	{
		cout << "吃食物" << endl;
	}
	~Animal()
	{
		cout << "调用Animal 析构" << endl;
	}
	int m_Hp;
};
class Cat : public Animal
{
	public:
	Cat()
	{
		m_Hp = 456;
		cout << "调用Cat 构造" << endl;
	}
	void eat ()
	{
		cout << "吃鱼" << endl;
	}
	~Cat()
	{
		cout << "调用Cat 析构" << endl;
	}
	int m_Hp;
};
class SamllCat : public Cat
{
	public:
	SamllCat()
	{
		cout << "调用SamllCat 构造" << endl;
	}
	~SamllCat()
	{
		cout << "调用SamllCat 析构" << endl;
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

	// 当成员属性名相同时 继承不会覆盖父类的成员变量的值
	// 两个地址不相同
	cout << &(c.m_Hp) << endl;
	cout << &(c.Animal::m_Hp) << endl;
	
	cout << endl << endl;

	// 当函数名相同时 继承不会覆盖父类的函数
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
多继承
父类实例化.子类::成员变量
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
虚函数
函数传参是个动物 但是传入不同的动物 会产生不同的行为 这个就叫多态
*/
/*
class Animal
{
	public:
		void eat()
		{
			cout << "动物在吃东西" << endl;
		}
		// 虚函数
		// 当类中有虚函数时 会自动创建一个虚函数指针数组
		// 以指针数组的形式保存 虚函数的地址
		// 当子类调用同名函数时 会删除对应父类虚函数的地址 并且更改为子类函数地址
		virtual void hover()
		{
			cout << "动物会行动" << endl;
		}
};
class Cat : public Animal
{
	public:
		void eat()
		{
			cout << "猫在吃东西" << endl;
		}
		void hover()
		{
			cout << "猫会跳" << endl;
		}
};
// 实例化对象是Cat 但是函数参数是Animal
// 所以调用的是Animal 的eat()
void Doing(Animal & other)
{
	other.eat();
	// 当父类同名函数使用虚函数virtual后 
	// 子类会重写父类的虚函数
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
	// 这里 Animal 是八个字节 是因为虚函数是一个指针变量
	cout << "Animal’size " << sizeof(Animal) << endl;
	return 0;
}
*/

/*
// 当类中有纯虚函数时 类就是抽象类
class Animal
{
	public:
		// 纯虚函数
		virtual void eat() = 0 ;
};

class Cat : public Animal
{
	public:
		// 如果子类继承时没有重写纯虚函数
		// 则子类也是抽象类
		virtual void eat()
		{
			cout << "猫在吃东西" << endl;
		}
};

int main()
{
	// Animal a;纯虚函数无法实例化
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
	// 虚析构函数
	// 如果不加virtual 就不会调用子类的析构 
	// virtual ~BaseA()
	// {
	//    cout << "BaseA 销毁了" << endl;
	// }

	// 纯虚构函数 
	virtual ~BaseA() = 0;
};
// 纯虚构函数需要外部调用
BaseA::~BaseA()
{
	cout << "BaseA 销毁了" << endl;
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
		cout << "Son 销毁了" << endl;
		delete m_Value;
	}
	int* m_Value;
};

int main()
{
	// 申请了Son类型的空间并赋值给a 
	BaseA* a = new Son;
	// 删除a 并调用BaseA的析构函数 
	delete a;
	// 当BaseA 是抽象类时
	// BaseA a; 抽象类无法调用 
	return 0;
}
