#include "String.h"

int Strlen( char *s1) {

	int len = 0;

	while (*(s1 + len) != '\0')
		len++;

	return len;
}

String::String() {
	cptr = NULL;
	size = 0;
}

String::String(const char *str) {

	int len = 0;

	while (str[len] != '\0')
		len++;

	size = len;
	cptr = new char[size];

	for (int i = 0; i < size; i++)
		cptr[i] = str[i];
}

String::String(const String &s1) {
	size = s1.size;
	cptr = new char[size];

	for (int i = 0; i < size; i++)
		cptr[i] = s1.cptr[i];
}

String::String(int x) {
	size = x;
	cptr = new char[size];
}

String::String(const string &str) {

	int len = 0;

	while (str[len] != '\0')
		len++;

	size = len;
	cptr = new char[size];

	for (int i = 0; i < size; i++)
		cptr[i] = str[i];
}

char String::getVal(int index) const {
	return this->cptr[index];
}

void String::addVal(int index, char val) {
	this->cptr[index] = val;
}

char& String::operator[](int i) {
	if (i < 0 || i >= size)
		exit(0);

	return cptr[i];
}

const char String::operator[](int i) const {

	return cptr[i];
}

String String::operator+(const String &str) const { // appends a String at the end of the String

	String s1(size + str.size);

	int i = 0, j = 0;

	while (i < size) {
		s1.cptr[i] = this->cptr[i];
		i++;
	}

	while (j < str.size) {
		s1.cptr[i] = str.cptr[j];
		i++;
		j++;
	}

	return s1;
}

String String::operator+(const char &str) const { // appends a char at the end of the String
	String s1(size + 1);

	for (int i = 0; i < size; i++)
		s1.cptr[i] = this->cptr[i];

	s1.cptr[this->size] = str;

	return s1;
}

String String::operator+(char *&str) const { // appends a String at the end of the String

	int len = 0;

	while (str[len] != '\0')
		len++;

	String s1(size + len);

	int i = 0, j = 0;

	while (i < size) {
		s1.cptr[i] = this->cptr[i];
		i++;
	}

	while (j < len) {
		s1.cptr[i] = str[j];
		i++;
		j++;
	}

	return s1;
}

int StrFind(char *s1, char *s2) {

	int len1 = 0, len2 = 0, index = -1;
	bool flag = false;

	while (*(s1 + len1) != '\0')
		len1++;

	while (*(s2 + len2) != '\0')
		len2++;

	for (int i = 0; i < len1; i++) {

		int j = 0;

		if (*(s1 + i) == *(s2 + j) ) {

			int k = i;

			for (j = 0; j < len2; j++) {

				if (*(s1 + k) == *(s2 + j) )
					k++;
				else
					break;
			}

			if (j == len2) {
				index = i;
				flag = true;
				break;
			}
		}
	}

	if (flag)
		return index;

	return -1;
}

String String::operator-(const String &substr) const { //removes the substr from the String

	int index = StrFind(this->cptr, substr.cptr);

	String s1(this->size);

	for (int i = 0; i < s1.size; i++)
		s1.cptr[i] = this->cptr[i];

//	String s1(*this);
//	cout << substr.size;
	s1.size -= substr.size;

	for (int i = index; i < s1.size; i++)
		s1.cptr[i] = s1.cptr[i + substr.size];

	return s1;
}


String String::operator-(const string &substr) const { //removes the substr from the String

	String s1(substr), toReturn(*this);

	int index = StrFind(this->cptr, s1.cptr);

	toReturn.size -= s1.size;

	for (int i = index; i < toReturn.size; i++)
		toReturn.cptr[i] = toReturn.cptr[i + s1.size];

	return toReturn;
}

String& String::operator=(const String& s1) {

	if (s1 == *this)
		return *this;

	~*this;

	this->size = s1.size;

	this->cptr = new char[size];

	for (int i = 0; i < size; i++)
		this->cptr[i] = s1.cptr[i];

	return *this;
}

String& String::operator=(char* c) {

	if (c == NULL)
		return *this;

	int len = 0;

	while (c[len] != '\0')
		len++;

	~*this;

	this->size = len;

	this->cptr = new char[size];

	for (int i = 0; i < size; i++)
		this->cptr[i] = c[i];

	return *this;
}

String& String::operator=(const string& s1) {

	int len = 0;

	while (s1[len] != '\0')
		len++;

	~*this;

	this->size = len;

	this->cptr = new char[size];

	for (int i = 0; i < size; i++)
		this->cptr[i] = s1[i];

	return *this;
}

bool String::operator==(const String& s1) const { // returns true if two Strings are equal

	if (this->size != s1.size)
		return false;

	for (int i = 0; i < size; i++) {
		if (this->cptr[i] != s1.cptr[i])
			return false;
	}

	return true;
}

bool String::operator==(const string& s1) const {  // returns true if the string is equal to the String

	int len = 0;

	while (s1[len] != '\0')
		len++;

	if (size != len)
		return false;

	for (int i = 0; i < size; i++) {
		if (this->cptr[i] != s1[i])
			return false;
	}

	return true;

}

bool String::operator==(char *c) const { // returns true if the c-string is equal to the String

	if (c == NULL)
		return false;

	int len = 0;

	while (c[len] != '\0')
		len++;

	if (size != len)
		return false;

	for (int i = 0; i < size; i++) {
		if (this->cptr[i] != c[i])
			return false;
	}

	return true;
}

bool String::operator!() {

	if (size == 0)
		return true;

	return false;
}

int String::operator()(char c) const { // returns the index of the character being searched

	if (this->cptr == NULL)
		exit(0);

	for (int i = 0; i < this->size; i++) {
		if (this->cptr[i] == c)
			return i;
	}

	return -1;
}

int String::operator()(const String& s1) const { // returns the index of the String being searched

	return StrFind(this->cptr, s1.cptr);
}

int String::operator()(const string& s1) const { // returns the index of the string being searched

	if (this->cptr == NULL)
		return -1;

	String s2(s1);

	return StrFind(this->cptr, s2.cptr);

}

int String::operator()(char *c) const { // returns the index of the c-string being searched

	if (c == NULL)
		return -1;

	String s2(c);

	return StrFind(this->cptr, s2.cptr);
}

String::operator int() const {

	return size;
}

String::~String() {
	delete []cptr;
}

ostream& operator<<(ostream& output, const String& s1) {

	for (int i = 0; i < (int)s1; i++)
		output << s1.getVal(i);

	return output;
}

istream& operator>>(istream& input, String& s1) {

	char ch;

	for (int i = 0; i < (int)s1; i++) {
		input >> ch;
		s1.addVal(i, ch);
	}

	return input;
}
