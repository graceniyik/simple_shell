#include "shell.h"

/**
 * yelloexit - exits the shell
 * @info: Structure containing potential arguments. Used to maintain
 * constant function prototype.
 * Return: exits with a given exit status
 * (0) if info.argv[0] != "exit"
 */
int yelloexit(info_t *info)
{
	int yellocheck;

	if (info->argv[1]) /* If there is an exit arguement */
	{
		yellocheck = yelloerratoi(info->argv[1]);
		if (yellocheck == -1)
		{
			info->status = 2;
			print_error(info, "Illegal number: ");
			yelloputs(info->argv[1]);
			yelloputchar('\n');
			return (1);
		}
		info->err_num = yelloerratoi(info->argv[1]);
		return (-2);
	} info->err_num = -1;
	return (-2);
}

/**
 * yellocd - changes the current directory of the process
 * @info: Structure containing potential arguments. Used to maintain
 * constant function prototype.
 * Return: Always 0
 */
int yellocd(info_t *info)
{
	char *yello, *dir, buffer[1024];
	int chdir_ret;

	yello = getcwd(buffer, 1024);
	if (!yello)
		yelloputs("TODO: >>getcwd failure emsg here<<\n");
	if (!info->argv[1])
	{
		dir = yellogetenv(info, "HOME=");
		if (!dir)
			chdir_ret = /* TODO: any idea about this? */
				chdir((dir = yellogetenv(info, "PWD=")) ? dir : "/");
		else
			chdir_ret = chdir(dir);
	}
	else if (yellostrcmp(info->argv[1], "-") == 0)
	{
		if (!yellogetenv(info, "OLDPWD="))
		{
			yelloputs(yello);
			yelloputchar('\n');
			return (1);
		}
		yelloputs(yellogetenv(info, "OLDPWD=")), yelloputchar('\n');
		chdir_ret = /* TODO: any idea about this? */
			chdir((dir = yellogetenv(info, "OLDPWD=")) ? dir : "/");
	}
	else
		chdir_ret = chdir(info->argv[1]);
	if (chdir_ret == -1)
	{
		print_error(info, "can't cd to ");
		yelloputs(info->argv[1]), yelloputchar('\n');
	}
	else
	{
		yellosetenv(info, "OLDPWD", yellogetenv(info, "PWD="));
		yellosetenv(info, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}

/**
 * yellohelp - changes the current directory of the process
 * @info: Structure containing potential arguments. Used to maintain
 * constant function prototype.
 * Return: Always 0
 */
int yellohelp(info_t *info)
{
	char **arg_array;

	arg_array = info->argv;
	yelloputs("come on. are you serious \n");
	if (0)
		yelloputs(*arg_array); /* temp att_unused workaround */
	return (0);
}
