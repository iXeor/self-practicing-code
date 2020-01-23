package Idea;

import java.util.*;
import java.util.ListIterator;

public class ListTest {
    public static void main(String args[]){
        List<String> l1 = new ArrayList<String>();
        Set<String> all = new HashSet<>();
        Scanner sc = new Scanner(System.in);
        String str = sc.next();
        l1.add(str);
        l1.add(str);
        l1.add(str);
        all.add("GKD");
        all.add("WSL");
        System.out.println(all);
        Iterator<String> iter = l1.listIterator();
        while(iter.hasNext()){
            System.out.println(iter.next());
        }
        ListIterator<String> listIterator = (ListIterator<String>) l1.iterator();
        while(listIterator.hasNext()){
            System.out.println(listIterator.next());
        }
        while(listIterator.hasPrevious()){
            System.out.println(listIterator.previous());
        }
    }
}
