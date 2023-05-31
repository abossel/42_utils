#include "Wildcard.hpp"
#include <iostream>
#include <string>

void test_wc(const std::string &s, const std::string &p)
{
	Wildcard wc;

	wc.set(p);
	std::cout << "pattern: " << p << " string: " << s << std::endl;
	if (wc.match(s))
		std::cout << "MATCH";
	else
		std::cout << "NO MATCH";
	std::cout << std::endl;
}

int main()
{
	test_wc("www.example.com", "ww***w.*ample.*om");
	test_wc("www.example.com", "www***w.*ample.*om");
	test_wc("www.example.com", "www.example.com");
	test_wc("www.example.com", "www.example*com");
	test_wc("www.example.com", "www.example.*com");
	test_wc("www.example.com", "www.example.*.com");
	test_wc("www.example.com", "www************?????????**************com");
	test_wc("www.example.com", "www?example?com");
	test_wc("www.example.com", "www??example?com");
	test_wc("www.example.com", "www*??*xample?com");
	test_wc("*www.example.com", "\\*www.example.com");
	test_wc("\\*?*?*?*?www.?example*.com*", "\\\\*\\?\\*\\?\\*\\?\\*\\?ww*??\\?*xample\\*?com\\*");

	return (0);
}
