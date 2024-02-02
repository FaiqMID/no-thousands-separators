#include <vector>
#include <algorithm>
#include <string>
#include <Geode/Geode.hpp>
#include <Geode/modify/ProfilePage.hpp>

using namespace geode::prelude;

void removeCommas(std::string& str);
void changeLabel(std::string const& str, cocos2d::CCLabelBMFont* label);

struct StatsType {
	std::string value;
	CCLabelBMFont* label;
};

class $modify(ProfilePage) {
	bool init(int accountID, bool ownProfile) {
    	if (!ProfilePage::init(accountID, ownProfile)) return false;
		return true;
	}

	virtual void loadPageFromUserInfo(GJUserScore* p0){
		ProfilePage::loadPageFromUserInfo(p0);

		auto starsLabel = typeinfo_cast<CCLabelBMFont*>(this->getChildByIDRecursive("stars-label"));
		auto moonsLabel = typeinfo_cast<CCLabelBMFont*>(this->getChildByIDRecursive("moons-label"));
		// auto secretCoinsLabel = typeinfo_cast<CCLabelBMFont*>(this->getChildByIDRecursive("coins-label"));
		auto userCoinsLabel = typeinfo_cast<CCLabelBMFont*>(this->getChildByIDRecursive("user-coins-label"));
		auto demonsLabel = typeinfo_cast<CCLabelBMFont*>(this->getChildByIDRecursive("demons-label"));
		auto creatorPointsLabel = typeinfo_cast<CCLabelBMFont*>(this->getChildByIDRecursive("creator-points-label"));
		
		std::string stars (starsLabel->getString());
		std::string moons (moonsLabel->getString());
		// std::string secretCoins (secretCoinsLabel->getString());
		std::string userCoins (userCoinsLabel->getString());
		std::string demons (demonsLabel->getString());

		std::vector<StatsType> stats;
		
		stats.push_back({stars, starsLabel});
		stats.push_back({moons, moonsLabel});
		// stats.push_back({secretCoins, secretCoinsLabel});
		stats.push_back({userCoins, userCoinsLabel});
		stats.push_back({demons, demonsLabel});

		if (creatorPointsLabel != nullptr){ 
			std::string creatorPoints (creatorPointsLabel->getString());
			stats.push_back({creatorPoints, creatorPointsLabel});
		};

		for (auto& a : stats) {
			removeCommas(a.value);
			changeLabel(a.value, a.label);
		}

		return;
	}
};

void removeCommas(std::string& str){
	str.erase(std::remove(str.begin(), str.end(), ','), str.end());
}

void changeLabel(std::string const& str, cocos2d::CCLabelBMFont* label){
	label->setString(str.c_str());
	label->setAlignment(kCCTextAlignmentRight);
	// label->updateLabel();
	return;
}