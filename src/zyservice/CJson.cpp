#include "CJson.h"
#include <fstream>

CJson::CJson()
{

}

int CJson::parse(const std::string & str)
{
	reader_["collectComments"] = false;
	JSONCPP_STRING errs;
	Json::CharReader* reader = reader_.newCharReader();
	if (!reader->parse(str.data(), str.data() + str.size(), &root_, &errs))
	{
		return -1;
	}
	readData(root_);
	return 0;
}

int CJson::getValuePath(const std::string & value, std::string & path) const
{
	for (auto it = map_.begin(); it != map_.end(); ++it)
	{
		if (it->second == value)
		{
			path = it->first;
			return 0;
		}
	}
	return -1;
}

void CJson::printMap() const
{
	std::cout << "map: " << "\n";
	for (auto it = map_.begin(); it != map_.end(); ++it)
	{
		std::cout << it->first << " - " << it->second << std::endl;
	}
}

void CJson::writeMap() const
{
	static unsigned int cnt = 0;
	std::stringstream ss;
	ss << cnt;
	std::string pth = "c:\\map_" + ss.str() + ".txt";
	std::ofstream fout(pth, std::ios::out);
	for (auto it = map_.begin(); it != map_.end(); ++it)
	{
		fout << it->first << " - " << it->second << "\n";
	}
	fout.close();

	pth = "c:\\map_child_" + ss.str() + ".txt";
	fout.open(pth, std::ios::out);
	for (auto it = map_child_.begin(); it != map_child_.end(); ++it)
	{
		fout << it->first << " - " << it->second << "\n";
	}
	fout.close();

	pth = "c:\\map_size_" + ss.str() + ".txt";
	fout.open(pth, std::ios::out);
	for (auto it = map_size_.begin(); it != map_size_.end(); ++it)
	{
		fout << it->first << " - " << it->second << "\n";
	}
	fout.close();

	++cnt;
}

void CJson::clear()
{
	map_.clear();
}

int CJson::getVal(const std::string & name, std::string & value) const
{
	auto it = map_.find(name);
	if (it != map_.end())
	{
		value = it->second;
		return 0;
	}
	return -1;
}

int CJson::getChild(const std::string & name, std::string & child) const
{
	auto it = map_child_.find(name);
	if (it != map_child_.end())
	{
		child = it->second;
		return 0;
	}
	return -1;
}

int CJson::getChildCnt(const std::string & name, unsigned int & child) const
{
	auto it = map_size_.find(name);
	if (it != map_size_.end())
	{
		child = it->second;
		return 0;
	}
	return -1;
}

int CJson::readData(Json::Value &value, const std::string &path)
{
	switch (value.type())
	{
	case Json::nullValue:
		map_[path] = "null";
		break;
	case Json::intValue:
		map_[path] = value.asString();
		break;
	case Json::uintValue:
	{
		std::stringstream ss;
		ss << value.asUInt();
		map_[path] = ss.str();
		break;
	}
	case Json::realValue:
	{
		std::stringstream ss;
		ss << value.asDouble();
		map_[path] = ss.str();
		break;
	}
	case Json::stringValue:
		map_[path] = value.asString();
		break;
	case Json::booleanValue:
		map_[path] = value.asString();
		break;
	case Json::arrayValue:
	{
		int size = value.size();
		std::string sVal;
		for (int index = 0; index < size; ++index)
		{
			static char buffer[16];
			sprintf_s(buffer, sizeof(buffer), "[%d]", index);
			std::string pbuffer = path + buffer;
			sVal += pbuffer + ";";
			readData(value[index], pbuffer);
		}
		std::stringstream ss;
		ss << size;
		map_child_[path] = sVal;
		map_[path] = "[" + ss.str() + "]";
		map_size_[path] = size;
	}
	break;
	case Json::objectValue:
	{
		Json::Value::Members members(value.getMemberNames());
		std::sort(members.begin(), members.end());
		std::string suffix = *(path.end() - 1) == '.' ? "" : ".";
		std::string sVal;
		for (Json::Value::Members::iterator it = members.begin(); it != members.end(); ++it)
		{
			const std::string &name = *it;
			std::string pname = path + suffix + name;
			sVal += pname + ";";
			readData(value[name], pname);
		}
		map_child_[path] = sVal;
		map_[path] = "{}";
	}
	break;
	default:
		break;
	}
	return 0;
}