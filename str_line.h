#ifndef _str_line_h
#define _str_line_h

char* End_line(char *str){
	size_t ln = strlen(str) - 1;
		if (str[ln] == '\n')
    		str[ln] = '\0';
  return str;
}

#endif
