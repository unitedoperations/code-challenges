package solution

import (
	"sort"
	"strconv"
	"strings"
)

// func sortVersions(versions []string) []string {
//     sorted := make([]string, len(versions))
//     copy(sorted, versions)

//     sort.Strings(sorted)
//     return sorted
// }

func sortVersions(versions []string) []string {
	// Convert a version string into slice of 3 integers
	asIntSlice := func(arr string) []int {
		var asInts []int
		for _, i := range strings.Split(arr, ".") {
			x, _ := strconv.Atoi(i)
			asInts = append(asInts, x)
		}

		for len(asInts) < 3 {
			asInts = append(asInts, 0)
		}

		return asInts
	}

	// Compare two integers slices
	cmp := func(a, b []int) bool {
		if int(a[0]) > int(b[0]) {
			return false
		} else if int(a[0]) < int(b[0]) {
			return true
		}

		if int(a[1]) > int(b[1]) {
			return false
		} else if int(a[1]) < int(b[1]) {
			return true
		}

		if int(a[2]) > int(b[2]) {
			return false
		} else if int(a[2]) < int(b[2]) {
			return true
		}

		return true
	}

	sorted := make([]string, len(versions))
	copy(sorted, versions)

	sort.SliceStable(sorted, func(i, j int) bool {
		x := asIntSlice(sorted[i])
		y := asIntSlice(sorted[j])
		return cmp(x, y)
	})
	sort.Strings(sorted)

	return sorted
}
