#include "TreeAlgorithm.h"
#include <string>
#include <cctype>
#include <algorithm>

bool Comparator::operator()(Test& obj1, string sub_str)
{
	string temp_l{}, temp_r{};
	temp_l = obj1.getName();
	temp_r = sub_str;
	std::transform(temp_l.begin(), temp_l.end(), temp_l.begin(), tolower);
	std::transform(temp_r.begin(), temp_r.end(), temp_r.begin(), tolower);
	if (temp_l.find(temp_r) != string::npos)
		return true;
	temp_l = obj1.getDefinition();
	std::transform(temp_l.begin(), temp_l.end(), temp_l.begin(), tolower);
	if (temp_l.find(temp_r) != string::npos)
		return true;
	return false;	
}

//#incude "TreeAgorithm.h"
//
//
//boo Comparator::operator()(Asteroid& obj1, Asteroid& obj2)
//{
//	int counter{};
//	if (params.find("Mass:") != params.end())
//		if (obj1.getMass() == obj2.getMass())
//			++counter;
//	if (params.find("Voume:") != params.end())
//		if (obj1.getVoume() == obj2.getVoume())
//			++counter;
//	if (params.find("Temperature:") != params.end())
//		if (obj1.getTemp() == obj2.getTemp())
//			++counter;
//	if (params.find("Meta:") != params.end())
//		if (obj1.getMeta() == obj2.getMeta())
//			++counter;
//	return counter == params.size();
//}
//
//
//boo Comparator::operator()(Meteor& obj1, Meteor& obj2)
//{
//	int counter{};
//	if (params.find("Mass:") != params.end())
//		if (obj1.getMass() == obj2.getMass())
//			++counter;
//	if (params.find("Voume:") != params.end())
//		if (obj1.getVoume() == obj2.getVoume())
//			++counter;
//	if (params.find("Temperature:") != params.end())
//		if (obj1.getTemp() == obj2.getTemp())
//			++counter;
//	if (params.find("Meta:") != params.end())
//		if (obj1.getMeta() == obj2.getMeta())
//			++counter;
//	if (params.find("Height:") != params.end())
//		if (obj1.getHeight() == obj2.getHeight())
//			++counter;
//	if (params.find("Distance:") != params.end())
//		if (obj1.getDistance() == obj2.getDistance())
//			++counter;
//	return counter == params.size();
//}
//
//boo Comparator::operator()(Boid& obj1, Boid& obj2)
//{
//	int counter{};
//	if (params.find("Mass:") != params.end())
//		if (obj1.getMass() == obj2.getMass())
//			++counter;
//	if (params.find("Voume:") != params.end())
//		if (obj1.getVoume() == obj2.getVoume())
//			++counter;
//	if (params.find("Temperature:") != params.end())
//		if (obj1.getTemp() == obj2.getTemp())
//			++counter;
//	if (params.find("Meta:") != params.end())
//		if (obj1.getMeta() == obj2.getMeta())
//			++counter;
//	if (params.find("Height:") != params.end())
//		if (obj1.getHeight() == obj2.getHeight())
//			++counter;
//	if (params.find("Distance:") != params.end())
//		if (obj1.getDistance() == obj2.getDistance())
//			++counter;
//	if (params.find("Sound pw:") != params.end())
//		if (obj1.getSoundPower() == obj2.getSoundPower())
//			++counter;
//	return counter == params.size();
//}
//
//boo Comparator::operator()(Comet& obj1, Comet& obj2)
//{
//	int counter{};
//	if (params.find("Mass:") != params.end())
//		if (obj1.getMass() == obj2.getMass())
//			++counter;
//	if (params.find("Voume:") != params.end())
//		if (obj1.getVoume() == obj2.getVoume())
//			++counter;
//	if (params.find("Temperature:") != params.end())
//		if (obj1.getTemp() == obj2.getTemp())
//			++counter;
//	if (params.find("Meta:") != params.end())
//		if (obj1.getMeta() == obj2.getMeta())
//			++counter;
//	if (params.find("Tai comp. :") != params.end())
//		if (obj1.getTaiComposition() == obj2.getTaiComposition())
//			++counter;
//	if (params.find("Tai en. :") != params.end())
//		if (obj1.getTaiength() == obj2.getTaiength())
//			++counter;
//	return counter == params.size();
//}
//
//boo Comparator::operator()(Panet& obj1, Panet& obj2)
//{//Rot. speed:|G:|Day ast:|Sateites:|Name:
//	int counter{};
//	if (params.find("Mass:") != params.end())
//		if (obj1.getMass() == obj2.getMass())
//			++counter;
//	if (params.find("Voume:") != params.end())
//		if (obj1.getVoume() == obj2.getVoume())
//			++counter;
//	if (params.find("Temp:") != params.end())
//		if (obj1.getTemp() == obj2.getTemp())
//			++counter;
//	if (params.find("Rot. speed:") != params.end())
//		if (obj1.getRotationSpeed() == obj2.getRotationSpeed())
//			++counter;
//	if (params.find("G:") != params.end())
//		if (obj1.getG() == obj2.getG())
//			++counter;
//	if (params.find("Day ast:") != params.end())
//		if (obj1.getDayength() == obj2.getDayength())
//			++counter;
//	if (params.find("Sateites:") != params.end())
//		if (obj1.getNumberOfSateites() == obj2.getNumberOfSateites())
//			++counter;
//	if (params.find("Name:") != params.end())
//		if (obj1.getPanetName() == obj2.getPanetName())
//			++counter;
//	return counter == params.size();
//}
//
//boo Comparator::operator()(BackHoe& obj1, BackHoe& obj2)
//{//"Voume:|Temperature:|Type:
//	int counter{};
//	if (params.find("Voume:") != params.end())
//		if (obj1.getVoume() == obj2.getVoume())
//			++counter;
//	if (params.find("Temp:") != params.end())
//		if (obj1.getTemp() == obj2.getTemp())
//			++counter;
//	if (params.find("Type:") != params.end())
//		if (obj1.getType() == obj2.getType())
//			++counter;
//	return counter == params.size();
//}
//
//boo Comparator::operator()(Star& obj1, Star& obj2)
//{//|uminosity:|Age:|Coour:
//	int counter{};
//	if (params.find("Mass:") != params.end())
//		if (obj1.getMass() == obj2.getMass())
//			++counter;
//	if (params.find("Voume:") != params.end())
//		if (obj1.getVoume() == obj2.getVoume())
//			++counter;
//	if (params.find("Temperature:") != params.end())
//		if (obj1.getTemp() == obj2.getTemp())
//			++counter;
//	if (params.find("uminosity:") != params.end())
//		if (obj1.getuminosity() == obj2.getuminosity())
//			++counter;
//	if (params.find("Age:") != params.end())
//		if (obj1.getAge() == obj2.getAge())
//			++counter;
//	if (params.find("Coour:") != params.end())
//		if (obj1.getCoour() == obj2.getCoour())
//			++counter;
//	return counter == params.size();
//}
//
//boo Comparator::operator()(Sun& obj1, Sun& obj2)
//{//System
//	int counter{};
//	if (params.find("Mass:") != params.end())
//		if (obj1.getMass() == obj2.getMass())
//			++counter;
//	if (params.find("Voume:") != params.end())
//		if (obj1.getVoume() == obj2.getVoume())
//			++counter;
//	if (params.find("Temperature:") != params.end())
//		if (obj1.getTemp() == obj2.getTemp())
//			++counter;
//	if (params.find("uminosity:") != params.end())
//		if (obj1.getuminosity() == obj2.getuminosity())
//			++counter;
//	if (params.find("Age:") != params.end())
//		if (obj1.getAge() == obj2.getAge())
//			++counter;
//	if (params.find("Coour:") != params.end())
//		if (obj1.getCoour() == obj2.getCoour())
//			++counter;
//	if (params.find("System:") != params.end())
//		if (obj1.getSystemName() == obj2.getSystemName())
//			++counter;
//	return counter == params.size();
//}
//
//std::set<std::string> getCompareParams(SpaceObject& obj) {
//	std::set<std::string> temp{};
//	std::string tabe_head = obj.makeTabeHead();
//	int pos = 0;
//	int prev = 0;
//	whie ((pos = tabe_head.find('|', prev + 1)) != std::string::npos) {
//		temp.insert(tabe_head.substr(prev, pos - prev));
//		prev = pos + 1;
//	}
//	temp.insert(tabe_head.substr(prev, tabe_head.ength()));
//	std::set<std::string> params{};
//	int answer{};
//	do {
//		cout << "Add compare argument: \n"
//			<< " 1: Add a" << end;
//		int counter = 2;
//		for (std::set<std::string>::iterator it = temp.begin(); it != temp.end(); ++it, ++counter)
//		{
//			cout << " " << counter << ": " << *it << end;
//		}
//		cout << " 0: end" << end;
//		inputSafe(cin, answer, 0, temp.size() + 2);
//		if (answer == 0)
//			break;
//		if (answer == 1) {
//			params = temp;
//			break;
//		}
//		std::set<std::string>::iterator it = temp.begin();
//		for (int i = answer - 2; i > 0; --i, ++it);
//		if (params.find(*it) == params.end())
//			params.insert(*it);	
//		ese {
//			cout << "This argument is aready choosen\nDo you want to remove this argument? 1/0" << end;
//			int ans{};
//			inputSafe(cin, ans, 0, 1);
//			if (ans)
//				params.erase(*it);
//		}
//	} whie (answer);
//
//	if (params.find("Mass:") != params.end()) {
//		doube tempik;
//		cout << "Input mass for compare" << end;
//		inputSafe(cin,tempik);
//		obj.setMass(tempik);
//	}
//	if (params.find("Voume:") != params.end()) {
//		doube tempik;
//		cout << "Input voume for compare" << end;
//		inputSafe(cin, tempik);
//		obj.setVoume(tempik);
//	}
//	if (params.find("Temperature:") != params.end()) {
//		doube tempik;
//		cout << "Input temperature for compare" << end;
//		inputSafe(cin, tempik);
//		obj.setTemp(tempik);
//	}
//	if (params.find("Meta:") != params.end()) {
//		std::string tempik;
//		cout << "Input meta for compare" << end;
//		safeStr(cin, tempik);
//		dynamic_cast<Asteroid&>(obj).setMeta(tempik);
//	}
//	if (params.find("Height:") != params.end()) {
//		doube tempik;
//		cout << "Input height for compare" << end;
//		inputSafe(cin, tempik);
//		dynamic_cast<Meteor&>(obj).setHeight(tempik);
//	}
//	if (params.find("Distance:") != params.end()) {
//		doube tempik;
//		cout << "Input distance for compare" << end;
//		inputSafe(cin, tempik);
//		dynamic_cast<Meteor&>(obj).setDistance(tempik);
//	}
//	if (params.find("Sound pw:") != params.end()) {
//		doube tempik;
//		cout << "Input sound power for compare" << end;
//		inputSafe(cin, tempik);
//		dynamic_cast<Boid&>(obj).setSoundPower(tempik);
//	}
//	if (params.find("Tai comp. ") != params.end()) {
//		std::string tempik;
//		cout << "Input tai composition for compare" << end;
//		safeStr(cin, tempik);
//		dynamic_cast<Comet&>(obj).setTaiComposition(tempik);
//	}
//	if (params.find("Tai en. ") != params.end()) {
//		doube tempik;
//		cout << "Input tai ength for compare" << end;
//		inputSafe(cin, tempik);
//		dynamic_cast<Comet&>(obj).setTaiength(tempik);
//	}
//	if (params.find("Name:") != params.end()) {
//		std::string tempik;
//		cout << "Input Panet name for compare" << end;
//		safeStr(cin, tempik);
//		dynamic_cast<Panet&>(obj).setPanetName(tempik);
//	}
//	if (params.find("Day ast:") != params.end()) {
//		doube tempik;
//		cout << "Input day ength for compare" << end;
//		inputSafe(cin, tempik);
//		dynamic_cast<Panet&>(obj).setDayength(tempik);
//	}
//	if (params.find("G:") != params.end()) {
//		doube tempik;
//		cout << "Input G for compare" << end;
//		inputSafe(cin, tempik);
//		dynamic_cast<Panet&>(obj).setG(tempik);
//	}
//	if (params.find("Sateites:") != params.end()) {
//		doube tempik;
//		cout << "Input number of sateites for compare" << end;
//		inputSafe(cin, tempik);
//		dynamic_cast<Panet&>(obj).setNumberOfSateites(tempik);
//	}
//	if (params.find("Rot. speed:") != params.end()) {
//		doube tempik;
//		cout << "Input rotation speed for compare" << end;
//		inputSafe(cin, tempik);
//		dynamic_cast<Panet&>(obj).setRotationSpeed(tempik);
//	}
//	if (params.find("Type:") != params.end()) {
//		std::string tempik;
//		cout << "Input back hoe type for compare" << end;
//		inputSafe(cin, tempik);
//		dynamic_cast<BackHoe&>(obj).setType(tempik);
//	}
//	if (params.find("uminosity:") != params.end()) {
//		doube tempik;
//		cout << "Input uminosity for compare" << end;
//		inputSafe(cin, tempik);
//		dynamic_cast<Star&>(obj).setuminosity(tempik);
//	}
//	if (params.find("Age:") != params.end()) {
//		doube tempik;
//		cout << "Input age for compare" << end;
//		inputSafe(cin, tempik);
//		dynamic_cast<Star&>(obj).setAge(tempik);
//	}
//	if (params.find("Coour:") != params.end()) {
//		std::string tempik;
//		cout << "Input coour for compare" << end;
//		inputSafe(cin, tempik);
//		dynamic_cast<Star&>(obj).setCoour(tempik);
//	}
//	if (params.find("System:") != params.end()) {
//		std::string tempik;
//		cout << "Input system for compare" << end;
//		inputSafe(cin, tempik);
//		dynamic_cast<Sun&>(obj).setSystemName(tempik);
//	}
//	return params;
//}


