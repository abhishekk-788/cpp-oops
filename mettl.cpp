Result Survey(int input1,int input2,int input3,int input4[])
{
    // Read only region end
    int row = input1/input2;
    int col = input2, k = 1;

    vector<vector<int> > vec;
    map<vector<int>, int> mp;
    
    vector<int> str;
    for(int i = 0; i < input1; i++)
    {
        if(i % input2 == 0 && i != 0)
        {
            sort(str.begin(), str.end());
            str.push_back(1000005 + k);
            
            vec.push_back(str);
            
            mp[str] = k++;
            str.clear();
        }
        str.push_back(input4[i]);
    }
    
    sort(str.begin(), str.end());
    
    str.push_back(1000005 + k);
    vec.push_back(str);
    mp[str] = k++;
    
    sort(vec.begin(), vec.end());
    
    int x = (input3-1) / input2;
    int y = (input3-1) % input2;
    
    Result res;
    
    vector<int> str1 = vec[x];
    
    res.output1 = mp[str1];
    res.output2 = vec[x][y];
    
    mp.clear();
    return res;
}



Result Survey(int input1, int input2, int input3, int intput4[])
{
    int row = input1/input2;
    int col = input2, k = 1;

    vector<string> vec;
    map<string, int> mp;

    string str = "";
    for(int i = 0; i < input1; i++)
    {
        if(i % input2 == 0 && i != 0) 
        {
            sort(str.begin(), str.end());
            vec.push_back(str);

            mp[str] = k++;
            str = "";
        }
        str += char(input4[i] + 48);
    }

    sort(str.begin(), str.end());
    vec.push_back(str);

    mp[str] = k++;

    sort(vec.begin(), vec.end());

    int x = (input3-1) / input2;
    int y = (input3-1) % input2;

    Result res;
    string str1 = vec[x];
    res.output1 = mp[str1];

    res.output2 = (int)vec[x][y] - 48;
    mp.clear();

    return res;
}