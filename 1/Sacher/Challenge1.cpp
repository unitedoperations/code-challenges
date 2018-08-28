


struct Version
{
    
    int majorV = 0;
    int minorV = -1;
    int revisionV = -1;
    std::string attachedString = "";
    bool operator<(const Version& other)
    {
            if(other.majorV == majorV && other.minorV == minorV && other.revisionV == revisionV) return true;
            if(majorV < other.majorV) return true;
            if(majorV == other.majorV)
            {
                 if(minorV < other.minorV) return true;
                 if(minorV == other.minorV)
                 {
                      if(revisionV < other.revisionV) return true;
                 }
            }
            return false;
    }
    
   
};



std::vector<std::string> split(std::string strToSplit, char delimeter)
{
    std::stringstream ss(strToSplit);
    std::string item;
    std::vector<std::string> splittedStrings;
    while (std::getline(ss, item, delimeter))
    {
       splittedStrings.push_back(item);
    }
    return splittedStrings;
}
bool firstBiggerThanSecondVersion(std::string first,std::string second)
{
    std::vector<std::string> firstV = split(first,'.');
    std::vector<std::string> secondV = split(second,'.');
    for(int i = firstV.size();i < 3;i++) firstV.push_back(std::string(".0"));
    for(int i = secondV.size();i < 3;i++) secondV.push_back(std::string(".0"));
    if(atoi(firstV[0].c_str()) < atoi(secondV[0].c_str())) return false;
    if(atoi(firstV[0].c_str()) == atoi(secondV[0].c_str()))
    {
        if(atoi(firstV[1].c_str()) < atoi(secondV[1].c_str())) return false;
        if(atoi(firstV[1].c_str()) == atoi(secondV[1].c_str()))
        {
            if(atoi(firstV[2].c_str()) < atoi(secondV[2].c_str())) return false;
        }
    }
    return true;
};


std::vector<std::string> sortVersions(std::vector<std::string> versions) 
{ 
  
     for (int i = 0; i < versions.size(); i++)
         for (int j = 0; j < versions.size()-i-1; j++) 
              if (firstBiggerThanSecondVersion(versions[j], versions[j+1]))
              {
                  std::string temp = versions[j];
                  versions[j] = versions[j +1];
                  versions[j +1] = temp;
              }
         
          
    return versions;
}

std::vector<std::string> sortVersions2(std::vector<std::string> versions) 
{ 
      if(versions.size() == 0) return std::vector<std::string>();
    
    std::vector<Version> collectedVersions = std::vector<Version>();
    std::vector<std::string> returnVector = std::vector<std::string>();
    
 
    
    for(std::string el : versions)
    {
        Version v;
       
        std::vector<std::string> splittedVersion = split(el,'.');
        if(splittedVersion.size() == 0 || splittedVersion.size() > 3) continue;
        if(splittedVersion.size() > 0)
            v.majorV = atoi(splittedVersion[0].c_str());
        if(splittedVersion.size() > 1)
            v.minorV = atoi(splittedVersion[1].c_str());
        if(splittedVersion.size() > 2)
            v.revisionV = atoi(splittedVersion[2].c_str());
        v.attachedString = el;
        collectedVersions.push_back(v);
    }
    std::sort(collectedVersions.begin(),collectedVersions.end());
    for(Version v : collectedVersions)
    {
       returnVector.push_back(v.attachedString);
    }
    return returnVector;
    
}
