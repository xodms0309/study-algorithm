/*
 ���ڿ� ����-���� ��Ʈ�� �����ؼ� �����ϴ� ��� ���ڿ��� ǥ���Ͽ� ��������� ���� �� �ִ�. ���� ��� "00011110"�� ���� CFA��� �� �� �ִ�.
 ��, ��Ʈ���� 1�� �����Ѵٸ� ������� ���� �տ� "1"�� �ٿ��� �����Ѵ�. "110"�� 1BA�� �ۼ��� �� �ִ�.
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
				count=0; // count �ʱ�ȭ
			}
			else count++;
		}
		answer+=(char)('A'+count);
		return answer;
	}
}
