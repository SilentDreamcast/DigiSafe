// USED FOR ACCOUNT INFORMATION, MODIFY AS NEEDED

// THESE ACCOUNT VALUES ARE HARD CODED AS PLAIN ASCII FOR THE PURPOSE OF DEMONSTRATION FOR COMP467
// THIS DOES NOT REFLECT THE FINAL VERSION OF DIGISAFE'S ACCOUNT STORAGE SOLUTION.
// THE OFFICIAL VERSION OF THIS CODE ENCRYPTS CREDENTIALS AND STORES THEM IN SELF-DESTRUCTING SECURE MEMORY

extern const byte accounts = 15; //number of accounts

// used PROGMEM to read info directly from disk instead of loading to RAM to save memory (THERE IS A BUG WITH PROGMEM & MATRIX)
//const char * const accountList[17][2] PROGMEM = {
extern const char* accountList[accounts+2][3] = {
  {"--Accounts--","",""},
  {" Apple ","UserName1","password 1"},
  {" Blizzard ","UserName2","password 2"},
  {" Crayola ","UserName3","password 3"},
  {" Discord ","UserName4","password 4"},
  {" Ebay ","UserName5","password 5"},
  {" Facebook ","UserName6","password 6"},
  {" Google ","UserName7","password 7"},
  {" Hello! ","UserName8","password 8"},
  {" IndieGoGo ","UserName9","password 9"},
  {" Jexxed ","UserName10","password 10"},
  {" Knoppix ","UserName11","password 11"},
  {" League of Legends ","UserName12","password 12"},
  {" Microsoft ","UserName13","password 13"},
  {" Niagra ","UserName14","password 14"},
  {" Orange ","UserName15","password 15"},
  {"--END--","",""}
};

extern byte accountRank[accounts+2] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
extern boolean sortMode = false; // false=alphabetical sorting, true=popularity sorting
