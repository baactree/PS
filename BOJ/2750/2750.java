import java.math.BigInteger;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int n = sc.nextInt();
		int[] dArr = new int[n];
		for (int i = 0; i < n; i++) {
			dArr[i] = sc.nextInt();
		}

		mySort(dArr);

		for (int i = 0; i < dArr.length; i++) {
			System.out.println(dArr[i]);
		}
	}

	static void mySort(int[] arr) {
		quickSort(arr, 0, arr.length - 1);
	}

	static void quickSort(int[] arr, int start, int end) {
		if (start >= end)
			return;

		int key = start;
		int left = start + 1, right = end, tmp;

		while (left <= right) {
			while (left <= right && arr[left] <= arr[key]) {
				left++;
			}
			while (left <= right && arr[right] >= arr[key]) {
				right--;
			}
			if(left<=right){
				tmp=arr[left];
				arr[left]=arr[right];
				arr[right]=tmp;
			}
		}
		tmp=arr[right];
		arr[right]=arr[start];
		arr[start]=tmp;
		quickSort(arr, start, right - 1);
		quickSort(arr, right + 1, end);
	}
}
