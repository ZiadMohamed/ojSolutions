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

	static int memo[][][], sz,sz2;
	static boolean a[],b[];
	static BigInteger ans,pow,zero,one,two;
	
	public static boolean solve(int ind,int prev,int change){
		if(ind==-1)return (change==0);
		
		
		if(memo[ind][prev][change]!=-1)
			return (memo[ind][prev][change]==1);
		
		
		boolean initial=a[ind];
		if(prev==1)initial=!initial;
		
		if(change==1){
			if(solve(ind-1,1,(initial==b[ind])?1:0)){
				memo[ind][prev][change]=1;
				return true;
			}
			memo[ind][prev][change]=0;
			return false;
		}
		
		if(initial!=b[ind]){
			if(solve(ind-1,0,1) || (ind==sz-1 && solve(ind-1,1,0))){
				memo[ind][prev][change]=1;
				return true;
			}
		}
		else{
			if(solve(ind-1,0,0) || (ind==sz-1 && solve(ind-1,1,1))){
				memo[ind][prev][change]=1;
				return true;
			}
		}
		
		
		
		memo[ind][prev][change]=0;
		return false;
	}
	
	
	public static void build(int ind,int prev,int change){
		if(ind==-1)return;
		
		
		
		boolean initial=a[ind];
		if(prev==1)initial=!initial;
		
		if(change==1){
			if(solve(ind-1,1,(initial==b[ind])?1:0)){
				ans=ans.add(pow);
				pow=pow.divide(two);
				build(ind-1,1,(initial==b[ind]?1:0));
				return;
			}
			return;
		}
		
		if(initial!=b[ind]){
			if(solve(ind-1,0,1)){
				pow=pow.divide(two);
				build(ind-1,0,1);
			}
			else if(ind==sz-1 && solve(ind-1,1,0)){
				ans=ans.add(pow);
				pow=pow.divide(two);
				build(ind-1,1,0);
			}
		}
		else{
			if(solve(ind-1,0,0)){
				pow=pow.divide(two);
				build(ind-1,0,0);
			}
			else if(ind==sz-1 && solve(ind-1,1,1)){
				ans=ans.add(pow);
				pow=pow.divide(two);
				build(ind-1,1,1);
			}
		}

		
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter writer = 
				new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		
		memo=new int[335][2][2];
		a=new boolean[335];
		b=new boolean[335];
		
		
		zero = new BigInteger("0");
		one = new BigInteger("1");
		two = new BigInteger("2");
		
		
		BigInteger x,y;
		int cs=1;
		while(true){
			StringTokenizer inp=new StringTokenizer(br.readLine());
			x=new BigInteger(inp.nextToken());
			y=new BigInteger(inp.nextToken());

			if(x.compareTo(zero)==0 && y.compareTo(zero)==0)break;
			
			
			sz=0;
			toBin(x,true);
			
			sz2=0;
			toBin(y,false);
			
			while(sz<sz2)a[sz++]=false;
			while(sz2<sz)b[sz2++]=false;
			
			
			
			for(int i=0;i<335;++i)
				for(int j=0;j<2;++j)
					for(int k=0;k<2;++k)
						memo[i][j][k]=-1;
			
			if(cs>1)writer.println();
			writer.print("Case Number "+cs+": ");
			++cs;
			
			if(solve(sz-1,0,0)){
				ans = new BigInteger("0");
				pow = two.pow(sz-1);
				build(sz-1,0,0);
				writer.println(ans);
			}
			else writer.println("impossible");
		}
		writer.close();
	}
	
	public static void toBin(BigInteger x,boolean f){
		while(x.compareTo(zero)==1){
			if(x.remainder(two).compareTo(one)==0){
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

}
