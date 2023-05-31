#include "Split.hpp"

Split::Split()
{
}

Split::Split(const std::string &string, char delimiter)
{
	split(string, delimiter);
}

Split::Split(const std::string &string, const std::string &delimiters)
{
	split(string, delimiters);
}

Split::Split(const Split &other)
{
	*this = other;
}

Split &Split::operator=(const Split &other)
{
	if (this != &other)
		_words.assign(other._words.begin(), other._words.end());
	return (*this);
}

Split::~Split()
{
}

size_t Split::size()
{
	return (_words.size());
}

void Split::clear()
{
	_words.clear();
}

std::string &Split::operator[](size_t index)
{
	return (_words[index]);
}

Split::iterator Split::begin()
{
	return (_words.begin());
}

Split::iterator Split::end()
{
	return (_words.end());
}

void Split::split(const std::string &string, char delimiter)
{
	std::string delimiters;

	delimiters.append(1, delimiter);
	split(string, delimiters);
}

void Split::split(const std::string &string, const std::string &delimiters)
{
	size_t pos;
	size_t end;

	_words.clear();
	end = 0;
	while (end != string.size())
	{
		pos = string.find_first_not_of(delimiters, end);
		if (pos == std::string::npos)
			break ;
		end = string.find_first_of(delimiters, pos);
		if (end == std::string::npos)
			end = string.size();
		_words.push_back(string.substr(pos, end - pos));
	}
}

std::string Split::join(char delimiter) const
{
	std::string out;
	size_t pos;

	for (pos = 0; pos < _words.size(); pos++)
	{
		if (pos != 0)
			out.append(1, delimiter);
		out.append(_words[pos]);
	}
	return (out);
}
