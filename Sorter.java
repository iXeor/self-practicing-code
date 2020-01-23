package Idea;

public class Sorter {
    static void outPut(int data[]){
        for(int i = 0 ; i < data.length ; i++){
            System.out.print(data[i]+"\t");
        }
        System.out.println();
    }
    static void copyArr(int t[],int data[]){
        for(int i = 0 ; i < data.length ; i++){
            t[i] = data[i];
        }
    }
    static void BubbleSort(int data[]){
        int temp;
        int t[] = new int[data.length];
        System.out.println("变换前：");
        outPut(data);
        copyArr(t,data);
        for(int i = 0; i < t.length-1 ; i++){
            for(int j = 0 ; j < t.length-1 ; j++){
                if(t[j] < t[j+1]){
                    temp = t[j];
                    t[j] = t[j+1];
                    t[j+1] = temp;
                }
            }
        }
        System.out.println("变换后：");
        outPut(t);
    }
    static void SelectionSort(int data[]){
        int temp;
        int t[] = new int[data.length];
        copyArr(t,data);
        System.out.println("变换前：");
        outPut(data);
        for(int i = 0 ; i < t.length-1 ; i++){
            for(int j = i+1;j < t.length; j++){
                if(t[i] < t[j]){
                    temp = t[i];
                    t[i] = t[j];
                    t[j] = temp;
                }
            }
        }
        System.out.println("变换后：");
        outPut(t);
    }
    public static void main(String args[]){
        int data[] = {9,4,2,7,1,8,10};
        int data2[] = {9,0,5,2,1,65,3};
        BubbleSort(data);
        SelectionSort(data2);
        BubbleSort(data2);
        SelectionSort(data);
    }
}
