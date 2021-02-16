import java.util.*;
class Main {
    public static void main(String args[]) {
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();
        int m = scan.nextInt();
        int a[] = new int[n];
        for(int i=0;i<n;i++)
            a[i] = scan.nextInt();
        Map<Integer,Integer> count = new HashMap<Integer,Integer>();
        int c = 0;
        int ans = 0;
        for(int i=0;i<m;i++) {
            try {
                count.put(a[i], count.get(a[i])+1);
            }
            catch(Exception e) {
                count.put(a[i],1);
            }
        }
        ans = count.keySet().size();
        int temp = ans;
        for(int i=0;(i+m)<n;i++) {
            try {
                count.put(a[i+m], count.get(a[i+m])+1);
            }
            catch(Exception e) {
                temp++;
                count.put(a[i+m], 1);
            }
            count.put(a[i], count.get(a[i]) - 1);
            if(count.get(a[i])==0) {
                temp--;
            }
            ans = Math.max(ans,temp);
        }
        System.out.println(ans);
        scan.close();
    }
}