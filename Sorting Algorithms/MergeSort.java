import java.util.Arrays;

class MergeSort{
  public static void main(String[] args) {
    int A[]={2,5,7,9,12,6,1,100};
    int C[]=merge_sort(A);
   System.out.println( Arrays.toString(C));
  }
  static int[] merge(int [] first,int [] second){

     int mix[]=new int[first.length+second.length];

    int i=0,j=0,k=0;
    while(i<first.length && j<second.length){
        if(first[i]<second[j])
              mix[k++]=first[i++];
        else 
              mix[k++]=second[j++];
    }
    while(i<first.length)
        mix[k++]=first[i++];
    while(j<second.length)
        mix[k++]=second[j++];



     return mix;
  }
  static int[] merge_sort(int []arr){

    if(arr.length==1)
        return arr;
     int mid=arr.length/2;

     int [] left=merge_sort(Arrays.copyOfRange(arr, 0,mid));
     int [] right=merge_sort(Arrays.copyOfRange(arr, mid,arr.length));

      return merge(left, right);
    }
}