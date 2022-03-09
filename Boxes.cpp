#include "Files\MainHeader.h"



Box::Box(int xx, int yy, std::string ss, DWORD boxcolorr, DWORD OutSideColorr, DWORD StringColorr) {
	BoxStringArray.push_back(ss);
	x = xx;
	y = yy;
	w = ss.size() * 6.2;
	h = BoxStringArray.size() * 14;
	BoxColor = boxcolorr;
	OutSideColor = OutSideColorr;
	StringColor = StringColorr;
};

Box::~Box() {
	memset(this, 0, sizeof(this));
};


Box* BoxFunctions::FindChild(Box* CurrentBox,std::vector<Box*> &NonTypedobjects) {

	for (int j = 0; j < NonTypedobjects.size(); j++) {
		if (NonTypedobjects.at(j) == CurrentBox) // Dont Check Your Shelf
			continue;

		if (CurrentBox->BoxCollide(NonTypedobjects.at(j))) {
			CurrentBox->ConnetIt(NonTypedobjects.at(j)); // Add collading box to Father Box

			return BoxFunctions::FindSecondChild(CurrentBox, NonTypedobjects.at(j), NonTypedobjects); //Has Child Also Has Child
		}		
	};
	return nullptr;
}

Box* BoxFunctions::FindSecondChild(Box* MainBox, Box* ChildBox, std::vector<Box*> &NonTypedobjects) {

	for (int j = 0; j < NonTypedobjects.size(); j++) { // Checking FirsBox Collisions
		if (NonTypedobjects.at(j) == ChildBox) // Dont Check Your Shelf
			continue;

		if (ChildBox->BoxCollide(NonTypedobjects.at(j))) {
			MainBox->ConnetIt(NonTypedobjects.at(j)); // Add collading box to Current Box

			return BoxFunctions::FindSecondChild(MainBox, NonTypedobjects.at(j), NonTypedobjects);
		}
	};
	return nullptr;
}

