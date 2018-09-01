List<string> RemoveMalformedMissions(List<string> missions) {
    Regex regex = new Regex(@"((?:CO|TVT|COTVT|LOL)(\d+)_.+)_[Vv](\d+).pbo");

    for (int i = 0; i < missions.Count; i++) {
        if (!regex.IsMatch(missions[i]))
            missions.RemoveAt(i--);
    }
    return missions;
}

List<string> RemoveOldVersions(List<string> missions) {
    Regex regex = new Regex(@"((?:CO|TVT|COTVT|LOL)(\d+)_.+)_[Vv]");

    string currentMissionName = "";
    for (int i = missions.Count - 1; i >= 0; i--) {
        string nextMissionName = regex.Match(missions[i]).Value;

        if (currentMissionName == nextMissionName)
            missions.RemoveAt(i);
        else
            currentMissionName = nextMissionName;
    }
    return missions;
}

string[] removeOldMissions(string[] missions) {
    var missionsList = missions.ToList();
    missionsList = RemoveMalformedMissions(missionsList);
    missionsList.Sort(new MissionComparer());
    missionsList = RemoveOldVersions(missionsList);

    return missionsList.ToArray();
}

class MissionComparer: IComparer<string> {
    public int Compare(string a, string b) {
        Regex regex = new Regex(@"\d+");
        var playerCountA = Int32.Parse(regex.Match(a).Value);
        var playerCountB = Int32.Parse(regex.Match(b).Value);

        if (playerCountA != playerCountB)
            return playerCountA - playerCountB;

        return a.CompareTo(b);
    }
}