public class MissionVersionContainer implements Comparable<MissionVersionContainer> {

	private final Matcher matcher;
	private final String missionRoot;
	private final int version;

	public MissionVersionContainer(Matcher matcher) {
		this.matcher = matcher;
		this.missionRoot = matcher.group(1);
		this.version = Integer.parseInt(matcher.group(3));
	}

	@Override
	public boolean equals(Object obj) {
		//Subversive equals: only compare the missionRoot...
		final MissionVersionContainer other = (MissionVersionContainer) obj;
		return Objects.equals(this.missionRoot, other.missionRoot);
	}

	public String getOriginalString() {
		return matcher.group(0);
	}

	@Override
	public int compareTo(MissionVersionContainer o) {
		//Mumble mumble.
		int MyPlayerCount = Integer.parseInt(matcher.group(2));
		int OtherPlayerCount = Integer.parseInt(o.matcher.group(2));
		int Compare1 = Integer.compare(MyPlayerCount, OtherPlayerCount);
		if (Compare1 != 0)
		{
			return Compare1;
		}
		//Technically a bad compare, since we want to do an ascending sort on this field
		return Integer.compare(o.version, version);
	}
}

String[] removeOldMissions(String[] missions) {
	//Regex is fun.
	final Pattern pattern = Pattern.compile("((?:CO|TVT|COTVT|LOL)(\\d+)_.+)_[Vv](\\d+).pbo");
	
	List<String> goodMissions // = new ArrayList<>(); goodMissions.add("TVT60_Knife_Fight_V2.chernarus.pbo");
			= Stream.of(missions) //For each input string...
					.map(pattern::matcher) //Make a matcher object out of each string.
					.filter(Matcher::matches) //Only valid names per the regex.
					.map((t) -> { //Wrap them in a container object for some of the glue logic...
						return new MissionVersionContainer(t);
					})
					.sorted() //Sort them so the highest versioned one comes before it's lesser brothers, and otherwise by playercount.
					.distinct() //Get the first of each of the container objects...
					.map(MissionVersionContainer::getOriginalString) //Pop the OG string back out again.
					.collect(Collectors.toList()); //Fill a list with all the elements as they come in, then return it.

	//Convert our list into an array.
	return goodMissions.toArray(new String[0]);
}
