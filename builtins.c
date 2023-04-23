#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

//vaihda null ja 0 getcwd:stä jos ei saa käyttää?? NULL kertoo että getcwdn pitää itse allocoida meille buffer
// ja 0 käskee sen itse tehdä oikean kokoisen
// https://www.qnx.com/developers/docs/7.1/#com.qnx.doc.neutrino.lib_ref/topic/g/getcwd.html

int built_pwd() 
{
    char *cwd = getcwd(NULL, 0);
    if (cwd == NULL)
	{
    	perror("getcwd");
		free(cwd);
        exit(1);
    }
    printf("%s\n", cwd);
    free(cwd);
    return 0;
}

//lisätään: parsetaan argumentit ja chdir pyydettyyn pathiin.

int	built_cd(char **argv)
{
    if (chdir(argv[1]) != 0) 
	{
        perror("chdir");
        exit(1);
    }
    return 0;
}

