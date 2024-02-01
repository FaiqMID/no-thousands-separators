#include <vector>
#include <string>
#include <Geode/Geode.hpp>
#include <Geode/modify/ProfilePage.hpp>

using namespace geode::prelude;

void changeLabel(std::string const& str, cocos2d::CCLabelBMFont* label);

struct StatsType {
	int value;
	CCLabelBMFont* label;
};

class $modify(ProfilePage) {
	bool init(int accountID, bool ownProfile) {
    	if (!ProfilePage::init(accountID, ownProfile)) return false;

		return true;
	}

	virtual void loadPageFromUserInfo(GJUserScore* p0){
		ProfilePage::loadPageFromUserInfo(p0);

		auto starsLabel = static_cast<CCLabelBMFont*>(this->getChildByIDRecursive("stars-label"));
		auto moonsLabel = static_cast<CCLabelBMFont*>(this->getChildByIDRecursive("moons-label"));
		auto secretCoinsLabel = static_cast<CCLabelBMFont*>(this->getChildByIDRecursive("coins-label"));
		auto userCoinsLabel = static_cast<CCLabelBMFont*>(this->getChildByIDRecursive("user-coins-label"));
		auto demonsLabel = static_cast<CCLabelBMFont*>(this->getChildByIDRecursive("demons-label"));

		std::vector<StatsType> stats;
		
		stats.push_back({p0->m_stars, starsLabel});
		stats.push_back({p0->m_moons, moonsLabel});
		stats.push_back({p0->m_secretCoins, secretCoinsLabel});
		stats.push_back({p0->m_userCoins, userCoinsLabel});
		stats.push_back({p0->m_demons, demonsLabel});

		if (p0->m_creatorPoints != 0){
			auto creatorPointsLabel = static_cast<CCLabelBMFont*>(this->getChildByIDRecursive("creator-points-label"));
			stats.push_back({p0->m_creatorPoints, creatorPointsLabel});
		};

		for (auto& a : stats) {
			changeLabel(std::to_string(a.value), a.label);
		}
	}
};

void changeLabel(std::string const& str, cocos2d::CCLabelBMFont* label){
	label->setAlignment(kCCTextAlignmentCenter);
	label->setString(str.c_str());
	label->updateLabel();
	return;
}