## 1000 A+B Problem

* 算法：直接相加
* 难点：无

## 1045 Bode Plot

* 算法：解方程。。。

    利用V2分别等于两个式子，将i,V2和V1带入，可得方程：R*C*d(Vs * cos(wt) - Vr * cos(wt + q))/dt  = Vr * cos(wt + q)

    根据求导公式：d(cos(x))/dx = -sinx可将原方程化为：R*C*w*(Vr*sin(wt + q) - Vs*sin(wt)) = Vr * cos(wt + q)
    
    在这里三角函数的参数有两个：wt+q和wt，我们分别令他们为0,方程分别可变为：R*C *w*Vs*sin(q) = Vr; R*C * w*sin(q) = cos(q)
    
    由2式得：cot(q) = R * C * w。
    
    由公式：sin^2(a) = 1/(cot ^2(a) + 1)
    
    可得：sin(q)=sqrt(1/(cot^2(q) + 1))
    
    即：sin(q) =sqrt(1/(R^2*C^2*w^2 + 1))
    
    代入1式可得：Vr = R * C * w * Vs * sqrt(1/(R^2*C^2*w^2 + 1))

* 难点：

    - 解方程。。。
    - 使用printf输出double一定要用%f。解释：

      printf的%f说明符的确既可以输出float型又可以输出double型。 根据"默认参数提升"规则（在printf这样的函数的可变参数列表中 ，不论作用域内有没有原型，都适用这一规则）float型会被提升为double型。因此printf()只会看到双精度数。对于scanf，情况就完全不同了，它接受指针，这里没有类似的类型提升。（通过指针）向float存储和向double存储大不一样，因此，scanf区别%f和%lf。严格地讲，%lf在printf下是未定义的，但是很多系统可能会接受它。要确保可移植性，就要坚持使用%f。

      下表列出了printf和scanf对于各种格式说明符可以接受的参数类型。
      
      |格式               |printf               |scanf
      |-----------------|---------------------|-----------------------|
      |%c               |  int                |  char*                |
      |%d, %i           |  int                |  int*                 |
      |%o, %u, %x       |  unsigned int       |  unsigned int*        |
      |%ld, %li         |  long int           |  long int*            |
      |%lo, %lu, %lx    |  unsigned long int  |  unsigned long int*   |
      |%hd, %hi         |  int                |  short int*           |
      |%ho, %hu, %hx    |  unsigned int       |  unsigned short int*  |
      |%e, %f, %g       |  double             |  float*               |
      |%le, %lf, %lg    |  n/a (undefined)    |  double*              |
      |%s               |  char*              |  char*                |
      |%[...]           |  n/a (undefined)    |  char*                |
      |%p               |  void               |  void**               | 
      |%n               |  int*               |  int*                 |
      |%%               |  none               |  none                 |

## 1051 P,MTHBGWB (PROBLEM_B)

* 算法：两个map, 字母到Morse和Morse到字母
* 难点：C语言没有map，用数组模拟。指针操作。。。

## 1068 Parencodings

* 算法：栈模拟。栈里保存所有未匹配的左括号index，当遇到一个右括号时，(右括号index - 栈顶左括号index + 1) / 2就是所要的w seq相应的值。
* 难点：注意输入的括号不一定是合法的，最后一个w seq值不能直接用p seq最后一个值。
