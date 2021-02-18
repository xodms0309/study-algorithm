import java.io.*;
import java.util.*;
public class Main {
	
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		String input=br.readLine();
		Stack<Character> stack=new Stack<Character>();
		
		StringBuilder output=new StringBuilder();
		
		for (int i=0; i<input.length();i++) {
			if (input.charAt(i)>='A'&&input.charAt(i)<='Z') 
				output.append(input.charAt(i));  
			else if (input.charAt(i)=='+'||input.charAt(i)=='-') {
				while(!stack.isEmpty()&&(stack.peek()=='+'||stack.peek()=='-'||stack.peek()=='*'||stack.peek()=='/')) {
					output.append(stack.pop());
				}
				stack.push(input.charAt(i));
			}
			else if (input.charAt(i)=='*'||input.charAt(i)=='/') {
				while(!stack.isEmpty()&&(stack.peek()=='*'||stack.peek()=='/')) {
					output.append(stack.pop());
				}
				stack.push(input.charAt(i));
			}
			else if (input.charAt(i)=='(') 
				stack.push(input.charAt(i)); 
			else if (input.charAt(i)==')') { 
				while(stack.peek()!='(') {
					output.append(stack.pop());
				}
				stack.pop();
				
			}
		}
		while(!stack.isEmpty()) {
			output.append(stack.pop());
		}
		System.out.println(output);
	}
}
