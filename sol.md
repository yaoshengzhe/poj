## [1000 A+B Problem](1000_A+B_Problem/Solution.c)

* 算法：直接相加
* 难点：无

## [1002 487-3279](1002_487-3279/Solution.c)

* 算法：将输入转为数字，放入数组中，然后排序
* 难点：

    - qsort中的比较函数一定要返回0，如果两个数相同。因为3-way parition对于有大量重复的数字能处理更好。
    - 输出要限定数字位数，用来处理001这种情况

## [1003 Hangover](1003_Hangover/Solution.c)

* 算法：一个一个数
* 难点：无

## [1005 I Think I Need a Houseboat](1005_I_Think_I_Need_a_Houseboat/Solution.c)

* 算法：pi * r^2 / 2 <= year * 50 => year = floor(pi * r^2 / 100 + 1)
* 难点：pi精度要够3.1415926535897

## [1007 DNA Sorting](1007_DNA_Sorting/Solution.c)

* 算法：算逆序数，然后排序输出。
* 难点：

    - O(n^2)求逆序数会超时，要用mergesort来做 => O(nlogn)
    - 本题数据有特殊性，可以做到O(n)求逆序数。用counting sort的思想，对dna从后往前扫；用一个大小为4的数组保存ACGT到当前位置出现的数量，然后可以轻易求出逆序。

## [1045 Bode Plot](1045_Bode_Plot/Solution.c)

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

## [1046 Color Me Less](1046_Color_Me_Less/Solution.c)

* 算法：一个一个算
* 难点：无

## [1050 To the Max](1050_To_the_Max/Solution.c)

* 算法：一维最长子数组和的二维版本。对于二维数组(matrix)，枚举两行的所有可能(行号i <= j)。然后将这两行row中间的所有row按column相加，这就构成了一个一维数组，然后找最大子数组和。复杂度O(n^3)
* 难点：计算两个row之间的column和。这个可以令matrix(i, j)保存\sum matrix(k, j) (0 <= k <= i)，并且第一行row数字为0

## [1051 P,MTHBGWB (PROBLEM_B)](1051_P,MTHBGWB/Solution.c)

* 算法：两个map, 字母到Morse和Morse到字母
* 难点：C语言没有map，用数组模拟。指针操作。。。

## [1056 IMMEDIATE DECODABILITY](1056_IMMEDIATE_DECODABILITY/Solution.c)

* 算法：暴力或者用trie。这题的trie可以用二叉树实现，left表示0, right表示1。对于一个字符串的每个字符，将其插入到trie中；在插入过程中，如果发现某节点是leaf的情况，则表示该字符串和之前已插入trie的另外一个字符串有公共前缀，此时退出，输出不可直接decode
* 难点：用trie的话，难点在实现trie以及如何在插入过程中退出(如果插入点是某个已存在的leaf)

## [1057 FILE MAPPING](1057_FILE_MAPPING/Solution.c)

* 算法：递归。当遇到dir时，递归打印。当遇到file时，保存到一个数组中。当全部扫描完毕时，对之前的file数组排序打印。
* 难点：

    - 确定递归函数形式。int print_data_set(dataset, offset, len, indent)，该函数返回下一个要处理的数据在dataset里的offset
    - 了解qsort

## [1068 Parencodings](1068_Parencodings/Solution.c)

* 算法：栈模拟。栈里保存所有未匹配的左括号index，当遇到一个右括号时，(右括号index - 栈顶左括号index + 1) / 2就是所要的w seq相应的值。
* 难点：注意输入的括号不一定是合法的，最后一个w seq值不能直接用p seq最后一个值。

## [1080 Human Gene Functions](1080_Human_Gene_Functions/Solution.c)

* 算法：edit distance变种，推导公式都一样。
* 难点：注意下标计算，s(i)(j)表示的是字符串a[0..i-1]和b[0..j-1]的距离。

## [1095 Trees Made to Order](1095_Trees_Made_to_Order/Solution.c)

* 算法：

    - 先算出n个节点的二叉树一共有多少组合(catalan数)，公式N(i) = \sum N(j) * N(i - j - 1)。想象一下所有节点一字排开，选i作为根节点，那么此时一共有二叉树N(i-1) * N(n - i)个。注意N(0) = 1，否则乘法会导致后面很多数为0。
    - 计算以上数组的accumulative，即acc(i) = \sum N(j) (0 <= j <= i)
    - 递归函数print_tree(n, k)，该函数打印节点数为n的二叉树的第k个状态(k >= 1)

* 难点：递归调用时要计算左节点有几个以及左子树的状态，比较恶心，看代码。
