Complex & operator=(string str) {
		int pos = str.find("+", 0);
		string sTmp = str.substr(0, pos);
		r = atof(sTmp.c_str());
		sTmp = str.substr(pos + 1, str.length() - pos - 2);
		i = atof(sTmp.c_str());
		return *this;
	}