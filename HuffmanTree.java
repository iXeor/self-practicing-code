package Idea;

import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

class HNode {
    private int weight;
    private int lchild;
    private int rchild;
    private int parent;
    private String name;
    private String code;
    private HNode(String name, int w){
        this.weight = w;
        this.name = name;
        this.lchild = -1;
        this.rchild = -1;
        this.parent = -1;
        this.code = "";

    }
    HNode(){
        this(null,0);
    }
    int getWeight() {
        return weight;
    }
    void setWeight(int weight) {
        this.weight = weight;
    }
    int getLchild() {
        return lchild;
    }
    void setLchild(int lchild) {
        this.lchild = lchild;
    }
    int getRchild() {
        return rchild;
    }
    void setRchild(int rchild) {
        this.rchild = rchild;
    }
    int getParent() {
        return parent;
    }
    void setParent(int parent) {
        this.parent = parent;
    }
    String getCode() {
        return code;
    }
    void setCode(String code) {
        this.code = code;
    }
    String getName() {
        return name;}
    void setName(String name) {
        this.name = name; }
}
public class HuffmanTree {
    private HNode[] data;

    private int leafNum;


    private void create(){
        Scanner sc = new Scanner(System.in);
        System.out.println("请输入要传输的报文:");
        String str = sc.nextLine().toLowerCase();
        str = str.replace(" ", "");
        int[] c = new int[26];
        for (int i = 0; i < str.length(); i++) {
            c[str.charAt(i) - 'a']++;
        }
        int cnt = 0;
        for (int i = 0; i < 26; i++) {
            if (c[i] > 0)
                cnt++;
        }
        this.leafNum = cnt;

        data = new HNode[this.leafNum * 2 - 1];
        for (int i = 0; i < 2 * leafNum - 1; i++)
            data[i] = new HNode();

        cnt = 0;
        for (int i = 0; i < 26; i++) {
            if (c[i] > 0) {
                data[cnt].setName((char) (i + 'a') + "");
                data[cnt++].setWeight(c[i]);
            }
        }
        int m1, m2, x1, x2;
        for (int i = 0; i < this.leafNum - 1; ++i) {
            m1 = m2 = Integer.MAX_VALUE;
            x1 = x2 = 0;
            for (int j = 0; j < this.leafNum + i; ++j) {
                if ((data[j].getWeight() < m1) && (data[j].getParent() == -1)) {
                    m2 = m1;
                    x2 = x1;
                    m1 = data[j].getWeight();
                    x1 = j;
                } else if ((data[j].getWeight() < m2)
                        && (data[j].getParent() == -1)) {
                    m2 = data[j].getWeight();
                    x2 = j;
                }
            }
            data[this.leafNum + i].setWeight(data[x1].getWeight()
                    + data[x2].getWeight());
            data[this.leafNum + i].setLchild(x1);
            data[this.leafNum + i].setRchild(x2);
            data[x1].setParent(this.leafNum + i);
            data[x2].setParent(this.leafNum + i);
        }
    }
    private void print() {
        System.out.println("位置\t字符\t权值\t父结点\t左孩子结点\t右孩子结点");
        for (int i = 0; i < 2 * leafNum - 1; i++) {
            System.out.printf("%d\t%s\t%d\t%d\t%d\t%d\r\n", i,
                    data[i].getName(), data[i].getWeight(),
                    data[i].getParent(), data[i].getLchild(),
                    data[i].getRchild());
        }
    }
    private int preorder(HNode root,String code) {
        int sum = 0;
        if (root != null) {
            root.setCode(code);
            if(isLeaf(root)){
                System.out.println(root.getName() + ":" + root.getCode());
                return root.getWeight()*root.getCode().length();
            }

            if(root.getLchild()!=-1){
                sum +=preorder(data[root.getLchild()],code+"0");
            }
            if(root.getRchild()!=-1){
                sum +=preorder(data[root.getRchild()],code+"1");
            }
        }
        return sum;
    }
    private void levelOrder(){
        int root = 2*leafNum-2;
        if (root == -1) {
            return;
        }
        Queue<HNode> q = new LinkedList<HNode>();
        q.add(data[root]);
        int sum = 0;
        String code = "";
        while (!q.isEmpty()) {
            HNode tmp = q.poll();
            code = tmp.getCode();
            if(isLeaf(tmp)){
                sum +=tmp.getWeight()*tmp.getCode().length();
            }
            if (tmp.getLchild() != -1) {
                q.add(data[tmp.getLchild()]);
                data[tmp.getLchild()].setCode(code+"0");
            }
            if (tmp.getRchild() != -1) {
                q.add(data[tmp.getRchild()]);
                data[tmp.getRchild()].setCode(code+"1");
            }
        }
        System.out.println("总的报文长度为："+sum);
    }
    private String decodes(String codes){
        int root = 2*leafNum-2;
        if (root == -1) {
            return "";
        }
        Queue<HNode> q = new LinkedList<HNode>();
        q.add(data[root]);
        int i = 0;
        String str = "";
        while (!q.isEmpty()) {
            HNode tmp = q.poll();
            if(!codes.startsWith(tmp.getCode())) continue;
            if(isLeaf(tmp)){
                str = str + tmp.getName();
                codes = codes.substring(tmp.getCode().length());
                if(codes.length()>0){
                    while(!q.isEmpty()) q.poll();
                    q.add(data[root]);
                    continue;
                }
            }
            if (tmp.getLchild() != -1) {
                q.add(data[tmp.getLchild()]);
            }
            if (tmp.getRchild() != -1) {
                q.add(data[tmp.getRchild()]);
            }
        }
        return str;
    }
    private void traverse() {
        int root = 2*leafNum-2;
        if (root == -1) {
            return;
        }
        int sum = preorder(data[root],"");
        System.out.println("所有报文长度为（位）："+sum);
    }
    private boolean isLeaf(HNode p) {
        return ((p != null) && (p.getLchild() == -1) && (p.getRchild() == -1));
    }
    public static void main(String[] args) {
        HuffmanTree ht = new HuffmanTree();
        ht.create();
        ht.print();
        ht.traverse();
        String op = "";
        do{
            System.out.println("请输入一个报文编码进行解码:");
            Scanner sc = new Scanner(System.in);
            String codes = sc.nextLine();
            String decodes = ht.decodes(codes);
            if(decodes.length()==0){
                System.out.println("解码出错！");
            }else{
                System.out.println("对应的报文为："+decodes);
            }
            System.out.println("按X键退出，其他键继续");
            op = sc.nextLine();
        }while(!op.toLowerCase().equals("x"));
        System.out.println("程序退出");
    }
}