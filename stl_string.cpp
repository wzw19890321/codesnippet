template< typename CharT >
inline void TrimLeft(std::basic_string<CharT> &str)
{
	str.erase(0, str.find_first_not_of(' '));
}

template< typename CharT >
inline void TrimRight(std::basic_string<CharT> &str)
{
	str.erase(str.find_last_not_of(' ') + 1);
}

template< typename CharT >
inline void Trim(std::basic_string<CharT> &str)
{
	str.erase(0, str.find_first_not_of(' '));
	str.erase(str.find_last_not_of(' ') + 1);
}


template<typename CharT>
inline void Erase(std::basic_string<CharT> &str, const CharT &charactor)
{
	str.erase(remove_if(str.begin(), str.end(), 
		bind2nd(std::equal_to<CharT>(), charactor)), str.end());
}

template<typename CharT>
inline void Replace(std::basic_string<CharT> &str, const std::basic_string<CharT> &strObj, const std::basic_string<CharT> &strDest)
{
	while(true)
	{
		CharT pos = str.find(strObj);

		if( pos != std::basic_string<CharT>::npos )
			str.replace(pos, strObj.size(), strDest);
		else
			break;
	}

}

template<typename T, typename CharT>
inline std::vector<T>& Split(std::vector<T> &seq, const std::basic_string<CharT> &str, CharT separator)
{
	if( str.empty() )
		return seq;

	std::basic_stringstream<CharT> iss(str);
	for(std::basic_string<CharT> s; std::getline(iss, s, separator); )
	{
		typename T val;
		std::basic_stringstream<CharT> isss(s);

		isss >> val;
		seq.push_back(val);
	}

	return seq;    
}

template < typename CharT >
inline std::basic_string<CharT> Split(const std::basic_string<CharT> &str, CharT separator, size_t index)
{
	if( str.empty() )
		return std::basic_string<CharT>();

	std::basic_stringstream<CharT> iss(str);
	std::vector<std::basic_string<CharT>> tmp;

	for(std::basic_string<CharT> s; std::getline(iss, s, separator); )
	{
		std::basic_string<CharT> val;
		std::basic_stringstream<CharT> isss(s);

		isss >> val;
		tmp.push_back(val);
	}

	if (index >= tmp.size())
	{
		assert(index < tmp.size());
		return std::basic_string<CharT>();
	}

	return tmp[index];
}
