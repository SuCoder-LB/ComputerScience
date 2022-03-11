### 语言特点
+ 面向对象，为c的超集，
+ 三特性：封装继承多态
+ 生成的代码质量高，运行效率高，
+ 安全，增加const常量，引用，四种cast转换，智能指针，try-catch，c指针使用，强制转换不确定，内存泄露
+ 可复用高，引入模板
+ 不断发展，新特性，c++11引入nullptr，auto，lambda，右值引用，智能指针

### struct与class
+ struct数据结构集合，class对象数据封装
+ struct默认public，class默认private
+ struct公有继承，class私有继承
+ class与typename可定义模板参数
~~~
template<typename T, typename Y> // 可以把typename 换成 class  
int Func(const T& t, const Y& y) {      //TODO  }
~~~
+ c++的struct对c的struct进行扩充，可以有成员函数，静态成员，修改访问控制，可以继承，可以初始化
+ c中struct使用需加struct关键字或取别名，c++可直接使用
~~~
struct Student{  
    int  iAgeNum;  
    string strName; 
} typedef struct Student Student2; //C中取别名  
struct Student stu1; // C 中正常使用 
Student2 stu2;   // C 中通过取别名的使用 
Student stu3;   // C++ 中使用
~~~
### include <>与" "
+ <>系统文件，编译器设置的头文件路径 ⟶ 系统变量
+ ""自定义文件，当前头文件目录 ⟶ 编译器设置的头文件路径 ⟶ 系统变量

### extern
+ 指示编译器这部分按c语言编译
+ c++重载，编译会将参数类型加到代码中，c只包括函数名

### 过程
#### 预编译
+ 删除define，展开宏定义
+ 处理预编译指令，#if,#ifdef，
+ 处理 include 预编译指令
+ 过滤注释
+ 添加行号文件名标识
#### 编译
+ 词法分析
+ 语法分析
+ 语义分析
+ 优化
+ 代码生成：生成汇编代码
#### 汇编
+ 转为机器码
#### 链接
+ 不同源文件产生的目标文件进行链接，形成可执行程序
+ 静态：把调用的函数链接到可执行文件中，把静态库删除不影响程序运行，window .lib，linux .a
+ 动态：执行过程中找链接函数，生成的可执行文件没有函数代码，window .dll linux .so
### static
+ 静态变量，静态函数，初始化的静态变量在数据段分配内存，未初始化在BSS段分配内存，直到程序结束，静态变量会维持前值
+ c++中，静态成员变量，静态成员函数，创建的类的对象共享静态存储空间
+ 静态成员函数没有this指针，无法访问对象的非静态成员（不属于任何一个对象）
+ c全局变量和静态变量在代码执行前初始化，编译期初始化
+ c++当首次用到时初始化
### 变量
+ 作用域
  全局，局部，类，语句，命名空间，文件
  - 全局变量：全局，通过extern作用于其他文件
  - 静态全局变量：全局+文件，无法在其他文件使用
  - 静态局部变量：局部，只被初始化一次，直到程序结束
  - 类静态成员变量：类作用域
+ 空间：局部变量在栈，其他在静态存储区
+ 生命周期：局部变量在栈上，出了作用域回收内存， 静态全局局部变量直到程序结束，类静态成员变量当超出类作用域回收内存
### 数组与指针
+ 数组存储相同类型集合，指针存地址
+ 同类型指针可以相互复制，数组只能拷贝或元素赋值
+ 数组连续，存储在静态区或栈上，指针灵活，存储空间不确定
+ 数组占存储空间 sizeof(数组名)/sizeof(数据类型)
+ 32位指针4位，64位指针8位
### 函数指针
+ 指向函数的指针
~~~
int func(int a);  
int (*f)(int a);  
f = &func;
~~~
+ 应用场景：回调
~~~
//以库函数qsort排序函数为例，它的原型如下：
void qsort(void *base,//void*类型，代表原始数组
           size_t nmemb, //第二个是size_t类型，代表数据数量
           size_t size, //第三个是size_t类型，代表单个数据占用空间大小
           int(*compar)(const void *,const void *)//第四个参数是函数指针
          );
//第四个参数告诉qsort，应该使用哪个函数来比较元素，即只要我们告诉qsort比较大小的规则，它就可以帮我们对任意数据类型的数组进行排序。在库函数qsort调用我们自定义的比较函数，这就是回调的应用。

//示例
int num[100];
int cmp_int(const void* _a , const void* _b){//参数格式固定
    int* a = (int*)_a;    //强制类型转换
    int* b = (int*)_b;
    return *a - *b;　　
}
qsort(num,100,sizeof(num[0]),cmp_int); //回调
~~~
### nullptr
+ 可调用成员函数，无法用this（编译时对象绑定了函数地址）

### inline
+ 一般用于函数体代码简单的函数，不能包含while，switch，不能调用自身
+ 编译时代码插入，省去函数调用的开销，但代码膨胀
+ 编译时进行类型检查，满足函数性质，有返回值，参数列表
+ 最好定义在头文件而不仅仅时声明
+ 好的编译器会自动取消内联
### define
+ 不是函数，预处理器复制宏代码代替函数调用，省去压栈退栈过程，提高效率
+ 预编译时宏名用宏体替代，即字符串替换
+ 没有类型检查
+ 定义的常量不会放在内存
+ 定义的常量不带类型
+ 使用时，注意类型和括号
### const
+ 定义常量
+ 生效于编译阶段
+ 存储于内存，需要额外内存空间
+ 带类型
+ 类内成员后面加const，不改变类内数据成员
+ 常量对象const对象，只能调用const成员函数
### ++i与i++
+ 赋值顺序不同
+ 效率不同，后置++速度慢
+ i++不能作左值，++i可以
+ 都不是原子操作

### 函数指针于指针函数
+ 指针函数时函数，返回指针
+ 函数指针是指针，指向函数
~~~
指针函数：int *fun(int x,int y);
函数指针：int (*fun)(int x,int y);
~~~
### 指针常量与常量指针
~~~
1. const int a;     //指的是a是一个常量，不允许修改。
2. const int *a;    //a指针所指向的内存里的值不变，即（*a）不变
3. int const *a;    //同const int *a;
4. int *const a;    //a指针所指向的内存地址不变，即a不变
5. const int *const a;   //都不变，即（*a）不变，a也不变
~~~
### 传值方式
+ 值传递，引用传递，指针传递
### new与malloc
+ new是操作符，malloc是函数
+ new先分配内存再调用构造函数，释放时调用析构函数，malloc没有调用构造函数和析构函数
+ malloc需要申请内存大小，返回的指针需要强转，new会调用构造函数，不用指定内存大小，返回指针不用强转
+ new可以被重载，更直接且安全，发生错误抛出异常，malloc返回null
+ malloc底层，当开辟空间小于128k时，调用brk()函数，否则调用mmap()，采用内存池的管理方式，以减少内存碎片。先申请大块内存作为堆区，然后将堆区分为多个内存块。用户申请内存时，直接从堆区分配一块合适的空闲块，采用隐式链表将所有空闲块，每一个空闲块记录了一个未分配的连续的内存地址
+ new底层，创建一个新对象，将构造函数的作用域赋值给这个新的对象，执行构造函数，返回新对象
+ 指针使用，初始置null，申请内存后判空，释放置null
### 野指针
+ 概念：指针指向的位置不可知
+ 原因：释放内存后指针不即使置空
~~~
char *p = (char *)malloc(sizeof(char)*100);  
strcpy(p, "Douya");  
free(p);//p所指向的内存被释放，但是p所指的地址仍然不变  
...  
if (p != NULL){//没有起到防错作用  
    strcpy(p, "hello, Douya!");//出错  
}  
~~~
+ 避免
  - 初始化置null
  - 申请内存后判空
  - 指针释放后置null
  - 使用智能指针
~~~
int *p = NULL; //初始化置NULL
p = (int *)malloc(sizeof(int)*n); //申请n个int内存空间  
assert(p != NULL); //判空，防错设计
p = (int *) realloc(p, 25);//重新分配内存, p 所指向的内存块会被释放并分配一个新的内存地址
free(p);  
p = NULL; //释放后置空

int *p1 = NULL; //初始化置NULL
p1 = (int *)calloc(n, sizeof(int)); //申请n个int内存空间同时初始化为0 
assert(p1 != NULL); //判空，防错设计
free(p1);  
p1 = NULL; //释放后置空

int *p2 = NULL; //初始化置NULL
p2 = new int[n]; //申请n个int内存空间  
assert(p2 != NULL); //判空，防错设计
delete []p2;  
p2 = nullptr; //释放后置空 
~~~
### 内存泄漏
+ 申请内存块后未释放
  - new与malloc，未用delete，free
  - 子类继承父类，父类析构不是虚函数
  - windows句柄资源使用后未释放
+ 检测
  - 使用相应的释放函数
  - 分配的内存指针以链表的形式管理，使用后从链表中删除，程序结束后检查链表
  - 智能指针
  - 工具插件，ccmalloc，dmalloc，leaky，valgrind
### 内存管理
+ 栈，存放函数参数，局部变量，超出作用域自动回收，一级缓存，被调用时处于存储空间，类似栈结构
+ 堆，由程序员分配释放，new，二级缓存，速度慢些，类似数组结构
+ 自由存储区，malloc分配的内存块，与堆类似，用free释放
+ 全局/静态存储区，全局变量与静态变量
+ 常量存储区，存放常量，不允许修改
+ 常见错误
  - 内存分配失败却使用
  - 内存分配成功未初始化就引用
  - 操作越界
  - 未释放内存，造成内存泄漏
  - 释放内存却继续使用
+ 对策
  - 定义指针时，初始化为null
  - 申请内存后判null
  - 初始化
  - 避免数组和动态内存下标越界
  - 内存申请与释放配对，防止泄漏
  - 释放之后置null，防止野指针
  - 使用智能指针
### 程序section
从低地址到高地址，代码段，数据段，BSS段，程序运行后：堆，共享区，栈
+ 受保护的地址
+ 代码段，存放程序执行代码，只读，还包括一些只读的常数变量
+ 数据段，存放初始化的全局变量和静态变量
+ BSS段，存放未初始化及初始化为0的全局变量和静态变量，可读写，程序执行之前自动清零
+ 堆，动态申请内存，从低地址向高地址增长
+ 共享区
+ 栈，存储局部变量，函数参数，从高地址向低地址增长，是一块连续空间
+ 命令行参数
+ 环境变量
+ 内核
### 程序启动过程
+ 操作系统创建相应的进程，分配私有进程空间，操作系统的加载器负责把可执行文件的数据段和代码段映射到进程的虚拟内存空间
+ 加载器读入可执行程序的导入符号表，根据符号表查出该可执行程序所有依赖的动态链接库
+ 加载器针对该程序的每一个动态链接库调用loadlibrary
  - 查找对应动态库文件，加载器为该动态链接库确定一个合适的基地址
  - 加载器读取该动态链接库的导入符号表和导出符号表，比较应用程序要求的导入符号是否匹配该库的导出符号
  - 针对该库的导入符号表，查找对应的依赖的动态链接库，如有跳转，则跳到3 
  - 调用该动态链接库的初始化函数
+ 初始化应用程序的全局变量，全局对象自动调用构造函数
+ 进入应用程序入口点函数开始执行
### atomoic内存顺序
有六个内存顺序选项可应用于对原子类型的操作：
+ memory_order_relaxed：在原子类型上的操作以自由序列执行，没有任何同步关系，仅对此操作要求原子性。
+ memory_order_consume：memory_order_consume只会对其标识的对象保证该对象存储先行于那些需要加载该对象的操作。
+ memory_order_acquire：使用memory_order_acquire的原子操作，当前线程的读写操作都不能重排到此操作之前。
+ memory_order_release：使用memory_order_release的原子操作，当前线程的读写操作都不能重排到此操作之后。
+ memory_order_acq_rel：memory_order_acq_rel在此内存顺序的读-改-写操作既是获得加载又是释放操作。没有操作能够从此操作之后被重排到此操作之前，也没有操作能够从此操作之前被重排到此操作之后。
+ memory_order_seq_cst：memory_order_seq_cst比std::memory_order_acq_rel更为严格。memory_order_seq_cst不仅是一个"获取释放"内存顺序，它还会对所有拥有此标签的内存操作建立一个单独全序。
除非你为特定的操作指定一个顺序选项，否则内存顺序选项对于所有原子类型默认都是memory_order_seq_cst。
### c++内存对齐
+ 编译器为结构体的每个成员按其自然边界（alignment）分配空间，即所谓的“对齐”，比如4字节的int型，其起始地址应该位于4字节的边界上，即起始地址能够被4整除
+ 应用：struct、class、union
+ 原则
  - struct与union，第一个数据成员放在offset为0的地方，以后每个数据成员存储的起始位置从该成员大小或成员子成员大小的整数倍开始
  - 如果一个结构里有某些结构体成员,则结构体成员要从其内部"最宽基本类型成员"的整数倍地址开始存储。(struct a里存有struct b,b里有char,int ,double等元素,那b应该从8的整数倍开始存储)
  - 收尾工作:结构体的总大小，也就是sizeof的结果，必须是其内部最大成员的"最宽基本类型成员"的整数倍。不足的要补齐。(基本类型不包括struct/class/uinon)
  - sizeof(union)，以结构里面size最大元素为union的size，因为在某一时刻，union只有一个成员真正存储于该地址
~~~
union example {    
  int a[5];    
  char b;    
  double c;   
};   
int result = sizeof(example);   /* 如果以最长20字节为准，内部double占8字节，这段内存的地址0x00000020并不是double的整数倍，只有当最小为0x00000024时可以满足整除double（8Byte）同时又可以容纳int a[5]的大小，所以正确的结果应该是result=24 */  
struct example {    
  int a[5];    
  char b;    
  double c;   
}test_struct; 
int result = sizeof(test_struct);   /* 如果我们不考虑字节对齐，那么内存地址0x0021不是double（8Byte）的整数倍，所以需要字节对齐，那么此时满足是double（8Byte）的整数倍的最小整数是0x0024，说明此时char b对齐int扩充了三个字节。所以最后的结果是result=32 */  
struct example {    
  char b;    
  double c;    
  int a;   
}test_struct;   
int result = sizeof(test_struct);   /* 字节对齐除了内存起始地址要是数据类型的整数倍以外，还要满足一个条件，那就是占用的内存空间大小需要是结构体中占用最大内存空间的类型的整数倍，所以20不是double（8Byte）的整数倍，我们还要扩充四个字节，最后的结果是result=24 */
~~~

### 面向对象
+ 一切皆对象，属性变量与函数打包成一个类进行封装，减少重复代码重写
### 封装
+ 隐藏对象属性和细节，对外公开接口和对象交互，不想让人看的，用protect和private将成员封装，开放共有的成员函数，本质是一种管理
### 继承
| 继承方式        | private | protected | public  |
|-------------|-------|---------|---------|
| 基类private   | 不可见   | 不可见     | 不可见     |
| 基类protected | private | protected | protcted |
| 基类public    | private | protected | public  |
### 虚继承
+ 解决菱形继承的二义性问题，多重继承在菱形继承下可能对基类多重拷贝
~~~
class A{
public:
    int _a;
};
class B :virtual public A{
public:
    int _b;
};
class C :virtual public A{
public:
    int _c;
};
class D :public B, public C{
public:
    int _d;
};
~~~
+ 虚继承中A共享，BC虚基表指针，指向虚基表，虚基表存放相对偏移量，用来找虚基类
### 虚函数
+ 普通函数只能重载，不能声明为虚函数
+ 构造函数不能声明虚函数
+ 内联函数不能声明为虚函数，内联编译时展开，虚函数运行时动态绑定
+ 静态函数不能声明为虚函数，每个类共享一份代码，不需要动态绑定
+ 友元函数不支持虚函数，c++不支持友元函数的继承，没有继承特性的函数无法作为虚函数
### 多态
+ 父类指针指向子类实例，通过父类指针调用实际子类成员函数
+ 两种方式，重写（动态多态），重载（静态多态） 
#### 重写
  - 派生类中重新定义的函数，函数名参数列表返回值类型与基类一致，派生类对象调用派生类重写函数，基类被重写函数要有virtual修饰，结合动态绑定
  - 虚函数，类的成员函数
  - 存在虚函数的类有一维的虚函数表，类的对象有指向虚表开始的虚指针，虚表与类对应，虚表指针与对象对应
  - 多态性为接口的多种实现，分类的多态性和函数的多态性
  - 纯虚函数，虚函数=0
  - 抽象类包括至少一个纯虚函数
  - 抽象类必须在子类实现这个函数，先有名词，没有内容，派生类实现内容
  - 所有派生的类对象都可以执行纯虚函数的动作，但类无法为纯虚函数提供合理的缺省实现
  - 构造函数可以调用虚函数，但可能达不到想要的效果
  - 派生类对象进入基类构造函数时，对象类型变成基类，此时调用虚函数，达不到多态的效果
  ~~~
  class A { 
    public: 
      virtual void fun()  {   
        cout << "A";  
      } 
  }; 
  class B :public A { 
    public:  
      virtual void fun()  {
        cout << "B";  
      } 
  }; 
  int main(void) {  
    A* a = new B();  
    a->fun();//输出B，A类中的fun在B类中重写 
  }
  ~~~
#### 重载
  - 同一函数名根据函数列表调用，命名倾轧，编译阶段完成
  ~~~
  class A {  
    void fun() {};  
    void fun(int i) {};  
    void fun(int i, int j) {};     
    void fun1(int i,int j){}; 
  };
  ~~~
+ c实现重载的方式
  - 函数指针，重载函数不能使用同名称，类似实现函数重载
  - 重载函数使用可变参数，如打开文件open函数
  - gcc内置函数，程序使用编译函数实现函数重载
~~~
void func_int(void * a) {     
  printf("%d\n",*(int*)a);  //输出int类型，注意 void * 转化为int 
}   
void func_double(void * b) {     
  printf("%.2f\n",*(double*)b); 
}   
typedef void (*ptr)(void *);  //typedef申明一个函数指针   
void c_func(ptr p,void *param) {      
  p(param);                //调用对应函数 
}   

int main() {     
  int a = 23;     
  double b = 23.23;     
  c_func(func_int,&a);     
  c_func(func_double,&b);     
  return 0; 
}
~~~
### 构造函数
+ 默认构造函数
+ 有参构造函数
  - 存在有参构造，不提供默认构造
+ 拷贝构造函数，必须是引用传递，否则变成传值，传值的方式会调用拷贝构造，死循环
~~~
class Test {     
  int i;     
  int *p; 
  public:     
  Test(int ai,int value)     {         
    i = ai;         
    p = new int(value);     
  }     
  ~Test() {         
    delete p;     
  }     
  Test(const Test& t)     {         
    this->i = t.i;         
    this->p = new int(*t.p);     
  } 
}; //复制构造函数用于复制本类的对象 
int main(int argc, char* argv[]) {     
  Test t1(1,2);     
  Test t2(t1);//将对象t1复制给t2。注意复制和赋值的概念不同     
  return 0; 
}
~~~
+ 赋值构造函数默认实现的是值拷贝（浅拷贝）。
~~~
class HasPtr
{
public:
    HasPtr(const string& s = string()) :ps(new string(s)), i(0) {}
    ~HasPtr() { delete ps; }
private:
    string * ps;
    int i;
};
HasPtr f(HasPtr hp)
{
    HasPtr ret = hp;
    ///... 其他操作
    return ret;
  //当函数执行完了之后，将会调用hp和ret的析构函数，将hp和ret的成员ps给delete掉，
  //但是由于ret和hp指向了同一个对象，因此该对象的ps成员被delete了两次，这样产生一个未定义的错误，
  //以说，如果一个类定义了析构函数，那么它要定义自己的拷贝构造函数和默认构造函数。
}
~~~
+ 移动构造函数
  - 将其他类型变量隐式转换为本类对象，对象值真实转移，源对象丢失内容
  - 形参为右值引用
  - 生成一个指针指向源对象或变量的地址，接管源对象内存，相对于大量数据的拷贝的拷贝节省时间和内存空间
~~~
Student(int r) {  
  int num=1004;  
  int age= r; 
~~~
~~~
class Example6 {
  string* ptr;
 public:
  Example6 (const string& str) : ptr(new string(str)) {}
  ~Example6 () {delete ptr;}
  // 移动构造函数，参数x不能是const Pointer&& x，
  // 因为要改变x的成员数据的值；
  // C++98不支持，C++0x（C++11）支持
  Example6 (Example6&& x) : ptr(x.ptr){
    x.ptr = nullptr;
  }
  // move assignment
  Example6& operator= (Example6&& x){
    delete ptr;
    ptr = x.ptr;
    x.ptr=nullptr;
    return *this;
  }
  // access content:
  const string& content() const {return *ptr;}
  // addition:
  Example6 operator+(const Example6& rhs){
    return Example6(content()+rhs.content());
  }
};
int main () {
  Example6 foo("Exam");           // 构造函数
  // Example6 bar = Example6("ple"); // 拷贝构造函数
  Example6 bar(move(foo));     // 移动构造函数
  // 调用move之后，foo变为一个右值引用变量，
  // 此时，foo所指向的字符串已经被"掏空"，
  // 所以此时不能再调用foo
  bar = bar+ bar;             // 移动赋值，在这儿"="号右边的加法操作，
  // 产生一个临时值，即一个右值
  // 所以此时调用移动赋值语句
  cout << "foo's content: " << foo.content() << '\n';
  return 0;
}
~~~
+ 默认存在
  - 无参构造
  - 拷贝构造
  - 赋值运算符
  - 析构（非虚）
### 初始化顺序
+ 创建派生类的对象，基类构造函数，优先与派生类的成员类
+ 成员类的构造函数，优先于本身的构造函数
+ 有多个基类，调用顺序为类在派生表中出现的顺序
+ 有多个成员类，调用顺序为对象在类中的声明的顺序
+ 不能直接向基类数据成员赋值，把值传递给适当的基类构造函数，否则两个函数实现紧耦合，难以修改与扩展
+ 析构顺序相反
### 转型
+ 子转父，dynamic_cast<type_id>(expression),安全，不会丢失数据
+ 父转子，强制转换，不安全，会有数据丢失，原因，父类指针引用内存可能不包含子类的成员内存
### 浅拷贝
+ 值拷贝，指针地址不变，会重复释放同一块内存
### 深拷贝
+ 开辟出和源对象一样的大小空间，不会出现重复释放同一块的内存
~~~
STRING( const STRING& s )
{
    //_str = s._str;
    _str = new char[strlen(s._str) + 1];
    strcpy_s( _str, strlen(s._str) + 1, s._str );
}
STRING& operator=(const STRING& s)
{
    if (this != &s)
    {
        //this->_str = s._str;
        delete[] _str;//先释放旧空间
        this->_str = new char[strlen(s._str) + 1];//申请一样的空间
        strcpy_s(this->_str, strlen(s._str) + 1, s._str);//拷贝
    }
    return *this;
}
~~~
### 虚析构
+ 父类析构虚析构，new子类，基类指针指向子类，释放基类指针可以释放子类空间，防止内存泄漏，否则只析构基类
### 虚构造
+ 虚函数对应一个vtale，表的地址存储在对象的内存空间，如果构造函数为虚函数，需要从vtable调用，但对象还未实例化，没有内存空间，产生悖论
+ 虚函数用于信息不全，使重载函数得到相应的调用，构造函数本身初始化实例，没有必要使虚函数，虚函数作用父类指针调用时调用子类函数，构造函数创建时使用，不可能通过父类指针调用
### 虚基类
+ 被继承的类前加virtual，被继承的类的为虚基类
+ 虚继承的类可以被实例化
### 模板类
+ 实例化，生成的类或函数按照模板定义实现
  - 显式实例化，告诉模板应该使用什么样的类型去生成具体的类或函数
  - 隐式实例化，编译器决定使用什么类型实例化模板
+ 具体化，模板使用某种类型时生成的类或函数不能满足需要，修改原模板的定义，使用该类型时，按照具体的定义实现，相当于特殊处理
~~~
// #1 模板定义
template<class T>
struct TemplateStruct
{
    TemplateStruct()
    {
        cout << sizeof(T) << endl;
    }
};

// #2 模板显示实例化
template struct TemplateStruct<int>;

// #3 模板具体化
template<> struct TemplateStruct<double>
{
    TemplateStruct() {
        cout << "--8--" << endl;
    }
};

int main()
{
    TemplateStruct<int> intStruct;
    TemplateStruct<double> doubleStruct;

    // #4 模板隐式实例化
    TemplateStruct<char> llStruct;
}
~~~
### 类内定义引用数据成员
+ 不能使用默认构造初始化，必须提供构造函数初始化引用成员变量，否则未初始化错误
+ 构造函数的形参为引用类型
+ 不能在构造函数里初始化，必须在初始化列表初始化
### 仿函数
+ 重载()的函数
~~~
class ShorterThan {
 public:
     explicit ShorterThan(int maxLength) : length(maxLength) {}
     bool operator() (const string& str) const {
         return str.length() < length;
     }
 private:
     const int length;
 };
~~~
### 类模板
+ 模板的定义，不是实实在在的类，定义中用到通用类型参数
+ 类型参数可以有多个，每个类型前加class，定义对象时代入实际类型名
+ 注意作用域，只能在有效作用域内定义对象
+ 可以作为基类，派生出派生模板类
### 模板类
+ 类模板的实例化，类定义中参数被实际类型所代替
### 虚函数表
+ 存储虚函数地址的数组，以null结尾，虚表编译阶段生成，对象内存空间开辟后，写入对象中的vfptr，调用构造函数
+ 考虑虚表二次写入机制，两次构造函数虚表写两次
+ 编译期生成基类与派生类的虚表，派生类的虚表不是真正的派生类虚表
+ 派生类对象进行给基类成员开辟内存，指向基类虚表
+ 调用基类构造函数，vfptr指向null
+ 派生类对象为自己的成员开辟内存
+ 虚表合并，生成派生类最终的虚函数表
+ 将vfptr指向派生类的虚表
+ 调用派生类的构造函数
+ 虚函数指针合并


## STL
### 容器
#### 顺序容器
+ vector动态数组，元素内存连续存放，随机存取O(1)，尾部增删O(1)
  - 增加元素
  ~~~
  //新增元素  
  void insert(const_iterator iter,const T& t ) {    
    int index=iter-begin();  
    if (index<size_)  {   
      if (size_==capacity_)   {    
        int capa=calculateCapacity();    
        newCapacity(capa);   
      }   
      memmove(buf+index+1,buf+index,(size_-index)*sizeof(T));    
      buf[index]=t;   
      size_++;  
    }  
  }
  ~~~
  - 删除元素
  ~~~
  //删除元素  
  iterator erase(const_iterator iter) {     
    int index=iter-begin();      
    if (index<size_ && size_>0)     {         
      memmove(buf+index ,buf+index+1,(size_-index)*sizeof(T));          
      buf[--size_]=T();     
    }      
    return iterator(iter);  
  } 
  ~~~
  - 迭代器
  ~~~
  //迭代器的实现 
  template<class _Category,class _Ty,class _Diff = ptrdiff_t,class _Pointer = _Ty *,class _Reference = _Ty&> 
  struct iterator {         
    // base type for all iterator classes     
    typedef _Category iterator_category;    
    typedef _Ty value_type;     
    typedef _Diff difference_type;     
    typedef _Diff distance_type;    // retained     
    typedef _Pointer pointer;     
    typedef _Reference reference; 
  };
  ~~~

+ deque双向队列，元素内存连续存放，随机存取O(1)，两端增删O(1)
+ list双向链表，元素内存不连续存放，增删O(1)，不支持随机存取
#### 关联容器，元素排序，红黑树（非严格平滑二叉搜索数）实现
+ set/multiset集合
+ map/multimap根据键值排序与检索
+ 键值无法修改
### 迭代器
+ 用于提供一种方法顺序访问一个聚合对象种各个元素，不暴露对象内部表示，可以在不知道对象内部表示的情况下，按照一定顺序访问聚合对象的各个元素
+ 不是指针，是类模板，表现的像指针，重载了指针的一些操作符，本质封装了原生指针，相当于智能指针，返回对象的引用
+ vector,deque，随机访问，erase后后面迭代器往前移动一位
+ map，set，双向迭代器，erase后当前迭代器失效，不影响后面的迭代器
+ list，双向迭代器，erase返回下一个有效的迭代器，上述两种方法都可以使用

### 容器适配器，封装了基本容器
+ stack，queue，priority_queue
### 空间配置器
+ 空间配置与对象构造分割
+ 内存配置：alloc::allocate()，内存释放：alloc::deallocate()，对象构造：::construct()，对象释放：::destroy()
+ 内存空间的配置与释放，两级配置器，
  - 一级配置器考虑大块内存空间，利用malloc与free实现
  - 二级配置器考虑小块内存空间（最大化解决内存碎片问题），链表free_list维护内存池，链表通过union实现，空闲的内存块挂在一起，一旦被使用，从链表剔除
### 算法，操作容器中的数据的模板函数
### 仿函数，函数对象，重载()
### resize与reserve
+ capacity能够容纳的最大元素个数
+ size元素的实际个数
+ resize既分配空间也创建对象，既修改capacity，也修改size，带两个参数
+ reserve预留空间，不创建对象，通过insert或push_back创建对象，只修改capacity，带一个参数
### push_back与emplace_back
+ push_back构造临时对象拷贝到容器末尾
+ emplace_back在容器末尾构造对象，省去拷贝过程
### 容器动态链接可能产生的问题
+ 给动态库函数传递容器的对象本身，会出现内存堆栈破坏的问题
+ 原因，容器与动态链接库互相支持不够好，动态链接库函数使用容器，只能传递容器的引用，并且保证容器大小不能超出初始大小，否则容器重新分配，出现内存堆栈破坏

