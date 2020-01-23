package Idea;                                                                           // 在包“Idea”内建立的类
import java.io.*;                                                                       // 引入java.io包
public class Counter {                                                                  // 建立的Counter类，设为Public(公共)权限

    private void reader(){                                                              // 建立类内的无返回值类型方法reader，内部用来实现读取文本文档与计数操作。
        int length = 0;                                                                 // 设单词个数为0（初始化用于记录单词个数的量）
        try {                                                                           // Java的try，catch语句，用于异常处理（比如找不到文件）
            FileReader file = new FileReader("D:\\作业\\TEST.txt");            // 引用java.io包内的Filereader类型的file用于存储预先选好的文本文档“"D:\作业\TEST.txt"”。
            BufferedReader buff = new BufferedReader(file);                             // 引用java.io包内的Bufferedreader类型的buff存储上面的file（缓冲，用于提高效率）
            String str = buff.readLine();                                               // 建立String类型的str,将buff内的字符逐行写入str里
            String temp,temp2,temp3;                                                    // 临时字符串
            while(str != null){                                                         // while循环，直到str内容变成空
                temp2 = str.replaceAll("'","");                       // 将“'”删除（实质为替换成空的字符），因为o'clock,I'm等算一个单词
                temp = temp2.trim();                                                    // 去除文件首部空格
                temp = temp.replaceAll("\\pP"," ");                   // 将其余符号转换成空格（理想状态下只需要查空格个数就知道有多少单词 问题： 文件尾部不是标点符号的话，单词数会少一个,单词间有多个空格会记录多次）
                char data[] = temp.toCharArray();                                       // 将str转换成字符数组，方便空格
                for(int i = 0; i < temp.length();i++){                                  // for循环，长度为字符数组的长度
                   if(data[i] == ' '){                                                  // if语句，用于判断是否为空格
                       length++;                                                        // 查到空格，单词数+1
                   }
                }
                str = buff.readLine();                                                  // 读取下一行的缓冲
                System.out.println(length);                                             // 输出单词个数
            }
            buff.close();                                                               // 结束后关闭buff流
            file.close();                                                               // 关闭file流
        } catch(IOException err) {                                                      // 异常处理，如果找不到文件，输出“文件不存在”
            System.out.println("文件不存在");
        }
    }
    public static void main(String[] args) {                                            // main函数
        Counter test = new Counter();                                                   // 用于测试方法可行性
        test.reader();
    }
}