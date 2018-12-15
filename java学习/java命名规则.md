# 1、java命名规则    

package的命名: package 的名字由全部小写的字母组成，例如：com.runoob。    
class和interface的命名: class和interface的名字由大写字母开头而其他字母都小写的单词组成，例如：Person，RuntimeException。  
class变量的命名: 变量的名字用一个小写字母开头，后面的单词用大写字母开头,例如：index，currentImage。    
class 方法的命名: 方法的名字用一个小写字母开头，后面的单词用大写字母开头,例如：run()，getBalance()。   
staticfinal变量的命名: static final变量的名字所有字母都大写，并且能表示完整含义。例如：PI，PASSWORD。    
参数的命名: 参数的名字和变量的命名规范一致。   
数组的命名: 数组应该总是用这样的方式来命名：byte[] buffer。

# 2、一个完整的java源程序，应该包含下面部分  
package语句，该部分至多只有一句，必须放在源程序的第一句。  
import语句，该部分可以有若干import语句或者没有，必须放在所有的类定义之前。    
public classDefinition，公共类定义部分，**至多只有一个公共类的定义**，Java语言规定该Java源程序的文件名必须与该公共类名完全一致。          
classDefinition，类定义部分，可以有0个或者多个类定义。
interfaceDefinition，接口定义部分，可以有0个或者多个接口定义

# 3、package作用
由于Java编译器为每个类生成一个字节码文件，且文件名与类名相同因此同名的类有可能发生冲突。为了解决这一问题，Java提供包来管理类名空间，包实 提供了一种命名机制和可见性限制机制    

摘自：http://www.runoob.com/java/java-basic-syntax.html