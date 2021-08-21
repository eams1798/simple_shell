#include "new_shell.h"



int main()
{
	char *strPATH = getenv_PATH();
	char **arrPATH = get_PATHS();
	char *sample;
	int i = 0;

	printf("%s\n\n", strPATH);
	(void)sample;
	sample = arrPATH[i];
	while(arrPATH[i] != NULL)
	{
		  printf("%sls\n", arrPATH[i]);
		    i++;
		      sample = arrPATH[i];
	}
	for (; i >= 0; i--)
	{
		  sample = arrPATH[i];
		    free(arrPATH[i]);
	}
	free(arrPATH);
	return(0);
}
