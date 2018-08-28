string[] sortVersions(string[] versions) {
    Array.Sort(versions, new VersionComparer());
    return versions;
}

public class VersionComparer: System.Collections.IComparer {
    public int Compare(object a, object b) {
            int[] a_numbers = (a as string).Split('.').Select((string s) => Int32.Parse(s)).ToArray();
            int[] b_numbers = (b as string).Split('.').Select((string s) => Int32.Parse(s)).ToArray();

            for (int i = 0; i < 3; i++) {
                var a_val = i < a_numbers.Length ? a_numbers[i] : 0;
                var b_val = i < b_numbers.Length ? b_numbers[i] : 0;
                if (a_val == b_val)
                    continue;
                return a_val - b_val;
            }
            return 0;
    }
}