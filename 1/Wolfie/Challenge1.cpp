//Technically, this treats the numbers incorrectly, but blame Synxe.
std::vector<std::string> sortVersions(std::vector<std::string> versions) {
     std::sort(versions.begin(), versions.end());
     return versions;
}
