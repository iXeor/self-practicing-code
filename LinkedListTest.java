package Idea;

import java.util.Scanner;

class Link{
    private class Node{
        private int data;
        private Node next;
        public Node(){
            data = 0;
            next = null;
        }
        public Node(int value){
            data = value;
            next = null;
        }
    }
    private Node headAddr;
    private Node searchValueAddr(int value){
        Node p = headAddr.next;
        while(p != null){
            if(p.data == value){
                return p;
            }
            p = p.next;
        }
        return null;
    }
    private Node searchPrevAddr(int value){
        Node p = headAddr.next;
        Node q = headAddr;
        while(p != null){
            if(p.data == value){
                return q;
            }
            q = p;
            p = p.next;
        }
        return null;
    }
    public void prtAllValue(){
        Node p = headAddr.next;
        while(p != null){
            System.out.print(p.data+" ");
            p = p.next;
        }
        System.out.println();
    }
    public Link(){
        headAddr = new Node();
        headAddr.next = null;
    }
    public void addValue(int value){
        Node addV = new Node(value);
        addV.next = headAddr.next;
        headAddr.next = addV;
    }
    public void addValueNonZero(){
        Scanner sc = new Scanner(System.in);
        for(;;){
            int x;
            x = sc.nextInt();
            if(x == 0) break;
            addValue(x);
        }
    }
    public void changeValue(int oldValue,int newValue){
        Node p = searchValueAddr(oldValue);
        if(p != null) p.data = newValue;
    }
    public void removeValue(int value){
        Node p,q;
        p = searchPrevAddr(value);
        if(p != null){
            q = p.next;
            p.next = q.next;
        }
    }
}

public class LinkedListTest {

    public static void main(String[] args) {
        Link l1 = new Link();
        l1.addValue(2);
        l1.addValue(6);
        l1.addValue(8);
        l1.prtAllValue();
        l1.changeValue(2,4);
        l1.prtAllValue();
        l1.removeValue(4);
        l1.prtAllValue();
        l1.addValueNonZero();
        l1.prtAllValue();
    }
}