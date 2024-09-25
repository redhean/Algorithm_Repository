import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());

        StringTokenizer st = new StringTokenizer(br.readLine());
        int[] arr = new int[N];
        for(int i = 0; i < N; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }

        Arrays.sort(arr);
        int result = 0;

        for(int i = 0; i < N; i++) {
            int left = 0;
            int right = N - 1;

            while(true) {
                if(left == i)
                    left++;
                else if(right == i)
                    right--;
                
                if(left >= right)
                    break;

                int sum = arr[left] + arr[right];

                if (sum < arr[i]) {
                    left++;
                }
                else if(sum > arr[i]){
                    right--;
                }
                else{
                    result++;
                    break;
                }
            }
        }
        System.out.println(result);
    }
}
