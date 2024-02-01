#include <algorithm>
#include <map>
#include <string>
#include <Geode/Geode.hpp>
#include <Geode/modify/ProfilePage.hpp>

using namespace geode::prelude;

std::string removeChar(std::string const& str, char chr);
std::string getLabelString(cocos2d::CCLabelBMFont* label);
void changeLabel(std::string const& str, cocos2d::CCLabelBMFont* label);

class $modify(ProfilePage) {
	bool init(int accountID, bool ownProfile) {
    	if (!ProfilePage::init(accountID, ownProfile)) return false;

		return true;
	}

	virtual void loadPageFromUserInfo(GJUserScore* p0){
		ProfilePage::loadPageFromUserInfo(p0);

		auto starsLabel = static_cast<cocos2d::CCLabelBMFont*>(this->m_mainLayer->getChildByIDRecursive("stars-label"));
		auto moonsLabel = static_cast<cocos2d::CCLabelBMFont*>(this->m_mainLayer->getChildByIDRecursive("moons-label"));
		auto secretCoinsLabel = static_cast<cocos2d::CCLabelBMFont*>(this->m_mainLayer->getChildByIDRecursive("coins-label"));
		auto userCoinsLabel = static_cast<cocos2d::CCLabelBMFont*>(this->m_mainLayer->getChildByIDRecursive("user-coins-label"));
		auto demonsLabel = static_cast<cocos2d::CCLabelBMFont*>(this->m_mainLayer->getChildByIDRecursive("demons-label"));
		auto creatorPointsLabel = static_cast<cocos2d::CCLabelBMFont*>(this->m_mainLayer->getChildByIDRecursive("creator-points-label"));
		
		std::map<int, cocos2d::CCLabelBMFont*> statsMap;

		statsMap[p0->m_stars] = starsLabel;
		statsMap[p0->m_moons] = moonsLabel;
		statsMap[p0->m_secretCoins] = secretCoinsLabel;
		statsMap[p0->m_userCoins] = userCoinsLabel;
		statsMap[p0->m_demons] = demonsLabel;

		if (p0->m_creatorPoints != 0) statsMap.insert({p0->m_creatorPoints, creatorPointsLabel});

		for (auto& a : statsMap) changeLabel(removeChar(std::to_string(a.first), ','), a.second);

	}
	// bool init(int accountID, bool ownProfile) {
    //     if (!ProfilePage::init(accountID, ownProfile)) return false;
		
	// 	auto starsLabel = static_cast<cocos2d::CCLabelBMFont*>(this->m_mainLayer->getChildByIDRecursive("stars-label"));
	// 	auto moonsLabel = static_cast<cocos2d::CCLabelBMFont*>(this->m_mainLayer->getChildByIDRecursive("moons-label"));
	// 	auto coinsLabel = static_cast<cocos2d::CCLabelBMFont*>(this->m_mainLayer->getChildByIDRecursive("coins-label"));
	// 	auto userCoinsLabel = static_cast<cocos2d::CCLabelBMFont*>(this->m_mainLayer->getChildByIDRecursive("user-coins-label"));
	// 	auto demonsLabel = static_cast<cocos2d::CCLabelBMFont*>(this->m_mainLayer->getChildByIDRecursive("demons-label"));
	// 	auto creatorPointsLabel = static_cast<cocos2d::CCLabelBMFont*>(this->m_mainLayer->getChildByIDRecursive("creator-points-label"));

	// 	std::map<std::string, cocos2d::CCLabelBMFont*> statsMap;

	// 	statsMap[getLabelString(starsLabel)] = starsLabel;
	// 	statsMap[getLabelString(moonsLabel)] = moonsLabel;
	// 	statsMap[getLabelString(coinsLabel)] = coinsLabel;
	// 	statsMap[getLabelString(userCoinsLabel)] = userCoinsLabel;
	// 	statsMap[getLabelString(demonsLabel)] = demonsLabel;
		
	// 	if (getLabelString(creatorPointsLabel) != "0") statsMap.insert({getLabelString(creatorPointsLabel), creatorPointsLabel});

	// 	for (auto& a : statsMap) changeLabel(removeChar(a.first, ','), a.second);

	// 	return true;
    // }
};

std::string removeChar(std::string const& str, char chr){
	std::string res;
	res.erase(std::remove(res.begin(), res.end(), chr), res.end());
	return res;
}

std::string getLabelString(cocos2d::CCLabelBMFont* label){
	std::string labelString = label->getString();
	return labelString;
}

void changeLabel(std::string const& str, cocos2d::CCLabelBMFont* label){
	label->setString(str.c_str(), true);
	return;
}