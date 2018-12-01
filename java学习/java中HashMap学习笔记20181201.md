---
title: Java 中HashMap学习过程中掌握的知识点总结（一）    
date: 2018-12-01    
tags: Java 
---

### 知识点如下：
1、Java类库为映射提供了两个通用的实现：HashMap和TreeMap。这两个类都实现了Map接口。散列映射对键值进行散列，树映射用键的整体顺序对元素进行排序，并将其最值成搜索树。    
2、Java编写的所有代码都位于某个类的内部。  
3、Java允许使用包（pacage）将类组织起来。导入包用import，将类放入包中需要将包的名字放在类源文件的开头，包中定义类的代码之前。
```
package com.horstmann.corejava;

public class Employee
{
	...
}

```    

4、go和python中也是用目录当做包，go中是在每个源码文件中指定package packname，则该源代码数据该包，导入的时候只能导入包的名字。python中是在目录下建立一个__init__.py文件，说明该目录是包，目录下的所有.py文件都属于该包，使用时导入比较随意。 
5、java中可以在eclips中查看库的源码文件，方法如下（亲测可用）：   

设置： 

    1.点 “window”-> "Preferences" -> "Java" -> "Installed JRES"
    2.此时"Installed JRES"右边是列表窗格，列出了系统中的 JRE 环境，选择你的JRE，然后点边上的 "Edit..."， 会出现一个窗口(Edit JRE)  
    3.选中rt.jar文件的这一项：“c:\program files\java\jre_1.5.0_06\lib\rt.jar” 
      点 左边的“+” 号展开它，
    4.展开后，可以看到“Source Attachment:(none)”，点这一项，点右边的按钮“Source Attachment...”, 选择你的JDK目录下的 “src.zip”文件
    5.一路点"ok",结束。
    dt.jar是关于运行环境的类库,主要是swing的包 
    tools.jar是关于一些工具的类库 
    rt.jar包含了jdk的基础类库，也就是你在java doc里面看到的所有的类的class文件    
    6、需要查看那个类时点击该类，进入类文件后
6、Java类中定义的public String toString()方法可以在调用System.out.println(对象)时被调用   
7、根据《Java核心编程卷1》，自己敲了一遍HashMap使用的源代码

```
package test;

import java.util.*;

public class MapTest {
	public static void main(String[] args)
	{
		/*
		Employee ljj = new Employee("ljj",10000);
		System.out.println(ljj);*/
		Map<String,Employee> staff = new HashMap<>();
		staff.put("144-25-5464", new Employee("Amy Lee"));
		staff.put("567-24-2546", new Employee("Harry Hacker"));
		staff.put("157-62-5527", new Employee("Gary Cooper"));
		staff.put("456-62-5627", new Employee("Francesca Cruz"));
		//print all entrys
		System.out.println(staff);
		//remove an entry
		staff.remove("567-24-2546");
		//replace an entry
		staff.replace("456-62-5627", new Employee("Francesca Miller"));
		//lookup
		System.out.println(staff.get("157-62-5527"));
		//iterate through all entries
		staff.forEach((k,v)->
		System.out.println("key = " + k + ", value="+v));
	}
}

class Employee{
	private String name;
	private double salary;
	
	public Employee(String n)
	{
		this.name = n;
		this.salary = 100000;
	}
	
	public String toString()
	{
		return "[name:"+this.name+" salary:"+this.salary+"]";
	}
}


```
