#ifndef __CJSON_H__
#define __CJSON_H__

#include <iostream>
#include <sstream>
#include <map>
#include <algorithm>
#include "json/json.h"

// Json 处理类
class CJson
{
public:
	CJson();

	// 解析 Json
	int parse(const std::string & str);

	void printMap() const;
	void writeMap() const;
	int getVal(const std::string & name, std::string & value) const;
	int getChild(const std::string & name, std::string & child) const;
	int getChildCnt(const std::string & name, unsigned int & child) const;
	int getValuePath(const std::string & value, std::string & path) const;
	void clear();

private:
	Json::CharReaderBuilder reader_;
	std::map<std::string, std::string> map_;
	std::map<std::string, std::string> map_child_;
	std::map<std::string, unsigned int> map_size_;
	Json::Value root_;

	int CJson::readData(Json::Value &value, const std::string &path = ".");
};

#endif