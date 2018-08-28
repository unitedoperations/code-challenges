#include <vector>
#include <tuple>

bool isValidChar(char c) {
	return (c <= '9' && c >= '0') || c == '.';
}

int* VersionStringToNumber(std::string version) {
	int i = 0;
	int versionComponentIndex = 0;
	int versionNumber = 0;
	int* numbers = new int[3];
	while (i < version.size()) {
		if (!isValidChar(version[i]) || versionComponentIndex > 2)
			throw std::invalid_argument("supplied string was not of correct format");

		if (version[i] != '.') {
			versionNumber *= 10;
			versionNumber += (version[i] - '0');
		}
		else {
			numbers[versionComponentIndex++] = versionNumber;
			versionNumber = 0;
		}
		i++;
	}
	numbers[versionComponentIndex++] = versionNumber;
	while (versionComponentIndex < 3)
		numbers[versionComponentIndex++] = 0;
	return numbers;
}

bool isFirstVersionArrayGreater(int *a, int *b) {
	for (int i = 0; i < 3; i++) {
		if (a[i] == b[i])
			continue;
		return a[i] > b[i];
	}
	return false;
}

#pragma region heapsort

void maxHeapify(std::vector<std::string> &versions, std::vector<int*> &versionNumbers, int heapSize, int i) {
	int left = 2 * i + 1;
	int right = 2 * i + 2;
	int largest = i;
	if (left < heapSize && isFirstVersionArrayGreater(versionNumbers[left], versionNumbers[largest]))
		largest = left;
	if (right < heapSize && isFirstVersionArrayGreater(versionNumbers[right], versionNumbers[largest]))
		largest = right;
	if (largest != i) {
		std::swap(versionNumbers[i], versionNumbers[largest]);
		std::swap(versions[i], versions[largest]);
		maxHeapify(versions, versionNumbers, heapSize, largest);
	}
}

void buildHeap(std::vector<std::string> &versions, std::vector<int*> &versionNumbers) {
	int heapSize = versions.size();
	for (int i = heapSize / 2; i > -1; i--) {
		maxHeapify(versions, versionNumbers, heapSize, i);
	}
}

void HeapSort(std::vector<std::string> &versions, std::vector<int*> &versionNumbers) {
	int heapSize = versions.size();
	buildHeap(versions, versionNumbers);

	for (int i = heapSize - 1; i > 0; i--) {
		std::swap(versionNumbers[0], versionNumbers[i]);
		std::swap(versions[i], versions[0]);
		heapSize--;
		maxHeapify(versions, versionNumbers, heapSize, 0);
	}
}
#pragma endregion

std::vector<std::string> sortVersions(std::vector<std::string> versions) {
	std::vector<int*> *versionValues = new std::vector<int*>();
	
	//we conver versions to integers so we don't have to parse strings on every comparison
	for (std::string version : versions) {
		int *addr;
		addr = VersionStringToNumber(version);
		versionValues->push_back(addr);
	}
	//using heapsort due to efficiency, also we don't care about sorting stability so we save some memory vs merge sort
	HeapSort(versions, *versionValues);
	for (int i = 0; i < versionValues->size(); i++)
		delete (*versionValues)[i];
	delete versionValues;

	return versions;
}
