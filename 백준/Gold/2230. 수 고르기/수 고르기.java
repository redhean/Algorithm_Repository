import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N, M;
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        int[] arr = new int[N];
        for(int i = 0; i < N; i++) {
            arr[i] = Integer.parseInt(br.readLine());
        }

        Arrays.sort(arr);

        int left = 0;
        int right = 1;
        int result = 2000000001;

        while(true) {
            if(right >= N)
                break;

            if(arr[right] - arr[left] > M) {
                if(result > arr[right] - arr[left])
                    result = arr[right] - arr[left];
                left++;
            }
            else if(arr[right] - arr[left] < M) {
                right++;
            }
            else {
                result = M;
                break;
            }
        }

        System.out.println(result);
    }
}
