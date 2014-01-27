/*
* Locate first occurrence of character in string.
* -----------------------------------------------
* Returns a pointer to the first occurence of character in the C
* string str. The terminating NULL-character is considered part of
* the C string. Therefore, it can also be located in order to 
* retrieve a pointer to the end of a string.
*/
char *
strChr(char *str, int chr){
	if (str == NULL)
	{
		return NULL;
	}
	else if ( (int)str[0] == chr )
	{
		return &str[0];
	}
	else
		return strChr( str+1, chr );
}
/*
* Locate last occurrence of character in string.
* -----------------------------------------------
* Returns a pointer to the last occurence of character in the C
* string str. The terminating NULL-character is considered part of
* the C string. Therefore, it can also be located in order to 
* retrieve a pointer to the end of a string.
*/
char *
strRChr(char *str, int chr){
	int length = strlen(str);
	if (str == NULL)
	{
		return NULL;
	}
	else if ( (int)str[length-1] == chr )
	{
		return &str[length-1];
	}
	else{
		str[length-1] = '\0';
		return strRChr( str, chr );
	}
}

/*
* This implementation recursive to calculate combination.
*
**/
int
getCombinationRec(int n, int k){
	if ( n >= 0 )
	{
		if ( k == 0 )
		{
			return 1;
		}
	}
	if ( k > 0 )
	{
		if ( n == 0 )
		{
			return 0;
		}
	}
	
	return getCombinationRec(n-1,k-1) + getCombinationRec(n-1,k);
}
/*
* This implementation iterative to calculate combination.
*
**/
int
getCombinationIter(int n, int k){
	return calculateFactorial(n) /
			( calculateFactorial(k) * calculateFactorial(n-k) );
}
int
calculateFactorial(int n){
	int i = 1, result = 1;

	if (n == 0 || n == 1)
	{
		return 1;
	}

	for ( i = 1; i <= n; ++i)
	{
		result *= i;
	}
	return result;
}