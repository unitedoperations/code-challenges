# Challenge 2

> https://app.codesignal.com/challenge/cQd77wNT7nR8ZRP2e

## Description

Something has goofed in the mission version control application for the primary server and old versions of missions aren't being removed when new versions are uploaded.

The GSOs have their tail feathers all ruffled about this, and you need to rewrite the algorithm to purge and sort the mission list.

For an input list of mission file names, remove all of the old mission versions if a new one exists and sort the list by number of players.

If a mission file name in the list is malformed, it should be removed.

The approved mission format is:
`(CO|TVT|COTVT|LOL)(##)_NAME_SEP_BY_UNDERSCORE_V(#).pbo`

Remember, two missions with the same name are different if the number of players varies.

**Example:**\
_Input:_ `['CO41_Mission_V1.pbo', 'TVT13_Example_V2.pbo', 'TVT13_Example_V3.pbo']`\
_Output:_ `['TVT13_Example_V3.pbo', 'CO41_Mission_V1.pbo']`

### Sample Structure

```cpp
std::vector<std::string> removeOldVersions(std::vector<std::string> mission) {
  // Your Solution
}
```
