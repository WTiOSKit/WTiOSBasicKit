基类层

作用：
1. 定义实现规则（类似cpp抽象方法）
2. 提供基础部件的特殊交互方式
3. 提供一些Utility（另一种实现方式：在Utility中，对基础类进行extension）


BaseViewController                                                      V

BaseWebViewController                                                   V

MTLModel，如需要解析Dictionary到Model，可以继承MTLModel                     M

UITableViewCell+Base
仅用于写法约定