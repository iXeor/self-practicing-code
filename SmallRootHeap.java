package Idea;
class Heap{
    private int data[];
    private int length;

    public Heap(){
        data = new int[100];
        length = 0;
    }
    public void addValue(int value){
        data[++length] = value;
    }
    public void exchangeValue(int aIndex,int bIndex){
        int temp = data[aIndex];
        data[aIndex] = data[bIndex];
        data[bIndex] = temp;
    }
    private void exchangeforSorter(int aIndex,int bIndex){
       if(data[aIndex]>data[bIndex]){
           int temp = data[aIndex];
           data[aIndex] = data[bIndex];
           data[bIndex] = temp;
       }
    }
    public void createHeap(){
        for(int i = length/2;i>=1;i--){
            recreateHeap(i,length);
        }
    }
    private void recreateHeap(int index,int length){
        int l_index,r_index,max_index,min_index;
        l_index = index*2;
        r_index = index*2+1;
        if(r_index <= length){
            if(data[r_index] > data[l_index]){
                max_index = r_index;
            }
            else{
                max_index = l_index;
            }
        }
        else {
            max_index = l_index;
        }
        if(data[index] < data[max_index]){
            exchangeValue(index,max_index);
        }
    }
    public void heapSorter() {
        int n = length;
        createHeap();
        while(n>0) {
            exchangeforSorter(1,n);
            n--;
            recreateHeap(1,n);
        }
        exchangeValue(1,2);
    }
    public void prtHeap(){
        for(int i = 1 ; i <= length ; i++){
            System.out.print(data[i]+"\t");
        }
        System.out.println();
    }
}
public class SmallRootHeap {
    public static void main(String[] args){
        Heap h1 = new Heap();
        h1.addValue(2);
        h1.addValue(23);
        h1.addValue(5);
        h1.addValue(7);
        h1.addValue(50);
        h1.addValue(8);
        h1.addValue(90);
        h1.prtHeap();
        h1.createHeap();
        h1.prtHeap();
        h1.heapSorter();
        h1.prtHeap();
    }
}
