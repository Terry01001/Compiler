/* Test file: Perfect test file
 * Compute sum = 1 + 2 + ... + n
 */
class sigma {
  // "final" should have const_expr
  final int n = 10;
  int sum, index;
  static int counter ;
  int x, y ;
  /*Duplicate declare x*/
  int x ;
  int z;
  int h b ;
  /*Need  ',' before y*/
  float w;
  
  int d;
  Point p = new Point()
  /*Need ';' at EOL*/
  int w,q;


  main()
  {
    index = 0;
    sum = 0;
    while (index <= n)
    {
      sum = sum + index;
      index = index + 1;
    }
    print(sum);
  }
  void clear()
    {
        x = 0 ;
        y = 0 ;
    }
}
class Point
{
	int x, y ;
	int p;
	boolean test()
	{	
		/*Another x, but in different scopes*/
		int x;
		/*Another x in the same scope*/
		char x;
		{
			boolean w;
		}
		/*Another w in the same scope*/
		int w;
	}
  void sum(){
    //------NEVER USED
          int sumxyz = x + y + z ;
      }
      void main() {
    //------ARRAY
          int [] i= new int [1];
          for(i[0] = 0; i[0]<5; i[0]++)
              i[0]++;
    
    //------NEW CLASS
          Point lowerLeft = new Point() ;
    
    //------ERROR CONDITION
          while(**/a++){
              print("error!!");
          }
    //------CLASS DECLARE
          class Point {
              int x, y, z;
          }
      }
}
class Test
{
	/*Another p, but in different scopes*/
	Point p = new Point();
  int add(int a1, int a2){
    return (a1 + a2);
}
void main() {
    int x, y, z;
    for(int i=0;i<2;i++){
        if(i==0){
//--------------ELSE WITHOUT IF
            else
                i = 1;
        }
        for(x = 0; x<5;x++){
            y++;
//--------------FUNCTION CALL
            x = add(x,y);
            x = z(x,y);
        }
    }
    print("x:"+x+"y:"+y);
    z = ( x + y ) * 5 / 2 -- -y;
}
}
/* this is a comment // line// with some /* /*and
// delimiters */
