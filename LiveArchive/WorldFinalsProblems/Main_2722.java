import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.StringTokenizer;


public class Main_2722 { 
	// class name should be changed to "Main" before submitting on LiveArchive

	static int sz,sz2;
	static boolean a[],b[],arr[];
	static BigInteger ans,pow,two;
	
	public static boolean solve(boolean f){
		boolean change=false,prev=false;
		for(int i=sz-1;i>=0;--i){
			boolean initial=a[i];
			if(prev)initial=!initial;
			
			if(change){
				arr[i]=prev=true;
				change=(initial==b[i]);
				continue;
			}
			
			if(initial!=b[i]){
				if(!f && i==sz-1){
					arr[i]=prev=true;
					change=false;
				}
				else{
					arr[i]=prev=false;
					change=true;
				}
			}
			else{
				if(!f && i==sz-1)
					arr[i]=prev=change=true;
				
				else{
					arr[i]=prev=false;
					change=false;
				}
			}
		}
		return !change;
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter writer = 
				new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		

		a=new boolean[335];
		b=new boolean[335];
		arr=new boolean[335];
		

		two=new BigInteger("2");
		
		BigInteger x,y;
		int cs=1;
		while(true){
			StringTokenizer inp=new StringTokenizer(br.readLine());
			x=new BigInteger(inp.nextToken());
			y=new BigInteger(inp.nextToken());

			if(x.compareTo(BigInteger.ZERO)==0 && y.compareTo(BigInteger.ZERO)==0)break;
			
			
			sz=0;
			toBin(x,true);
			
			sz2=0;
			toBin(y,false);
			
			while(sz<sz2)a[sz++]=false;
			while(sz2<sz)b[sz2++]=false;

			
			if(cs>1)writer.println();
			writer.print("Case Number "+cs+": ");
			++cs;
			
			ans = BigInteger.ZERO;
			pow = BigInteger.ONE;
			
			if(!solve(true)){
				if(!solve(false)){
					writer.println("impossible");
					continue;
				}
				else toDec();
			}
			else toDec();
			
			writer.println(ans);
		}
		writer.close();
	}
	
	public static void toBin(BigInteger x,boolean f){
		while(x.compareTo(BigInteger.ZERO)==1){
			if(x.remainder(two).compareTo(BigInteger.ONE)==0){
				if(f)a[sz++]=true;
				else b[sz2++]=true;
			}
			else{
				if(f)a[sz++]=false;
				else b[sz2++]=false;
			}
			x=x.divide(two);
		}
	}
	
	public static void toDec(){
		for(int i=0;i<sz;++i){
			if(arr[i])ans=ans.add(pow);
			pow=pow.multiply(two);
		}
	}

}
