class Box {
public:
	Box(int xx, int yy, std::string ss, DWORD boxcolorr, DWORD OutSideColorr, DWORD StringColorr);
	~Box();

	int x, y, w, h;
	std::vector<std::string>BoxStringArray;	
	DWORD BoxColor, OutSideColor, StringColor;
	bool IsAlreadyConnected = false;
	bool IsMother = false;
	int ListLengt = 0;
	

	void UpdateSize() {
		this->h = this->BoxStringArray.size() * 14;
		this->y -= this->BoxStringArray.size() * 14;

		std::sort(BoxStringArray.begin(), BoxStringArray.end(), [](std::string & a, std::string & b) ->bool // find the lognes string whit lengt
		{
			return strlen(a.c_str()) < strlen(b.c_str());
		});

		this->w = BoxStringArray.back().size() * 6.2; // set weight by the longest lengs string
	}

	void AddString(std::string ss) {
		BoxStringArray.push_back(ss);
		UpdateSize();
	}

	void RemoveString(std::string ss) {	
		for (int i = 0; i < BoxStringArray.size(); i++) {
			if (BoxStringArray.at(i).compare(ss.c_str()) == 0) {
				BoxStringArray.erase(BoxStringArray.begin() + i);
			}			
		};
		UpdateSize();
	}

	bool BoxCollide(Box* myBox)
	{
		if (this->IsAlreadyConnected)
			return false;
		if (myBox->IsAlreadyConnected)
			return false;
		// AABB 1
		int x1Min = this->x;
		int x1Max = this->x + this->w;
		int y1Max = this->y + this->h;
		int y1Min = this->y;

		// AABB 2
		int x2Min = myBox->x;
		int x2Max = myBox->x + myBox->w;
		int y2Max = myBox->y + myBox->h;
		int y2Min = myBox->y;

		// Collision tests
		if (x1Max < x2Min || x1Min > x2Max) return false;
		if (y1Max < y2Min || y1Min > y2Max) return false;

		return true;
	}	
	bool HasChild(Box* mybox) {
		return (mybox->ListLengt >= 1);
	}
	bool ConnetIt(Box* myBox) {
		if (this->IsAlreadyConnected)
			return false;
		if (myBox->IsAlreadyConnected)
			return false;

			for (int i = 0; i < myBox->BoxStringArray.size(); i++) {

			//	if ((std::find(this->BoxStringArray.begin(), this->BoxStringArray.end(), myBox->BoxStringArray.at(i).c_str()) != this->BoxStringArray.end()) == false)
					this->BoxStringArray.push_back(myBox->BoxStringArray.at(i));

				myBox->IsAlreadyConnected = true;
				this->ListLengt++;
			};
			this->UpdateSize();	

			return true;
	}
};
