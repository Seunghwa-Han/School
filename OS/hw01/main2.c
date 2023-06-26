#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

void copy_file(char * source, char *target, int verbose_mode);
void copy_directory(char * source, char * target, int verbose_mode);

int main(int argc, char * argv[]){
	//...
	
	if (flag_f)
	{
		//set file name
		
		//copy file from source to destination
		copy_file(source, target, flag_v);
	}
	else if (flag_m)
	{
		// make target directory
		mkdir(...);

		for(int i=2; i<=argc-2; i++)
		{
			//set file name 
			strcpy(source, argv[i]);
			sprintf(target, "%s/%s",argv[argc-1], argv[i]);
			// copy file from source to destination
			copy_file(source, target, flag_v);
		}
	}
	else if (flag_d)
	{
		//set directory name

		// copy directory from source to destination
		copy_directory(source, target, flag_v);
	}

	return 0;
}

void copy_file(char * source, char *target, int verbose_mode)
{
	fd_source = open(source, O_RDONLY);

	// get file permission of source file
	if( stat(source, &sb) == -1)
	{

	}

	// create destination file 
	fd_target = open(target, O_WRONLY|O_CREAT|O_TRUNC, sb.st_mode);

	// copy contents from source file to destination file
	
}

void copy_directory(char * source, char * target, int verbose_mode)
{
	DIR * dir;
	struct dirent * entry;

	dir = opendir(source);
	if (dir)
	{
		// create target directory
		stat(..);
		mkdir(..);

		while ((entry=readdir(dir)))
		{
			// set source and target path name
			sprintf(source_pathname, ..);
			sprintf(target_pathname, ..);

			// get file or directory status
			if (stat(source_pathname, &info)==-1)
			{
				..
			}
			
			// check whether directory or regular file
			if (S_ISDIR(info.st_mode))
			{
				// if directory name are not . or ..
				if (..)
				{
					//copy directory
					copy_directory(source_pathname, target_pathname, ...);
				}
				else if (S_ISREG(info.st_mode))
				{
					//copy file
					copy_file(...);
				}
			}
		}
	}
