# calculator

## attention
### input文件规范
1. input文件中的表达式不需要等号  
2. input文件中的表达式最后加入quit并换行  
3. 请使用半角符号  
4. 使用pi和e的时候请用括号括起  

### 命令行输入规范
1. 请使用半角字符  
2. 使用pi和e的时候请用括号括起

### 编码格式
1. 请用utf-8格式打开源代码以保证交互以及注释不乱码

### 优先级实现参考
> 数据结构《严》 优先级表<br />
> ![](http://images.cnitblog.com/blog/443163/201308/07150219-dcbf61ec400d4f18baf50388d1abc619.png)


___
## 版本号更新

## v0.2.0
### 2016.11.29
**严重bug发现以及修复**  
**1.形于sin(a+b)类似表达式，括号内运算无效**  
**2.在乘除后的()内运算无效**  

增添特性  
- 修复只输入'\n'程序奔溃的问题  
- 增加pi(圆周率)和e(欧拉数)  

原特性  
- 支持算数优先级，指数，对数，三角函数运算  
- 输入错误操作符与表达式违法时，程序正常退出并给出错误代码  
- 支持文件操作，可从input文件中读取字符串  

暂存问题：  
1. pi运算不精确



## v0.1.1
### 2016.11.28
增添特性   
- 支持文件操作，可从input文件中读取字符串

原特性  
- 支持算数优先级，指数，对数，三角函数运算  
- 输入错误操作符与表达式违法时，程序正常退出并给出错误代码  


暂存问题：  
1. pi的运算无法精确  
2. 若只输入一个'\n',程序崩溃




## V0.1.0
### 2016.11.26
初始版本<br />特性：<br />
- 支持算数优先级，指数，对数，三角函数运算<br />
- 输入错误操作符与表达式违法时，程序正常退出并给出错误代码<br /><br />

暂存问题：<br />
1. pi的运算无法精确<br />
2. 文件操作尚未完成<br />
3. 若只输入一个'\n',程序崩溃<br />
