/*******************************************************************************
* Daniel Bachler
* 3/10/16
* scantext.c
* Desc:	
*		Contains 4 functions that interact with strings
*******************************************************************************/

static int mystrlen(const char *string)
{
  int length = 0;
  
  while (*string++)
    length++;

  return length;

}

/*Counts the number of tabs in a string*/
int count_tabs(const char *string) {
	int i = 0;
	int length = mystrlen(string);
	int tabs = 0;
	for(;i < length; ++i) {
		if(string[i] == '\t')
			++tabs;
	}
	return tabs;
}

/*Replaces the old_char with the new char and returns the substitutions*/
int substitute_char(char *string, char old_char, char new_char) {
	int i, length = mystrlen(string), subs = 0;
	for(i = 0; i < length; ++i) {
		if(string[i] == old_char) {
			++subs;
			string[i] = new_char;
		}
	}
	return subs;
}

/*Given the size of a tab returns the total size, and the size of the string when printed*/
void calculate_lengths(const char *string, int tabsize, int *string_length, int *display_length) {
	int printSize = 0, realSize = 0;
	while(*string) {
		++realSize;
		if(*string == '\t') {
			printSize += tabsize;
		} else {
			++printSize;
		}
		string++;
	}
	*string_length = realSize;
	*display_length = printSize;
}

/*Counts the number of words in a given string*/
int count_words(const char *string) {
	int wordsInString = 0, onWord = 0, letters = 0;
	while(*string) {
		switch(*string) {
			case ' ':
			case '\t':
			case '\n':
				onWord = 0;
				letters = 0;
				break;
			default:
				onWord = 1;
				letters++;
				break;
		}
		if(onWord && letters == 1) {
			++wordsInString;
		}
		string++;
	}
	return wordsInString;
}






