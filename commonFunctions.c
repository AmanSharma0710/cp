//Find gcd of two numbers
int gcd (int a, int b)
{
   int r;

   if ((a == 0) && (b == 0)) {
      return 0;
   }

   if (a < 0) a = -a;
   if (b < 0) b = -b;
   if (b > a) { r = a; a = b; b = r; }

   while (b) {
      r = a % b;
      a = b;
      b = r;
   }

   return a;
}
//Factorial
int factorial(int n){
    if (n==1){
        return n;
    }
    else {
        return n*factorial(n-1);
    }
}
//Power function
int power(int x, int n)
{
    if (n != 0)
        return (x*power(x, n-1));
    else
        return 1;
}

//Find prime number
int isPrime(int n)
{
    if (n <= 1)
        return 0;

    for (int i = 2; i < (int)sqrt(n); i++)
        if (n % i == 0){
            return 0;
        }
    return 1;
}

//Find max element in an array
int largest(int arr[], int n)
{
    int i;
     
    // Initialize maximum element
    int max = arr[0];
 
    // Traverse array elements
    // from second and compare
    // every element with current max
    for (i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
 
    return max;
}

//Binary search
int binsearch ( int A[], int x, int L, int R )
{
   int M;

   printf("L = %d, R = %d\n", L, R);

   if (L == R) return (x == A[L]) ? 1 : 0;

   M = (L + R) / 2;
   if (x <= A[M]) return binsearch(A,x,L,M);
   else return binsearch(A,x,M+1,R);
}