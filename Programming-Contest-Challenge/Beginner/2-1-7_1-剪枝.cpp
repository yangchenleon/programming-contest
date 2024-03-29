/* 
 * 就是削减掉一些没必要的状态，如递归中sum已经超过要求的k了，那就应该到此为止
 * 
 * 主调函数及其变量存储在栈内存区，new和malloc的分配的内存叫堆内训
 * 栈内存有上限，因此递归深度有上限，java中可以设定参数指定栈大小
 * 不推荐全局变量，但是竞赛中函数不多且同时访问一个数组，全局很方便
 * 申请巨大数组，放在堆内存能减少的栈溢出的风险
 * 通常只需申请要求大小的数组，但是额外申请一点点能避免漏了'\0'等漏洞
 */