// To convert a string into an array
string s;
char arr[s.length()+1];
strcpy(arr, s.c_str());

// For substring operation

  string substr (size_t pos = 0, size_t len = npos) const;

  string str="We think in generalities, but we live in details.";
                                           // (quoting Alfred N. Whitehead)

 string str2 = str.substr (3,5);     // "think"

 size_t pos = str.find("live");      // position of "live" in str

string str3 = str.substr (pos);     // get from "live" to the end

 cout << str2 << ' ' << str3 << '\n';


// To check if a substring is  part of a string or not

bool isSubstring(string s1, string s2)
{
    // using find method to check if s1 is
    // a substring of s2
    if (s2.find(s1) != string::npos)
        return true;
    return false;
}
