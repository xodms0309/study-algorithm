/*
 문자열 압축-같은 비트가 연속해서 등장하는 경우 문자열로 표기하여 저장공간을 줄일 수 있다. 예를 들면 "00011110"의 경우는 CFA라고 쓸 수 있다.
 단, 비트열이 1로 시작한다면 저장공간 가장 앞에 "1"을 붙여서 저장한다. "110"는 1BA로 작성할 수 있다.
 */
import java.util.Scanner;

public class Solution {
	public static void main(String args[]) {
		Scanner S=new Scanner(System.in);
		String input=S.nextLine();
		String answer=Solution(input);
		System.out.println(answer);
	}
	public static String Solution(String input) {
		String answer = "";
		int count=0;
		if (input.charAt(0)=='1') answer+='1';
		for (int i=1; i<input.length();i++) {
			if (input.charAt(i-1)!=input.charAt(i)) {
				answer+=(char)('A'+count); 
				count=0; // count 초기화
			}
			else count++;
		}
		answer+=(char)('A'+count);
		return answer;
	}
}
